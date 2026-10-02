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
 * window or the EXE is missing. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_cpu_status.h"
#include "musashi_native_lane.h"

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
    unsigned counts[4] = {0}, functions[4] = {0};
    unsigned long long checkpoints = 0;
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
    image = malloc(MUSASHI_RAM_SIZE);
    if (!image) return 1;
    memcpy(image, memory->bytes, MUSASHI_RAM_SIZE);
    for (i = 0; i < musashi_native_lane_generated_count; ++i) {
        const MusashiNativeLaneEntry *e = &musashi_native_lane_generated[i];
        unsigned pattern, same = 0, diff = 0;
        if (!e->ledger) continue;
        if (only && strtoul(only, NULL, 16) != e->guest_pc) continue;
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
            if (outcome == G_SAME) same++;
            if (outcome == G_DIFFERENT) diff++;
        }
        functions[diff ? G_DIFFERENT : same ? G_SAME : G_NOT_COMPARABLE]++;
    }
    printf("native_lane_guard: functions same=%u different=%u not_comparable=%u cases same=%u different=%u "
           "not_comparable=%u fixed_reached=%u mid_native_checkpoints=%llu\n",
           functions[G_SAME], functions[G_DIFFERENT], functions[G_NOT_COMPARABLE], counts[G_SAME],
           counts[G_DIFFERENT], counts[G_NOT_COMPARABLE], counts[G_FIXED], checkpoints);
    return functions[G_DIFFERENT] || !checkpoints ? 1 : 0;
}
