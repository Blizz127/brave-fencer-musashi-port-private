/* D-011 deadline guard: the mid-native checkpoint against the interpreter's.
 *
 * For every ledger-mapped generated function and a few argument patterns,
 * each case runs the function on the interpreter (lane off) and through the
 * lane (native) with the same recording clock and the same fake device:
 * device events fall due on a fixed schedule (first at phase D0, then every
 * P cycles), the clock's deadline query reports the cycles to the next one,
 * and the checkpoint, called before every interpreted instruction and by the
 * lane's tick, "delivers" a due event by charging an IRQ handler's cost (H
 * cycles) and recording what it saw: the CPU context (retail pc, delay slot,
 * branch pc, fetched instruction, identity) and the clock. The sequence of
 * deliveries and the cycle totals at return must be equal, and every
 * checkpoint must see the run's own CPU identity (the lane's tick uses the
 * interrupted CPU, never a nested one). Many phases put the deadlines at
 * every position inside the native body's segments, delay slots included.
 *
 * A case whose interpreter run is refused proves nothing; one whose native
 * run reached a fixed (unmapped) charge is not comparable either. Exit 0
 * when nothing differs and the tick path ran; 1 otherwise; 77 when the host
 * window or the EXE is missing.
 *
 * N-GTE natives (GTE_FNS) need the GTE owner on the interpreter leg (CU2
 * transfers through a transfer device) and the lane GTE helpers on the same
 * owner on the native leg; without them both legs refuse and nothing is
 * compared. Their arguments are built per kind (the targeted probe's GTE
 * family kinds, simplified: this probe compares checkpoint positions, not
 * values), the GTE bank is a seeded scene, and each leg runs in its own fork
 * so that both start from that bank (the owner has no restore). They are
 * also reported on their own line. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_cpu_status.h"
#include "musashi_native_lane.h"
#ifdef MUSASHI_WITH_PSYCROSS
#include "musashi_gte_owner.h"
#include <sys/mman.h>
#endif

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern const MusashiNativeLaneEntry musashi_native_lane_generated[];
extern const size_t musashi_native_lane_generated_count;

enum { ARENA = 0x80180000u, ARENA_SIZE = 0x40000u, STACK_TOP = 0x801fe000u, PATTERNS = 3,
       MAX_DELIVERIES = 512, HANDLER_CYCLES = 50u };
static const uint32_t PHASES[] = {1u, 2u, 3u, 4u, 5u, 6u, 7u, 9u, 11u, 13u, 17u, 23u, 31u, 47u, 64u, 101u};
static const uint32_t PERIODS[] = {37u, 211u};
#define N(a) (sizeof(a) / sizeof((a)[0]))
enum { G_SAME, G_DIFFERENT, G_NOT_COMPARABLE, G_FIXED };

typedef struct Delivery {
    uint32_t pc, branch_pc, instruction;
    uint8_t delay_slot;
    uint64_t cycle;
} Delivery;

typedef struct Run {
    uint64_t cycles, next_due, period;
    Delivery d[MAX_DELIVERIES];
    unsigned n;
    int overflow, identity_bad;
    const void *identity;
} Run;

static Run g_run;

static int fake_advance(void *u, uint32_t c) { (void)u; g_run.cycles += c; return 1; }
static int fake_deadline(void *u, uint64_t *until) {
    (void)u;
    *until = g_run.next_due > g_run.cycles ? g_run.next_due - g_run.cycles : 0;
    return 1;
}
static const MusashiExecutionClock g_clock = {NULL, fake_advance};

static int fake_checkpoint(void *u, const void *continuation) {
    MusashiCpuContext ctx;
    (void)u;
    if (!g_run.identity) g_run.identity = continuation;
    else if (g_run.identity != continuation) g_run.identity_bad = 1;
    if (g_run.cycles < g_run.next_due) return 1;
    if (!musashi_boot_cpu_context(continuation, MUSASHI_CPU_CONTEXT_SOURCE, &ctx)) return 0;
    if (g_run.n == MAX_DELIVERIES) { g_run.overflow = 1; return 1; }
    g_run.d[g_run.n].pc = ctx.pc;
    g_run.d[g_run.n].branch_pc = ctx.delay_slot ? ctx.branch_pc : 0u;
    g_run.d[g_run.n].instruction = ctx.instruction_valid ? ctx.instruction : 0u;
    g_run.d[g_run.n].delay_slot = ctx.delay_slot ? 1u : 0u;
    g_run.d[g_run.n].cycle = g_run.cycles;
    ++g_run.n;
    /* the IRQ handler runs here and charges its own time */
    g_run.cycles += HANDLER_CYCLES;
    while (g_run.next_due <= g_run.cycles) g_run.next_due += g_run.period;
    return 1;
}

static uint32_t rng_state = 0x1234567u;
static uint32_t rng(void) {
    rng_state ^= rng_state << 13; rng_state ^= rng_state >> 17; rng_state ^= rng_state << 5;
    return rng_state;
}
static void seed_arena(MusashiBootMemory *memory, uint32_t seed) {
    uint32_t a;
    rng_state = seed | 1u;
    for (a = ARENA; a < ARENA + ARENA_SIZE; a += 4u)
        musashi_boot_write32(memory, a, ARENA + (rng() % (ARENA_SIZE - 0x1000u) & ~3u));
}
static void make_args(unsigned pattern, uint32_t *args) {
    unsigned i;
    for (i = 0; i < 8; ++i) {
        if (pattern == 0) args[i] = ARENA + 0x1000u * (i + 1u);
        else if (pattern == 1) args[i] = rng() % 8u;
        else args[i] = (i & 1u) ? rng() % 4u : ARENA + 0x800u * (i + 3u);
    }
}

static int run_once(MusashiBootMemory *memory, const MusashiNativeLaneEntry *e, const uint32_t *args,
                    unsigned argc, int use_lane, uint32_t phase, uint32_t period) {
    uint32_t regs[32];
    int ok;
    memset(&g_run, 0, sizeof g_run);
    g_run.next_due = phase;
    g_run.period = period;
    alarm(5);
    ok = musashi_native_lane_reference_call_checkpoint(memory, e->guest_pc, args, argc, STACK_TOP,
                                                       use_lane, regs, &g_clock, fake_checkpoint, NULL);
    alarm(0);
    return ok;
}

#ifdef MUSASHI_WITH_PSYCROSS
/* The N-GTE natives and their argument kinds (tests/native_lane_targeted_probe.c GTE_FAMILY): p pointer, i small
 * integer, b packed screen bounds, v pointer to a 3-word vector, c zero-terminated list (3, 9 or 7 entries by
 * pattern: both buffer paths), x matrix, r/k part records, o skip (set in pattern 1). */
typedef struct { uint32_t pc; const char *kinds; } GteFn;
static const GteFn GTE_FNS[] = {
    {0x800123F0u, "pi"}, {0x80012558u, "pi"}, {0x800126C4u, "pi"}, {0x8001D70Cu, "p"},
    {0x8001D8C4u, "ppp"}, {0x8001E378u, "p"}, {0x8001E668u, "pppp"}, {0x80021174u, "bv"},
    {0x80020248u, "crxxo"}, {0x80020A28u, "ckxxo"},
};
static MusashiCpuStatus *g_status;
static MusashiGteOwner g_owner;
static const int g_identity;
static const uint32_t g_gpr[32];
static int g_gte_ok;
static uint64_t thread_token(void *u) { (void)u; return 1u; }
static MusashiCpuContext lease_ctx(void) {
    MusashiCpuContext c;
    memset(&c, 0, sizeof c);
    c.identity = &g_identity;
    c.gpr = g_gpr;
    c.pc = 0x80049440u;
    c.npc = c.pc + 4u;
    c.instruction = 0x4884F000u;
    c.instruction_valid = 1;
    c.provenance = MUSASHI_CPU_CONTEXT_SOURCE;
    return c;
}
/* Test-only adaptor, as in the targeted probe: present the owner's lease identity for the nested interpreter. */
static MusashiCpuContext as_lease(const MusashiCpuContext *c) {
    MusashiCpuContext x = *c;
    x.identity = &g_identity;
    return x;
}
static int t_write_data(void *u, const MusashiCpuContext *c, uint32_t sel, uint32_t v) {
    MusashiCpuContext x = as_lease(c); (void)u;
    return musashi_gte_owner_write_data(&g_owner, &x, sel, v);
}
static int t_read_data(void *u, const MusashiCpuContext *c, uint32_t sel, uint32_t *v) {
    MusashiCpuContext x = as_lease(c); (void)u;
    return musashi_gte_owner_read_data(&g_owner, &x, sel, v);
}
static int t_write_control(void *u, const MusashiCpuContext *c, uint32_t sel, uint32_t v) {
    MusashiCpuContext x = as_lease(c); (void)u;
    return musashi_gte_owner_write_control(&g_owner, &x, sel, v);
}
static int t_read_control(void *u, const MusashiCpuContext *c, uint32_t sel, uint32_t *v) {
    MusashiCpuContext x = as_lease(c); (void)u;
    return musashi_gte_owner_read_control(&g_owner, &x, sel, v);
}
static int t_command(void *u, const MusashiCpuContext *c, uint32_t word) {
    MusashiCpuContext x = as_lease(c); (void)u;
    return musashi_gte_owner_command(&g_owner, &x, word);
}
static const MusashiCpuTransferDevice g_transfer = {
    .write_control = t_write_control, .write_data = t_write_data, .read_data = t_read_data,
    .read_control = t_read_control, .command = t_command};

static const char *gte_kinds(uint32_t pc) {
    size_t k;
    for (k = 0; k < N(GTE_FNS); ++k)
        if (GTE_FNS[k].pc == pc) return GTE_FNS[k].kinds;
    return NULL;
}
static uint32_t s16pair(int32_t lo, int32_t hi) { return ((uint32_t)hi << 16) | ((uint32_t)lo & 0xFFFFu); }
static int32_t sm(uint32_t span) { return (int32_t)(rng() % (2u * span)) - (int32_t)span; }
/* The targeted probe's scene bank: a rotation-scale matrix and a translation in front of the viewer, small
 * background/light/far colour terms, screen offset, projection distance, depth-cue and Z-average scales, small V0
 * and IR. */
static int gte_scene(uint32_t salt) {
    MusashiCpuContext c = lease_ctx();
    int32_t e[9];
    uint32_t w[8], k;
    rng_state = salt | 1u;
    for (k = 0; k < 9u; ++k) e[k] = sm(4096u);
    w[0] = s16pair(e[0], e[1]); w[1] = s16pair(e[2], e[3]); w[2] = s16pair(e[4], e[5]);
    w[3] = s16pair(e[6], e[7]); w[4] = s16pair(e[8], 0);
    w[5] = (uint32_t)sm(300u); w[6] = (uint32_t)sm(300u); w[7] = 1500u + rng() % 4500u;
    for (k = 0; k <= 7u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, w[k])) return 0;
    for (k = 13; k <= 23u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, k <= 15u ? (uint32_t)sm(256u) :
                                             s16pair(sm(4096u), sm(4096u)))) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 24, (160u + rng() % 64u) << 16) ||
        !musashi_gte_owner_write_control(&g_owner, &c, 25, (120u + rng() % 64u) << 16) ||
        !musashi_gte_owner_write_control(&g_owner, &c, 26, 200u + rng() % 300u) ||
        !musashi_gte_owner_write_control(&g_owner, &c, 27, (uint32_t)-(int32_t)(rng() % 512u)) ||
        !musashi_gte_owner_write_control(&g_owner, &c, 28, 0x01400000u + rng() % 0x10000u) ||
        !musashi_gte_owner_write_control(&g_owner, &c, 29, 0x155u + rng() % 16u) ||
        !musashi_gte_owner_write_control(&g_owner, &c, 30, 0x100u + rng() % 16u)) return 0;
    if (!musashi_gte_owner_write_data(&g_owner, &c, 0, s16pair(sm(400u), sm(400u))) ||
        !musashi_gte_owner_write_data(&g_owner, &c, 1, (uint32_t)sm(400u))) return 0;
    for (k = 9; k <= 11u; ++k)
        if (!musashi_gte_owner_write_data(&g_owner, &c, k, (uint32_t)sm(4096u))) return 0;
    return 1;
}
/* Arguments by kind, in the seeded arena (one 8 KiB slot per argument). */
static unsigned gte_args(MusashiBootMemory *memory, const char *kinds, unsigned pattern, uint32_t *args) {
    static const unsigned list_n[PATTERNS] = {3u, 9u, 7u};
    unsigned i, j;
    for (i = 0; kinds[i] && i < 8u; ++i) {
        const uint32_t base = ARENA + 0x2000u * (i + 1u);
        switch (kinds[i]) {
        case 'i': args[i] = rng() % 8u; break;
        case 'o': args[i] = pattern == 1u; break;
        case 'b': args[i] = ((32u + rng() % 368u) << 16) | (32u + rng() % 368u); break;
        case 'v':
            for (j = 0; j < 3u; ++j) musashi_boot_write32(memory, base + 4u * j, rng() % 800u - 400u);
            args[i] = base;
            break;
        case 'c':
            for (j = 0; j < list_n[pattern]; ++j) musashi_boot_write32(memory, base + 4u * j, rng() | 1u);
            musashi_boot_write32(memory, base + 4u * list_n[pattern], 0u);
            args[i] = base;
            break;
        default: args[i] = base; break; /* p, x, r, k: the seeded arena words */
        }
    }
    return i;
}

/* One leg in its own fork (both legs start from the case's GTE bank); results through shared memory. -1 when the
 * leg did not exit normally (a fault or the 5 s alarm, which in guard_case ends the whole case: not comparable). */
typedef struct { Run run; int ok; uint32_t fixed; uint64_t ticks; } Leg;
static Leg *g_leg;
static int gte_leg(MusashiBootMemory *memory, const MusashiNativeLaneEntry *e, const uint32_t *args,
                   unsigned argc, int use_lane, uint32_t phase, uint32_t period) {
    int status;
    pid_t child;
    memset(g_leg, 0, sizeof *g_leg);
    fflush(stderr);
    child = fork();
    if (child == 0) {
        MusashiNativeLaneGuardStats a, b;
        const uint32_t fixed0 = musashi_lane_fixed;
        uint32_t regs[32];
        musashi_native_lane_guard_stats(&a);
        memset(&g_run, 0, sizeof g_run);
        g_run.next_due = phase;
        g_run.period = period;
        alarm(5);
        g_leg->ok = musashi_native_lane_reference_call_device(memory, e->guest_pc, args, argc, STACK_TOP, use_lane,
                                                              regs, &g_clock, fake_checkpoint, NULL,
                                                              &g_transfer) == 1;
        alarm(0);
        musashi_native_lane_guard_stats(&b);
        g_leg->run = g_run;
        g_leg->fixed = musashi_lane_fixed - fixed0;
        g_leg->ticks = b.checkpoints - a.checkpoints;
        _exit(0);
    }
    if (child < 0 || waitpid(child, &status, 0) != child || !WIFEXITED(status)) return -1;
    g_run = g_leg->run;
    return g_leg->ok;
}

/* guard_case for an N-GTE native: the same schedules and comparisons. The guest window (RAM and scratchpad) is a
 * shared mapping, so both are restored before every leg. */
static int gte_guard_case(MusashiBootMemory *memory, const uint8_t *image, const MusashiNativeLaneEntry *e,
                          const char *kinds, unsigned pattern, uint64_t *ticks) {
    uint32_t args[8];
    unsigned argc, p, q, i, compared = 0;
    uint8_t *start = malloc(MUSASHI_RAM_SIZE), scratch[MUSASHI_SCRATCHPAD_SIZE];
    static Run ref;
    if (!start || !g_leg) return G_NOT_COMPARABLE;
    memcpy(memory->bytes, image, MUSASHI_RAM_SIZE);
    memset(memory->scratchpad, 0, MUSASHI_SCRATCHPAD_SIZE);
    seed_arena(memory, e->guest_pc ^ (pattern * 0x9e3779b9u));
    argc = gte_args(memory, kinds, pattern, args);
    if (!gte_scene(e->guest_pc ^ (pattern * 0x85ebca6bu))) return G_NOT_COMPARABLE;
    memcpy(start, memory->bytes, MUSASHI_RAM_SIZE);
    memcpy(scratch, memory->scratchpad, MUSASHI_SCRATCHPAD_SIZE);
    *ticks = 0;
    for (q = 0; q < N(PERIODS); ++q)
        for (p = 0; p < N(PHASES); ++p) {
            int r;
            memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
            memcpy(memory->scratchpad, scratch, MUSASHI_SCRATCHPAD_SIZE);
            r = gte_leg(memory, e, args, argc, 0, PHASES[p], PERIODS[q]);
            if (r < 0) return G_NOT_COMPARABLE;
            if (!r || g_run.overflow) continue;
            ref = g_run;
            memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
            memcpy(memory->scratchpad, scratch, MUSASHI_SCRATCHPAD_SIZE);
            r = gte_leg(memory, e, args, argc, 1, PHASES[p], PERIODS[q]);
            if (r < 0) return G_NOT_COMPARABLE;
            if (!r) {
                fprintf(stderr, "guard: %s pattern %u phase %u period %u: native run failed\n", e->name,
                        pattern, PHASES[p], PERIODS[q]);
                return G_DIFFERENT;
            }
            if (g_leg->fixed) return G_FIXED;
            if (g_run.identity_bad) {
                fprintf(stderr, "guard: %s: a checkpoint saw another CPU identity\n", e->name);
                return G_DIFFERENT;
            }
            if (g_run.n != ref.n || g_run.cycles != ref.cycles) {
                fprintf(stderr, "guard: %s pattern %u phase %u period %u: deliveries %u/%u total %llu/%llu\n",
                        e->name, pattern, PHASES[p], PERIODS[q], ref.n, g_run.n,
                        (unsigned long long)ref.cycles, (unsigned long long)g_run.cycles);
                return G_DIFFERENT;
            }
            for (i = 0; i < ref.n; ++i) {
                const Delivery *a = &ref.d[i], *b = &g_run.d[i];
                if (a->pc != b->pc || a->cycle != b->cycle || a->delay_slot != b->delay_slot ||
                    a->branch_pc != b->branch_pc || a->instruction != b->instruction) {
                    fprintf(stderr, "guard: %s pattern %u phase %u period %u delivery %u: interp %08x%s@%llu "
                            "native %08x%s@%llu\n", e->name, pattern, PHASES[p], PERIODS[q], i,
                            a->pc, a->delay_slot ? "(slot)" : "", (unsigned long long)a->cycle,
                            b->pc, b->delay_slot ? "(slot)" : "", (unsigned long long)b->cycle);
                    return G_DIFFERENT;
                }
            }
            *ticks += g_leg->ticks;
            ++compared;
        }
    free(start);
    return compared ? G_SAME : G_NOT_COMPARABLE;
}
#endif

/* One (function, pattern): every schedule. Returns a G_* outcome. */
static int guard_case(MusashiBootMemory *memory, const uint8_t *image, const MusashiNativeLaneEntry *e,
                      unsigned pattern, uint64_t *ticks) {
    uint32_t args[8];
    unsigned argc = e->argc > 8u ? 8u : e->argc, p, q, i, compared = 0;
    uint8_t *start = malloc(MUSASHI_RAM_SIZE);
    static Run ref;
    MusashiNativeLaneGuardStats g0, g1;
    if (!start) return G_NOT_COMPARABLE;
    memcpy(memory->bytes, image, MUSASHI_RAM_SIZE);
    seed_arena(memory, e->guest_pc ^ (pattern * 0x9e3779b9u));
    make_args(pattern, args);
    memcpy(start, memory->bytes, MUSASHI_RAM_SIZE);
    musashi_native_lane_guard_stats(&g0);
    for (q = 0; q < N(PERIODS); ++q)
        for (p = 0; p < N(PHASES); ++p) {
            uint32_t fixed0;
            memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
            if (!run_once(memory, e, args, argc, 0, PHASES[p], PERIODS[q]) || g_run.overflow) continue;
            ref = g_run;
            memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
            fixed0 = musashi_lane_fixed;
            if (!run_once(memory, e, args, argc, 1, PHASES[p], PERIODS[q])) {
                fprintf(stderr, "guard: %s pattern %u phase %u period %u: native run failed\n", e->name,
                        pattern, PHASES[p], PERIODS[q]);
                return G_DIFFERENT;
            }
            if (musashi_lane_fixed != fixed0) return G_FIXED;
            if (g_run.identity_bad) {
                fprintf(stderr, "guard: %s: a checkpoint saw another CPU identity\n", e->name);
                return G_DIFFERENT;
            }
            if (g_run.n != ref.n || g_run.cycles != ref.cycles) {
                fprintf(stderr, "guard: %s pattern %u phase %u period %u: deliveries %u/%u total %llu/%llu\n",
                        e->name, pattern, PHASES[p], PERIODS[q], ref.n, g_run.n,
                        (unsigned long long)ref.cycles, (unsigned long long)g_run.cycles);
                return G_DIFFERENT;
            }
            for (i = 0; i < ref.n; ++i) {
                const Delivery *a = &ref.d[i], *b = &g_run.d[i];
                if (a->pc != b->pc || a->cycle != b->cycle || a->delay_slot != b->delay_slot ||
                    a->branch_pc != b->branch_pc || a->instruction != b->instruction) {
                    fprintf(stderr, "guard: %s pattern %u phase %u period %u delivery %u: interp %08x%s@%llu "
                            "native %08x%s@%llu\n", e->name, pattern, PHASES[p], PERIODS[q], i,
                            a->pc, a->delay_slot ? "(slot)" : "", (unsigned long long)a->cycle,
                            b->pc, b->delay_slot ? "(slot)" : "", (unsigned long long)b->cycle);
                    return G_DIFFERENT;
                }
            }
            ++compared;
        }
    musashi_native_lane_guard_stats(&g1);
    *ticks = g1.checkpoints - g0.checkpoints;
    free(start);
    return compared ? G_SAME : G_NOT_COMPARABLE;
}

int main(int argc, char **argv) {
    MusashiBootMemory *memory;
    uint8_t *image, *exe;
    FILE *file;
    size_t exe_size, i;
    unsigned counts[4] = {0}, functions[4] = {0}, gte_counts[4] = {0}, gte_functions[4] = {0};
    unsigned long long checkpoints = 0, gte_checkpoints = 0;
    const char *only = getenv("MUSASHI_LANE_PROBE_ONLY");
    int pipefd[2];
    if (argc != 2) { fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]); return 2; }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "guard: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, file) : 0;
    fclose(file);
    memory = musashi_native_lane_map_guest(sizeof(*memory), NULL);
    if (!memory) { fprintf(stderr, "guard: host window at 0x80000000 unavailable; NOT_RUN\n"); return 77; }
    if (!musashi_boot_map_exe(memory, exe, exe_size)) { fprintf(stderr, "guard: EXE rejected\n"); return 1; }
    if (musashi_native_lane_install(musashi_native_lane_generated, musashi_native_lane_generated_count) < 0 ||
        !musashi_native_lane_usable(memory)) {
        fprintf(stderr, "guard: lane not usable\n");
        return 1;
    }
    musashi_execution_clock_set_deadline(&g_clock, fake_deadline);
#ifdef MUSASHI_WITH_PSYCROSS
    g_gte_ok = musashi_cpu_status_open(&g_status, thread_token, NULL) &&
               musashi_gte_owner_init(&g_owner, g_status, thread_token, NULL, &g_identity);
    if (!g_gte_ok) fprintf(stderr, "guard: no gte owner; the N-GTE natives stay not comparable\n");
    /* N-GTE: the native leg's lane_gte_* helpers use the same owner. */
    musashi_native_lane_gte_bind(g_gte_ok ? &g_owner : NULL);
    g_leg = mmap(NULL, sizeof *g_leg, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (g_leg == MAP_FAILED) g_leg = NULL;
#endif
    image = malloc(MUSASHI_RAM_SIZE);
    if (!image) return 1;
    memcpy(image, memory->bytes, MUSASHI_RAM_SIZE);
    for (i = 0; i < musashi_native_lane_generated_count; ++i) {
        const MusashiNativeLaneEntry *e = &musashi_native_lane_generated[i];
        unsigned pattern, same = 0, diff = 0;
        const char *kinds = NULL;
        if (!e->ledger) continue;
        if (only && strtoul(only, NULL, 16) != e->guest_pc) continue;
#ifdef MUSASHI_WITH_PSYCROSS
        if (g_gte_ok) kinds = gte_kinds(e->guest_pc);
#endif
        for (pattern = 0; pattern < PATTERNS; ++pattern) {
            int status, outcome;
            uint64_t ticks = 0;
            pid_t child;
            if (pipe(pipefd)) return 1;
            fflush(stderr);
            child = fork();
            if (child == 0) {
                int r;
                close(pipefd[0]);
                signal(SIGSEGV, SIG_DFL);
                signal(SIGALRM, SIG_DFL);
#ifdef MUSASHI_WITH_PSYCROSS
                if (kinds) r = gte_guard_case(memory, image, e, kinds, pattern, &ticks);
                else
#endif
                    r = guard_case(memory, image, e, pattern, &ticks);
                if (write(pipefd[1], &ticks, sizeof ticks) != sizeof ticks) r = G_NOT_COMPARABLE;
                _exit(r);
            }
            close(pipefd[1]);
            if (child < 0) return 1;
            if (read(pipefd[0], &ticks, sizeof ticks) != sizeof ticks) ticks = 0;
            close(pipefd[0]);
            if (waitpid(child, &status, 0) != child) return 1;
            /* a native fault on these arguments is the RAM probe's business */
            outcome = WIFEXITED(status) && WEXITSTATUS(status) <= G_FIXED ? WEXITSTATUS(status)
                                                                          : G_NOT_COMPARABLE;
            counts[outcome]++;
            checkpoints += ticks;
            if (kinds) { gte_counts[outcome]++; gte_checkpoints += ticks; }
            if (outcome == G_SAME) same++;
            if (outcome == G_DIFFERENT) diff++;
        }
        functions[diff ? G_DIFFERENT : same ? G_SAME : G_NOT_COMPARABLE]++;
        if (kinds) gte_functions[diff ? G_DIFFERENT : same ? G_SAME : G_NOT_COMPARABLE]++;
    }
    printf("native_lane_guard: functions same=%u different=%u not_comparable=%u cases same=%u different=%u "
           "not_comparable=%u fixed_reached=%u mid_native_checkpoints=%llu\n",
           functions[G_SAME], functions[G_DIFFERENT], functions[G_NOT_COMPARABLE], counts[G_SAME],
           counts[G_DIFFERENT], counts[G_NOT_COMPARABLE], counts[G_FIXED], checkpoints);
    printf("native_lane_guard_gte: functions same=%u different=%u not_comparable=%u cases same=%u different=%u "
           "not_comparable=%u fixed_reached=%u mid_native_checkpoints=%llu\n",
           gte_functions[G_SAME], gte_functions[G_DIFFERENT], gte_functions[G_NOT_COMPARABLE], gte_counts[G_SAME],
           gte_counts[G_DIFFERENT], gte_counts[G_NOT_COMPARABLE], gte_counts[G_FIXED], gte_checkpoints);
    return functions[G_DIFFERENT] || !checkpoints ? 1 : 0;
}
