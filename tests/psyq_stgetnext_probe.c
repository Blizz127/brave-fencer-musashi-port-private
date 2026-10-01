/* Same-input differential of the StGetNext HLE (bfm_psyq_StGetNext) against
 * the retail libcd2 code at 0x80046C38, run on the interpreter as a test-only
 * oracle from the developer's own EXE (extracted/disc/files/SLUS_007.26; no
 * retail bytes are compiled in or committed).
 *
 * Each case seeds the pinned EXE image plus a pseudo-random arena, writes a
 * synthetic stream-ring state (the StSetRing/StSetMask globals, the 32-byte
 * sector headers, sentinel output words) and then runs a short script of
 * steps on it:
 *   GET      StGetNext(addr_out, head_out)
 *   FREE     the retail StFreeRing (0x80046B44) on *addr_out, interpreted in
 *            every leg, so the ring advances as it does in the game
 *   SET      a host write of one slot status (the stream interrupt filling a
 *            frame between polls)
 * The script runs in up to three legs from the same start state:
 *   interp   every PC interpreted (lane suspended): the retail oracle
 *   lane     the same CPU with the lane installed (MUSASHI_NATIVE_LANE
 *            builds), so 0x80046C38 enters the HLE through lane_try
 *   direct   bfm_psyq_StGetNext(r) on an o32 register file, FREE/SET as above
 * After every GET the legs must agree on: whether the call completed, the
 * whole general register file (v0 and every caller-saved register the retail
 * code leaves), and a 64-bit hash of all 2 MB of guest RAM plus the 1 KiB
 * scratchpad; at the end the full RAM and scratchpad must be byte-identical.
 * The direct leg must also show the HLE ran (returned 1) on every GET the
 * oracle completed, except in the cases that expect a refusal, where it must
 * return 0 with nothing written (the lane then interprets the retail code).
 *
 * Exit 0 when every case agrees; 1 on any difference; 77 when the EXE or the
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

enum { ST_GET_NEXT = 0x80046C38u, ST_FREE_RING = 0x80046B44u };
enum { READ_INDEX = 0x800C6D40u, RING_BASE = 0x800C7C94u, RING_SIZE = 0x800C7F00u,
       END_FRAME = 0x800C7C84u };
enum { ARENA = 0x80180000u, ARENA_END = 0x801F8000u, STACK_TOP = 0x801FE000u,
       OUT = 0x801FDFF0u, GP = 0x80074750u };
enum { MAX_SLOTS = 64, MAX_STEPS = 160, LEGS = 3 };
enum { LEG_INTERP, LEG_LANE, LEG_DIRECT };

typedef enum { GET, FREE, SET } StepKind;
typedef struct Step { StepKind kind; uint16_t slot, value; } Step;

typedef struct Case {
    const char *name;
    uint32_t base, size, index, end, addr_out, head_out;
    unsigned nslots;                       /* headers written: statuses/counts */
    uint16_t status[MAX_SLOTS], count[MAX_SLOTS];
    unsigned nsteps;
    Step steps[MAX_STEPS];
    int expect_refusal;                    /* direct HLE must refuse every GET */
} Case;

typedef struct Leg {
    unsigned gets;
    int ok[MAX_STEPS];
    uint32_t regs[MAX_STEPS][32];
    uint64_t hash[MAX_STEPS];
    int hle_ran[MAX_STEPS];
} Leg;

static MusashiBootMemory *g_mem;
static uint8_t *g_image;
static uint8_t *g_final_ram[LEGS];
static uint8_t g_final_scratch[LEGS][MUSASHI_SCRATCHPAD_SIZE];
static unsigned g_cases, g_gets, g_bad, g_refusal_cases, g_hle_calls, g_ready_paths,
    g_wrap_paths, g_notready_paths;
static int g_have_lane;

static uint32_t rng_state;
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

/* Guest address -> host byte, for seeding (RAM through any segment, or the
 * scratchpad); NULL when the case points somewhere else on purpose. */
static uint8_t *host(uint32_t a) {
    uint32_t phys = a & 0x1FFFFFFFu;
    if (phys >= 0x1F800000u && phys < 0x1F800400u) return g_mem->scratchpad + (phys - 0x1F800000u);
    if (phys < MUSASHI_RAM_SIZE) return g_mem->bytes + phys;
    return NULL;
}
static void put16(uint32_t a, uint16_t v) {
    uint8_t *p = host(a), *q = host(a + 1u);
    if (p) *p = (uint8_t)v;
    if (q) *q = (uint8_t)(v >> 8);
}
static void put32(uint32_t a, uint32_t v) {
    put16(a, (uint16_t)v);
    put16(a + 2u, (uint16_t)(v >> 16));
}
static uint32_t get32(uint32_t a) {
    uint32_t v = 0;
    unsigned i;
    for (i = 0; i < 4; ++i) {
        uint8_t *p = host(a + i);
        v |= (uint32_t)(p ? *p : 0) << (8 * i);
    }
    return v;
}

static void seed(const Case *c, uint32_t salt) {
    uint32_t a;
    unsigned i;
    memcpy(g_mem->bytes, g_image, MUSASHI_RAM_SIZE);
    rng_state = salt | 1u;
    for (a = ARENA; a < ARENA_END; a += 4u) put32(a, rng());
    for (i = 0; i < MUSASHI_SCRATCHPAD_SIZE; ++i) g_mem->scratchpad[i] = (uint8_t)rng();
    /* Sentinels first: a case may aim an output at a global or a header. */
    put32(c->addr_out, 0xDEADBEEFu);
    put32(c->head_out, 0xFEEDF00Du);
    put32(READ_INDEX, c->index);
    put32(RING_BASE, c->base);
    put32(RING_SIZE, c->size);
    put32(END_FRAME, c->end);
    for (i = 0; i < c->nslots; ++i) {
        put16(c->base + i * 32u, c->status[i]);
        put16(c->base + i * 32u + 6u, c->count[i]);
    }
}

static int get_direct(const Case *c, uint32_t *regs, int *hle_ran) {
    uint32_t r[32];
    uint8_t *before = NULL, scratch[MUSASHI_SCRATCHPAD_SIZE];
    memset(r, 0, sizeof r);
    r[4] = c->addr_out;
    r[5] = c->head_out;
    r[28] = GP;
    r[29] = r[30] = STACK_TOP;
    r[31] = UINT_MAX;
    if (c->expect_refusal) {
        before = malloc(MUSASHI_RAM_SIZE);
        if (!before) return 0;
        memcpy(before, g_mem->bytes, MUSASHI_RAM_SIZE);
        memcpy(scratch, g_mem->scratchpad, sizeof scratch);
    }
    *hle_ran = bfm_psyq_StGetNext(r);
    if (*hle_ran) {
        memcpy(regs, r, sizeof r);
        free(before);
        return 1;
    }
    if (before) {
        uint32_t i;
        int changed = memcmp(before, g_mem->bytes, MUSASHI_RAM_SIZE) != 0 ||
                      memcmp(scratch, g_mem->scratchpad, sizeof scratch) != 0;
        for (i = 0; i < 32; ++i)
            changed |= r[i] != (i == 4 ? c->addr_out : i == 5 ? c->head_out
                                : i == 28 ? GP : (i == 29 || i == 30) ? STACK_TOP
                                : i == 31 ? UINT_MAX : 0u);
        free(before);
        if (changed) {
            fprintf(stderr, "stgetnext: %s: HLE refused but changed state\n", c->name);
            return -1;
        }
    }
    /* Refused: the lane would interpret the retail code, so do that. */
    {
        const uint32_t args[2] = {c->addr_out, c->head_out};
        return musashi_native_lane_reference_call_regs(g_mem, ST_GET_NEXT, args, 2, STACK_TOP, 0, regs);
    }
}

static int run_leg(const Case *c, uint32_t salt, int leg, Leg *out) {
    unsigned s;
    int last_ready = 0;
    seed(c, salt);
    out->gets = 0;
    for (s = 0; s < c->nsteps; ++s) {
        const Step *st = &c->steps[s];
        if (st->kind == SET) {
            put16(c->base + st->slot * 32u, st->value);
            continue;
        }
        if (st->kind == FREE) {
            /* Only a frame this leg's last GET handed out is released (the
             * legs agree on that, or the comparison below fails anyway). */
            const uint32_t arg = get32(c->addr_out);
            uint32_t regs[32];
            if (!last_ready) continue;
            last_ready = 0;
            if (!musashi_native_lane_reference_call_regs(g_mem, ST_FREE_RING, &arg, 1, STACK_TOP, 0, regs))
                return 0;
            continue;
        }
        {
            const unsigned k = out->gets++;
            const uint32_t args[2] = {c->addr_out, c->head_out};
            out->hle_ran[k] = 0;
            if (leg == LEG_DIRECT) {
                out->ok[k] = get_direct(c, out->regs[k], &out->hle_ran[k]);
                if (out->ok[k] < 0) return -1;
            } else {
                out->ok[k] = musashi_native_lane_reference_call_regs(
                    g_mem, ST_GET_NEXT, args, 2, STACK_TOP, leg == LEG_LANE, out->regs[k]);
            }
            out->hash[k] = hash_state();
            last_ready = out->ok[k] && out->regs[k][2] == 0u;
        }
    }
    memcpy(g_final_ram[leg], g_mem->bytes, MUSASHI_RAM_SIZE);
    memcpy(g_final_scratch[leg], g_mem->scratchpad, MUSASHI_SCRATCHPAD_SIZE);
    return 1;
}

static const char *kLegName[LEGS] = {"interp", "lane", "direct"};

static int compare(const Case *c, const Leg *ref, const Leg *got, int leg) {
    unsigned k, i, shown = 0;
    if (got->gets != ref->gets) return 0;
    for (k = 0; k < ref->gets; ++k) {
        if (got->ok[k] != ref->ok[k]) {
            fprintf(stderr, "stgetnext: %s GET %u: %s completed=%d interp completed=%d\n",
                    c->name, k, kLegName[leg], got->ok[k], ref->ok[k]);
            return 0;
        }
        for (i = 1; i < 32; ++i)
            if (got->regs[k][i] != ref->regs[k][i]) {
                fprintf(stderr, "stgetnext: %s GET %u: %s r%u=%08x interp=%08x\n", c->name, k,
                        kLegName[leg], i, got->regs[k][i], ref->regs[k][i]);
                return 0;
            }
        if (got->hash[k] != ref->hash[k]) {
            fprintf(stderr, "stgetnext: %s GET %u: %s guest RAM differs from interp\n", c->name, k,
                    kLegName[leg]);
            break;
        }
    }
    for (i = 0; i < MUSASHI_RAM_SIZE; ++i)
        if (g_final_ram[leg][i] != g_final_ram[LEG_INTERP][i] && shown++ < 8)
            fprintf(stderr, "stgetnext: %s: %s RAM %08x=%02x interp=%02x\n", c->name, kLegName[leg],
                    0x80000000u + i, g_final_ram[leg][i], g_final_ram[LEG_INTERP][i]);
    for (i = 0; i < MUSASHI_SCRATCHPAD_SIZE; ++i)
        if (g_final_scratch[leg][i] != g_final_scratch[LEG_INTERP][i] && shown++ < 8)
            fprintf(stderr, "stgetnext: %s: %s scratchpad %03x=%02x interp=%02x\n", c->name,
                    kLegName[leg], i, g_final_scratch[leg][i], g_final_scratch[LEG_INTERP][i]);
    return !shown && k == ref->gets;
}

static void run_case(const Case *c) {
    static Leg legs[LEGS];
    const uint32_t salt = 0x9E3779B9u * (g_cases + 1u);
    unsigned k;
    int leg, good = 1;
    g_cases++;
    for (leg = 0; leg < LEGS; ++leg) {
        int r;
        if (leg == LEG_LANE && !g_have_lane) continue;
        r = run_leg(c, salt, leg, &legs[leg]);
        if (r <= 0) {
            fprintf(stderr, "stgetnext: %s: %s leg %s\n", c->name, kLegName[leg],
                    r < 0 ? "HLE refusal changed state" : "FREE step not completed");
            good = 0;
        }
    }
    if (good) {
        for (leg = 1; leg < LEGS; ++leg) {
            if (leg == LEG_LANE && !g_have_lane) continue;
            if (!compare(c, &legs[LEG_INTERP], &legs[leg], leg)) good = 0;
        }
    }
    for (k = 0; good && k < legs[LEG_DIRECT].gets; ++k) {
        const int ran = legs[LEG_DIRECT].hle_ran[k];
        if (c->expect_refusal ? ran : (!ran && legs[LEG_INTERP].ok[k])) {
            fprintf(stderr, "stgetnext: %s GET %u: HLE %s\n", c->name, k,
                    ran ? "ran where a refusal was expected" : "refused a state the retail code completes");
            good = 0;
        }
        if (ran) {
            g_hle_calls++;
            if (legs[LEG_DIRECT].regs[k][2] == 0) g_ready_paths++;
            else g_notready_paths++;
            if (legs[LEG_DIRECT].regs[k][1] == 0x800C0000u) g_wrap_paths++;
        }
    }
    g_gets += legs[LEG_INTERP].gets;
    g_refusal_cases += c->expect_refusal != 0;
    if (!good) g_bad++;
    if (getenv("STGETNEXT_PROBE_VERBOSE") || !good)
        printf("stgetnext: %-28s gets=%u first: retail_completed=%d v0=%08x hle_ran=%d -> %s\n",
               c->name, legs[LEG_INTERP].gets, legs[LEG_INTERP].ok[0], legs[LEG_INTERP].regs[0][2],
               legs[LEG_DIRECT].hle_ran[0], good ? "same" : "DIFFERENT");
}

/* ---- case builders --------------------------------------------------- */

static Case *ring(Case *c, const char *name, uint32_t base, uint32_t size, uint32_t index) {
    memset(c, 0, sizeof *c);
    c->name = name;
    c->base = base;
    c->size = size;
    c->index = index;
    c->addr_out = OUT;
    c->head_out = OUT + 4u;
    c->nslots = size < MAX_SLOTS ? size : MAX_SLOTS;
    return c;
}
static void frame(Case *c, unsigned slot, unsigned sectors) {
    c->status[slot] = 2;
    c->count[slot] = (uint16_t)sectors;
}
static void step(Case *c, StepKind kind, unsigned slot, unsigned value) {
    if (c->nsteps < MAX_STEPS) c->steps[c->nsteps++] = (Step){kind, (uint16_t)slot, (uint16_t)value};
}
static void gets(Case *c, unsigned n) { while (n--) step(c, GET, 0, 0); }

static void named_cases(void) {
    static Case c;
    static const uint16_t odd_status[] = {3, 5, 6, 0x00FF, 0x0102, 0x0201, 0x8002, 0x8001, 0xFFFF};
    static const char *const odd_name[] = {"status-3", "status-5", "status-6", "status-00ff",
                                           "status-0102", "status-0201", "status-8002",
                                           "status-8001", "status-ffff"};
    unsigned i;

    run_case((ring(&c, "empty-ring", ARENA, 16, 0), gets(&c, 4), &c));
    run_case((ring(&c, "empty-ring-mid-index", ARENA, 16, 9), gets(&c, 2), &c));

    ring(&c, "one-ready-frame", ARENA, 16, 0);
    frame(&c, 0, 1);
    gets(&c, 2);                          /* ready, then taken (4) = not ready */
    step(&c, FREE, 0, 0);
    gets(&c, 2);                          /* freed slot 1 is empty */
    run_case(&c);

    ring(&c, "one-ready-frame-mid", ARENA, 32, 7);
    frame(&c, 7, 3);
    gets(&c, 1);
    step(&c, FREE, 0, 0);
    gets(&c, 1);
    run_case(&c);

    ring(&c, "several-frames", ARENA, 16, 0);
    frame(&c, 0, 3); frame(&c, 3, 2); frame(&c, 5, 4); frame(&c, 9, 1);
    for (i = 0; i < 4; ++i) { gets(&c, 1); step(&c, FREE, 0, 0); }
    gets(&c, 3);
    run_case(&c);

    /* The game's consumption pattern across the ring end: frames up to a wrap
     * marker, the interrupt refilling slot 0 meanwhile. */
    ring(&c, "wrap-sequence", ARENA, 16, 8);
    frame(&c, 8, 3); frame(&c, 11, 3); c.status[14] = 1;
    gets(&c, 1); step(&c, FREE, 0, 0);
    gets(&c, 1); step(&c, FREE, 0, 0);
    gets(&c, 2);                          /* marker -> slot 0, not filled yet */
    step(&c, SET, 0, 0);
    c.count[0] = 2;
    step(&c, SET, 0, 2);
    gets(&c, 1); step(&c, FREE, 0, 0);
    gets(&c, 1);
    run_case(&c);

    ring(&c, "wrap-end0-slot0-ready", ARENA, 16, 13);
    c.status[13] = 1; frame(&c, 0, 2);
    gets(&c, 2);
    run_case(&c);

    ring(&c, "wrap-endset-slot0-ready", ARENA, 16, 13);
    c.end = 120; c.status[13] = 1; frame(&c, 0, 2);
    gets(&c, 2);
    run_case(&c);

    ring(&c, "wrap-end0-slot0-empty", ARENA, 16, 15);
    c.status[15] = 1;
    gets(&c, 3);
    run_case(&c);

    ring(&c, "wrap-endset-slot0-empty", ARENA, 16, 15);
    c.end = 1; c.status[15] = 1;
    gets(&c, 3);
    run_case(&c);

    ring(&c, "wrap-endset-slot0-taken", ARENA, 16, 4);
    c.end = 0xFFFFFFFFu; c.status[4] = 1; c.status[0] = 4;
    gets(&c, 2);
    run_case(&c);

    ring(&c, "wrap-marker-at-slot0-end0", ARENA, 16, 0);
    c.status[0] = 1;
    gets(&c, 3);
    run_case(&c);

    ring(&c, "wrap-marker-at-slot0-endset", ARENA, 16, 0);
    c.end = 5; c.status[0] = 1;
    gets(&c, 3);
    run_case(&c);

    ring(&c, "wrap-slot0-marker-too", ARENA, 16, 6);
    c.status[6] = 1; c.status[0] = 1;   /* the re-read slot 0 is a marker as well */
    gets(&c, 3);
    run_case(&c);

    /* A frame still filling: its first header is not 2 yet even though
     * later sectors have landed; then the interrupt completes it. */
    ring(&c, "partial-frame", ARENA, 16, 2);
    c.status[3] = 2; c.status[4] = 2; c.count[2] = 3;
    gets(&c, 3);
    step(&c, SET, 2, 2);
    gets(&c, 1);
    step(&c, FREE, 0, 0);
    gets(&c, 1);
    run_case(&c);

    /* The polling loop at 0x800D27C4 spins here (up to 0x8000 tries). */
    ring(&c, "not-ready-spin-taken", ARENA, 16, 5);
    c.status[5] = 4; c.count[5] = 2;
    gets(&c, 100);
    run_case(&c);

    for (i = 0; i < sizeof odd_status / sizeof odd_status[0]; ++i) {
        ring(&c, odd_name[i], ARENA, 16, 3);
        c.status[3] = odd_status[i];
        gets(&c, 2);
        run_case(&c);
    }

    ring(&c, "ring-size-1", ARENA, 1, 0);
    frame(&c, 0, 1);
    gets(&c, 1); step(&c, FREE, 0, 0); gets(&c, 1);
    run_case(&c);

    ring(&c, "large-ring-last-slot", ARENA, 255, 254);
    c.nslots = 0;
    step(&c, SET, 254, 2);
    gets(&c, 2);
    run_case(&c);

    ring(&c, "index-beyond-size", ARENA, 8, 40);
    c.nslots = 0;
    step(&c, SET, 40, 2);
    gets(&c, 1);
    run_case(&c);

    /* index << 5 and index * 2016 wrap at 32 bits (0x08000001 << 5 = 0x20). */
    ring(&c, "index-32bit-wrap", ARENA, 16, 0x08000001u);
    frame(&c, 1, 1);
    gets(&c, 1);
    run_case(&c);

    ring(&c, "ring-kseg1", 0xA0180000u, 16, 2);
    frame(&c, 2, 1);
    gets(&c, 2);
    run_case(&c);

    ring(&c, "ring-kuseg", 0x00180000u, 16, 2);
    c.status[2] = 1; frame(&c, 0, 1);
    gets(&c, 2);
    run_case(&c);

    ring(&c, "outputs-kseg1", ARENA, 16, 0);
    frame(&c, 0, 1);
    c.addr_out = 0xA01FDFF0u; c.head_out = 0xA01FDFF4u;
    gets(&c, 1);
    run_case(&c);

    ring(&c, "ring-and-outputs-scratchpad", 0x1F800000u, 8, 1);
    frame(&c, 1, 1);
    c.addr_out = 0x1F800200u; c.head_out = 0x1F800204u;
    gets(&c, 2);
    run_case(&c);

    ring(&c, "outputs-alias-each-other", ARENA, 16, 0);
    frame(&c, 0, 1);
    c.head_out = c.addr_out;              /* *header lands last */
    gets(&c, 1);
    run_case(&c);

    ring(&c, "header-out-onto-own-slot", ARENA, 16, 3);
    frame(&c, 3, 1);
    c.head_out = ARENA + 3u * 32u;        /* overwrites the status just set to 4 */
    gets(&c, 2);
    run_case(&c);

    ring(&c, "addr-out-onto-read-index", ARENA, 16, 3);
    frame(&c, 3, 1);
    c.addr_out = READ_INDEX;
    gets(&c, 1);
    run_case(&c);

    ring(&c, "outputs-null-ready", ARENA, 16, 0);
    frame(&c, 0, 1);
    c.addr_out = 0; c.head_out = 4;       /* low RAM: retail writes there */
    gets(&c, 1);
    run_case(&c);

    ring(&c, "outputs-wild-not-ready", ARENA, 16, 0);
    c.addr_out = 0x1F000000u; c.head_out = 0xFFFF0001u;   /* never written */
    gets(&c, 2);
    run_case(&c);

    /* Refusals: the retail code would fault (address error or a bus access
     * outside RAM) or read globals it just changed. The HLE must refuse with
     * nothing written; the lane leg then interprets the retail code. */
    ring(&c, "refuse-addr-out-misaligned", ARENA, 16, 0);
    frame(&c, 0, 1);
    c.addr_out = OUT + 2u; c.expect_refusal = 1;
    gets(&c, 1);
    run_case(&c);

    ring(&c, "refuse-head-out-misaligned", ARENA, 16, 0);
    frame(&c, 0, 1);
    c.head_out = OUT + 5u; c.expect_refusal = 1;
    gets(&c, 1);
    run_case(&c);

    ring(&c, "refuse-addr-out-io", ARENA, 16, 0);
    frame(&c, 0, 1);
    c.addr_out = 0x1F801000u; c.expect_refusal = 1;
    gets(&c, 1);
    run_case(&c);

    ring(&c, "refuse-head-out-kseg2", ARENA, 16, 0);
    frame(&c, 0, 1);
    c.head_out = 0xFFFE0130u; c.expect_refusal = 1;
    gets(&c, 1);
    run_case(&c);

    ring(&c, "refuse-ring-odd-base", ARENA + 1u, 4, 0);
    c.nslots = 0; c.expect_refusal = 1;
    gets(&c, 1);
    run_case(&c);

    ring(&c, "refuse-ring-mirror", 0x80200000u + ARENA - 0x80000000u, 4, 0);
    c.nslots = 0; c.expect_refusal = 1;
    gets(&c, 1);
    run_case(&c);

    /* A ring header slot on top of the library globals (StSetRing given a
     * pointer into its own variables): left to the retail code. */
    ring(&c, "refuse-slot-on-globals", READ_INDEX - 3u * 32u, 8, 3);
    c.nslots = 0; c.expect_refusal = 1;
    gets(&c, 1);
    run_case(&c);
}

/* Random ring states and scripts: statuses drawn from the values the
 * library uses plus arbitrary halfwords, random end frames, indices,
 * segments and output placements. */
static void fuzz_cases(unsigned n) {
    static Case c;
    static const uint16_t pick[] = {0, 0, 1, 2, 2, 2, 4, 4};
    unsigned k, i;
    uint32_t state = 0xC0FFEEu;
    for (k = 0; k < n; ++k) {
        uint32_t size, base, v;
        rng_state = state;
        v = rng(); state = rng_state;
        size = 1u + v % MAX_SLOTS;
        base = (ARENA + 0x40u * (rng() % 0x400u)) & ~3u;
        if (k % 7 == 3) base = (base & 0x1FFFFFFFu) | 0xA0000000u;
        if (k % 11 == 5) base = base & 0x1FFFFFFFu;
        ring(&c, "fuzz", base, size, rng() % (size + (k % 5 == 0 ? 4u : 0u)));
        c.end = (rng() & 1u) ? 0u : rng() % 600u;
        for (i = 0; i < c.nslots; ++i) {
            c.status[i] = (rng() % 16u == 0) ? (uint16_t)rng() : pick[rng() % 8u];
            c.count[i] = (uint16_t)(1u + rng() % 4u);
        }
        if (k % 13 == 6) c.head_out = c.addr_out;
        if (k % 17 == 8) c.addr_out = base + 32u * (rng() % size);
        for (i = 0; i < 12u; ++i) {
            const uint32_t roll = rng() % 8u;
            if (roll < 4u) step(&c, GET, 0, 0);
            else if (roll < 6u) step(&c, SET, rng() % size, pick[rng() % 8u]);
            else { step(&c, GET, 0, 0); step(&c, FREE, 0, 0); }
        }
        run_case(&c);
    }
}

int main(int argc, char **argv) {
    FILE *file;
    uint8_t *exe;
    size_t exe_size;
    int leg;
    const char *fuzz = getenv("STGETNEXT_PROBE_FUZZ");
    if (argc != 2) {
        fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]);
        return 2;
    }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "stgetnext: EXE unavailable; NOT_RUN\n"); return 77; }
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
    if (!g_mem) {
        fprintf(stderr, "stgetnext: host window at 0x80000000 unavailable; NOT_RUN\n");
        return 77;
    }
    if (!musashi_boot_map_exe(g_mem, exe, exe_size)) {
        fprintf(stderr, "stgetnext: pinned EXE rejected\n");
        return 1;
    }
    bfm_psyq_set_ram(g_mem->bytes, MUSASHI_RAM_SIZE);
    bfm_psyq_set_scratchpad(g_mem->scratchpad);
#ifdef PSYQ_PROBE_WITH_LANE
    {
        size_t count = 0, i;
        MusashiNativeLaneEntry *table = musashi_native_lane_psyq_merge(NULL, 0, MUSASHI_PSYQ_LANE_PURE, &count);
        for (i = 0; table && i < count; ++i) g_have_lane |= table[i].guest_pc == ST_GET_NEXT;
        if (!table || !g_have_lane) {
            fprintf(stderr, "stgetnext: StGetNext is not a pure lane entry\n");
            return 1;
        }
        musashi_native_lane_psyq_bind(g_mem, NULL);
        if (musashi_native_lane_install(table, count) < 0 || !musashi_native_lane_usable(g_mem)) {
            fprintf(stderr, "stgetnext: lane not usable\n");
            return 1;
        }
    }
#endif
    g_image = malloc(MUSASHI_RAM_SIZE);
    for (leg = 0; leg < LEGS; ++leg) g_final_ram[leg] = malloc(MUSASHI_RAM_SIZE);
    if (!g_image || !g_final_ram[0] || !g_final_ram[1] || !g_final_ram[2]) return 1;
    memcpy(g_image, g_mem->bytes, MUSASHI_RAM_SIZE);

    named_cases();
    fuzz_cases(fuzz ? (unsigned)strtoul(fuzz, NULL, 0) : 400u);

    printf("stgetnext: legs=%s cases=%u gets=%u hle_calls=%u (ready=%u not_ready=%u wrapped=%u) "
           "refusal_cases=%u different=%u -> %s\n",
           g_have_lane ? "interp,lane,direct" : "interp,direct", g_cases, g_gets, g_hle_calls,
           g_ready_paths, g_notready_paths, g_wrap_paths, g_refusal_cases, g_bad,
           g_bad ? "DIFFERS" : "same");
    return g_bad ? 1 : 0;
}
