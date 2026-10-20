/* func_80016714 (STARTUP_ENVIRONMENT_CLEAR, a zeroing memset) through the
 * REAL generated native lane, linked from musashi_native_lane: the installed
 * table's entry, its generated wrap_80016714 and lane_func_80016714, and the
 * generated caller stubs. This file includes mips_formatter.c only to seed
 * the guest CPU (v0 = 0 and a nonzero sentinel) and to call the formatter's
 * own static lane_try / run_startup_cpu. No wrapper is written here.
 *
 * Retail contract (src/main/80016714.c): v0 = 0xFFFFFFFF for every count >= 0;
 * main_0012 80140420 branches on it (`bnez v0`). Routes checked per case:
 *   1  lane_try directly (returns 1 only when the generated wrapper ran);
 *   1b run_startup_cpu -> formatter_call -> lane_try (the startup/guest-call loop);
 *   3  the same loop with the lane suspended (the host intrinsic);
 *   2  the generated direct-call function (value and memory) and both
 *      generated caller stubs (value ignored, memory cleared).
 * v1 is a KNOWN GAP: retail leaves -1 there when count >= 4; no route
 * restores it, and the probe pins the seed. Exit 0 = pass, 1 = fail,
 * 77 = EXE or host window unavailable. */
#include "../pc_port/mips_formatter.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const MusashiNativeLaneEntry musashi_native_lane_generated[];
extern const size_t musashi_native_lane_generated_count;
/* The generated direct-call function: uint32_t after the repair (void before;
 * the probe calls it only when the installed entry declares a return value). */
extern uint32_t lane_func_80016714(void *, uint32_t);
/* The generated caller-side stubs (callers' own void prototypes). */
extern void lane_call_func_80016714__rvoid_ptr_i32(void *, uint32_t);
extern void lane_call_func_80016714__va2_void(uint32_t, uint32_t);

enum { V1_SEED = 0x0BADF00Du, FILL = 0xA5u, SP = 0x801FFF00u, RA = 0x80012340u };
static MusashiBootMemory *g_mem;
static unsigned g_fail;

#define CHECK(c, ...) do { if (!(c)) { ++g_fail; fprintf(stderr, "env_clear: FAIL " __VA_ARGS__); fputc('\n', stderr); } } while (0)

static void fill(void) { memset(g_mem->bytes + 0x0FFF00u, FILL, 0x80100u); memset(g_mem->bytes + 0x747C0u - 0x40u, FILL, 0x80u); }

static int cleared_ok(uint32_t dst, uint32_t count) {
    uint32_t off = dst - 0x80000000u, i;
    for (i = 0; i < count; ++i) if (g_mem->bytes[off + i] != 0) return 0;
    return g_mem->bytes[off - 1u] == FILL && g_mem->bytes[off + count] == FILL;
}

static void seed_cpu(FormatterCpu *cpu, MusashiCallbackDevice *dev, uint32_t dst, uint32_t count, uint32_t v0, uint32_t ra) {
    memset(cpu, 0, sizeof *cpu);
    memset(dev, 0, sizeof *dev);
    cpu->callback_device = dev;          /* as lane_reference_call: a device-less CPU */
    cpu->pc = STARTUP_ENVIRONMENT_CLEAR;
    cpu->npc = STARTUP_ENVIRONMENT_CLEAR + 4u;
    cpu->r[4] = dst;
    cpu->r[5] = count;
    cpu->r[2] = v0;
    cpu->r[3] = V1_SEED;
    cpu->r[28] = 0x80074750u;
    cpu->r[29] = cpu->r[30] = SP;
    cpu->r[31] = ra;
}

static void one_case(uint32_t dst, uint32_t count, uint32_t v0, int returns) {
    FormatterCpu cpu;
    MusashiCallbackDevice dev;
    MusashiResetGraphPrefixStop stop;
    int32_t result = 0;
    int r;
    /* route 1: the generated wrapper through lane_try */
    fill();
    seed_cpu(&cpu, &dev, dst, count, v0, RA);
    r = lane_try(g_mem, &cpu);
    CHECK(r == 1, "route1 lane_try=%d dst=%08x n=%u", r, dst, count);
    CHECK(cpu.r[2] == 0xFFFFFFFFu, "route1 v0=%08x (seed %08x) dst=%08x n=%u", cpu.r[2], v0, dst, count);
    CHECK(cpu.r[3] == V1_SEED, "route1 v1=%08x (known gap pinned)", cpu.r[3]);
    CHECK(cpu.pc == RA && cpu.npc == RA + 4u, "route1 pc=%08x", cpu.pc);
    CHECK(cleared_ok(dst, count), "route1 memory dst=%08x n=%u", dst, count);
    /* route 1b: the startup/guest-call loop, lane on */
    fill();
    seed_cpu(&cpu, &dev, dst, count, v0, UINT_MAX);
    memset(&stop, 0, sizeof stop);
    CHECK(run_startup_cpu(g_mem, &cpu, lane_reference_sink, NULL, &result, &stop, NULL, NULL, NULL) ==
              MUSASHI_RESETGRAPH_PREFIX_COMPLETE, "route1b status dst=%08x n=%u", dst, count);
    CHECK(cpu.r[2] == 0xFFFFFFFFu, "route1b v0=%08x (seed %08x)", cpu.r[2], v0);
    CHECK(cleared_ok(dst, count), "route1b memory dst=%08x n=%u", dst, count);
    /* route 3: the same loop with the lane suspended -> the host intrinsic */
    fill();
    seed_cpu(&cpu, &dev, dst, count, v0, UINT_MAX);
    memset(&stop, 0, sizeof stop);
    musashi_native_lane_suspend(1);
    r = run_startup_cpu(g_mem, &cpu, lane_reference_sink, NULL, &result, &stop, NULL, NULL, NULL) ==
        MUSASHI_RESETGRAPH_PREFIX_COMPLETE;
    musashi_native_lane_suspend(0);
    CHECK(r, "route3 status dst=%08x n=%u", dst, count);
    CHECK(cpu.r[2] == 0xFFFFFFFFu, "route3 v0=%08x (seed %08x)", cpu.r[2], v0);
    CHECK(cleared_ok(dst, count), "route3 memory dst=%08x n=%u", dst, count);
    /* route 2: the generated direct-call function and the caller stubs */
    if (returns) {
        uint32_t ret;
        fill();
        ret = lane_func_80016714((void *)(uintptr_t)dst, count);
        CHECK(ret == 0xFFFFFFFFu, "route2 direct value %08x", ret);
        CHECK(cleared_ok(dst, count), "route2 direct memory dst=%08x n=%u", dst, count);
    }
    fill();
    lane_call_func_80016714__rvoid_ptr_i32((void *)(uintptr_t)dst, count);
    CHECK(cleared_ok(dst, count), "route2 stub rvoid_ptr_i32 memory dst=%08x n=%u", dst, count);
    fill();
    lane_call_func_80016714__va2_void(dst, count);
    CHECK(cleared_ok(dst, count), "route2 stub va2_void memory dst=%08x n=%u", dst, count);
}

int main(int argc, char **argv) {
    static const uint32_t seeds[2] = {0x5EB7C0DEu, 0u};
    static const struct { uint32_t dst, count; } cases[6] = {
        {0x80100001u, 0}, {0x80100001u, 3}, {0x80100000u, 4},
        {0x80100003u, 38}, {0x80100000u, 64}, {0x800747C0u, 8}};
    const MusashiNativeLaneEntry *e = NULL;
    uint8_t *exe;
    size_t exe_size, k;
    unsigned s, c;
    FILE *file;
    if (argc != 2) { fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]); return 2; }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "env_clear: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, file) : 0;
    fclose(file);
    g_mem = musashi_native_lane_map_guest(sizeof(*g_mem), NULL);
    if (!g_mem) { fprintf(stderr, "env_clear: host window unavailable; NOT_RUN\n"); return 77; }
    if (!musashi_boot_map_exe(g_mem, exe, exe_size)) { fprintf(stderr, "env_clear: EXE rejected\n"); return 1; }
    if (musashi_native_lane_install(musashi_native_lane_generated, musashi_native_lane_generated_count) < 0 ||
        !musashi_native_lane_usable(g_mem)) { fprintf(stderr, "env_clear: lane not usable\n"); return 1; }
    for (k = 0; k < musashi_native_lane_generated_count; ++k)
        if (musashi_native_lane_generated[k].guest_pc == STARTUP_ENVIRONMENT_CLEAR) e = &musashi_native_lane_generated[k];
    CHECK(e != NULL, "no installed lane entry for 80016714");
    if (!e) return 1;
    CHECK(e->returns == 1u, "installed entry for 80016714 declares returns=%u: its wrapper cannot set v0", (unsigned)e->returns);
    for (s = 0; s < 2; ++s)
        for (c = 0; c < 6; ++c) one_case(cases[c].dst, cases[c].count, seeds[s], e->returns == 1u);
    if (g_fail) { fprintf(stderr, "env_clear: %u check(s) failed\n", g_fail); return 1; }
    printf("NATIVE_LANE_ENV_CLEAR_PASS cases=6 seeds=2 routes=lane_try,loop,intrinsic,direct,stubs (entry %s returns=%u)\n",
           e->name ? e->name : "?", (unsigned)e->returns);
    return 0;
}
