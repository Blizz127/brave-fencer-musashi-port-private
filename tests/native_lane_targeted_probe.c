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
 * probe. Retail bytes are read from the pinned EXE at run time, never
 * committed. Exit 0 = no difference; 1 = difference/native failure/harness
 * self-check failure; 77 = EXE or host window unavailable. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_native_lane.h"

#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern const MusashiNativeLaneEntry musashi_native_lane_generated[];
extern const size_t musashi_native_lane_generated_count;

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
static struct { unsigned n; uint32_t pc, a0, a1; } g_hit;
static uint32_t g_last_handler;
static void entry_hook(void *user, uint32_t pc, const uint32_t *regs) {
    (void)user;
    if (!g_hit.n++) { g_hit.pc = pc; g_hit.a0 = regs[4]; g_hit.a1 = regs[5]; }
}

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
    uint32_t ref_v0 = 0, lane_v0 = 0, ref_v1 = 0, lane_v1 = 0;
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
    alarm(5);
    ok = musashi_native_lane_reference_call(m, c.pc, c.args, c.argc, STACK_TOP, 0, &ref_v0, &ref_v1);
    alarm(0);
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
    alarm(5);
    ok = musashi_native_lane_reference_call(m, c.pc, c.args, c.argc, STACK_TOP, 1, &lane_v0, &lane_v1);
    alarm(0);
    if (!ok) return NATIVE_FAILED;
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
    return c.expect_call > 0 ? SAME_CALLED : SAME;
}

static void on_fault(int sig, siginfo_t *info, void *ctx) {
    (void)sig; (void)ctx;
    fprintf(stderr, "targeted: native fault address %llx\n", (unsigned long long)(uintptr_t)info->si_addr);
    _exit(NATIVE_FAILED);
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
    for (which = 0; which < 3; ++which) {
        unsigned counts[7] = {0}, idx;
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
        total_bad += counts[DIFFERENT] + counts[NATIVE_FAILED] + counts[HARNESS_BAD];
        /* a probe that compares nothing proves nothing */
        if (counts[SAME] < FN[which].cases / 2u) total_bad++;
    }
    return total_bad ? 1 : 0;
}
