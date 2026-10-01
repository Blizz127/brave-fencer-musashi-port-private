/* Same-input differential of the native VSync path (bfm_psyq_VSync, retail
 * func_8004239C, libetc) against the retail code run on the interpreter as a
 * test-only oracle from the developer's own EXE (extracted/disc/files/
 * SLUS_007.26; no retail bytes are compiled in or committed).
 *
 * Only VSync(mode < 0) is native. For those modes the legs are:
 *   interp   musashi_native_lane_reference_call_regs with the lane suspended:
 *            every retail word of 8004239C runs; the oracle
 *   lane     the same CPU with the lane installed (MUSASHI_NATIVE_LANE
 *            builds), so 8004239C enters the wrapper (device_sync, then the
 *            HLE) through lane_try
 *   direct   the lane table entry's function (wrapper) called on an o32
 *            register file; without the lane, bfm_psyq_VSync itself
 * Every case starts from the pinned EXE image plus a pseudo-random arena and
 * the same VSync globals (8006BA94/98 aimed at RAM words so the retail GPUSTAT
 * and Timer1 loads need no device, 8006BA9C latch, 8006CBB8 tick). All legs
 * must agree on completion, the whole general register file after the call
 * and every byte of guest RAM and scratchpad (this includes the three dead
 * stack slots the retail prologue fills below sp).
 *
 * Lazy-epoch cases model the device epoch with a deferred vblank pending: the
 * retail routine's first device read (GPUSTAT) triggers the commit, so the
 * oracle applies the commit (the 80042CE8 tick increment) before the tick
 * load; the native path must see the same tick because device_sync commits
 * first. The sync hook counts calls: exactly one per native call, none when a
 * wrapper refuses a mode (the lane must not count).
 *
 * Refusals (modes 0, 1, 2, 16, 0x7FFFFFFF, a failing device_sync, an
 * unaligned or unmapped sp) must return 0 with every register and all RAM
 * byte-identical; the lane then interprets the retail words (mode 1, the one
 * non-waiting refused mode, is also run through the lane against the oracle).
 *
 * Exit 0 when everything agrees; 1 on any difference; 77 when the EXE or the
 * host window at 0x80000000 is unavailable. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_native_lane.h"
#include "psyq/bfm_psyq_compat.h"
#ifdef PSYQ_PROBE_WITH_LANE
#include "musashi_native_lane_psyq.h"
#endif

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#ifndef MAP_FIXED_NOREPLACE
#define MAP_FIXED_NOREPLACE 0x100000
#endif

enum { VSYNC_PC = 0x8004239Cu, GPUSTAT_PTR = 0x8006BA94u, HCOUNT_PTR = 0x8006BA98u,
       LATCH = 0x8006BA9Cu, LAST_TICK = 0x8006BAA0u, TICK = 0x8006CBB8u };
enum { ARENA = 0x80180000u, ARENA_END = 0x801F0000u, GP = 0x80074750u };
enum { LEG_INTERP, LEG_LANE, LEG_DIRECT, LEGS };

typedef struct Case {
    const char *name;
    uint32_t mode, sp, tick, latch, gpustat, hcount;
    int pending;      /* a deferred vblank the device sync commits (tick + 1) */
    int sync_fails;   /* device_sync refuses */
} Case;

typedef struct Leg {
    int ok;
    uint32_t regs[32];
    uint64_t hash;
    unsigned syncs;
} Leg;

static MusashiBootMemory *g_mem;
static uint8_t *g_image, *g_final_ram[LEGS];
static uint8_t g_final_scratch[LEGS][MUSASHI_SCRATCHPAD_SIZE];
static unsigned g_cases, g_bad, g_native, g_refusals;
static int g_have_lane;
static uint32_t rng_state;

/* device-epoch model driven by the current case */
static int g_pending, g_sync_fails;
static unsigned g_syncs;

static uint32_t rng(void) {
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 17;
    rng_state ^= rng_state << 5;
    return rng_state;
}

static uint64_t hash_state(void) {
    uint64_t h = 1469598103934665603ull;
    size_t i;
    for (i = 0; i < MUSASHI_RAM_SIZE; ++i) h = (h ^ g_mem->bytes[i]) * 1099511628211ull;
    for (i = 0; i < MUSASHI_SCRATCHPAD_SIZE; ++i) h = (h ^ g_mem->scratchpad[i]) * 1099511628211ull;
    return h;
}

static void put32(uint32_t a, uint32_t v) {
    uint8_t *p = g_mem->bytes + (a & 0x1FFFFFFFu);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t get32(uint32_t a) {
    const uint8_t *p = g_mem->bytes + (a & 0x1FFFFFFFu);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static void seed(const Case *c, uint32_t salt) {
    uint32_t a;
    unsigned i;
    memcpy(g_mem->bytes, g_image, MUSASHI_RAM_SIZE);
    rng_state = salt | 1u;
    for (a = ARENA; a < ARENA_END; a += 4u) put32(a, rng());
    for (i = 0; i < MUSASHI_SCRATCHPAD_SIZE; ++i) g_mem->scratchpad[i] = (uint8_t)rng();
    /* the retail GPUSTAT / Timer1 loads read two RAM words instead of devices */
    put32(0x801F0000u, c->gpustat);
    put32(0x801F0004u, c->hcount);
    put32(GPUSTAT_PTR, 0x801F0000u);
    put32(HCOUNT_PTR, 0x801F0004u);
    put32(LATCH, c->latch);
    put32(LAST_TICK, rng());
    put32(TICK, c->tick);
}

/* the epoch hook of the native legs: commits the deferred vblank */
static int sync_hook(void *user) {
    (void)user;
    g_syncs++;
    if (g_sync_fails) return 0;
    if (g_pending) {
        put32(TICK, get32(TICK) + 1u);
        g_pending = 0;
    }
    return 1;
}

#ifdef PSYQ_PROBE_WITH_LANE
static MusashiNativeLaneEntry g_entry;
#endif

/* The wrapper (device_sync, then HLE) on a register file; without the lane
 * bfm_psyq_VSync directly. 1 = the native path completed. */
static int call_native(uint32_t *r) {
#ifdef PSYQ_PROBE_WITH_LANE
    MusashiNativeLaneCall call = {g_mem, r};
    return g_entry.fn(&call);
#else
    return sync_hook(NULL) && bfm_psyq_VSync(r);   /* the wrapper's order */
#endif
}

static int run_leg(const Case *c, uint32_t salt, int leg, Leg *out) {
    uint32_t args[1];
    seed(c, salt);
    g_pending = c->pending && leg != LEG_INTERP;
    g_sync_fails = c->sync_fails;
    g_syncs = 0;
    args[0] = c->mode;
    if (leg == LEG_INTERP) {
        /* retail: GPUSTAT is the first device read; it commits the epoch */
        if (c->pending) put32(TICK, get32(TICK) + 1u);
        out->ok = musashi_native_lane_reference_call_regs(g_mem, VSYNC_PC, args, 1, c->sp, 0, out->regs);
    } else if (leg == LEG_LANE) {
        out->ok = musashi_native_lane_reference_call_regs(g_mem, VSYNC_PC, args, 1, c->sp, 1, out->regs);
    } else {
        uint32_t r[32];
        memset(r, 0, sizeof r);
        r[4] = c->mode;
        r[28] = GP;
        r[29] = r[30] = c->sp;
        r[31] = UINT_MAX;
        if (call_native(r)) {
            out->ok = 1;
            g_native++;
        } else {
            /* refused: the lane would interpret the retail words */
            out->ok = musashi_native_lane_reference_call_regs(g_mem, VSYNC_PC, args, 1, c->sp, 0, r);
        }
        memcpy(out->regs, r, sizeof r);
    }
    out->syncs = g_syncs;
    out->hash = hash_state();
    memcpy(g_final_ram[leg], g_mem->bytes, MUSASHI_RAM_SIZE);
    memcpy(g_final_scratch[leg], g_mem->scratchpad, MUSASHI_SCRATCHPAD_SIZE);
    return 1;
}

static const char *kLegName[LEGS] = {"interp", "lane", "direct"};

static int compare(const Case *c, const Leg *ref, const Leg *got, int leg) {
    unsigned i, shown = 0;
    if (got->ok != ref->ok) {
        fprintf(stderr, "vsync: %s: %s completed=%d interp=%d\n", c->name, kLegName[leg], got->ok, ref->ok);
        return 0;
    }
    for (i = 1; i < 32; ++i)
        if (got->regs[i] != ref->regs[i]) {
            fprintf(stderr, "vsync: %s mode=%08x: %s r%u=%08x interp=%08x\n", c->name, c->mode,
                    kLegName[leg], i, got->regs[i], ref->regs[i]);
            shown++;
        }
    for (i = 0; i < MUSASHI_RAM_SIZE; ++i)
        if (g_final_ram[leg][i] != g_final_ram[LEG_INTERP][i] && shown++ < 12)
            fprintf(stderr, "vsync: %s: %s RAM %08x=%02x interp=%02x\n", c->name, kLegName[leg],
                    0x80000000u + i, g_final_ram[leg][i], g_final_ram[LEG_INTERP][i]);
    for (i = 0; i < MUSASHI_SCRATCHPAD_SIZE; ++i)
        if (g_final_scratch[leg][i] != g_final_scratch[LEG_INTERP][i] && shown++ < 12)
            fprintf(stderr, "vsync: %s: %s scratchpad %03x differs\n", c->name, kLegName[leg], i);
    return !shown && got->hash == ref->hash;
}

/* A native-completed case: all legs agree with the retail oracle. */
static void run_case(const Case *c) {
    static Leg legs[LEGS];
    const uint32_t salt = 0x9E3779B9u * (g_cases + 1u);
    int leg, good = 1;
    g_cases++;
    for (leg = 0; leg < LEGS; ++leg) {
        if (leg == LEG_LANE && !g_have_lane) continue;
        if (!run_leg(c, salt, leg, &legs[leg])) good = 0;
    }
    if (!legs[LEG_INTERP].ok) {
        fprintf(stderr, "vsync: %s: retail oracle did not complete\n", c->name);
        good = 0;
    }
    for (leg = 1; good && leg < LEGS; ++leg) {
        if (leg == LEG_LANE && !g_have_lane) continue;
        if (!compare(c, &legs[LEG_INTERP], &legs[leg], leg)) good = 0;
    }
#ifdef PSYQ_PROBE_WITH_LANE
    /* sync discipline: once per native call, so the deferred epoch commits */
    if (good && g_have_lane && (int32_t)c->mode < 0 && !c->sync_fails) {
        if (legs[LEG_LANE].syncs != 1u || legs[LEG_DIRECT].syncs != 1u) {
            fprintf(stderr, "vsync: %s: device_sync calls lane=%u direct=%u (want 1)\n", c->name,
                    legs[LEG_LANE].syncs, legs[LEG_DIRECT].syncs);
            good = 0;
        }
    }
#endif
    if (!good) g_bad++;
    if (getenv("VSYNC_PROBE_VERBOSE") || !good)
        printf("vsync: %-26s mode=%08x v0=%08x v1=%08x -> %s\n", c->name, c->mode,
               legs[LEG_INTERP].regs[2], legs[LEG_INTERP].regs[3], good ? "same" : "DIFFERENT");
}

/* A refused case: direct native call returns 0 and changes nothing. */
static void run_refusal(const Case *c) {
    uint32_t r[32], saved[32], k;
    uint8_t *ram = malloc(MUSASHI_RAM_SIZE);
    uint8_t scratch[MUSASHI_SCRATCHPAD_SIZE];
    int bad = 0;
    g_cases++;
    g_refusals++;
    seed(c, 0xABCD1234u ^ g_cases);
    g_pending = c->pending;
    g_sync_fails = c->sync_fails;
    g_syncs = 0;
    for (k = 1; k < 32; ++k) r[k] = rng();
    r[0] = 0;
    r[4] = c->mode;
    r[29] = c->sp;
    memcpy(saved, r, sizeof r);
    /* a pending commit changes the tick only through the sync, which is not
     * a refusal's guest effect; snapshot after it has been taken */
    if (c->sync_fails || !c->pending) {
        memcpy(ram, g_mem->bytes, MUSASHI_RAM_SIZE);
        memcpy(scratch, g_mem->scratchpad, sizeof scratch);
    }
    if (call_native(r)) {
        fprintf(stderr, "vsync: refusal %s mode=%08x sp=%08x: the native path completed\n", c->name, c->mode, c->sp);
        bad = 1;
    }
    if (memcmp(saved, r, sizeof r)) {
        fprintf(stderr, "vsync: refusal %s: registers changed\n", c->name);
        bad = 1;
    }
    if ((c->sync_fails || !c->pending) &&
        (memcmp(ram, g_mem->bytes, MUSASHI_RAM_SIZE) || memcmp(scratch, g_mem->scratchpad, sizeof scratch))) {
        fprintf(stderr, "vsync: refusal %s: guest RAM changed\n", c->name);
        bad = 1;
    }
    free(ram);
    if (!bad) { if (getenv("VSYNC_PROBE_VERBOSE")) printf("vsync: refusal %-22s mode=%08x -> refused cleanly\n", c->name, c->mode); }
    g_bad += bad;
}

static Case mk(const char *name, uint32_t mode, uint32_t sp, uint32_t tick) {
    Case c;
    memset(&c, 0, sizeof c);
    c.name = name; c.mode = mode; c.sp = sp; c.tick = tick;
    c.latch = rng(); c.gpustat = rng(); c.hcount = rng();
    return c;
}

#ifdef PSYQ_PROBE_WITH_LANE
/* class selector and table membership */
static int check_classes(void) {
    static const struct { const char *env; unsigned classes; int in_table; } k[] = {
        {NULL, MUSASHI_PSYQ_LANE_PURE | MUSASHI_PSYQ_LANE_VSYNC | MUSASHI_PSYQ_LANE_PAD, 1},
        {"pure", MUSASHI_PSYQ_LANE_PURE, 0},
        {"pure+vsync", MUSASHI_PSYQ_LANE_PURE | MUSASHI_PSYQ_LANE_VSYNC, 1},
        {"pure+vsync+pad", MUSASHI_PSYQ_LANE_PURE | MUSASHI_PSYQ_LANE_VSYNC | MUSASHI_PSYQ_LANE_PAD, 1},
        {"all", MUSASHI_PSYQ_LANE_PURE | MUSASHI_PSYQ_LANE_VSYNC | MUSASHI_PSYQ_LANE_PAD |
                MUSASHI_PSYQ_LANE_DEVICE, 1},
        {"0", 0u, 0},
    };
    unsigned i;
    int bad = 0;
    for (i = 0; i < sizeof k / sizeof k[0]; ++i) {
        size_t count = 0, j;
        int found = 0;
        MusashiNativeLaneEntry *table;
        if (k[i].env) setenv("MUSASHI_PSYQ_LANE", k[i].env, 1); else unsetenv("MUSASHI_PSYQ_LANE");
        if (musashi_native_lane_psyq_classes() != k[i].classes) {
            fprintf(stderr, "vsync: MUSASHI_PSYQ_LANE=%s classes=%u want %u\n", k[i].env ? k[i].env : "(unset)",
                    musashi_native_lane_psyq_classes(), k[i].classes);
            bad = 1;
        }
        table = musashi_native_lane_psyq_merge(NULL, 0, musashi_native_lane_psyq_classes(), &count);
        for (j = 0; table && j < count; ++j) found |= table[j].guest_pc == VSYNC_PC;
        if (found != k[i].in_table) {
            fprintf(stderr, "vsync: MUSASHI_PSYQ_LANE=%s VSync in table=%d want %d\n", k[i].env ? k[i].env : "(unset)",
                    found, k[i].in_table);
            bad = 1;
        }
    }
    unsetenv("MUSASHI_PSYQ_LANE");
    return !bad;
}
#endif

int main(int argc, char **argv) {
    FILE *file;
    uint8_t *exe;
    size_t exe_size;
    int leg;
    unsigned n, i;
    const char *fuzz = getenv("VSYNC_PROBE_FUZZ");
    static const uint32_t sps[] = {0x801FE000u, 0x801FFF80u, 0x80100000u, 0x80000040u, 0x801FFFF8u,
                                   0xA01FE000u, 0x001FE000u};
    char nm[48];
    Case c;
    if (argc != 2) { fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]); return 2; }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "vsync: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, file) : 0;
    fclose(file);
#ifdef PSYQ_PROBE_WITH_LANE
    g_mem = musashi_native_lane_map_guest(sizeof(*g_mem), NULL);
#else
    g_mem = mmap((void *)(uintptr_t)MUSASHI_NATIVE_LANE_GUEST_BASE, sizeof(*g_mem),
                 PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE, -1, 0);
    if (g_mem == MAP_FAILED || (uintptr_t)g_mem != MUSASHI_NATIVE_LANE_GUEST_BASE) g_mem = NULL;
#endif
    if (!g_mem) { fprintf(stderr, "vsync: host window at 0x80000000 unavailable; NOT_RUN\n"); return 77; }
    if (!musashi_boot_map_exe(g_mem, exe, exe_size)) { fprintf(stderr, "vsync: pinned EXE rejected\n"); return 1; }
    bfm_psyq_set_ram(g_mem->bytes, MUSASHI_RAM_SIZE);
    bfm_psyq_set_scratchpad(g_mem->scratchpad);
#ifdef PSYQ_PROBE_WITH_LANE
    {
        size_t count = 0, j;
        MusashiNativeLaneEntry *table;
        if (!check_classes()) return 1;
        table = musashi_native_lane_psyq_merge(NULL, 0, MUSASHI_PSYQ_LANE_PURE | MUSASHI_PSYQ_LANE_VSYNC, &count);
        for (j = 0; table && j < count; ++j)
            if (table[j].guest_pc == VSYNC_PC) { g_entry = table[j]; g_have_lane = 1; }
        if (!g_have_lane) { fprintf(stderr, "vsync: VSync is not a pure+vsync lane entry\n"); return 1; }
        if (g_entry.cost_cycles != 64u || g_entry.argc != 1u || !g_entry.returns) {
            fprintf(stderr, "vsync: lane entry cost=%u argc=%u returns=%u\n", g_entry.cost_cycles, g_entry.argc, g_entry.returns);
            return 1;
        }
        musashi_native_lane_psyq_bind(g_mem, NULL);
        musashi_native_lane_psyq_set_device_sync(sync_hook, NULL);
        if (musashi_native_lane_install(table, count) < 0 || !musashi_native_lane_usable(g_mem)) {
            fprintf(stderr, "vsync: lane not usable\n");
            return 1;
        }
    }
#endif
    g_image = malloc(MUSASHI_RAM_SIZE);
    for (leg = 0; leg < LEGS; ++leg) g_final_ram[leg] = malloc(MUSASHI_RAM_SIZE);
    if (!g_image || !g_final_ram[0] || !g_final_ram[1] || !g_final_ram[2]) return 1;
    memcpy(g_image, g_mem->bytes, MUSASHI_RAM_SIZE);
    rng_state = 0x5EED5EEDu;

    /* native modes: -1 (the route's call), -2, the smallest negative */
    for (i = 0; i < sizeof sps / sizeof sps[0]; ++i) {
        snprintf(nm, sizeof nm, "minus_one_sp%u", i);
        c = mk(nm, 0xFFFFFFFFu, sps[i], 0x1234u + i);
        run_case(&c);
    }
    c = mk("minus_two", 0xFFFFFFFEu, sps[0], 77u); run_case(&c);
    c = mk("int_min", 0x80000000u, sps[0], 78u); run_case(&c);
    c = mk("int_min_plus_1", 0x80000001u, sps[0], 79u); run_case(&c);
    c = mk("tick_zero", 0xFFFFFFFFu, sps[0], 0u); run_case(&c);
    c = mk("tick_max", 0xFFFFFFFFu, sps[0], 0xFFFFFFFFu); run_case(&c);
    c = mk("latch_zero", 0xFFFFFFFFu, sps[0], 5u); c.latch = 0; run_case(&c);
    /* lazy epoch: a deferred vblank the sync commits before the tick read */
    c = mk("pending_commit", 0xFFFFFFFFu, sps[0], 100u); c.pending = 1; run_case(&c);
    c = mk("pending_commit_wrap", 0xFFFFFFFFu, sps[1], 0xFFFFFFFFu); c.pending = 1; run_case(&c);
    c = mk("pending_minus_two", 0xFFFFFFFEu, sps[2], 41u); c.pending = 1; run_case(&c);
    for (n = fuzz ? (unsigned)strtoul(fuzz, NULL, 0) : 200u, i = 0; i < n; ++i) {
        uint32_t mode = 0x80000000u | rng();
        if (i % 5 == 0) mode = 0xFFFFFFFFu - (rng() & 7u);
        c = mk("random", mode, (0x80000040u + (rng() % 0x1FFF00u)) & ~7u, rng());
        c.pending = (int)(rng() & 1u);
        if (i % 9 == 0) c.sp = sps[rng() % (sizeof sps / sizeof sps[0])];
        run_case(&c);
    }
    /* mode 1 does not wait: the lane refuses and the interpreter completes it
     * with the retail result; all legs equal (the wrapper changed nothing) */
    c = mk("mode1_refused_interpreted", 1u, sps[0], 9u);
#ifdef PSYQ_PROBE_WITH_LANE
    run_case(&c);
#endif

    /* refusals: every register and all RAM untouched */
    {
        static const uint32_t modes[] = {0u, 1u, 2u, 16u, 0x7FFFFFFFu, 3u, 1000u};
        for (i = 0; i < sizeof modes / sizeof modes[0]; ++i) {
            snprintf(nm, sizeof nm, "mode_%u", modes[i]);
            c = mk(nm, modes[i], sps[0], 50u + i);
            run_refusal(&c);
            c.pending = 1;
            run_refusal(&c);
        }
        c = mk("sync_fails", 0xFFFFFFFFu, sps[0], 60u); c.sync_fails = 1; run_refusal(&c);
        c = mk("sync_fails_pending", 0xFFFFFFFFu, sps[0], 61u); c.sync_fails = 1; c.pending = 1; run_refusal(&c);
        c = mk("sp_unaligned", 0xFFFFFFFFu, 0x801FE002u, 62u); run_refusal(&c);
        c = mk("sp_low", 0xFFFFFFFFu, 0x80000008u, 63u); run_refusal(&c);
        c = mk("sp_unmapped", 0xFFFFFFFFu, 0x90000000u, 64u); run_refusal(&c);
    }

    printf("vsync: legs=%s cases=%u native_completions=%u refusals=%u different=%u -> %s\n",
           g_have_lane ? "interp,lane,direct" : "interp,direct", g_cases, g_native, g_refusals, g_bad,
           g_bad ? "DIFFERS" : "same");
    return g_bad ? 1 : 0;
}
