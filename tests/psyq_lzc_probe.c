/* Same-input differential of the LZC HLE (bfm_psyq_LZC, retail func_80049440:
 * MTC2 LZCS=a0, MFC2 v0=LZCR) against the retail code run on the interpreter as
 * a test-only oracle from the developer's own EXE (extracted/disc/files/
 * SLUS_007.26; no retail bytes are compiled in or committed).
 *
 * Oracle leg: musashi_boot_execute_source_call(0x80049440, a0) on the
 * interpreter with a MusashiCpuTransferDevice over a real gte_owner (test-only
 * adaptor: the nested CPU's context identity is replaced by the owner's lease
 * identity). HLE leg: bfm_psyq_LZC through the GTE bridge over the same owner.
 *
 * Every case starts from the same state: the pinned EXE image plus a
 * pseudo-random arena, and the GTE data/control banks seeded through the
 * owner. Both legs must then agree on v0, the whole GTE data and control banks
 * (all 64 registers), both owner counters (write/read, the HLE must credit
 * exactly one of each) and every byte of guest RAM and scratchpad. The HLE
 * must also leave every guest register except v0 as it found it. That check
 * is on the HLE side only: execute_source_call does not expose the nested
 * interpreter's register file. It is justified by the retail words, which are
 * `mtc2 a0,$30` (asm/main.s func_80049440, 0x80049440), two nops, `mfc2 v0,$31`
 * (0x8004944C), `jr ra` (0x80049450) and a nop: the only general register
 * written is v0, the rest are only read (a0, ra).
 * Refusals (no bridge, lease already held, counter overflow) must return 0 with
 * the bank, counters and RAM untouched.
 *
 * Exit 0 when everything agrees; 1 on any difference; 77 when the EXE or the
 * host window at 0x80000000 is unavailable. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_cpu_status.h"
#include "musashi_gte_owner.h"
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

enum { LZC_PC = 0x80049440u, ARENA = 0x80180000u, ARENA_END = 0x801F8000u };

static MusashiBootMemory *g_mem;
static uint8_t *g_image, *g_ram_interp;
static uint8_t g_scr_interp[MUSASHI_SCRATCHPAD_SIZE];
static MusashiCpuStatus *g_status;
static MusashiGteOwner g_owner;
static const int g_identity;
static unsigned g_cases, g_bad, g_refusals;
static uint32_t rng_state;

static uint32_t rng(void) {
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 17;
    rng_state ^= rng_state << 5;
    return rng_state;
}

static uint64_t thread_token(void *u) { (void)u; return 1u; }

/* Fake lease context used to seed and snapshot the bank through the owner. */
static const uint32_t g_gpr[32];
static MusashiCpuContext lease_ctx(void) {
    MusashiCpuContext c;
    memset(&c, 0, sizeof c);
    c.identity = &g_identity;
    c.gpr = g_gpr;
    c.pc = LZC_PC;
    c.npc = LZC_PC + 4u;
    c.instruction = 0x4884F000u;
    c.instruction_valid = 1;
    c.provenance = MUSASHI_CPU_CONTEXT_SOURCE;
    return c;
}

/* Test-only adaptor: the nested interpreter's identity is its own stack CPU,
 * so present the owner's lease identity instead. */
static int t_write_data(void *u, const MusashiCpuContext *c, uint32_t sel, uint32_t v) {
    MusashiCpuContext x = *c;
    (void)u;
    x.identity = &g_identity;
    return musashi_gte_owner_write_data(&g_owner, &x, sel, v);
}
static int t_read_data(void *u, const MusashiCpuContext *c, uint32_t sel, uint32_t *v) {
    MusashiCpuContext x = *c;
    (void)u;
    x.identity = &g_identity;
    return musashi_gte_owner_read_data(&g_owner, &x, sel, v);
}
static const MusashiCpuTransferDevice g_transfer = {.write_data = t_write_data,
                                                    .read_data = t_read_data};

/* Own bridge when the lane (which carries the production one) isn't linked. */
#ifndef PSYQ_PROBE_WITH_LANE
static int b_begin(void *u) { return musashi_gte_owner_native_begin(u); }
static void b_end(void *u, uint32_t c) { musashi_gte_owner_native_end(u, c); }
static int b_lzc(void *u, uint32_t v, uint32_t *l) { return musashi_gte_owner_native_lzc(u, v, l); }
#endif
static void bind_bridge(int on) {
#ifdef PSYQ_PROBE_WITH_LANE
    musashi_native_lane_psyq_bind(g_mem, on ? &g_owner : NULL);
    bfm_psyq_set_ram(g_mem->bytes, MUSASHI_RAM_SIZE);
    bfm_psyq_set_scratchpad(g_mem->scratchpad);
#else
    BfmPsyqGteBridge b = {b_begin, b_end, &g_owner, b_lzc};
    bfm_psyq_set_gte_bridge(on ? &b : NULL);
#endif
}

static void sink(void *u, const uint8_t *b, int32_t n) { (void)u; (void)b; (void)n; }

static void put32(uint32_t a, uint32_t v) {
    uint8_t *p = g_mem->bytes + (a & 0x1FFFFFFFu);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

/* Identical starting state for a leg: RAM, scratchpad and GTE bank. */
static int seed(uint32_t salt) {
    static const uint32_t data_sel[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 19, 20, 21, 22, 28, 30};
    MusashiCpuContext c = lease_ctx();
    uint32_t a, k;
    memcpy(g_mem->bytes, g_image, MUSASHI_RAM_SIZE);
    rng_state = salt | 1u;
    for (a = ARENA; a < ARENA_END; a += 4u) put32(a, rng());
    for (k = 0; k < MUSASHI_SCRATCHPAD_SIZE; ++k) g_mem->scratchpad[k] = (uint8_t)rng();
    for (k = 0; k < sizeof data_sel / sizeof data_sel[0]; ++k)
        if (!musashi_gte_owner_write_data(&g_owner, &c, data_sel[k], rng())) return 0;
    for (k = 0; k <= 7u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, rng())) return 0;
    for (k = 13; k <= 30u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, rng())) return 0;
    return 1;
}

static int snap(MusashiGteSnapshot *s) { return musashi_gte_owner_snapshot(&g_owner, s); }

static int same_bank(const char *name, const MusashiGteSnapshot *a, const MusashiGteSnapshot *b) {
    unsigned i, bad = 0;
    for (i = 0; i < MUSASHI_GTE_DATA_COUNT; ++i)
        if (a->data[i] != b->data[i]) {
            fprintf(stderr, "lzc: %s: data[%u] hle=%08x retail=%08x\n", name, i, a->data[i], b->data[i]);
            bad = 1;
        }
    for (i = 0; i < MUSASHI_GTE_CONTROL_COUNT; ++i)
        if (a->control[i] != b->control[i]) {
            fprintf(stderr, "lzc: %s: control[%u] hle=%08x retail=%08x\n", name, i, a->control[i],
                    b->control[i]);
            bad = 1;
        }
    return !bad;
}

static void run_case(const char *name, uint32_t a0) {
    const uint32_t salt = 0x9E3779B9u * (g_cases + 1u);
    MusashiStartupPrefixDevice devices;
    MusashiResetGraphPrefixStop stop = {0};
    MusashiGteSnapshot s0, s0_ret, s_ret, s_hle;
    int32_t retail_v0 = 0;
    uint32_t r[32], expect_regs[32], k;
    uint8_t scr_hle[MUSASHI_SCRATCHPAD_SIZE];
    int good = 1;
    g_cases++;

    /* retail on the interpreter */
    if (!seed(salt) || !snap(&s0_ret)) { fprintf(stderr, "lzc: %s: seed refused\n", name); g_bad++; return; }
    memset(&devices, 0, sizeof devices);
    devices.cpu_transfer = &g_transfer;
    {
        static const MusashiCallbackDevice cb;
        devices.callback = &cb;
    }
    if (musashi_boot_execute_source_call(g_mem, &devices, LZC_PC, a0, 0, &retail_v0, sink, NULL,
                                         &stop) != MUSASHI_RESETGRAPH_PREFIX_COMPLETE ||
        !snap(&s_ret)) {
        fprintf(stderr, "lzc: %s: retail did not complete (pc %08x)\n", name, stop.target_address);
        g_bad++;
        return;
    }
    memcpy(g_ram_interp, g_mem->bytes, MUSASHI_RAM_SIZE);
    memcpy(g_scr_interp, g_mem->scratchpad, sizeof g_scr_interp);

    /* HLE through the bridge, same start state */
    if (!seed(salt) || !snap(&s0)) { fprintf(stderr, "lzc: %s: reseed refused\n", name); g_bad++; return; }
    memset(r, 0, sizeof r);
    for (k = 1; k < 32; ++k) r[k] = rng();
    r[4] = a0;
    memcpy(expect_regs, r, sizeof r);
    if (!bfm_psyq_LZC(r) || !snap(&s_hle)) {
        fprintf(stderr, "lzc: %s: HLE refused a state the retail code completes\n", name);
        g_bad++;
        return;
    }
    memcpy(scr_hle, g_mem->scratchpad, sizeof scr_hle);

    if ((uint32_t)retail_v0 != r[2]) {
        fprintf(stderr, "lzc: %s a0=%08x: v0 hle=%08x retail=%08x\n", name, a0, r[2], (uint32_t)retail_v0);
        good = 0;
    }
    expect_regs[2] = r[2];
    if (memcmp(expect_regs, r, sizeof r)) { fprintf(stderr, "lzc: %s: HLE changed registers other than v0\n", name); good = 0; }
    if (!same_bank(name, &s_hle, &s_ret)) good = 0;
    /* the owner's counters are cumulative: compare what each leg added */
    {
        const uint64_t hw = s_hle.data_write_count - s0.data_write_count,
                       hr = s_hle.data_read_count - s0.data_read_count,
                       hc = s_hle.command_count - s0.command_count,
                       hk = s_hle.write_count - s0.write_count,
                       rw = s_ret.data_write_count - s0_ret.data_write_count,
                       rr = s_ret.data_read_count - s0_ret.data_read_count,
                       rc = s_ret.command_count - s0_ret.command_count,
                       rk = s_ret.write_count - s0_ret.write_count;
        if (hw != rw || hr != rr || hc != rc || hk != rk) {
            fprintf(stderr, "lzc: %s: counter deltas hle w=%llu r=%llu c=%llu cw=%llu retail w=%llu r=%llu c=%llu cw=%llu\n",
                    name, (unsigned long long)hw, (unsigned long long)hr, (unsigned long long)hc,
                    (unsigned long long)hk, (unsigned long long)rw, (unsigned long long)rr,
                    (unsigned long long)rc, (unsigned long long)rk);
            good = 0;
        }
    }
    if (s_hle.data_write_count != s0.data_write_count + 1u || s_hle.data_read_count != s0.data_read_count + 1u) {
        fprintf(stderr, "lzc: %s: HLE did not credit exactly one write and one read\n", name);
        good = 0;
    }
    if (memcmp(g_ram_interp, g_mem->bytes, MUSASHI_RAM_SIZE) || memcmp(g_scr_interp, scr_hle, sizeof scr_hle)) {
        fprintf(stderr, "lzc: %s: guest RAM/scratchpad differs\n", name);
        good = 0;
    }
    if (!good) g_bad++;
}

/* A refusal changes nothing and leaves the lease usable afterwards. */
static void refusal(const char *name, int bridge_on, int hold_lease, int overflow) {
    MusashiGteSnapshot a, b;
    uint32_t r[32] = {0}, saved[32], k;
    uint8_t *ram = malloc(MUSASHI_RAM_SIZE);
    int bad = 0, got;
    g_refusals++;
    g_cases++;
    if (!seed(0xABCD1234u) || !snap(&a) || !ram) { g_bad++; free(ram); return; }
    memcpy(ram, g_mem->bytes, MUSASHI_RAM_SIZE);
    for (k = 1; k < 32; ++k) r[k] = rng();
    r[4] = 0x00FF1234u;
    memcpy(saved, r, sizeof r);
    bind_bridge(bridge_on);
    if (hold_lease && !musashi_gte_owner_native_begin(&g_owner)) bad = 1;
    if (overflow) g_owner.data_read_count = UINT64_MAX;
    got = bfm_psyq_LZC(r);
    if (got) { fprintf(stderr, "lzc: %s: HLE ran where a refusal was expected\n", name); bad = 1; }
    if (hold_lease) musashi_gte_owner_native_end(&g_owner, 0);
    if (overflow) g_owner.data_read_count = a.data_read_count;
    if (!snap(&b) || !same_bank(name, &b, &a) || b.data_write_count != a.data_write_count ||
        b.data_read_count != a.data_read_count || memcmp(saved, r, sizeof r) ||
        memcmp(ram, g_mem->bytes, MUSASHI_RAM_SIZE)) {
        fprintf(stderr, "lzc: %s: refusal changed state\n", name);
        bad = 1;
    }
    /* the failed attempt must not have left the lease or the wrapper stuck */
    bind_bridge(1);
    if (!bfm_psyq_LZC(r) || r[2] != 8u) { fprintf(stderr, "lzc: %s: lease not released\n", name); bad = 1; }
    free(ram);
    g_bad += bad;
}

int main(int argc, char **argv) {
    FILE *file;
    uint8_t *exe;
    size_t exe_size, i;
    unsigned n;
    const char *fuzz = getenv("LZC_PROBE_FUZZ");
    char nm[48];
    if (argc != 2) { fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]); return 2; }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "lzc: EXE unavailable; NOT_RUN\n"); return 77; }
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
    if (!g_mem) { fprintf(stderr, "lzc: host window at 0x80000000 unavailable; NOT_RUN\n"); return 77; }
    if (!musashi_boot_map_exe(g_mem, exe, exe_size)) { fprintf(stderr, "lzc: pinned EXE rejected\n"); return 1; }
    bfm_psyq_set_ram(g_mem->bytes, MUSASHI_RAM_SIZE);
    bfm_psyq_set_scratchpad(g_mem->scratchpad);
    g_image = malloc(MUSASHI_RAM_SIZE);
    g_ram_interp = malloc(MUSASHI_RAM_SIZE);
    if (!g_image || !g_ram_interp) return 1;
    memcpy(g_image, g_mem->bytes, MUSASHI_RAM_SIZE);
    if (!musashi_cpu_status_open(&g_status, thread_token, NULL) ||
        !musashi_gte_owner_init(&g_owner, g_status, thread_token, NULL, &g_identity)) {
        fprintf(stderr, "lzc: gte owner init refused\n");
        return 1;
    }
    bind_bridge(1);
#ifdef PSYQ_PROBE_WITH_LANE
    {
        size_t count = 0, j;
        int found = 0;
        MusashiNativeLaneEntry *table = musashi_native_lane_psyq_merge(NULL, 0, MUSASHI_PSYQ_LANE_PURE, &count);
        for (j = 0; table && j < count; ++j) found |= table[j].guest_pc == LZC_PC;
        if (!found) { fprintf(stderr, "lzc: 80049440 is not a default lane entry\n"); return 1; }
    }
#endif

    run_case("zero", 0);
    run_case("one", 1);
    run_case("minus_one", 0xFFFFFFFFu);
    run_case("int_min", 0x80000000u);
    run_case("int_max", 0x7FFFFFFFu);
    run_case("minus_two", 0xFFFFFFFEu);
    run_case("lo16", 0x0000FFFFu);
    run_case("hi16", 0xFFFF0000u);
    run_case("0x00FF1234", 0x00FF1234u);
    run_case("0xFF00EDCB", 0xFF00EDCBu);
    for (n = 0; n < 32; ++n) {
        snprintf(nm, sizeof nm, "bit%u", n);
        run_case(nm, 1u << n);
        snprintf(nm, sizeof nm, "notbit%u", n);
        run_case(nm, ~(1u << n));
    }
    /* every leading-zeros / leading-ones length, trailing bits random */
    for (n = 1; n <= 32; ++n) {
        const uint32_t tail = n == 32 ? 0u : rng() & (0xFFFFFFFFu >> n);
        uint32_t z = n == 32 ? 0u : (1u << (32 - n)) | (tail >> 1);
        uint32_t o = ~z;
        snprintf(nm, sizeof nm, "lead_zero_len%u", n);
        run_case(nm, z);
        snprintf(nm, sizeof nm, "lead_ones_len%u", n);
        run_case(nm, o);
    }
    for (i = 0, n = fuzz ? (unsigned)strtoul(fuzz, NULL, 0) : 600u; i < n; ++i) {
        uint32_t v = rng();
        switch (rng() & 3u) {          /* mix magnitudes so every length appears */
        case 0: break;
        case 1: v >>= rng() & 31u; break;
        case 2: v = ~(v >> (rng() & 31u)); break;
        default: v = (uint32_t)((int32_t)v >> (rng() & 31u)); break;
        }
        run_case("random", v);
    }
    refusal("no_bridge", 0, 0, 0);
    refusal("lease_held", 1, 1, 0);
    refusal("counter_overflow", 1, 0, 1);

    printf("lzc: cases=%u (refusals=%u) different=%u -> %s\n", g_cases, g_refusals, g_bad,
           g_bad ? "DIFFERS" : "same");
    return g_bad ? 1 : 0;
}
