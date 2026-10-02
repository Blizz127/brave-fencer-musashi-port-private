/* Targeted same-input differential for three clean-room native-lane functions:
 *   8001D388  dispatch table D_8006351C[subtype](obj)          (type 2, subtype < 11)
 *   8001FB8C  dispatch table D_80063500[subtype](obj, count); ++*count (type 1, subtype < 9)
 *   80020DA4  3x3 4.12 rotation matrix from three 12-bit angles
 *
 * The generic native_lane_probe gives these functions only a couple of
 * comparable cases. Here every case builds the same seeded guest RAM, runs
 * the function once on the interpreter (lane off) and once through the lane
 * (native), and compares v0 (when the function returns one) and the whole
 * 2 MiB of guest RAM outside the callee's stack scratch.
 *
 * For the dispatchers the real retail handlers in the guest tables run on
 * both sides (the interpreter only executes admitted retail code, so
 * synthetic RAM stubs are not possible); the native path's thunk into the
 * interpreter is thereby compared too, and handlers that refuse the seeded
 * state count as not comparable. Each case runs in a forked child so a native
 * crash cannot kill the
 * probe. D-011: both runs carry a recording clock; for a ledger-mapped
 * function the cycles at the handler's entry and at the return must be
 * equal (a case whose native run reached a fixed, unmapped charge is not
 * comparable in cycles). Retail bytes are read from the pinned EXE at run time, never
 * committed. Exit 0 = no difference; 1 = difference/native failure/harness
 * self-check failure; 77 = EXE or host window unavailable.
 *
 * Escape family (guest-frame locals, tools/native_lane_gen.py
 * place_guest_locals): functions that pass a local's address to a callee.
 * Seeded scratch pointers and a seeded GTE bank (a real gte_owner behind a
 * CPU transfer device, so libgte callees run on both sides); each case
 * compares (a) at the first guest callee entry: its pc, a0-a3, sp, the four
 * outgoing stack-argument words and the bytes of every guest-frame local, and
 * (b) at the return: v0, all guest RAM outside the frame band plus the
 * guest-frame locals inside it, both GTE banks, and the cycles. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_native_lane.h"

#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <ucontext.h>
#include <sys/wait.h>
#include <unistd.h>

#ifdef MUSASHI_WITH_PSYCROSS
#include "musashi_cpu_status.h"
#include "musashi_gte_owner.h"
#endif

extern const MusashiNativeLaneEntry musashi_native_lane_generated[];
extern const size_t musashi_native_lane_generated_count;
extern const MusashiNativeLaneGuestLocal musashi_native_lane_guest_locals[];
extern const size_t musashi_native_lane_guest_locals_count;

enum { STACK_TOP = 0x801fe000u, FRAME_GUARD = 0x10000u };
enum { SIN_PTR = 0x800636D4u };
/* Scratch layout: unused guest RAM above the retail image. */
enum { OBJ_BASE = 0x80190000u,
       COUNT_CELL = 0x80194000u, ANGLES = 0x80195000u, OUT_BUF = 0x80196000u,
       OWN_TABLE = 0x801a0000u, FILL_BASE = 0x80190000u, FILL_SIZE = 0x40000u };
enum { SAME, DIFFERENT, NATIVE_FAILED, NOT_COMPARABLE, HARNESS_BAD, SAME_CALLED, NOT_COMPARABLE_CALLED };

static uint32_t rng_state = 1u;
static uint32_t rng(void) {
    rng_state ^= rng_state << 13; rng_state ^= rng_state >> 17; rng_state ^= rng_state << 5;
    return rng_state;
}

/* Entry hook: the first jalr/jal target reached during a run (the dispatcher's
 * handler call). The interpreter run is the oracle for "the callee was reached". */
static uint64_t g_cycles;
static int cycle_advance(void *u, uint32_t c) { (void)u; g_cycles += c; return 1; }
static const MusashiExecutionClock g_clock = {NULL, cycle_advance};
static struct { unsigned n; uint32_t pc, a0, a1; uint64_t cycle; } g_hit;
static uint32_t g_last_handler;
static void entry_hook(void *user, uint32_t pc, const uint32_t *regs) {
    (void)user;
    if (!g_hit.n++) { g_hit.pc = pc; g_hit.a0 = regs[4]; g_hit.a1 = regs[5]; g_hit.cycle = g_cycles; }
}
/* cycle outcome, in bits 4-5 of a case's exit status */
enum { CYC_SAME = 0, CYC_DIFFERENT = 1, CYC_NOT_COMPARABLE = 2 };

typedef struct {
    uint32_t pc, argc, args[3], returns;
    int expect_call;          /* dispatchers: the guard passes (callee reached); -1 = n/a */
    uint32_t handler;         /* ... and the table entry it must call */
} Case;

static void w32(MusashiBootMemory *m, uint32_t a, uint32_t v) { musashi_boot_write32(m, a, v); }
static void put16(MusashiBootMemory *m, uint32_t a, uint32_t v) {
    uint8_t *p = m->bytes + (a - 0x80000000u);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

/* Half the dispatcher cases run the retail table as is. The other half
 * rewrite entries 0..15 of the table (past the guard bound too) with retail
 * handlers the interpreter can complete on seeded RAM, in a per-case rotation,
 * so the native thunk call completes and is compared far more often, and an
 * index or bound error lands on a different handler. */
static void retarget_table(MusashiBootMemory *m, uint32_t table, unsigned idx) {
    static const uint32_t GOOD[3] = {0x8001D3FCu, 0x8001E7E0u, 0x8002374Cu};
    unsigned k, rot = idx / 2u % 3u;
    if (idx & 1u) return;
    for (k = 0; k < 16; ++k) w32(m, table + 4u * k, GOOD[(k + rot) % 3u]);
}

static void seed_ram(MusashiBootMemory *m, uint32_t seed) {
    uint32_t a;
    rng_state = seed | 1u;
    /* every word is a plausible guest pointer back into the scratch window, so
     * retail handlers that chase pointers stay inside mapped, admitted RAM */
    for (a = FILL_BASE; a < FILL_BASE + FILL_SIZE; a += 4u)
        w32(m, a, FILL_BASE + ((rng() % (FILL_SIZE - 0x1000u)) & ~3u));
}

static const uint32_t STATES[] = {0x80000000u, 0xFFFFFFFFu, 0u, 1u, 0x7FFFFFFFu};
static const uint32_t ENABLED[] = {0u, 1u, 0xFFFFFFFFu, 0x80000000u, 0x00010000u};
static const uint32_t TYPES[] = {2u, 1u, 0u, 3u, 0xFFFFu};
static const uint32_t TYPES1[] = {1u, 2u, 0u, 3u, 0xFFFFu};
static const uint32_t SUBS[] = {0u, 10u, 11u, 12u, 0xFFu, 0x8000u, 0xFFFFu, 0xFFFFFFFFu};
static const uint32_t SUBS1[] = {0u, 8u, 9u, 10u, 0xFFu, 0x8000u, 0xFFFFu, 0xFFFFFFFFu};
static const uint32_t COUNTS[] = {0u, 1u, 0xFFFFFFFFu, 0x7FFFFFFFu, 0x80000000u, 5u};
#define N(a) (sizeof(a) / sizeof((a)[0]))

static uint32_t pick_obj(unsigned i) { return OBJ_BASE + 0x40u * (i % 16u); }

static void setup_d388(MusashiBootMemory *m, unsigned idx, Case *c) {
    uint32_t state, enabled, type, sub, obj, sub_masked;
    unsigned prod = N(STATES) * N(ENABLED) * N(TYPES) * N(SUBS);
    if (idx < prod) {
        unsigned i = idx;
        sub = SUBS[i % N(SUBS)]; i /= N(SUBS);
        type = TYPES[i % N(TYPES)]; i /= N(TYPES);
        enabled = ENABLED[i % N(ENABLED)]; i /= N(ENABLED);
        state = STATES[i % N(STATES)];
    } else {
        /* random, biased toward the call path */
        state = rng() % 3u ? rng() & 0x7FFFFFFFu : rng();
        enabled = rng() % 4u ? rng() | 1u : 0u;
        type = rng() % 4u ? 2u : rng() & 0xFFFFu;
        sub = rng() % 2u ? rng() % 11u : (rng() % 2u ? rng() & 0xFFFFu : 11u + rng() % 8u);
    }
    obj = pick_obj(idx);
    retarget_table(m, 0x8006351Cu, idx);
    put16(m, obj + 0, type); put16(m, obj + 2, sub);
    w32(m, obj + 4, state);
    w32(m, obj + 0x20, enabled);
    sub_masked = sub & 0xFFFFu;
    c->pc = 0x8001D388u; c->argc = 1; c->args[0] = obj; c->returns = 0;
    c->expect_call = (int32_t)state >= 0 && enabled != 0 && (type & 0xFFFFu) == 2 && sub_masked < 11;
    if (c->expect_call) musashi_boot_read32(m, 0x8006351Cu + 4u * sub_masked, &c->handler);
}

static void setup_fb8c(MusashiBootMemory *m, unsigned idx, Case *c) {
    uint32_t state, type, sub, count, obj, cnt_addr, sub_masked;
    unsigned prod = N(STATES) * N(TYPES1) * N(SUBS1) * N(COUNTS);
    if (idx < prod) {
        unsigned i = idx;
        count = COUNTS[i % N(COUNTS)]; i /= N(COUNTS);
        sub = SUBS1[i % N(SUBS1)]; i /= N(SUBS1);
        type = TYPES1[i % N(TYPES1)]; i /= N(TYPES1);
        state = STATES[i % N(STATES)];
    } else {
        state = rng() % 3u ? rng() & 0x7FFFFFFFu : rng();
        type = rng() % 4u ? 1u : rng() & 0xFFFFu;
        sub = rng() % 2u ? rng() % 9u : (rng() % 2u ? rng() & 0xFFFFu : 9u + rng() % 8u);
        count = rng() % 3u ? COUNTS[rng() % N(COUNTS)] : rng();
    }
    obj = pick_obj(idx);
    retarget_table(m, 0x80063500u, idx);
    cnt_addr = COUNT_CELL + 4u * (idx % 8u);
    /* a few random cases alias *count onto the object's own state word */
    if (idx >= prod && rng() % 10u == 0) cnt_addr = obj + 4u;
    put16(m, obj + 0, type); put16(m, obj + 2, sub);
    w32(m, obj + 4, state);
    w32(m, cnt_addr, count);
    if (cnt_addr == obj + 4u) state = count; /* aliased: the count store is the state word */
    sub_masked = sub & 0xFFFFu;
    c->pc = 0x8001FB8Cu; c->argc = 2; c->args[0] = obj; c->args[1] = cnt_addr; c->returns = 0;
    c->expect_call = (int32_t)state >= 0 && (type & 0xFFFFu) == 1 && sub_masked < 9;
    if (c->expect_call) musashi_boot_read32(m, 0x80063500u + 4u * sub_masked, &c->handler);
}

static const uint32_t ANG_B[] = {0u, 1u, 2u, 0x7FFu, 0x800u, 0xFFFu, 0x1000u, 0x1001u, 0x17FFu,
                                 0x1800u, 0x1FFFu, 0x8000u, 0xF000u, 0xFFFFu, 0xFFFEu};
static const uint32_t OUTS[] = {OUT_BUF, OUT_BUF + 2u, OUT_BUF + 0x100u, OUT_BUF + 0x1ee, 0x801b0000u,
                                0x801c0002u, 0x801d0010u};

static void setup_rot(MusashiBootMemory *m, unsigned idx, Case *c) {
    uint32_t ang[3], out, in = ANGLES + 8u * (idx % 4u);
    unsigned prod = N(ANG_B) * N(ANG_B) * N(ANG_B), i;
    uint32_t table = SIN_PTR;
    (void)table;
    if (idx < prod) {
        ang[0] = ANG_B[idx % N(ANG_B)];
        ang[1] = ANG_B[idx / N(ANG_B) % N(ANG_B)];
        ang[2] = ANG_B[idx / (N(ANG_B) * N(ANG_B))];
    } else {
        for (i = 0; i < 3; ++i) ang[i] = rng() % 3u ? rng() & 0xFFFFu : rng() & 0xFFFu;
    }
    /* Table: the retail one for 2 of 3 cases; otherwise an own table that is a
     * real 4.12 sin/cos for half and pure random 32-bit words for the rest. */
    if (idx % 3u == 2u) {
        uint32_t k;
        for (k = 0; k < 4096u; ++k) {
            uint32_t word;
            if (idx % 2u) {
                int32_t s = (int32_t)lround(sin(k * 6.283185307179586 / 4096.0) * 4096.0);
                int32_t co = (int32_t)lround(cos(k * 6.283185307179586 / 4096.0) * 4096.0);
                word = (uint32_t)(uint16_t)s | (uint32_t)(uint16_t)co << 16;
            } else {
                word = rng();
            }
            w32(m, OWN_TABLE + 4u * k, word);
        }
        w32(m, SIN_PTR, OWN_TABLE);
    }
    /* output buffer: several aligned addresses; every 7th case overlaps the input */
    out = OUTS[idx % N(OUTS)];
    if (idx % 7u == 3u) out = in;
    else if (idx % 7u == 5u) out = in + 4u;
    else if (idx % 11u == 6u) out = in - 6u;
    for (i = 0; i < 3; ++i) put16(m, in + 2u * i, ang[i]);
    for (i = 0; i < 9; ++i) put16(m, out + 2u * i, rng());
    c->pc = 0x80020DA4u; c->argc = 2; c->args[0] = in; c->args[1] = out; c->returns = 0;
    c->expect_call = -1;
}

static int run_case(MusashiBootMemory *m, const uint8_t *image, int which, unsigned idx,
                    uint8_t *reference, int returns) {
    uint32_t ref_v0 = 0, lane_v0 = 0, regs[32];
    uint64_t ref_total, ref_hit_cycle;
    unsigned ref_hits;
    uint32_t fixed0;
    int cyc;
    Case c;
    uint8_t *start = malloc(MUSASHI_RAM_SIZE);
    int ok;
    if (!start) return HARNESS_BAD;
    memset(&c, 0, sizeof(c));
    memcpy(m->bytes, image, MUSASHI_RAM_SIZE);
    seed_ram(m, 0x9e3779b9u * (which + 1u) + idx * 0x85ebca6bu);
    if (which == 0) setup_d388(m, idx, &c);
    else if (which == 1) setup_fb8c(m, idx, &c);
    else setup_rot(m, idx, &c);
    c.returns = returns;
    g_last_handler = c.expect_call > 0 ? c.handler : 0;
    memcpy(start, m->bytes, MUSASHI_RAM_SIZE);
    memset(&g_hit, 0, sizeof(g_hit));
    g_cycles = 0;
    alarm(5);
    ok = musashi_native_lane_reference_call_clocked(m, c.pc, c.args, c.argc, STACK_TOP, 0, regs, &g_clock);
    alarm(0);
    ref_v0 = regs[2];
    ref_total = g_cycles; ref_hit_cycle = g_hit.cycle; ref_hits = g_hit.n;
    /* Harness self-check on the oracle: the dispatcher's handler call must
     * happen exactly when the guard predicts, to the table's own entry for
     * this subtype, with the right arguments (even if the handler later refuses). */
    if (c.expect_call >= 0) {
        if (!!g_hit.n != c.expect_call ||
            (c.expect_call && (g_hit.pc != c.handler || g_hit.a0 != c.args[0] ||
                               (which == 1 && g_hit.a1 != c.args[1])))) {
            fprintf(stderr, "targeted: harness self-check failed fn %d case %u hits=%u pc=%08x want %08x\n",
                    which, idx, g_hit.n, g_hit.pc, c.handler);
            free(start); return HARNESS_BAD;
        }
    }
    if (!ok) { free(start); return c.expect_call > 0 ? NOT_COMPARABLE_CALLED : NOT_COMPARABLE; }
    memcpy(reference, m->bytes, MUSASHI_RAM_SIZE);
    memcpy(m->bytes, start, MUSASHI_RAM_SIZE);
    free(start);
    memset(&g_hit, 0, sizeof(g_hit));
    g_cycles = 0;
    fixed0 = musashi_lane_fixed;
    alarm(5);
    ok = musashi_native_lane_reference_call_clocked(m, c.pc, c.args, c.argc, STACK_TOP, 1, regs, &g_clock);
    alarm(0);
    lane_v0 = regs[2];
    if (!ok) return NATIVE_FAILED;
    {
        const MusashiNativeLaneEntry *e = NULL;
        size_t k;
        for (k = 0; k < musashi_native_lane_generated_count; ++k)
            if (musashi_native_lane_generated[k].guest_pc == c.pc) e = &musashi_native_lane_generated[k];
        if (!e || !e->ledger || musashi_lane_fixed != fixed0) cyc = CYC_NOT_COMPARABLE;
        else if (g_cycles != ref_total || g_hit.n != ref_hits || (ref_hits && g_hit.cycle != ref_hit_cycle)) {
            fprintf(stderr, "targeted: fn %d case %u cycles interp %llu (handler@%llu) native %llu (handler@%llu)\n",
                    which, idx, (unsigned long long)ref_total, (unsigned long long)ref_hit_cycle,
                    (unsigned long long)g_cycles, (unsigned long long)g_hit.cycle);
            cyc = CYC_DIFFERENT;
        } else cyc = CYC_SAME;
    }
    if (returns && ref_v0 != lane_v0) {
        fprintf(stderr, "targeted: fn %d case %u v0 interp=%08x native=%08x\n", which, idx, ref_v0, lane_v0);
        return DIFFERENT;
    }
    {
        /* callee's own frame and o32 home area are interpreter-private scratch */
        const uint32_t lo = STACK_TOP - FRAME_GUARD - 0x80000000u;
        const uint32_t hi = STACK_TOP + 0x10u + 4u * 8u - 0x80000000u;
        uint32_t i, shown = 0;
        int differ = 0;
        for (i = 0; i < MUSASHI_RAM_SIZE; ++i) {
            if (i >= lo && i < hi) continue;
            if (m->bytes[i] != reference[i]) {
                if (shown++ < 4)
                    fprintf(stderr, "targeted: fn %d case %u args %08x %08x RAM %08x interp=%02x native=%02x\n",
                            which, idx, c.args[0], c.args[1], 0x80000000u + i, reference[i], m->bytes[i]);
                differ = 1;
            }
        }
        if (differ) return DIFFERENT;
    }
    return (c.expect_call > 0 ? SAME_CALLED : SAME) | (cyc << 4);
}

/* Set by an escape case whose interpreter leg was refused: a host fault in
 * its native leg (e.g. a wild pointer the interpreter refused to follow) is
 * then not comparable, as the main probe's mirror/wrap faults are. */
static volatile int g_ref_refused;

static void on_fault(int sig, siginfo_t *info, void *ctx);

/* ---- escape family ---------------------------------------------------- */

/* kinds per argument: p = pointer into the seeded scratch (4-aligned),
 * h = pointer that may be 2-aligned (s16 arrays), i = small integer,
 * n = index 0..3, l = zero-terminated word list (empty) or NULL */
static const struct { uint32_t pc; const char *kinds; } ESC[] = {
    {0x8001282Cu, "p"}, {0x800128B4u, "p"}, {0x800128ECu, "pp"}, {0x80012E0Cu, "iiii"},
    {0x80014168u, "pp"}, {0x80014774u, ""}, {0x80016D78u, "pi"},
    {0x8001C1E4u, "pp"}, {0x8001C214u, "pl"},
    {0x8001C2C4u, "p"}, {0x8001C448u, "p"}, {0x8001C4A4u, "pl"}, {0x8001C558u, "p"},
    {0x8001C6E4u, "p"}, {0x8001C744u, "pi"}, {0x8001C7B0u, "p"}, {0x8001C810u, "pl"},
    {0x8001C8C4u, "p"}, {0x8001CA1Cu, "pi"}, {0x8001CA88u, "pi"}, {0x80028620u, "np"},
    {0x8002E5BCu, ""},
};
enum { ESC_CASES = 400u, ESC_LOCAL_MAX = 128u };
enum { ENTRY_NONE = 0, ENTRY_SAME = 1, ENTRY_DIFFERENT = 2, ENTRY_SKIPPED = 3 };

typedef struct {
    unsigned n;
    uint32_t pc, a[4], sp, stack[4];
    uint8_t local[ESC_LOCAL_MAX];
} EscEntry;
static EscEntry g_esc;
static uint32_t g_esc_pc;

/* Bytes of fn's guest-frame locals, its retail sp being sp (concatenated). */
static unsigned esc_locals(const MusashiBootMemory *m, uint32_t fn, uint32_t sp, uint8_t *out) {
    size_t k;
    unsigned n = 0, b;
    for (k = 0; k < musashi_native_lane_guest_locals_count; ++k) {
        const MusashiNativeLaneGuestLocal *g = &musashi_native_lane_guest_locals[k];
        if (g->guest_pc != fn || g->member) continue;
        for (b = 0; b < g->size && n < ESC_LOCAL_MAX; ++b)
            out[n++] = m->bytes[sp + g->off + b - 0x80000000u];
    }
    return n;
}

static uint32_t esc_frame(uint32_t fn) {
    size_t k;
    for (k = 0; k < musashi_native_lane_guest_locals_count; ++k)
        if (musashi_native_lane_guest_locals[k].guest_pc == fn && !musashi_native_lane_guest_locals[k].member)
            return musashi_native_lane_guest_locals[k].frame;
    return 0;
}

static MusashiBootMemory *g_esc_mem;
static void esc_hook(void *user, uint32_t pc, const uint32_t *regs) {
    unsigned k;
    (void)user;
    if (g_esc.n++) return;
    g_esc.pc = pc;
    for (k = 0; k < 4; ++k) g_esc.a[k] = regs[4 + k];
    g_esc.sp = regs[29];
    for (k = 0; k < 4; ++k) musashi_boot_read32(g_esc_mem, regs[29] + 0x10u + 4u * k, &g_esc.stack[k]);
    esc_locals(g_esc_mem, g_esc_pc, STACK_TOP - esc_frame(g_esc_pc), g_esc.local);
}

static int esc_is_native(uint32_t pc) {
    size_t k;
    for (k = 0; k < musashi_native_lane_generated_count; ++k)
        if (musashi_native_lane_generated[k].guest_pc == pc) return 1;
    return 0;
}

#ifdef MUSASHI_WITH_PSYCROSS
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
/* Test-only adaptor: the nested interpreter's identity is its own stack CPU,
 * so present the owner's lease identity instead (as tests/psyq_lzc_probe.c). */
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
    for (k = 0; k < sizeof data_sel / sizeof data_sel[0]; ++k)
        if (!musashi_gte_owner_write_data(&g_owner, &c, data_sel[k], rng())) return 0;
    for (k = 0; k <= 7u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, rng())) return 0;
    for (k = 13; k <= 30u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, rng())) return 0;
    return 1;
}
static int gte_same(const MusashiGteSnapshot *a, const MusashiGteSnapshot *b) {
    return !memcmp(a->data, b->data, sizeof a->data) && !memcmp(a->control, b->control, sizeof a->control);
}
#endif

/* The interpreter leg's results, written by its forked grandchild. */
typedef struct {
    int done, ok, gte_ok;
    uint32_t v0;
    uint64_t total;
    EscEntry entry;
#ifdef MUSASHI_WITH_PSYCROSS
    MusashiGteSnapshot gte;
#endif
    uint8_t ram[MUSASHI_RAM_SIZE];
} EscShared;
static EscShared *g_sh;

static int in_band(uint32_t a) {
    return a >= STACK_TOP - FRAME_GUARD && a < STACK_TOP + 0x30u;
}

static void esc_args(MusashiBootMemory *m, unsigned k, unsigned idx, uint32_t *args, unsigned *argc) {
    const char *kinds = ESC[k].kinds;
    unsigned i;
    for (i = 0; kinds[i]; ++i) {
        uint32_t base = FILL_BASE + 0x200u * ((idx * 7u + i * 3u) % 64u) + 0x40u * i;
        switch (kinds[i]) {
        case 'p': args[i] = base; break;
        case 'h': args[i] = base + ((idx >> 2) & 1u) * 2u; break;
        case 'n': args[i] = rng() % 4u; break;
        /* a zero-terminated list: empty, or absent (NULL) */
        case 'l': args[i] = idx % 4u == 3u ? 0u : base; w32(m, base, 0u); break;
        default: args[i] = idx % 3u ? rng() % 8u : rng(); break;
        }
    }
    *argc = i;
}

static int run_escape_case(MusashiBootMemory *m, const uint8_t *image, unsigned k, unsigned idx,
                           uint8_t *reference, int returns, int ledger) {
    const uint32_t pc = ESC[k].pc, salt = 0x85ebca6bu * (idx + 1u) ^ pc;
    uint32_t args[4] = {0}, regs[32], ref_v0, a;
    unsigned argc = 0;
    uint64_t ref_total;
    uint32_t fixed0;
    int ok, cyc, entry = ENTRY_NONE;
    EscEntry ref_entry;
    const MusashiCpuTransferDevice *transfer = NULL;
    uint8_t *start = malloc(MUSASHI_RAM_SIZE);
#ifdef MUSASHI_WITH_PSYCROSS
    MusashiGteSnapshot gte_ref, gte_lane;
    if (g_gte_ok) transfer = &g_transfer;
#endif
    if (!start) return HARNESS_BAD;
    memcpy(m->bytes, image, MUSASHI_RAM_SIZE);
    rng_state = salt | 1u;
    if (idx % 3u == 2u) {
        /* small signed values: vectors and counts rather than pointers */
        for (a = FILL_BASE; a < FILL_BASE + FILL_SIZE; a += 4u)
            w32(m, a, (rng() % 0x2000u) - 0x1000u);
    } else {
        seed_ram(m, salt);
    }
    esc_args(m, k, idx, args, &argc);
    memcpy(start, m->bytes, MUSASHI_RAM_SIZE);
    g_esc_mem = m;
    g_esc_pc = pc;
#ifdef MUSASHI_WITH_PSYCROSS
    /* Seeded once: both legs inherit this bank (the interpreter leg runs in
     * a forked grandchild, the native leg here), so registers the owner
     * cannot write (the colour FIFO, MAC0, ...) start equal too. */
    if (transfer && !gte_seed(salt ^ 0x5bd1e995u)) { free(start); return HARNESS_BAD; }
#endif
    {
        pid_t leg;
        int st;
        memset(g_sh, 0, sizeof *g_sh);
        fflush(stderr);
        leg = fork();
        if (leg == 0) {
            memset(&g_esc, 0, sizeof g_esc);
            g_cycles = 0;
            alarm(5);
            g_sh->ok = musashi_native_lane_reference_call_transfer(m, pc, args, argc, STACK_TOP, 0, regs,
                                                                   &g_clock, transfer);
            alarm(0);
            g_sh->v0 = regs[2];
            g_sh->total = g_cycles;
            g_sh->entry = g_esc;
#ifdef MUSASHI_WITH_PSYCROSS
            g_sh->gte_ok = !transfer || musashi_gte_owner_snapshot(&g_owner, &g_sh->gte);
#else
            g_sh->gte_ok = 1;
#endif
            memcpy(g_sh->ram, m->bytes, MUSASHI_RAM_SIZE);
            g_sh->done = 1;
            _exit(0);
        }
        if (leg < 0 || waitpid(leg, &st, 0) != leg) { free(start); return HARNESS_BAD; }
        /* an interpreter leg that faulted or hung proves nothing */
        if (!g_sh->done || !g_sh->gte_ok) { free(start); return NOT_COMPARABLE; }
    }
    ok = g_sh->ok;
    ref_v0 = g_sh->v0;
    ref_total = g_sh->total;
    ref_entry = g_sh->entry;
#ifdef MUSASHI_WITH_PSYCROSS
    gte_ref = g_sh->gte;
#endif
    memcpy(reference, g_sh->ram, MUSASHI_RAM_SIZE);
    memcpy(m->bytes, start, MUSASHI_RAM_SIZE);
    free(start);
    memset(&g_esc, 0, sizeof g_esc);
    g_cycles = 0;
    fixed0 = musashi_lane_fixed;
    g_ref_refused = !ok;
    {
        int ok2;
        alarm(5);
        ok2 = musashi_native_lane_reference_call_transfer(m, pc, args, argc, STACK_TOP, 1, regs, &g_clock, transfer);
        alarm(0);
        /* (a) the first guest callee entry: sp, every argument register or
         * outgoing stack word that points into the frame band (on either
         * side), and the guest-frame locals' bytes. Other argument registers
         * are not compared: a callee of lower arity sees retail leftovers in
         * them where the native caller leaves the thunk's. */
        if (ref_entry.n) {
            if (!g_esc.n || g_esc.pc != ref_entry.pc) {
                entry = esc_is_native(ref_entry.pc) ? ENTRY_SKIPPED : ENTRY_DIFFERENT;
            } else {
                unsigned r;
                int same = g_esc.sp == ref_entry.sp &&
                           !memcmp(g_esc.local, ref_entry.local, sizeof g_esc.local);
                for (r = 0; r < 4; ++r) {
                    if ((in_band(g_esc.a[r]) || in_band(ref_entry.a[r])) && g_esc.a[r] != ref_entry.a[r])
                        same = 0;
                    if ((in_band(g_esc.stack[r]) || in_band(ref_entry.stack[r])) &&
                        g_esc.stack[r] != ref_entry.stack[r])
                        same = 0;
                }
                entry = same ? ENTRY_SAME : ENTRY_DIFFERENT;
            }
            if (entry == ENTRY_DIFFERENT)
                fprintf(stderr, "targeted_escape: %08x case %u entry interp %08x(a0=%08x a1=%08x sp=%08x) "
                        "native %08x(a0=%08x a1=%08x sp=%08x)\n", pc, idx, ref_entry.pc, ref_entry.a[0],
                        ref_entry.a[1], ref_entry.sp, g_esc.pc, g_esc.a[0], g_esc.a[1], g_esc.sp);
        }
        if (!ok) return NOT_COMPARABLE | (entry << 6);
        if (!ok2) return NATIVE_FAILED | (entry << 6);
    }
    if (!ledger || musashi_lane_fixed != fixed0) cyc = CYC_NOT_COMPARABLE;
    else if (g_cycles != ref_total) {
        fprintf(stderr, "targeted_escape: %08x case %u cycles interp %llu native %llu\n", pc, idx,
                (unsigned long long)ref_total, (unsigned long long)g_cycles);
        cyc = CYC_DIFFERENT;
    } else cyc = CYC_SAME;
    if (returns && ref_v0 != regs[2]) {
        fprintf(stderr, "targeted_escape: %08x case %u v0 interp=%08x native=%08x\n", pc, idx, ref_v0, regs[2]);
        return DIFFERENT | (entry << 6);
    }
#ifdef MUSASHI_WITH_PSYCROSS
    if (transfer && (!musashi_gte_owner_snapshot(&g_owner, &gte_lane) || !gte_same(&gte_ref, &gte_lane))) {
        unsigned r;
        for (r = 0; r < MUSASHI_GTE_DATA_COUNT; ++r)
            if (gte_ref.data[r] != gte_lane.data[r])
                fprintf(stderr, "targeted_escape: %08x case %u GTE data[%u] interp=%08x native=%08x\n",
                        pc, idx, r, gte_ref.data[r], gte_lane.data[r]);
        for (r = 0; r < MUSASHI_GTE_CONTROL_COUNT; ++r)
            if (gte_ref.control[r] != gte_lane.control[r])
                fprintf(stderr, "targeted_escape: %08x case %u GTE control[%u] interp=%08x native=%08x\n",
                        pc, idx, r, gte_ref.control[r], gte_lane.control[r]);
        return DIFFERENT | (entry << 6);
    }
#endif
    {
        const uint32_t lo = STACK_TOP - FRAME_GUARD - 0x80000000u;
        const uint32_t hi = STACK_TOP + 0x10u + 4u * 8u - 0x80000000u;
        const uint32_t frame = esc_frame(pc);
        uint32_t i, shown = 0;
        int differ = 0;
        for (i = 0; i < MUSASHI_RAM_SIZE; ++i) {
            if (i >= lo && i < hi) {
                /* inside the band only the guest-frame locals are compared */
                size_t g;
                int local = 0;
                for (g = 0; g < musashi_native_lane_guest_locals_count; ++g) {
                    const MusashiNativeLaneGuestLocal *e = &musashi_native_lane_guest_locals[g];
                    uint32_t l0 = STACK_TOP - frame + e->off - 0x80000000u;
                    if (e->guest_pc == pc && !e->member && i >= l0 && i < l0 + e->size) local = 1;
                }
                if (!local) continue;
            }
            if (m->bytes[i] != reference[i]) {
                if (shown++ < 4)
                    fprintf(stderr, "targeted_escape: %08x case %u RAM %08x interp=%02x native=%02x\n",
                            pc, idx, 0x80000000u + i, reference[i], m->bytes[i]);
                differ = 1;
            }
        }
        if (differ) return DIFFERENT | (entry << 6);
    }
    return SAME | (cyc << 4) | (entry << 6);
}

static int run_escape_family(MusashiBootMemory *memory, const uint8_t *image, uint8_t *reference) {
    unsigned k, bad = 0;
    const char *only = getenv("TARGETED_ESCAPE_PC");
    g_sh = mmap(NULL, sizeof *g_sh, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (g_sh == MAP_FAILED) return 1;
    musashi_formatter_set_entry_hook(esc_hook, NULL);
    for (k = 0; k < sizeof ESC / sizeof ESC[0]; ++k) {
        unsigned counts[7] = {0}, cyc[3] = {0}, ent[4] = {0}, idx;
        int returns = 0, ledger = 0, found = 0;
        size_t e;
        if (only && strtoul(only, NULL, 16) != ESC[k].pc) continue;
        for (e = 0; e < musashi_native_lane_generated_count; ++e)
            if (musashi_native_lane_generated[e].guest_pc == ESC[k].pc) {
                found = 1;
                returns = musashi_native_lane_generated[e].returns;
                ledger = musashi_native_lane_generated[e].ledger;
            }
        if (!found) {
            printf("targeted_escape: %08x has no lane entry (skipped)\n", ESC[k].pc);
            continue;
        }
        if (!esc_frame(ESC[k].pc)) {
            fprintf(stderr, "targeted_escape: %08x has no guest-frame locals in the table\n", ESC[k].pc);
            bad++;
            continue;
        }
        for (idx = 0; idx < ESC_CASES; ++idx) {
            int status, outcome;
            pid_t child;
            fflush(stderr);
            child = fork();
            if (child == 0) {
                struct sigaction a;
                memset(&a, 0, sizeof(a));
                a.sa_sigaction = on_fault; a.sa_flags = SA_SIGINFO;
                sigaction(SIGSEGV, &a, NULL); sigaction(SIGBUS, &a, NULL);
                signal(SIGALRM, SIG_DFL);
                _exit(run_escape_case(memory, image, k, idx, reference, returns, ledger));
            }
            if (child < 0 || waitpid(child, &status, 0) != child) return 1;
            outcome = WIFEXITED(status) ? WEXITSTATUS(status) : NATIVE_FAILED;
            ent[(outcome >> 6) & 3]++;
            if ((outcome & 15) == SAME) cyc[(outcome >> 4) & 3]++;
            outcome &= 15;
            if (outcome > NOT_COMPARABLE_CALLED) outcome = NATIVE_FAILED;
            counts[outcome]++;
        }
        printf("targeted_escape: %08x cases=%u same=%u different=%u native_failed=%u not_comparable=%u "
               "harness_bad=%u entry_same=%u entry_different=%u entry_skipped=%u entry_none=%u "
               "cycles_same=%u cycles_different=%u cycles_not_comparable=%u\n",
               ESC[k].pc, ESC_CASES, counts[SAME], counts[DIFFERENT], counts[NATIVE_FAILED],
               counts[NOT_COMPARABLE], counts[HARNESS_BAD], ent[ENTRY_SAME], ent[ENTRY_DIFFERENT],
               ent[ENTRY_SKIPPED], ent[ENTRY_NONE], cyc[CYC_SAME], cyc[CYC_DIFFERENT],
               cyc[CYC_NOT_COMPARABLE]);
        bad += counts[DIFFERENT] + counts[NATIVE_FAILED] + counts[HARNESS_BAD] + ent[ENTRY_DIFFERENT] +
               cyc[CYC_DIFFERENT];
        /* a function that compares nothing proves nothing */
        if (!counts[SAME] && !ent[ENTRY_SAME]) bad++;
    }
    musashi_formatter_set_entry_hook(entry_hook, NULL);
    return (int)bad;
}

static void on_fault(int sig, siginfo_t *info, void *ctx) {
    (void)sig;
    fprintf(stderr, "targeted: native fault address %llx rip %llx%s\n",
            (unsigned long long)(uintptr_t)info->si_addr,
            (unsigned long long)((ucontext_t *)ctx)->uc_mcontext.gregs[REG_RIP],
            g_ref_refused ? " (interpreter refused this case)" : "");
    _exit(g_ref_refused ? NOT_COMPARABLE : NATIVE_FAILED);
}

int main(int argc, char **argv) {
    static const struct { const char *name; uint32_t pc; unsigned cases; } FN[3] = {
        {"8001D388", 0x8001D388u, 3000u}, {"8001FB8C", 0x8001FB8Cu, 3000u}, {"80020DA4", 0x80020DA4u, 4500u}};
    MusashiBootMemory *memory;
    uint8_t *image, *reference, *exe;
    FILE *file;
    size_t exe_size, e;
    unsigned which, total_bad = 0;
    if (argc != 2) { fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]); return 2; }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "targeted: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, file) : 0;
    fclose(file);
    memory = musashi_native_lane_map_guest(sizeof(*memory), NULL);
    if (!memory) { fprintf(stderr, "targeted: host window unavailable; NOT_RUN\n"); return 77; }
    if (!musashi_boot_map_exe(memory, exe, exe_size)) { fprintf(stderr, "targeted: EXE rejected\n"); return 1; }
    if (musashi_native_lane_install(musashi_native_lane_generated, musashi_native_lane_generated_count) < 0 ||
        !musashi_native_lane_usable(memory)) {
        fprintf(stderr, "targeted: lane not usable\n");
        return 1;
    }
    musashi_formatter_set_entry_hook(entry_hook, NULL);
    image = malloc(MUSASHI_RAM_SIZE);
    reference = malloc(MUSASHI_RAM_SIZE);
    if (!image || !reference) return 1;
    memcpy(image, memory->bytes, MUSASHI_RAM_SIZE);
    /* TARGETED_ESCAPE_ONLY=1: only the escape family (iteration aid) */
    for (which = getenv("TARGETED_ESCAPE_ONLY") ? 3u : 0u; which < 3; ++which) {
        unsigned counts[7] = {0}, cyc[3] = {0}, idx;
        int returns = 0, found = 0;
        for (e = 0; e < musashi_native_lane_generated_count; ++e)
            if (musashi_native_lane_generated[e].guest_pc == FN[which].pc) {
                found = 1; returns = musashi_native_lane_generated[e].returns;
            }
        if (!found) {
            fprintf(stderr, "targeted: %s has no lane entry\n", FN[which].name);
            return 1;
        }
        for (idx = 0; idx < FN[which].cases; ++idx) {
            int status, outcome;
            pid_t child;
            fflush(stderr);
            child = fork();
            if (child == 0) {
                struct sigaction a;
                memset(&a, 0, sizeof(a));
                a.sa_sigaction = on_fault; a.sa_flags = SA_SIGINFO;
                sigaction(SIGSEGV, &a, NULL); sigaction(SIGBUS, &a, NULL);
                signal(SIGALRM, SIG_DFL);
{
                    int r = run_case(memory, image, (int)which, idx, reference, returns);
                    if (getenv("TARGETED_VERBOSE") && g_last_handler)
                        fprintf(stderr, "handler %08x outcome %d\n", g_last_handler, r);
                    _exit(r);
                }
            }
            if (child < 0 || waitpid(child, &status, 0) != child) return 1;
            outcome = WIFEXITED(status) ? WEXITSTATUS(status) : NATIVE_FAILED;
            if ((outcome & 15) == SAME || (outcome & 15) == SAME_CALLED) {
                if ((outcome >> 4) > CYC_NOT_COMPARABLE) outcome = NATIVE_FAILED;
                else { cyc[outcome >> 4]++; outcome &= 15; }
            }
            if (outcome > NOT_COMPARABLE_CALLED) outcome = NATIVE_FAILED;
            counts[outcome]++;
        }
        counts[SAME] += counts[SAME_CALLED];
        counts[NOT_COMPARABLE] += counts[NOT_COMPARABLE_CALLED];
        printf("targeted: %s cases=%u same=%u (callee_reached=%u) different=%u native_failed=%u "
               "not_comparable=%u (callee_reached=%u) harness_bad=%u\n",
               FN[which].name, FN[which].cases, counts[SAME], counts[SAME_CALLED], counts[DIFFERENT],
               counts[NATIVE_FAILED], counts[NOT_COMPARABLE], counts[NOT_COMPARABLE_CALLED],
               counts[HARNESS_BAD]);
        printf("targeted_cycles: %s same=%u different=%u not_comparable=%u\n",
               FN[which].name, cyc[CYC_SAME], cyc[CYC_DIFFERENT], cyc[CYC_NOT_COMPARABLE]);
        total_bad += counts[DIFFERENT] + counts[NATIVE_FAILED] + counts[HARNESS_BAD] + cyc[CYC_DIFFERENT];
        /* a probe that compares nothing proves nothing */
        if (counts[SAME] < FN[which].cases / 2u) total_bad++;
    }
#ifdef MUSASHI_WITH_PSYCROSS
    g_gte_ok = musashi_cpu_status_open(&g_status, thread_token, NULL) &&
               musashi_gte_owner_init(&g_owner, g_status, thread_token, NULL, &g_identity);
    if (!g_gte_ok) fprintf(stderr, "targeted_escape: no gte owner; GTE callees refuse on both sides\n");
#endif
    total_bad += (unsigned)run_escape_family(memory, image, reference);
    return total_bad ? 1 : 0;
}
