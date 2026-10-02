/* A host stop inside a GTE load delay is a stop, not a refusal.
 *
 * r32 smoke (fb8c): SIGTERM reached native_boot's checkpoint at 8004B6C0,
 * the delay successor of `cfc2 v0, $31` in libgte, while func_8001FB8C
 * (native) was running an interpreted handler through a guest call. The
 * checkpoint parks pc and npc at the sentinel; the run loop's GTE-load rule
 * then refused (RUN_REFUSED why=gte-load-pending, lane abort 4) before the
 * stop was seen. The same held on the interpreter alone.
 *
 * Here native-lane functions whose libgte callees run on a real GTE owner
 * (the escape family of native_lane_targeted_probe) run once with a
 * checkpoint that only counts the checkpoints at an MFC2/CFC2 delay
 * successor, then once per such checkpoint (up to STOPS_PER_CASE) with a
 * checkpoint that requests a host stop exactly there, as native_boot does.
 * Both legs, interpreter (lane off) and lane (native caller, interpreted
 * callee), must report the stop (reference call 2; lane abort 5), never a
 * refusal. A control stop at a checkpoint outside any load delay must
 * behave the same. Exit 0 = every stop reported as a stop and at least one
 * load-delay stop ran on each leg; 1 otherwise; 77 = EXE, host window or
 * GTE owner unavailable. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_native_lane.h"

#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#ifdef MUSASHI_WITH_PSYCROSS
#include "musashi_cpu_status.h"
#include "musashi_gte_owner.h"

extern const MusashiNativeLaneEntry musashi_native_lane_generated[];
extern const size_t musashi_native_lane_generated_count;

enum { STACK_TOP = 0x801fe000u, FILL_BASE = 0x80190000u, FILL_SIZE = 0x40000u,
       SEEDS = 24u, STOPS_PER_CASE = 6u };
/* kinds: p pointer into the scratch, i small integer, n index 0..3, l empty list or NULL */
static const struct { uint32_t pc; const char *kinds; } FN[] = {
    {0x8001282Cu, "p"}, {0x800128B4u, "p"}, {0x800128ECu, "pp"}, {0x80012E0Cu, "iiii"},
    {0x80014168u, "pp"}, {0x80016D78u, "pi"},
    {0x8001C1E4u, "pp"}, {0x8001C214u, "pl"},
    {0x8001C2C4u, "p"}, {0x8001C448u, "p"}, {0x8001C4A4u, "pl"}, {0x8001C558u, "p"},
    {0x8001C6E4u, "p"}, {0x8001C744u, "pi"}, {0x8001C7B0u, "p"}, {0x8001C810u, "pl"},
    {0x8001C8C4u, "p"}, {0x8001CA1Cu, "pi"}, {0x8001CA88u, "pi"}, {0x80028620u, "np"},
};
#define N(a) (sizeof(a) / sizeof((a)[0]))

static uint32_t rng_state = 1u;
static uint32_t rng(void) {
    rng_state ^= rng_state << 13; rng_state ^= rng_state >> 17; rng_state ^= rng_state << 5;
    return rng_state;
}
static uint64_t g_cycles;
static int cycle_advance(void *u, uint32_t c) { (void)u; g_cycles += c; return 1; }
static const MusashiExecutionClock g_clock = {NULL, cycle_advance};

static MusashiCpuStatus *g_status;
static MusashiGteOwner g_owner;
static const int g_identity;
static const uint32_t g_gpr[32];
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
static int gte_seed(uint32_t salt) {
    static const uint32_t data_sel[] = {0, 1, 9, 10, 11};
    MusashiCpuContext c = lease_ctx();
    uint32_t k;
    rng_state = salt | 1u;
    for (k = 0; k < N(data_sel); ++k)
        if (!musashi_gte_owner_write_data(&g_owner, &c, data_sel[k], rng())) return 0;
    for (k = 0; k <= 7u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, rng())) return 0;
    for (k = 13; k <= 30u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, rng())) return 0;
    return 1;
}

/* ---- the checkpoint ---------------------------------------------------- */
static MusashiBootMemory *g_mem;
static struct {
    long stop_at;             /* stop at this load-delay checkpoint (-1: never) */
    long stop_plain_at;       /* control: stop at this plain checkpoint (-1: never) */
    unsigned delay, plain;    /* checkpoints seen */
    int stopped, stop_pc_in_call;
} g_cp;

/* MFC2 (rs 0) or CFC2 (rs 2): the retail word before pc schedules a load
 * whose delay successor is pc, when pc itself is not a branch delay slot. */
static int after_cop2_load(const MusashiCpuContext *c) {
    uint32_t w;
    if (c->delay_slot || c->pc < 0x80000004u || c->pc >= 0x80200000u) return 0;
    if (!musashi_boot_read32(g_mem, c->pc - 4u, &w)) return 0;
    return (w >> 26) == 0x12u && (((w >> 21) & 31u) == 0u || ((w >> 21) & 31u) == 2u);
}

static int checkpoint(void *u, const void *continuation) {
    MusashiCpuContext c;
    uint32_t *raw = (uint32_t *)(uintptr_t)continuation;
    (void)u;
    if (g_cp.stopped || !musashi_boot_cpu_context(continuation, MUSASHI_CPU_CONTEXT_SOURCE, &c))
        return 1;
    if (after_cop2_load(&c)) {
        if ((long)g_cp.delay++ != g_cp.stop_at) return 1;
    } else {
        if ((long)g_cp.plain++ != g_cp.stop_plain_at) return 1;
    }
    /* native_boot's host stop: pc (word 34) and npc (word 35) at the sentinel */
    g_cp.stopped = 1;
    g_cp.stop_pc_in_call = c.pc;
    raw[34] = UINT_MAX;
    raw[35] = UINT_MAX;
    return 1;
}

static void fill(MusashiBootMemory *m, const uint8_t *image, unsigned k, unsigned seed,
                 uint32_t *args, unsigned *argc) {
    const char *kinds = FN[k].kinds;
    uint32_t a;
    unsigned i;
    memcpy(m->bytes, image, MUSASHI_RAM_SIZE);
    rng_state = (0x9e3779b9u * (seed + 1u)) ^ FN[k].pc;
    rng_state |= 1u;
    for (a = FILL_BASE; a < FILL_BASE + FILL_SIZE; a += 4u)
        musashi_boot_write32(m, a, FILL_BASE + ((rng() % (FILL_SIZE - 0x1000u)) & ~3u));
    for (i = 0; kinds[i]; ++i) {
        uint32_t base = FILL_BASE + 0x200u * ((seed * 7u + i * 3u) % 64u) + 0x40u * i;
        switch (kinds[i]) {
        case 'p': args[i] = base; break;
        case 'n': args[i] = rng() % 4u; break;
        case 'l': args[i] = seed % 4u == 3u ? 0u : base; musashi_boot_write32(m, base, 0u); break;
        default: args[i] = seed % 3u ? rng() % 8u : rng(); break;
        }
    }
    *argc = i;
}

/* One run; returns the reference call's 0/1/2. */
static int run(MusashiBootMemory *m, const uint8_t *image, unsigned k, unsigned seed, int lane,
               long stop_at, long stop_plain_at) {
    uint32_t args[4] = {0}, regs[32];
    unsigned argc = 0;
    int r;
    fill(m, image, k, seed, args, &argc);
    if (!gte_seed(0x85ebca6bu * (seed + 1u) ^ FN[k].pc)) return -1;
    memset(&g_cp, 0, sizeof g_cp);
    g_cp.stop_at = stop_at;
    g_cp.stop_plain_at = stop_plain_at;
    g_cycles = 0;
    alarm(5);
    r = musashi_native_lane_reference_call_device(m, FN[k].pc, args, argc, STACK_TOP, lane, regs,
                                                  &g_clock, checkpoint, NULL, &g_transfer);
    alarm(0);
    return r;
}

typedef struct {
    unsigned cases, delay_stops, delay_ok, plain_stops, plain_ok, bad;
} Tally;

/* Every (seed, leg) of function k, in this (forked) process. */
static void run_function(MusashiBootMemory *m, const uint8_t *image, unsigned k, Tally *t) {
    unsigned seed, j;
    int lane;
    for (lane = 0; lane < 2; ++lane)
        for (seed = 0; seed < SEEDS; ++seed) {
            unsigned delays, plains;
            if (run(m, image, k, seed, lane, -1, -1) != 1) continue;   /* refused/unusable: skip */
            delays = g_cp.delay;
            plains = g_cp.plain;
            t[lane].cases++;
            for (j = 0; j < delays && j < STOPS_PER_CASE; ++j) {
                int r = run(m, image, k, seed, lane, (long)j, -1);
                int last = musashi_native_lane_last_abort();
                t[lane].delay_stops++;
                if (r == 2 && g_cp.stopped) {
                    t[lane].delay_ok++;
                } else {
                    t[lane].bad++;
                    fprintf(stderr, "host_stop: %08x seed %u %s: stop in a load delay at %08x "
                            "(#%u) -> %d, lane abort %d\n", FN[k].pc, seed, lane ? "lane" : "interp",
                            (unsigned)g_cp.stop_pc_in_call, j, r, last);
                }
            }
            /* control: a stop at a plain checkpoint, mid-callee */
            if (plains > 2u) {
                int r = run(m, image, k, seed, lane, -1, (long)(plains / 2u));
                t[lane].plain_stops++;
                if (r == 2 && g_cp.stopped) t[lane].plain_ok++;
                else {
                    t[lane].bad++;
                    fprintf(stderr, "host_stop: %08x seed %u %s: plain stop -> %d\n",
                            FN[k].pc, seed, lane ? "lane" : "interp", r);
                }
            }
        }
}

int main(int argc, char **argv) {
    MusashiBootMemory *memory;
    uint8_t *image, *exe;
    FILE *file;
    size_t exe_size;
    unsigned k, lane, bad = 0;
    Tally *shared;
    if (argc != 2) { fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]); return 2; }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "host_stop: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, file) : 0;
    fclose(file);
    memory = musashi_native_lane_map_guest(sizeof(*memory), NULL);
    if (!memory) { fprintf(stderr, "host_stop: host window unavailable; NOT_RUN\n"); return 77; }
    if (!musashi_boot_map_exe(memory, exe, exe_size)) { fprintf(stderr, "host_stop: EXE rejected\n"); return 1; }
    if (musashi_native_lane_install(musashi_native_lane_generated, musashi_native_lane_generated_count) < 0 ||
        !musashi_native_lane_usable(memory)) {
        fprintf(stderr, "host_stop: lane not usable\n");
        return 1;
    }
    if (!musashi_cpu_status_open(&g_status, thread_token, NULL) ||
        !musashi_gte_owner_init(&g_owner, g_status, thread_token, NULL, &g_identity)) {
        fprintf(stderr, "host_stop: no gte owner; NOT_RUN\n");
        return 77;
    }
    g_mem = memory;
    image = malloc(MUSASHI_RAM_SIZE);
    shared = mmap(NULL, sizeof(Tally) * 2u * N(FN), PROT_READ | PROT_WRITE,
                  MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (!image || shared == MAP_FAILED) return 1;
    memcpy(image, memory->bytes, MUSASHI_RAM_SIZE);
    memset(shared, 0, sizeof(Tally) * 2u * N(FN));
    for (k = 0; k < N(FN); ++k) {
        pid_t pid;
        int status = 0;
        fflush(NULL);
        pid = fork();
        if (pid == 0) { run_function(memory, image, k, &shared[2u * k]); _exit(0); }
        if (pid < 0 || waitpid(pid, &status, 0) != pid || !WIFEXITED(status) || WEXITSTATUS(status)) {
            /* a native crash on seeded RAM is the other probes' business */
            fprintf(stderr, "host_stop: %08x child ended abnormally (status %d); its tally is partial\n",
                    FN[k].pc, status);
        }
    }
    for (lane = 0; lane < 2; ++lane) {
        Tally t = {0};
        for (k = 0; k < N(FN); ++k) {
            const Tally *s = &shared[2u * k + lane];
            t.cases += s->cases; t.delay_stops += s->delay_stops; t.delay_ok += s->delay_ok;
            t.plain_stops += s->plain_stops; t.plain_ok += s->plain_ok; t.bad += s->bad;
        }
        printf("host_stop: %s cases=%u load_delay_stops=%u ok=%u plain_stops=%u ok=%u bad=%u\n",
               lane ? "lane" : "interp", t.cases, t.delay_stops, t.delay_ok, t.plain_stops, t.plain_ok, t.bad);
        bad += t.bad;
        if (!t.delay_stops) { fprintf(stderr, "host_stop: no load-delay stop ran on this leg\n"); ++bad; }
    }
    return bad ? 1 : 0;
}

#else
int main(void) {
    fprintf(stderr, "host_stop: built without the GTE owner; NOT_RUN\n");
    return 77;
}
#endif
