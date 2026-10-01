/* Runtime plumbing of overlay entries in the native lane (no generated code):
 *
 *   deny     : MUSASHI_NATIVE_LANE_DENY / _RANGE filter the overlay table,
 *              and install_overlay returns the count kept;
 *   counters : entry verified/refused (lane_try at an overlay PC) and guard
 *              verified/refused (musashi_native_lane_overlay_resident) are
 *              counted separately;
 *   recheck  : after a guest call from a native overlay body, the bytes of
 *              every native overlay frame of that lane entry are re-hashed;
 *              a body whose own bytes (or a directly called overlay callee's
 *              bytes) changed under the call aborts fail closed, and the same
 *              call succeeds again once the bytes are restored;
 *   hook     : the interpreter thunk arms the platform entry hook for its
 *              target, as a jal does;
 *   tracer   : with MUSASHI_TRACE_FUNCS, an overlay entry counts native only
 *              when its digest verified.
 *
 * Two synthetic "overlay functions" live at OVL_A / OVL_B with arbitrary
 * bytes; their host bodies are the functions below. The guest callee is a
 * small retail main-EXE function run by the interpreter. Exit 0 on PASS, 1 on
 * a failed check, 77 without the EXE or the host window. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_native_lane.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum { OVL_A = 0x80180000u, SIZE_A = 64u, OVL_B = 0x80180100u, SIZE_B = 32u,
       STACK_TOP = 0x801fe000u };
/* func_80012AB0: a 12-byte main-EXE leaf (registry), run interpreted. */
#define GUEST_CALLEE 0x80012ab0u

static unsigned g_fail;
#define CHECK(cond, ...) do { if (!(cond)) { ++g_fail; fprintf(stderr, "overlay_runtime: FAIL " __VA_ARGS__); fputc('\n', stderr); } } while (0)

static uint64_t fnv(const uint8_t *p, uint32_t n) {
    uint64_t h = 0xcbf29ce484222325ull;
    while (n--) { h ^= *p++; h *= 0x100000001b3ull; }
    return h;
}

static MusashiBootMemory *g_mem;
static uint64_t g_digest_a, g_digest_b;
static unsigned g_ran_a, g_ran_a_after, g_ran_b;
/* 0: plain; 1: flip a byte of A's own extent during the body; 2: flip a
 * byte of B's extent while B is a directly called native frame. */
static int g_mode;
static unsigned g_hook_hits;

static uint8_t *ram(uint32_t a) { return g_mem->bytes + (a & 0x1fffffu); }

/* -1: no check; else the guard result B must see for A (A resident) */
static int g_b_expect_a = -1;
static unsigned g_b_checked;

static int body_b(MusashiNativeLaneCall *call) {
    ++g_ran_b;
    if (g_b_expect_a >= 0) {
        ++g_b_checked;
        CHECK(musashi_native_lane_overlay_resident(OVL_A, SIZE_A, g_digest_a) == g_b_expect_a,
              "guard for A from B: want %d", g_b_expect_a);
    }
    call->r[2] = 0xb0b0u;
    return 1;
}

static int body_a(MusashiNativeLaneCall *call) {
    ++g_ran_a;
    /* guard counters: one resident, one not */
    CHECK(musashi_native_lane_overlay_resident(OVL_B, SIZE_B, g_digest_b) == 1, "guard on resident B");
    CHECK(musashi_native_lane_overlay_resident(OVL_B, SIZE_B, g_digest_b ^ 1u) == 0, "guard on wrong digest");
    /* a direct native call into B, as generated stubs do */
    musashi_native_lane_overlay_enter(OVL_B, SIZE_B, g_digest_b);
    if (g_mode == 1) ram(OVL_A + 40u)[0] ^= 0x5au;
    if (g_mode == 2) ram(OVL_B + 20u)[0] ^= 0x5au;
    (void)musashi_native_guest_call(GUEST_CALLEE, 0u, NULL, NULL);
    musashi_native_lane_overlay_leave();
    ++g_ran_a_after;
    call->r[2] = 0xa0a0u;
    return 1;
}

static void hook(void *user, uint32_t pc, const uint32_t *regs) {
    (void)user; (void)regs;
    if (pc == GUEST_CALLEE) ++g_hook_hits;
}

static void fill(uint32_t at, uint32_t n, uint8_t seed) {
    uint32_t i;
    for (i = 0; i < n; ++i) ram(at + i)[0] = (uint8_t)(seed + i * 7u);
}

static int install(const char *deny) {
    MusashiNativeLaneOverlayEntry t[2];
    memset(t, 0, sizeof t);
    t[0].entry.guest_pc = OVL_A; t[0].entry.cost_cycles = 2u * (SIZE_A / 4u);
    t[0].entry.fn = body_a; t[0].entry.name = "probe_a"; t[0].entry.returns = 1u;
    t[0].size = SIZE_A; t[0].digest = g_digest_a; t[0].member = "probe_0000";
    t[1].entry.guest_pc = OVL_B; t[1].entry.cost_cycles = 2u * (SIZE_B / 4u);
    t[1].entry.fn = body_b; t[1].entry.name = "probe_b"; t[1].entry.returns = 1u;
    t[1].size = SIZE_B; t[1].digest = g_digest_b; t[1].member = "probe_0000";
    if (deny) setenv("MUSASHI_NATIVE_LANE_DENY", deny, 1); else unsetenv("MUSASHI_NATIVE_LANE_DENY");
    {
        int n = musashi_native_lane_install_overlay(t, 2u);
        unsetenv("MUSASHI_NATIVE_LANE_DENY");
        return n;
    }
}

static int call(uint32_t pc, uint32_t *v0) {
    *v0 = 0;
    return musashi_native_lane_reference_call(g_mem, pc, NULL, 0u, STACK_TOP, 1, v0, NULL);
}

int main(int argc, char **argv) {
    FILE *f;
    uint8_t *exe;
    size_t exe_size;
    uint32_t v0;
    uint8_t saved_a[SIZE_A];
    MusashiNativeLaneOverlayStats st0, st;
    char trace[512];
    if (argc != 3) { fprintf(stderr, "usage: %s SLUS_007.26 TRACE_PATH\n", argv[0]); return 2; }
    snprintf(trace, sizeof trace, "%s", argv[2]);
    setenv("MUSASHI_TRACE_FUNCS", trace, 1);
    f = fopen(argv[1], "rb");
    if (!f) { fprintf(stderr, "overlay_runtime: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, f) : 0;
    fclose(f);
    g_mem = musashi_native_lane_map_guest(sizeof(*g_mem), NULL);
    if (!g_mem) { fprintf(stderr, "overlay_runtime: host window unavailable; NOT_RUN\n"); return 77; }
    if (!musashi_boot_map_exe(g_mem, exe, exe_size)) { fprintf(stderr, "overlay_runtime: EXE rejected\n"); return 1; }
    fill(OVL_A, SIZE_A, 0x11u);
    fill(OVL_B, SIZE_B, 0x93u);
    g_digest_a = fnv(ram(OVL_A), SIZE_A);
    g_digest_b = fnv(ram(OVL_B), SIZE_B);
    memcpy(saved_a, ram(OVL_A), SIZE_A);
    musashi_formatter_set_entry_hook(hook, NULL);

    /* deny: both PCs, then one denied, then a RANGE that keeps only B */
    CHECK(install("80180100") == 1, "DENY=80180100 keeps 1 overlay entry");
    {
        unsigned before = g_ran_b;
        (void)call(OVL_B, &v0);
        CHECK(g_ran_b == before, "denied overlay entry ran natively");
    }
    setenv("MUSASHI_NATIVE_LANE_RANGE", "80180080-80180200", 1);
    CHECK(install(NULL) == 1, "RANGE keeps 1 overlay entry");
    /* A filtered out: a direct native call from B to A is refused by the
     * guard (A's bytes are resident and match), so A stays interpreted */
    {
        MusashiNativeLaneOverlayStats a, b;
        musashi_native_lane_overlay_stats_get(&a);
        g_b_expect_a = 0;
        CHECK(call(OVL_B, &v0) == 1 && v0 == 0xb0b0u && g_b_checked == 1, "B runs (RANGE)");
        musashi_native_lane_overlay_stats_get(&b);
        CHECK(b.guard_refused == a.guard_refused + 1, "guard_refused +1 (filtered callee)");
    }
    unsetenv("MUSASHI_NATIVE_LANE_RANGE");
    CHECK(install(NULL) == 2, "no filter keeps 2 overlay entries");
    g_b_expect_a = 1;
    CHECK(call(OVL_B, &v0) == 1 && g_b_checked == 2, "B runs (unfiltered)");
    g_b_expect_a = -1;
    if (!musashi_native_lane_usable(g_mem)) { fprintf(stderr, "overlay_runtime: lane not usable\n"); return 1; }

    /* counters + clean recheck */
    musashi_native_lane_overlay_stats_get(&st0);
    g_mode = 0;
    CHECK(call(OVL_A, &v0) == 1 && v0 == 0xa0a0u, "plain call (v0=%08x)", v0);
    musashi_native_lane_overlay_stats_get(&st);
    CHECK(st.entry_verified == st0.entry_verified + 1, "entry_verified +1");
    CHECK(st.guard_verified == st0.guard_verified + 1, "guard_verified +1");
    CHECK(st.guard_refused == st0.guard_refused + 1, "guard_refused +1");
    CHECK(st.recheck_ok == st0.recheck_ok + 2, "recheck_ok +2 (A and B frames)");
    CHECK(st.recheck_failed == st0.recheck_failed, "no recheck failure");
    CHECK(g_hook_hits == 1, "thunk armed the entry hook (hits=%u)", g_hook_hits);

    /* entry refused: A's resident bytes differ before the call */
    ram(OVL_A + 8u)[0] ^= 0xffu;
    {
        unsigned before = g_ran_a;
        (void)call(OVL_A, &v0); /* the interpreter runs the synthetic words */
        musashi_native_lane_overlay_stats_get(&st0);
        CHECK(g_ran_a == before, "native body ran on modified bytes");
        CHECK(st0.entry_refused == st.entry_refused + 1, "entry_refused +1");
    }
    memcpy(ram(OVL_A), saved_a, SIZE_A);

    /* fail closed: the caller's own bytes change under its guest call */
    g_mode = 1;
    {
        unsigned after = g_ran_a_after;
        CHECK(call(OVL_A, &v0) == 0, "corrupted caller must abort");
        CHECK(g_ran_a_after == after, "native body continued after its bytes changed");
        musashi_native_lane_overlay_stats_get(&st);
        CHECK(st.recheck_failed == st0.recheck_failed + 1, "recheck_failed +1 (caller)");
    }
    memcpy(ram(OVL_A), saved_a, SIZE_A); /* restore */
    g_mode = 0;
    CHECK(call(OVL_A, &v0) == 1 && v0 == 0xa0a0u, "restored caller runs again");

    /* fail closed: a directly called overlay frame's bytes change */
    g_mode = 2;
    musashi_native_lane_overlay_stats_get(&st0);
    CHECK(call(OVL_A, &v0) == 0, "corrupted direct callee frame must abort");
    musashi_native_lane_overlay_stats_get(&st);
    CHECK(st.recheck_failed == st0.recheck_failed + 1, "recheck_failed +1 (callee frame)");
    fill(OVL_B, SIZE_B, 0x93u);
    g_mode = 0;
    CHECK(call(OVL_A, &v0) == 1 && v0 == 0xa0a0u, "restored callee frame runs again");

    /* tracer: A entered 6 times as 'd' entries; verified 3 (plain, restored,
     * restored) + the 2 aborted ones also verified at entry = 5; the one
     * refusal is interpreted */
    musashi_trace_function_flush();
    {
        char path[600], line[256];
        unsigned native = 0, interp = 0;
        FILE *c;
        snprintf(path, sizeof path, "%s.counts", trace);
        c = fopen(path, "r");
        CHECK(c != NULL, "trace counts %s", path);
        while (c && fgets(line, sizeof line, c)) {
            unsigned target, count, caller;
            char kind, lane[16];
            if (sscanf(line, "%x %u %c %x %15s", &target, &count, &kind, &caller, lane) == 5 &&
                target == OVL_A) {
                if (!strcmp(lane, "native")) native = count; else interp = count;
            }
        }
        if (c) fclose(c);
        CHECK(native == 5 && interp == 1, "trace A native=%u interp=%u (want 5/1)", native, interp);
    }
    musashi_native_lane_overlay_stats_get(&st);
    printf("overlay_runtime: entry_verified=%llu entry_refused=%llu guard_verified=%llu "
           "guard_refused=%llu recheck_ok=%llu recheck_failed=%llu hook_hits=%u %s\n",
           (unsigned long long)st.entry_verified, (unsigned long long)st.entry_refused,
           (unsigned long long)st.guard_verified, (unsigned long long)st.guard_refused,
           (unsigned long long)st.recheck_ok, (unsigned long long)st.recheck_failed, g_hook_hits,
           g_fail ? "FAIL" : "PASS");
    return g_fail ? 1 : 0;
}
