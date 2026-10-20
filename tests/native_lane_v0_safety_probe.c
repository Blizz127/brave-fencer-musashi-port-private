/* The three r55 native voids whose retail v0 the lane did not leave, through
 * the REAL generated native lane (musashi_native_lane): the installed table, its
 * generated wrappers and the formatter's own lane_try / run_startup_cpu. This
 * file includes mips_formatter.c only to seed the guest CPU and reach those
 * static routes; no wrapper is written here.
 *
 * Retail contracts (src/main/8002d4c8.c, src/main/80031be0.c, the 80011C10 words):
 *   80031BE0  v0 = the paused byte (D_800A46E8+0x82F = 0x800A4F17) when nonzero,
 *             else the closing loop flag, 0 at exit; slot status words published.
 *   8002D4C8  v0 = the pending byte 0x800A4F18 when no work is pending (0);
 *             interpreted callers set v0 just before the jal (e.g. 1 / 0x308D).
 *   80011C10  v0 = the state base 0x800AF630;
 *             held out of the lane, so the interpreter must run it.
 * No reader of these values is known: the v3.2 audit's two candidates (main_0012
 * 80128AA8, 80148BB0) cannot reach them (r56 review packet, R55-IMPACT-REPORT-v2).
 * Routes: 1 lane_try (returns 1 only when the generated wrapper ran);
 *         1b run_startup_cpu -> formatter_call -> lane_try or the interpreter;
 *         D  differential: the same seeded state run once through the loop with the
 *            lane on and once with it suspended, so the interpreter executes the
 *            retail words (the original path); all 32 GPRs, hi/lo and the whole
 *            2 MiB RAM are compared. v0, the callee-saved registers, sp, fp, ra and
 *            every live byte must match; the other caller-saved registers and the
 *            dead stack below sp are reported, not required (the wrapper boundary).
 * Not exercised: 8002D4C8 with work pending (its callees 80030F80 and 8002D320
 * are interpreted SPU/voice code that needs device state the probe lacks).
 * Exit 0 = pass, 1 = fail, 77 = EXE or host window unavailable. */
#include "../pc_port/mips_formatter.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const MusashiNativeLaneEntry musashi_native_lane_generated[];
extern const size_t musashi_native_lane_generated_count;

enum {
    SP = 0x801FFF00u, RA = 0x80012340u, V1_SEED = 0x0BADF00Du,
    SLOTS = 0x800A46E8u, SLOT_SIZE = 0x54u, PAUSED = 0x800A4F17u, PENDING = 0x800A4F18u,
    COUNTDOWN = 0x800A4EFCu, STATUS_A = 0x800A2BB0u, STATUS_B = 0x800BA108u,
    STATE = 0x800AF630u
};
static MusashiBootMemory *g_mem;
static unsigned g_fail, g_checks;

#define CHECK(c, ...) do { ++g_checks; if (!(c)) { ++g_fail; fprintf(stderr, "v0_safety: FAIL " __VA_ARGS__); fputc('\n', stderr); } } while (0)

static uint8_t *at(uint32_t a) { return g_mem->bytes + (a - 0x80000000u); }
static uint16_t rd16(uint32_t a) { uint16_t v; memcpy(&v, at(a), 2); return v; }
static void wr16(uint32_t a, uint16_t v) { memcpy(at(a), &v, 2); }

static const MusashiNativeLaneEntry *entry(uint32_t pc) {
    size_t k;
    for (k = 0; k < musashi_native_lane_generated_count; ++k)
        if (musashi_native_lane_generated[k].guest_pc == pc) return &musashi_native_lane_generated[k];
    return NULL;
}

static void seed_cpu(FormatterCpu *cpu, MusashiCallbackDevice *dev, uint32_t pc, uint32_t a0, uint32_t a1,
                     uint32_t v0, uint32_t ra) {
    memset(cpu, 0, sizeof *cpu);
    memset(dev, 0, sizeof *dev);
    cpu->callback_device = dev;          /* as lane_reference_call: a device-less CPU */
    cpu->pc = pc;
    cpu->npc = pc + 4u;
    cpu->r[4] = a0;
    cpu->r[5] = a1;
    cpu->r[2] = v0;
    cpu->r[3] = V1_SEED;
    cpu->r[28] = 0x80074750u;
    cpu->r[29] = cpu->r[30] = SP;
    cpu->r[31] = ra;
}

/* Runs pc through both routes; `prep` restores the guest state before each. */
static void run_both(const char *what, uint32_t pc, uint32_t a0, uint32_t a1, uint32_t v0_seed, int lane_expected,
                     void (*prep)(void), uint32_t want_v0, int (*memory_ok)(void)) {
    FormatterCpu cpu;
    MusashiCallbackDevice dev;
    MusashiResetGraphPrefixStop stop;
    int32_t result = 0;
    int r;
    prep();
    seed_cpu(&cpu, &dev, pc, a0, a1, v0_seed, RA);
    r = lane_try(g_mem, &cpu);
    CHECK(r == lane_expected, "%s route1 lane_try=%d (want %d)", what, r, lane_expected);
    if (r == 1) {
        CHECK(cpu.r[2] == want_v0, "%s route1 v0=%08x want %08x (seed %08x)", what, cpu.r[2], want_v0, v0_seed);
        CHECK(cpu.pc == RA && cpu.npc == RA + 4u, "%s route1 pc=%08x", what, cpu.pc);
        CHECK(memory_ok(), "%s route1 memory", what);
    }
    prep();
    seed_cpu(&cpu, &dev, pc, a0, a1, v0_seed, UINT_MAX);
    memset(&stop, 0, sizeof stop);
    CHECK(run_startup_cpu(g_mem, &cpu, lane_reference_sink, NULL, &result, &stop, NULL, NULL, NULL) ==
              MUSASHI_RESETGRAPH_PREFIX_COMPLETE, "%s route1b status", what);
    CHECK(cpu.r[2] == want_v0, "%s route1b v0=%08x want %08x (seed %08x)", what, cpu.r[2], want_v0, v0_seed);
    CHECK(memory_ok(), "%s route1b memory", what);
}

/* 80031BE0 */
static uint8_t g_paused;
static void prep_slots(void) {
    unsigned i;
    memset(at(SLOTS), 0, 0x830u);
    for (i = 0; i < 8; ++i) {
        wr16(SLOTS + i * SLOT_SIZE + 4u, (uint16_t)(0x1100u + i));
        wr16(SLOTS + i * SLOT_SIZE + 6u, (uint16_t)(0x2200u + i));
        wr16(STATUS_A + i * 2u, 0xEEEEu);
        wr16(STATUS_B + i * 2u, 0xDDDDu);
    }
    wr16(SLOTS + 3u * SLOT_SIZE, 1u);    /* kind 1: its timer counts down */
    wr16(SLOTS + 3u * SLOT_SIZE + 8u, 3u);
    *at(PAUSED) = g_paused;
}
static int slots_published(void) {
    unsigned i;
    for (i = 0; i < 8; ++i)
        if (rd16(STATUS_A + i * 2u) != 0x1100u + i || rd16(STATUS_B + i * 2u) != 0x2200u + i) return 0;
    return rd16(SLOTS + 3u * SLOT_SIZE + 8u) == 2u && *at(PAUSED) == 0;
}
static int slots_untouched(void) {
    unsigned i;
    for (i = 0; i < 8; ++i)
        if (rd16(STATUS_A + i * 2u) != 0xEEEEu || rd16(STATUS_B + i * 2u) != 0xDDDDu) return 0;
    return rd16(SLOTS + 3u * SLOT_SIZE + 8u) == 3u && *at(PAUSED) == g_paused;
}

/* 8002D4C8 with a command in [0x80,0x100), which dispatches nothing */
static void prep_dispatch(void) { *at(PAUSED) = 0x77u; *at(PENDING) = 0; wr16(COUNTDOWN, 5u); }
static int dispatch_ok(void) { return *at(PAUSED) == 0 && *at(PENDING) == 0 && rd16(COUNTDOWN) == 5u; }

/* 80011C10 */
static void prep_state(void) {
    wr16(STATE + 0xA3C6u, 0x0041u);
    wr16(STATE + 0xA3C8u, 0x1111u); wr16(STATE + 0xA3CCu, 0x2222u);
    wr16(STATE + 0xA3CEu, 0x3333u); wr16(STATE + 0xA3D0u, 0x4444u);
}
static int state_ok(void) {
    return rd16(STATE + 0xA3C6u) == 0x0042u && rd16(STATE + 0xA3C8u) == 0 && rd16(STATE + 0xA3CCu) == 0 &&
           rd16(STATE + 0xA3CEu) == 0 && rd16(STATE + 0xA3D0u) == 0;
}

static const char *const kRegName[32] = {
    "zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
    "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"};
static uint8_t *g_snap0, *g_snapn;

/* Route D: native (lane on) vs original (lane suspended: the interpreter runs the retail words). */
static void differential(const char *what, uint32_t pc, uint32_t a0, uint32_t a1, uint32_t v0_seed, void (*prep)(void)) {
    FormatterCpu n, o;
    MusashiCallbackDevice dn, dd;
    MusashiResetGraphPrefixStop stop;
    int32_t result = 0;
    unsigned k, live = 0, dead = 0;
    uint32_t first_live = 0;
    int rn, ro;
    char regs[512];
    size_t used = 0;
    prep();
    memcpy(g_snap0, g_mem->bytes, MUSASHI_RAM_SIZE);
    seed_cpu(&n, &dn, pc, a0, a1, v0_seed, UINT_MAX);
    memset(&stop, 0, sizeof stop);
    rn = run_startup_cpu(g_mem, &n, lane_reference_sink, NULL, &result, &stop, NULL, NULL, NULL);
    memcpy(g_snapn, g_mem->bytes, MUSASHI_RAM_SIZE);
    memcpy(g_mem->bytes, g_snap0, MUSASHI_RAM_SIZE);
    seed_cpu(&o, &dd, pc, a0, a1, v0_seed, UINT_MAX);
    memset(&stop, 0, sizeof stop);
    musashi_native_lane_suspend(1);
    ro = run_startup_cpu(g_mem, &o, lane_reference_sink, NULL, &result, &stop, NULL, NULL, NULL);
    musashi_native_lane_suspend(0);
    CHECK(rn == MUSASHI_RESETGRAPH_PREFIX_COMPLETE && ro == MUSASHI_RESETGRAPH_PREFIX_COMPLETE,
          "%s D status native=%d original=%d", what, rn, ro);
    regs[0] = 0;
    for (k = 0; k < 32; ++k)
        if (n.r[k] != o.r[k] && used < sizeof regs - 48)
            used += (size_t)snprintf(regs + used, sizeof regs - used, " %s:%08x/%08x", kRegName[k], n.r[k], o.r[k]);
    if (n.hi != o.hi || n.lo != o.lo)
        used += (size_t)snprintf(regs + used, sizeof regs - used, " hi/lo:%08x.%08x/%08x.%08x", n.hi, n.lo, o.hi, o.lo);
    CHECK(n.r[2] == o.r[2], "%s D v0 native=%08x original=%08x (seed %08x)", what, n.r[2], o.r[2], v0_seed);
    for (k = 16; k < 24; ++k) CHECK(n.r[k] == o.r[k], "%s D callee-saved %s differs", what, kRegName[k]);
    for (k = 28; k < 32; ++k) CHECK(n.r[k] == o.r[k], "%s D %s differs", what, kRegName[k]);
    CHECK(n.pc == o.pc, "%s D pc native=%08x original=%08x", what, n.pc, o.pc);
    for (k = 0; k < MUSASHI_RAM_SIZE; ++k) {
        if (g_snapn[k] == g_mem->bytes[k]) continue;
        if (0x80000000u + k >= SP - 0x400u && 0x80000000u + k < SP) ++dead;
        else if (!live++) first_live = 0x80000000u + k;
    }
    CHECK(live == 0, "%s D %u live RAM byte(s) differ, first at %08x", what, live, first_live);
    printf("DIFF %-18s seed=%08x v0=%08x/%08x regs(native/original):%s%s dead_stack_bytes=%u live_bytes=%u\n",
           what, v0_seed, n.r[2], o.r[2], regs[0] ? regs : " ", "", dead, live);
}

int main(int argc, char **argv) {
    static const uint32_t seeds[3] = {0x5EB7C0DEu, 1u, 0u};
    const MusashiNativeLaneEntry *e31, *e2d, *e11;
    uint8_t *exe;
    size_t exe_size;
    unsigned s;
    FILE *file;
    if (argc != 2) { fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]); return 2; }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "v0_safety: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, file) : 0;
    fclose(file);
    g_mem = musashi_native_lane_map_guest(sizeof(*g_mem), NULL);
    if (!g_mem) { fprintf(stderr, "v0_safety: host window unavailable; NOT_RUN\n"); return 77; }
    if (!musashi_boot_map_exe(g_mem, exe, exe_size)) { fprintf(stderr, "v0_safety: EXE rejected\n"); return 1; }
    if (musashi_native_lane_install(musashi_native_lane_generated, musashi_native_lane_generated_count) < 0 ||
        !musashi_native_lane_usable(g_mem)) { fprintf(stderr, "v0_safety: lane not usable\n"); return 1; }
    e31 = entry(0x80031BE0u);
    e2d = entry(0x8002D4C8u);
    e11 = entry(0x80011C10u);
    CHECK(e31 && e31->returns == 1u, "80031BE0: installed entry %s, returns=%u (its wrapper cannot set v0)",
          e31 ? "present" : "missing", e31 ? (unsigned)e31->returns : 0u);
    CHECK(e2d && e2d->returns == 1u, "8002D4C8: installed entry %s, returns=%u (its wrapper cannot set v0)",
          e2d ? "present" : "missing", e2d ? (unsigned)e2d->returns : 0u);
    CHECK(e11 == NULL, "80011C10: still an installed lane entry (returns=%u); it must be held out",
          e11 ? (unsigned)e11->returns : 0u);
    for (s = 0; s < 3; ++s) {
        g_paused = 0x5Au;
        run_both("80031BE0 paused", 0x80031BE0u, 0, 0, seeds[s], e31 != NULL, prep_slots, 0x5Au, slots_untouched);
        g_paused = 0;
        if (seeds[s] != 0)   /* retail's 0 is indistinguishable from a 0 seed */
            run_both("80031BE0 running", 0x80031BE0u, 0, 0, seeds[s], e31 != NULL, prep_slots, 0u, slots_published);
        if (seeds[s] != 0)
            run_both("8002D4C8 idle", 0x8002D4C8u, 0x90u, 0x1234u, seeds[s], e2d != NULL, prep_dispatch, 0u, dispatch_ok);
        run_both("80011C10", 0x80011C10u, 0, 0, seeds[s], e11 != NULL, prep_state, STATE, state_ok);
    }
    g_snap0 = malloc(MUSASHI_RAM_SIZE);
    g_snapn = malloc(MUSASHI_RAM_SIZE);
    if (!g_snap0 || !g_snapn) { fprintf(stderr, "v0_safety: no memory for RAM snapshots\n"); return 1; }
    for (s = 0; s < 3; ++s) {
        g_paused = 0x5Au;
        differential("80031BE0 paused", 0x80031BE0u, 0, 0, seeds[s], prep_slots);
        g_paused = 0;
        differential("80031BE0 running", 0x80031BE0u, 0, 0, seeds[s], prep_slots);
        differential("8002D4C8 idle", 0x8002D4C8u, 0x90u, 0x1234u, seeds[s], prep_dispatch);
        differential("80011C10", 0x80011C10u, 0, 0, seeds[s], prep_state);
    }
    if (g_fail) { fprintf(stderr, "v0_safety: %u of %u check(s) failed\n", g_fail, g_checks); return 1; }
    printf("NATIVE_LANE_V0_SAFETY_PASS checks=%u seeds=3 routes=lane_try,loop,differential (80031BE0 returns=%u, 8002D4C8 returns=%u, 80011C10 interpreted)\n",
           g_checks, (unsigned)e31->returns, (unsigned)e2d->returns);
    return 0;
}
