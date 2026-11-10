/* Same-input differential of the host implementations of hand-assembly main
 * routines (pc_port/platform/psyq/psyq_psycross.c, "main-exe hand-assembly
 * host implementations") against the retail words run on the interpreter as a
 * test-only oracle from the developer's own EXE (extracted/disc/files/
 * SLUS_007.26; no retail bytes are compiled in or committed).
 *
 * 800249F0 (bfm_psyq_main_f3_nccs, TMD flat-shaded triangle emitter): every
 * case builds the same seeded scene (vertex, normal and primitive tables, an
 * ordering table with random old contents, a packet area) and the same GTE
 * bank (an identity-ish camera so a good share of the primitives survive the
 * FLAG and NCLIP culls), runs the retail routine on the interpreter over a real
 * gte_owner (test-only transfer adaptor), restores RAM and the bank, then runs
 * the host implementation through the production GTE bridge. Compared: v0,
 * the whole GTE data and control banks, and all of guest RAM outside the
 * callee's own stack scratch (the asm's 8-byte local frame). A probe that
 * never exercises the semi-transparent tail, the culls and a non-empty link
 * fails itself.
 *
 * Exit 0 when everything agrees; 1 on any difference; 77 when the EXE, the
 * host window at 0x80000000 or the lane library is unavailable. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_cpu_status.h"
#include "musashi_gte_owner.h"
#include "musashi_native_lane.h"
#include "musashi_native_lane_psyq.h"
#include "psyq/bfm_psyq_compat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bfm_psyq_main_f3_nccs(uint32_t *r);
int bfm_psyq_main_gt3(uint32_t *r);
int bfm_psyq_main_gt4(uint32_t *r);
int bfm_psyq_main_f4(uint32_t *r);
/* PsyCross's GTE bank; the owner's write profile has no light matrix (8..12). */
extern void CTC2(unsigned int value, int reg);

enum { STACK_TOP = 0x801fe000u, FRAME_GUARD = 0x10000u,
       VERT = 0x80190000u, NORM = 0x80190400u, PRIM = 0x80190800u,
       PKT = 0x801A0000u, OT = 0x801A1000u, OT_WORDS = 1024u, NVERT = 48u, NNORM = 16u,
       FLAG_ADDR = 0x800A2B78u };

static MusashiBootMemory *g_mem;
static uint8_t *g_image, *g_ram_interp, *g_start;
static MusashiCpuStatus *g_status;
static MusashiGteOwner g_owner;
static const int g_identity;
static const uint32_t g_gpr[32];
typedef struct {
    const char *name; uint32_t pc; unsigned nargs; int (*fn)(uint32_t *r);
    unsigned prim_stride, nnorm, semi_second; /* semi_second: second packet of 8 bytes behind the first */
    uint32_t packet_size; int kind;           /* 0 F3, 1 F4, 2 GT3, 3 GT4 */
} Routine;
static const Routine g_routines[] = {
    {"800249F0 F3", 0x800249F0u, 7, bfm_psyq_main_f3_nccs, 16, 1, 1, 20, 0},
    {"80027200 F4", 0x80027200u, 7, bfm_psyq_main_f4, 20, 0, 1, 24, 1},
    {"80026514 GT3", 0x80026514u, 8, bfm_psyq_main_gt3, 20, 3, 0, 40, 2},
    {"800268D0 GT4", 0x800268D0u, 8, bfm_psyq_main_gt4, 24, 4, 0, 52, 3},
};
static uint32_t g_pc;
static uint32_t rng_state = 1u;
static unsigned g_bad, g_cases, g_linked, g_semi, g_culled, g_empty;

static uint32_t rng(void) {
    rng_state ^= rng_state << 13; rng_state ^= rng_state >> 17; rng_state ^= rng_state << 5;
    return rng_state;
}
static uint64_t thread_token(void *u) { (void)u; return 1u; }
static MusashiCpuContext lease_ctx(void) {
    MusashiCpuContext c;
    memset(&c, 0, sizeof c);
    c.identity = &g_identity; c.gpr = g_gpr;
    c.pc = g_pc; c.npc = g_pc + 4u; c.instruction = 0x4884F000u;
    c.instruction_valid = 1; c.provenance = MUSASHI_CPU_CONTEXT_SOURCE;
    return c;
}
static MusashiCpuContext as_lease(const MusashiCpuContext *c) { MusashiCpuContext x = *c; x.identity = &g_identity; return x; }
static int t_write_data(void *u, const MusashiCpuContext *c, uint32_t s, uint32_t v) { MusashiCpuContext x = as_lease(c); (void)u; return musashi_gte_owner_write_data(&g_owner, &x, s, v); }
static int t_read_data(void *u, const MusashiCpuContext *c, uint32_t s, uint32_t *v) { MusashiCpuContext x = as_lease(c); (void)u; return musashi_gte_owner_read_data(&g_owner, &x, s, v); }
static int t_write_control(void *u, const MusashiCpuContext *c, uint32_t s, uint32_t v) { MusashiCpuContext x = as_lease(c); (void)u; return musashi_gte_owner_write_control(&g_owner, &x, s, v); }
static int t_read_control(void *u, const MusashiCpuContext *c, uint32_t s, uint32_t *v) { MusashiCpuContext x = as_lease(c); (void)u; return musashi_gte_owner_read_control(&g_owner, &x, s, v); }
static int t_command(void *u, const MusashiCpuContext *c, uint32_t w) { MusashiCpuContext x = as_lease(c); (void)u; return musashi_gte_owner_command(&g_owner, &x, w); }
static const MusashiCpuTransferDevice g_transfer = {
    .write_control = t_write_control, .write_data = t_write_data, .read_data = t_read_data,
    .read_control = t_read_control, .command = t_command};

static void w32(uint32_t a, uint32_t v) { musashi_boot_write32(g_mem, a, v); }
static uint32_t r32(const uint8_t *ram, uint32_t a) {
    const uint8_t *p = ram + (a - 0x80000000u);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w16(uint32_t a, uint32_t v) { uint8_t *p = g_mem->bytes + (a - 0x80000000u); p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); }

/* Camera: identity rotation, translation in front of the screen, H = 500,
 * light matrix and colour matrix random but modest, so NCCS gives varied colours. */
static int seed_gte(uint32_t salt) {
    MusashiCpuContext c = lease_ctx();
    uint32_t k;
    rng_state = salt | 1u;
    {
        static const uint32_t data_sel[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 19, 20, 21, 22};
        for (k = 0; k < sizeof data_sel / sizeof data_sel[0]; ++k)
            if (!musashi_gte_owner_write_data(&g_owner, &c, data_sel[k], rng() & 0x0FFFu)) return 0;
    }
    if (!musashi_gte_owner_write_control(&g_owner, &c, 0, 0x00001000u)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 1, 0)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 2, 0x00001000u)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 3, 0)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 4, 0x1000u)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 5, (rng() % 400u) - 200u)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 6, (rng() % 400u) - 200u)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 7, 600u + rng() % 1500u)) return 0;
    for (k = 8; k <= 12u; ++k) CTC2(((rng() % 0x1800u) << 16) | (rng() % 0x1800u), (int)k);
    for (k = 13; k <= 15u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, rng() % 0x800u)) return 0;
    for (k = 16; k <= 20u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, ((rng() % 0x1800u) << 16) | (rng() % 0x1800u))) return 0;
    for (k = 21; k <= 23u; ++k)
        if (!musashi_gte_owner_write_control(&g_owner, &c, k, rng() % 0x1000u)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 24, 160u << 16)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 25, 120u << 16)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 26, 500u)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 27, 0)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 28, 0)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 29, 0x155u)) return 0;
    if (!musashi_gte_owner_write_control(&g_owner, &c, 30, 0x100u)) return 0;
    return 1;
}

typedef struct { uint32_t n, shift, flag; } Params;

static Params build_scene(uint32_t salt, unsigned idx, const Routine *rt) {
    static const uint32_t counts[] = {0, 1, 2, 5, 8, 16, 24, 32};
    Params p;
    uint32_t a, i;
    memcpy(g_mem->bytes, g_image, MUSASHI_RAM_SIZE);
    rng_state = (salt * 2654435761u) | 1u;
    p.n = counts[idx % 8u];
    p.shift = idx % 3u;
    p.flag = (idx & 4u) ? 1u + rng() % 7u : 0u;
    w32(FLAG_ADDR, p.flag);
    for (i = 0; i < NVERT; ++i) {
        /* a few vertices behind the camera or far outside (flag culls) */
        int32_t x = (int32_t)(rng() % 900u) - 450, y = (int32_t)(rng() % 900u) - 450;
        int32_t z = (rng() % 11u == 0) ? -(int32_t)(rng() % 3000u) : (int32_t)(rng() % 1800u);
        if (rng() % 17u == 0) x *= 40;
        w16(VERT + 8u * i, (uint32_t)x); w16(VERT + 8u * i + 2u, (uint32_t)y);
        w16(VERT + 8u * i + 4u, (uint32_t)z); w16(VERT + 8u * i + 6u, 0);
    }
    for (i = 0; i < NNORM; ++i) {
        w16(NORM + 8u * i, (rng() % 0x2000u) - 0x1000u); w16(NORM + 8u * i + 2u, (rng() % 0x2000u) - 0x1000u);
        w16(NORM + 8u * i + 4u, (rng() % 0x2000u) - 0x1000u); w16(NORM + 8u * i + 6u, 0);
    }
    for (i = 0; i < 32u; ++i) {
        uint32_t o = PRIM + 24u * i, k;
        w32(o, 0x24000403u | (rng() & 0xFF00u));
        w32(o + 4u, (rng() & 0x00FFFFFFu) | ((rng() & 1u ? 0x20u : 0x24u) | (rng() & 2u)) << 24);
        switch (rt->kind) {
        case 0: w16(o + 8u, rng() % NNORM); for (k = 0; k < 3u; ++k) w16(o + 10u + 2u * k, rng() % NVERT); break;
        case 1: for (k = 0; k < 4u; ++k) w16(o + 10u + 2u * k, rng() % NVERT); break;
        default:
            for (k = 0; k < rt->nnorm; ++k) { w16(o + 8u + 4u * k, rng() % NNORM); w16(o + 10u + 4u * k, rng() % NVERT); }
            break;
        }
    }
    /* texture tables (0x80063884.. / 0x8006389C..) and the U/V bias byte */
    for (a = 0x80063884u; a < 0x800638B0u; a += 4u) w32(a, rng());
    musashi_boot_write32(g_mem, 0x800B99D8u, rng());
    for (a = 0; a < OT_WORDS; ++a) w32(OT + 4u * a, rng());
    for (a = 0; a < 0x800u; a += 4u) w32(PKT + a, rng());
    return p;
}

static int same_bank(const MusashiGteSnapshot *a, const MusashiGteSnapshot *b, const char *name) {
    unsigned i, bad = 0;
    for (i = 0; i < MUSASHI_GTE_DATA_COUNT; ++i)
        if (a->data[i] != b->data[i]) { fprintf(stderr, "main_hostasm: %s data[%u] host=%08x retail=%08x\n", name, i, a->data[i], b->data[i]); bad = 1; }
    for (i = 0; i < MUSASHI_GTE_CONTROL_COUNT; ++i)
        if (a->control[i] != b->control[i]) { fprintf(stderr, "main_hostasm: %s control[%u] host=%08x retail=%08x\n", name, i, a->control[i], b->control[i]); bad = 1; }
    return !bad;
}

static void run_case(const Routine *rt, unsigned idx) {
    const uint32_t salt = 0x9E3779B9u * (idx + 1u);
    Params p;
    uint32_t args[8], regs[32], r[32], retail_v0, host_v0, a;
    MusashiGteSnapshot s_ret, s_host;
    const uint32_t lo = STACK_TOP - FRAME_GUARD - 0x80000000u, hi = STACK_TOP + 0x30u - 0x80000000u;
    int ok, differ = 0;
    g_cases++;
    g_pc = rt->pc;
    p = build_scene(salt, idx, rt);
    memcpy(g_start, g_mem->bytes, MUSASHI_RAM_SIZE);
    if (!seed_gte(salt)) { fprintf(stderr, "main_hostasm: case %u seed refused\n", idx); g_bad++; return; }
    args[0] = PRIM; args[1] = VERT; args[2] = NORM; args[3] = PKT; args[4] = p.n; args[5] = p.shift; args[6] = OT; args[7] = (idx % 5u) ? (idx % 4u) : 0u;
    ok = musashi_native_lane_reference_call_transfer(g_mem, rt->pc, args, rt->nargs, STACK_TOP, 0, regs, NULL, &g_transfer);
    if (!ok || !musashi_gte_owner_snapshot(&g_owner, &s_ret)) {
        fprintf(stderr, "main_hostasm: case %u retail run refused\n", idx); g_bad++; return;
    }
    retail_v0 = regs[2];
    memcpy(g_ram_interp, g_mem->bytes, MUSASHI_RAM_SIZE);
    memcpy(g_mem->bytes, g_start, MUSASHI_RAM_SIZE);
    if (!seed_gte(salt)) { g_bad++; return; }
    memset(r, 0, sizeof r);
    r[4] = args[0]; r[5] = args[1]; r[6] = args[2]; r[7] = args[3];
    r[29] = STACK_TOP;
    w32(STACK_TOP + 16u, args[4]); w32(STACK_TOP + 20u, args[5]); w32(STACK_TOP + 24u, args[6]); w32(STACK_TOP + 28u, args[7]);
    if (!rt->fn(r) || !musashi_gte_owner_snapshot(&g_owner, &s_host)) {
        fprintf(stderr, "main_hostasm: case %u host implementation refused\n", idx); g_bad++; return;
    }
    host_v0 = r[2];
    if (host_v0 != retail_v0) { fprintf(stderr, "main_hostasm: %s case %u v0 host=%08x retail=%08x\n", rt->name, idx, host_v0, retail_v0); differ = 1; }
    if (!same_bank(&s_host, &s_ret, rt->name)) differ = 1;
    for (a = 0; a < MUSASHI_RAM_SIZE; ++a) {
        if (a >= lo && a < hi) continue;
        if (g_mem->bytes[a] != g_ram_interp[a]) {
            if (differ < 6) fprintf(stderr, "main_hostasm: case %u (n=%u shift=%u flag=%u) RAM %08x host=%02x retail=%02x\n",
                                    idx, p.n, p.shift, p.flag, 0x80000000u + a, g_mem->bytes[a], g_ram_interp[a]);
            differ++;
        }
    }
    if (differ) { g_bad++; return; }
    if (p.n == 0) g_empty++;
    if (host_v0 > PKT) g_linked++;
    if ((host_v0 - PKT) % rt->packet_size) g_semi++;
    if (p.n && host_v0 == PKT) g_culled++;
}

int main(int argc, char **argv) {
    FILE *file;
    uint8_t *exe;
    size_t exe_size;
    unsigned i, r, cases = 96;
    if (argc != 2) { fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]); return 2; }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "main_hostasm: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, file) : 0;
    fclose(file);
    g_mem = musashi_native_lane_map_guest(sizeof(*g_mem), NULL);
    if (!g_mem) { fprintf(stderr, "main_hostasm: host window unavailable; NOT_RUN\n"); return 77; }
    if (!musashi_boot_map_exe(g_mem, exe, exe_size)) { fprintf(stderr, "main_hostasm: EXE rejected\n"); return 1; }
    g_image = malloc(MUSASHI_RAM_SIZE); g_ram_interp = malloc(MUSASHI_RAM_SIZE); g_start = malloc(MUSASHI_RAM_SIZE);
    if (!g_image || !g_ram_interp || !g_start) return 1;
    memcpy(g_image, g_mem->bytes, MUSASHI_RAM_SIZE);
    if (!musashi_cpu_status_open(&g_status, thread_token, NULL) ||
        !musashi_gte_owner_init(&g_owner, g_status, thread_token, NULL, &g_identity)) {
        fprintf(stderr, "main_hostasm: no gte owner; NOT_RUN\n");
        return 77;
    }
    musashi_native_lane_psyq_bind(g_mem, &g_owner);
    for (r = 0; r < sizeof g_routines / sizeof g_routines[0]; ++r) {
        unsigned bad0 = g_bad;
        g_cases = g_linked = g_semi = g_culled = g_empty = 0;
        for (i = 0; i < cases; ++i) run_case(&g_routines[r], i);
        printf("main_hostasm: %s cases=%u bad=%u (n=0: %u, all culled: %u, linked: %u, with semi-transparent packets: %u)\n",
               g_routines[r].name, g_cases, g_bad - bad0, g_empty, g_culled, g_linked, g_semi);
        if (!g_empty || !g_culled || !g_linked || (g_routines[r].semi_second && !g_semi)) {
            fprintf(stderr, "main_hostasm: %s scenes did not exercise the empty/cull/link/semi-transparent paths; probe proves nothing\n", g_routines[r].name);
            return 1;
        }
    }
    return g_bad ? 1 : 0;
}
