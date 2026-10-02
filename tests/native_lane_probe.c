/* Differential check of the generated native lane against the interpreter.
 *
 * Guest RAM is mapped at host 0x80000000 and holds the pinned retail EXE.
 * For every lane entry and a few argument patterns, each case runs in a
 * forked child (a native crash or hang cannot take the probe down):
 *   1. restore the image, run the function on the interpreter only;
 *   2. restore the image, run it through the lane (native, with interpreter
 *      thunks for unported callees);
 * then compares v0 (when the function returns a value) and all of guest RAM
 * outside the callee's own stack frame. A case whose interpreter run is
 * refused (it needs a device, a BIOS call, or a wild pointer) proves
 * nothing and is counted as not comparable.
 *
 * D-011 cycle oracle: each case also runs (in a second child, with only the
 * generated table installed, so PsyQ code is interpreted on both sides) the
 * interpreter and the lane with a recording clock. The cycle total at every
 * entry to a function outside the generated table (the native side's
 * thunks and everything below them) and at the return must be equal for a
 * function whose body charges the mapped ledger. A case whose native run
 * reached a fixed (unmapped) charge proves nothing about the mapping and is
 * not comparable; a body that left its mapped graph (ledger_lost) differs.
 *
 * Exit 0 when no comparable case differs (RAM or cycles) and no native run
 * failed where the interpreter succeeded; 77 when the host window or the EXE
 * is missing. MUSASHI_LANE_CYCLES_REPORT=path writes one line per function:
 * pc name ledger same different not_comparable. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_native_lane.h"
#include "musashi_native_lane_psyq.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef MAP_FIXED_NOREPLACE
#define MAP_FIXED_NOREPLACE 0x100000
#endif

extern const MusashiNativeLaneEntry musashi_native_lane_generated[];
extern const size_t musashi_native_lane_generated_count;

enum { ARENA = 0x80180000u, ARENA_SIZE = 0x40000u, STACK_TOP = 0x801fe000u,
       FRAME_GUARD = 0x10000u, PATTERNS = 3, CYCLE_PATTERNS = 5 };

enum Outcome { SAME, DIFFERENT, NATIVE_FAILED, NOT_COMPARABLE, MIRROR_FAULT, WRAP_FAULT };

/* Two documented model gaps, not miscompiles: the interpreter decodes the
 * RAM mirrors (the 2 MB window repeats through the first 8 MB of KUSEG,
 * KSEG0 and KSEG1) while the host window maps only 0x80000000-0x80200000;
 * and guest address arithmetic wraps at 32 bits where host pointer
 * arithmetic does not. The probe's absurd arguments (arena pointers used as
 * array indices) reach both; anything else is a real failure. */
static void on_fault(int sig, siginfo_t *info, void *context) {
    uint64_t address = (uint64_t)(uintptr_t)info->si_addr;
    (void)sig; (void)context;
    if (address < 0x00800000u || (address >= 0x80200000u && address < 0x80800000u) ||
        (address >= 0xa0000000u && address < 0xa0800000u))
        _exit(MIRROR_FAULT);
    if (address >= 0x100000000ull)
        _exit(WRAP_FAULT);
    fprintf(stderr, "native_lane: fault address %llx\n", (unsigned long long)address);
    _exit(128 + SIGSEGV);
}

static uint32_t rng_state = 0x1234567u;
static uint32_t rng(void) {
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 17;
    rng_state ^= rng_state << 5;
    return rng_state;
}

static void seed_arena(MusashiBootMemory *memory, uint32_t seed);
static void make_args(unsigned pattern, uint32_t *args);

/* ---- cycle oracle --------------------------------------------------- */
enum CycleOutcome { C_SAME, C_DIFFERENT, C_NOT_COMPARABLE, C_FIXED, C_NATIVE_FAILED, C_UNMAPPED };
typedef struct CycleMark { uint32_t pc; uint64_t cycle; } CycleMark;
enum { MARKS = 8192 };
static uint64_t g_cycles;
static CycleMark g_marks[MARKS];
static unsigned g_nmarks;
static int g_marks_overflow;
static uint32_t *g_lane_pcs;
static size_t g_lane_n;

static int cycle_advance(void *userdata, uint32_t cycles) {
    (void)userdata;
    g_cycles += cycles;
    return 1;
}
static const MusashiExecutionClock g_cycle_clock = {NULL, cycle_advance};

static int pc_cmp(const void *a, const void *b) {
    uint32_t x = *(const uint32_t *)a, y = *(const uint32_t *)b;
    return x < y ? -1 : x > y;
}
static void cycle_mark(void *userdata, uint32_t pc, const uint32_t *regs) {
    (void)userdata; (void)regs;
    if (bsearch(&pc, g_lane_pcs, g_lane_n, sizeof pc, pc_cmp)) return;
    if (g_nmarks == MARKS) { g_marks_overflow = 1; return; }
    g_marks[g_nmarks].pc = pc;
    g_marks[g_nmarks].cycle = g_cycles;
    ++g_nmarks;
}

static int cycle_case(MusashiBootMemory *memory, const uint8_t *image,
                      const MusashiNativeLaneEntry *entry, unsigned pattern) {
    uint32_t args[8], regs[32];
    unsigned argc = entry->argc > 8u ? 8u : entry->argc, i, ref_n;
    uint64_t ref_total;
    CycleMark *ref;
    uint32_t lost0, fixed0;
    int ok;
    if (!entry->ledger) return C_UNMAPPED;
    /* generated table only: PsyQ code is interpreted on both sides */
    if (musashi_native_lane_install(musashi_native_lane_generated,
                                    musashi_native_lane_generated_count) < 0)
        return C_NOT_COMPARABLE;
    musashi_formatter_set_entry_hook(cycle_mark, NULL);
    memcpy(memory->bytes, image, MUSASHI_RAM_SIZE);
    seed_arena(memory, entry->guest_pc ^ (pattern * 0x9e3779b9u));
    make_args(pattern, args);
    {
        uint8_t *start = malloc(MUSASHI_RAM_SIZE);
        if (!start) return C_NOT_COMPARABLE;
        memcpy(start, memory->bytes, MUSASHI_RAM_SIZE);
        g_cycles = 0; g_nmarks = 0; g_marks_overflow = 0;
        alarm(5);
        ok = musashi_native_lane_reference_call_clocked(memory, entry->guest_pc, args, argc,
                                                        STACK_TOP, 0, regs, &g_cycle_clock);
        alarm(0);
        if (!ok || g_marks_overflow) { free(start); return C_NOT_COMPARABLE; }
        ref_total = g_cycles;
        ref_n = g_nmarks;
        ref = malloc((ref_n + 1u) * sizeof *ref);
        if (!ref) { free(start); return C_NOT_COMPARABLE; }
        memcpy(ref, g_marks, ref_n * sizeof *ref);
        memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
        free(start);
    }
    g_cycles = 0; g_nmarks = 0; g_marks_overflow = 0;
    lost0 = musashi_lane_ledger_lost;
    fixed0 = musashi_lane_fixed;
    alarm(5);
    ok = musashi_native_lane_reference_call_clocked(memory, entry->guest_pc, args, argc,
                                                    STACK_TOP, 1, regs, &g_cycle_clock);
    alarm(0);
    if (!ok) return C_NATIVE_FAILED;
    if (musashi_lane_ledger_lost != lost0) {
        fprintf(stderr, "native_lane_cycles: %s pattern %u left its mapped graph (ledger_lost)\n",
                entry->name, pattern);
        return C_DIFFERENT;
    }
    if (musashi_lane_fixed != fixed0 || g_marks_overflow) return C_FIXED;
    for (i = 0; i < ref_n || i < g_nmarks; ++i) {
        if (i >= ref_n || i >= g_nmarks || ref[i].pc != g_marks[i].pc ||
            ref[i].cycle != g_marks[i].cycle) {
            fprintf(stderr, "native_lane_cycles: %s pattern %u boundary %u: interp %08x@%llu native %08x@%llu\n",
                    entry->name, pattern, i, i < ref_n ? ref[i].pc : 0u,
                    i < ref_n ? (unsigned long long)ref[i].cycle : 0ull,
                    i < g_nmarks ? g_marks[i].pc : 0u,
                    i < g_nmarks ? (unsigned long long)g_marks[i].cycle : 0ull);
            return C_DIFFERENT;
        }
    }
    if (ref_total != g_cycles) {
        fprintf(stderr, "native_lane_cycles: %s pattern %u return: interp %llu native %llu\n",
                entry->name, pattern, (unsigned long long)ref_total, (unsigned long long)g_cycles);
        return C_DIFFERENT;
    }
    return C_SAME;
}

static void seed_arena(MusashiBootMemory *memory, uint32_t seed) {
    uint32_t a;
    rng_state = seed | 1u;
    /* Every arena word is a plausible guest pointer back into the arena, so
     * functions that chase pointers stay inside mapped guest RAM. */
    for (a = ARENA; a < ARENA + ARENA_SIZE; a += 4u)
        musashi_boot_write32(memory, a, ARENA + (rng() % (ARENA_SIZE - 0x1000u) & ~3u));
}

static void make_args(unsigned pattern, uint32_t *args) {
    unsigned i;
    for (i = 0; i < 8; ++i) {
        if (pattern == 0) args[i] = ARENA + 0x1000u * (i + 1u);
        else if (pattern == 1) args[i] = rng() % 8u;
        else if (pattern == 2) args[i] = (i & 1u) ? rng() % 4u : ARENA + 0x800u * (i + 3u);
        /* cycle-only patterns: negative values reach the data-dependent
         * division costs (divisor -1, negative dividend) */
        else if (pattern == 3) args[i] = 0xFFFFFFFFu;
        else args[i] = (uint32_t)-(int32_t)(1u + rng() % 64u);
    }
}

static int run_case(MusashiBootMemory *memory, const uint8_t *image,
                    const MusashiNativeLaneEntry *entry, unsigned pattern,
                    uint8_t *reference) {
    uint32_t args[8], ref_v0 = 0, lane_v0 = 0;
    unsigned argc = entry->argc > 8u ? 8u : entry->argc;
    int ok;
    memcpy(memory->bytes, image, MUSASHI_RAM_SIZE);
    seed_arena(memory, entry->guest_pc ^ (pattern * 0x9e3779b9u));
    make_args(pattern, args);
    {
        uint8_t *start = malloc(MUSASHI_RAM_SIZE);
        if (!start) return NOT_COMPARABLE;
        memcpy(start, memory->bytes, MUSASHI_RAM_SIZE);
        alarm(5);
        ok = musashi_native_lane_reference_call(memory, entry->guest_pc, args, argc,
                                                STACK_TOP, 0, &ref_v0, NULL);
        alarm(0);
        if (!ok) { free(start); return NOT_COMPARABLE; }
        memcpy(reference, memory->bytes, MUSASHI_RAM_SIZE);
        memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
        free(start);
    }
    alarm(5);
    ok = musashi_native_lane_reference_call(memory, entry->guest_pc, args, argc,
                                            STACK_TOP, 1, &lane_v0, NULL);
    alarm(0);
    if (!ok) return NATIVE_FAILED;
    if (entry->returns && ref_v0 != lane_v0) {
        fprintf(stderr, "native_lane: %s pattern %u v0 interp=%08x native=%08x\n",
                entry->name, pattern, ref_v0, lane_v0);
        return DIFFERENT;
    }
    {
        /* The interpreted callee's own frame and o32 home area are its
         * private scratch; the native function keeps those on the host. */
        const uint32_t lo = STACK_TOP - FRAME_GUARD - 0x80000000u;
        const uint32_t hi = STACK_TOP + 0x10u + 4u * 8u - 0x80000000u;
        uint32_t i;
        int differ = 0;
        for (i = 0; i < MUSASHI_RAM_SIZE; ++i) {
            if (i >= lo && i < hi) continue;
            if (memory->bytes[i] != reference[i]) {
                fprintf(stderr, "native_lane: %s pattern %u RAM %08x interp=%02x native=%02x\n",
                        entry->name, pattern, 0x80000000u + i, reference[i], memory->bytes[i]);
                if (!getenv("MUSASHI_LANE_PROBE_ONLY")) return DIFFERENT;
                differ = 1;
            }
        }
        if (differ) return DIFFERENT;
    }
    return SAME;
}

int main(int argc, char **argv) {
    MusashiBootMemory *memory;
    uint8_t *image, *reference, *exe;
    FILE *file;
    size_t exe_size, i, table_count = 0;
    MusashiNativeLaneEntry *table;
    unsigned counts[6] = {0}, functions_same = 0, functions_bad = 0;
    unsigned ccounts[6] = {0}, cf_same = 0, cf_diff = 0, cf_nc = 0, mapped = 0;
    FILE *creport = getenv("MUSASHI_LANE_CYCLES_REPORT") ?
        fopen(getenv("MUSASHI_LANE_CYCLES_REPORT"), "w") : NULL;
    const char *only = getenv("MUSASHI_LANE_PROBE_ONLY");
    if (argc != 2) {
        fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]);
        return 2;
    }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "native_lane: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, file) : 0;
    fclose(file);
    memory = musashi_native_lane_map_guest(sizeof(*memory), NULL);
    if (!memory) {
        fprintf(stderr, "native_lane: host window at 0x80000000 unavailable; NOT_RUN\n");
        return 77;
    }
    if (!musashi_boot_map_exe(memory, exe, exe_size)) {
        fprintf(stderr, "native_lane: pinned EXE rejected\n");
        return 1;
    }
    /* Generated decomp C plus port-plat's pure PsyQ wrappers (no GTE owner
     * here, so the GTE-state wrappers refuse and prove only the fallback). */
    table = musashi_native_lane_psyq_merge(musashi_native_lane_generated,
                                           musashi_native_lane_generated_count,
                                           MUSASHI_PSYQ_LANE_PURE, &table_count);
    if (!table) return 1;
    musashi_native_lane_psyq_bind(memory, NULL);
    if (musashi_native_lane_install(table, table_count) < 0) {
        fprintf(stderr, "native_lane: table rejected\n");
        return 1;
    }
    if (!musashi_native_lane_usable(memory)) {
        fprintf(stderr, "native_lane: lane not usable\n");
        return 1;
    }
    g_lane_n = musashi_native_lane_generated_count;
    g_lane_pcs = malloc((g_lane_n + 1u) * sizeof *g_lane_pcs);
    if (!g_lane_pcs) return 1;
    for (i = 0; i < g_lane_n; ++i) g_lane_pcs[i] = musashi_native_lane_generated[i].guest_pc;
    qsort(g_lane_pcs, g_lane_n, sizeof *g_lane_pcs, pc_cmp);
    image = malloc(MUSASHI_RAM_SIZE);
    reference = malloc(MUSASHI_RAM_SIZE);
    if (!image || !reference) return 1;
    memcpy(image, memory->bytes, MUSASHI_RAM_SIZE);
    for (i = 0; i < table_count; ++i) {
        const MusashiNativeLaneEntry *entry = &table[i];
        unsigned pattern, same = 0, bad = 0, csame = 0, cdiff = 0, cnc = 0;
        if (only && strtoul(only, NULL, 16) != entry->guest_pc) continue;
        for (pattern = 0; pattern < CYCLE_PATTERNS; ++pattern) {
            int status, outcome = NOT_COMPARABLE;
            if (pattern >= PATTERNS) goto cycles_only;
            pid_t child;
            fflush(stderr);
            child = fork();
            if (child == 0) {
                struct sigaction action;
                memset(&action, 0, sizeof(action));
                action.sa_sigaction = on_fault;
                action.sa_flags = SA_SIGINFO;
                sigaction(SIGSEGV, &action, NULL);
                sigaction(SIGBUS, &action, NULL);
                signal(SIGALRM, SIG_DFL);
                _exit(run_case(memory, image, entry, pattern, reference));
            }
            if (child < 0 || waitpid(child, &status, 0) != child) return 1;
            if (WIFEXITED(status)) outcome = WEXITSTATUS(status);
            else outcome = -WTERMSIG(status);
            if (outcome < 0) {
                /* The bounds-checked interpreter cannot fault, and its step
                 * limit ends well inside the alarm: this is the native run. */
                fprintf(stderr, "native_lane: %s pattern %u child signal %d\n",
                        entry->name, pattern, -outcome);
                outcome = NATIVE_FAILED;
            }
            if (outcome >= 128) {
                fprintf(stderr, "native_lane: %s pattern %u native fault (signal %d)\n",
                        entry->name, pattern, outcome - 128);
                outcome = NATIVE_FAILED;
            } else if (outcome > WRAP_FAULT) {
                outcome = NOT_COMPARABLE;
            }
            counts[outcome]++;
            if (outcome == SAME) same++;
        cycles_only:
            if (entry->ledger) {
                int cstatus, coutcome;
                fflush(stderr);
                child = fork();
                if (child == 0) {
                    struct sigaction action;
                    memset(&action, 0, sizeof(action));
                    action.sa_handler = SIG_DFL;
                    sigaction(SIGSEGV, &action, NULL);
                    signal(SIGALRM, SIG_DFL);
                    _exit(cycle_case(memory, image, entry, pattern));
                }
                if (child < 0 || waitpid(child, &cstatus, 0) != child) return 1;
                coutcome = WIFEXITED(cstatus) && WEXITSTATUS(cstatus) <= C_UNMAPPED ?
                    WEXITSTATUS(cstatus) : C_NATIVE_FAILED;
                /* a native fault the RAM run classed as a mirror/wrap gap */
                if (coutcome == C_NATIVE_FAILED && outcome != SAME && outcome != DIFFERENT)
                    coutcome = C_NOT_COMPARABLE;
                ccounts[coutcome]++;
                if (coutcome == C_SAME) csame++;
                else if (coutcome == C_DIFFERENT || coutcome == C_NATIVE_FAILED) cdiff++;
                else cnc++;
            }
            if (outcome == DIFFERENT || outcome == NATIVE_FAILED) {
                bad++;
                if (outcome == NATIVE_FAILED)
                    fprintf(stderr, "native_lane: %s pattern %u native failed where interp returned\n",
                            entry->name, pattern);
            }
        }
        functions_same += same && !bad;
        functions_bad += bad != 0;
        if (entry->ledger) {
            ++mapped;
            if (cdiff) ++cf_diff;
            else if (csame) ++cf_same;
            else ++cf_nc;
            if (creport)
                fprintf(creport, "%08x %s ledger %u %u %u\n", entry->guest_pc, entry->name,
                        csame, cdiff, cnc);
        } else if (creport && i < table_count && entry->guest_pc) {
            fprintf(creport, "%08x %s fixed 0 0 0\n", entry->guest_pc, entry->name);
        }
    }
    printf("native_lane: entries=%zu psyq=%zu cases same=%u different=%u native_failed=%u not_comparable=%u "
           "mirror_fault=%u wrap_fault=%u functions_verified=%u functions_bad=%u\n",
           table_count, table_count - musashi_native_lane_generated_count, counts[SAME], counts[DIFFERENT],
           counts[NATIVE_FAILED], counts[NOT_COMPARABLE], counts[MIRROR_FAULT], counts[WRAP_FAULT],
           functions_same, functions_bad);
    printf("native_lane_cycles: mapped=%u functions same=%u different=%u not_comparable=%u "
           "cases same=%u different=%u not_comparable=%u fixed_reached=%u native_failed=%u\n",
           mapped, cf_same, cf_diff, cf_nc, ccounts[C_SAME], ccounts[C_DIFFERENT],
           ccounts[C_NOT_COMPARABLE], ccounts[C_FIXED], ccounts[C_NATIVE_FAILED]);
    if (creport) fclose(creport);
    return functions_bad || cf_diff ? 1 : 0;
}
