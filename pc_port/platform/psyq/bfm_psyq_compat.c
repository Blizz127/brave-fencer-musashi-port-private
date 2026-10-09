/* Psy-Q compatibility layer: the table and the HLE wrappers.
 * Written from the PS1 hardware/packet formats and the documented Psy-Q API
 * behaviour; no Psy-Q code. See bfm_psyq_compat.h. */
#include "bfm_psyq_compat.h"
#include "../bfm_plat.h"
#include "../bfm_plat_widescreen.h"
#ifdef MUSASHI_STRICT_NATIVE
#include "../../include/musashi_strict.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- table ---------------------------------------------------------- */

#define BFM_PSYQ_FN_BFM_PSYQ_HLE(w) w
#define BFM_PSYQ_FN_BFM_PSYQ_STUB(w) bfm_psyq_stub
#define BFM_PSYQ_OK_BFM_PSYQ_HLE 1
#define BFM_PSYQ_OK_BFM_PSYQ_STUB 0
#ifdef BFM_PLAT_WITH_PSYCROSS
#define BFM_PSYQ_FN_BFM_PSYQ_PSYCROSS(w) w
#define BFM_PSYQ_OK_BFM_PSYQ_PSYCROSS 1
#else
#define BFM_PSYQ_FN_BFM_PSYQ_PSYCROSS(w) bfm_psyq_stub
#define BFM_PSYQ_OK_BFM_PSYQ_PSYCROSS 0
#endif
#define BFM_PSYQ_FN(st, w) BFM_PSYQ_FN_##st(w)
#define BFM_PSYQ_OK(st) BFM_PSYQ_OK_##st

static const BfmPsyqEntry table[] = {
#define BFM_PSYQ(pc, name, status, argc, returns, wrapper) \
    {pc, #name, status, argc, returns, BFM_PSYQ_OK(status), BFM_PSYQ_FN(status, wrapper)},
#include "bfm_psyq_compat.def"
#undef BFM_PSYQ
};

static BfmPsyqStats stats;

size_t bfm_psyq_table(const BfmPsyqEntry **out) {
    if (out) *out = table;
    return sizeof table / sizeof table[0];
}

const BfmPsyqEntry *bfm_psyq_find(uint32_t pc) {
    size_t lo = 0, hi = sizeof table / sizeof table[0];
    while (lo < hi) {                     /* the generator emits sorted PCs */
        size_t mid = (lo + hi) / 2;
        if (table[mid].pc < pc) lo = mid + 1;
        else hi = mid;
    }
    return lo < sizeof table / sizeof table[0] && table[lo].pc == pc ? &table[lo] : NULL;
}

int bfm_psyq_call(uint32_t pc, uint32_t *r) {
    const BfmPsyqEntry *e = bfm_psyq_find(pc);
    int ok;
    if (!e || !r) return 0;
    ok = e->fn(r);
#ifdef MUSASHI_STRICT_NATIVE
    /* Seam: psyq_refused. A wrapper that refuses (STUB, a held-back row, or
     * a PsyCross class compiled out) means the hybrid build would interpret
     * the retail entry; a strict build refuses visibly instead. */
    if (!ok) musashi_strict_abort("psyq_refused", e->name, pc);
#endif
    if (!ok) stats.refused++;
    return ok;
}

int bfm_psyq_stub(uint32_t *r) {
    (void)r;
    return 0;
}

/* ---- GTE bridge ----------------------------------------------------- */

static BfmPsyqGteBridge gte_bridge;
static int gte_have_bridge;
static int gte_in_call;

void bfm_psyq_set_gte_bridge(const BfmPsyqGteBridge *b) {
    gte_have_bridge = b && b->begin && b->end;
    if (gte_have_bridge) gte_bridge = *b;
    else memset(&gte_bridge, 0, sizeof gte_bridge);
}

int bfm_psyq_gte_begin(void) {
    if (!gte_have_bridge || gte_in_call) return 0;       /* no lease owner, or reentry */
    if (!gte_bridge.begin(gte_bridge.user)) return 0;
    gte_in_call = 1;
    return 1;
}

void bfm_psyq_gte_end(uint32_t commands) {
    if (!gte_in_call) return;
    gte_in_call = 0;
    gte_bridge.end(gte_bridge.user, commands);
}

int bfm_psyq_gte_lzc(uint32_t value, uint32_t *lzcr) {
    if (!gte_in_call || !gte_bridge.lzc || !lzcr) return 0;
    return gte_bridge.lzc(gte_bridge.user, value, lzcr);
}

/* ---- guest memory --------------------------------------------------- */

static uint8_t *ram;
static size_t ram_size;
static uint8_t *scratch;

void bfm_psyq_set_ram(void *phys0, size_t size) {
    ram = (uint8_t *)phys0;
    ram_size = size;
}

void bfm_psyq_set_scratchpad(void *base) { scratch = (uint8_t *)base; }

static BfmPsyqGuestCallFn guest_call_fn;
void bfm_psyq_set_guest_call(BfmPsyqGuestCallFn fn) { guest_call_fn = fn; }
int bfm_psyq_guest_call(uint32_t target, unsigned argc, const uint32_t *args, uint32_t *v0) {
    uint32_t ret;
    if (!guest_call_fn) return 0;
    ret = guest_call_fn(target, argc, args, NULL);
    if (v0) *v0 = ret;
    return 1;
}

void *bfm_psyq_ptr(uint32_t addr, uint32_t len) {
    uint32_t phys = addr & 0x1FFFFFFFu;
    if (phys >= 0x1F800000u && phys < 0x1F800400u) {
        if (!scratch || phys - 0x1F800000u + len > 0x400u) return NULL;
        return scratch + (phys - 0x1F800000u);
    }
    phys &= 0x1FFFFFu;
    if (!ram || (size_t)phys + len > ram_size) return NULL;
    return ram + phys;
}

static int rd32(uint32_t a, uint32_t *v) {
    uint8_t *p = (uint8_t *)bfm_psyq_ptr(a, 4);
    if (!p) return 0;
    *v = (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
    return 1;
}

static int wr32(uint32_t a, uint32_t v) {
    uint8_t *p = (uint8_t *)bfm_psyq_ptr(a, 4);
    if (!p) return 0;
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
    return 1;
}

static int16_t rd16s(const uint8_t *p) { return (int16_t)(uint16_t)(p[0] | (p[1] << 8)); }
static void wr16(uint8_t *p, uint16_t v) { p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); }

uint32_t bfm_psyq_arg(const uint32_t *r, unsigned n) {
    uint32_t v = 0;
    if (n < 4) return r[4 + n];
    rd32(r[29] + 0x10u + 4u * (n - 4u), &v);
    return v;
}

#define A(n) bfm_psyq_arg(r, n)
#define RET(v) (r[2] = (uint32_t)(v))

void bfm_psyq_stats(BfmPsyqStats *out) { if (out) *out = stats; }
void bfm_psyq_reset(void) { memset(&stats, 0, sizeof stats); }

/* ---- libgpu: packet helpers ----------------------------------------- */

int bfm_psyq_GetTPage(uint32_t *r) {
    uint32_t tp = A(0), abr = A(1), x = A(2), y = A(3);
    RET(((tp & 3u) << 7) | ((abr & 3u) << 5) | (((y & 0x1FFu) >> 8) << 4) | ((x & 0x3FFu) >> 6) |
        (((y & 0x200u) >> 9) << 11));
    return 1;
}

int bfm_psyq_GetClut(uint32_t *r) {
    RET(((A(1) & 0x1FFu) << 6) | ((A(0) & 0x3FFu) >> 4));
    return 1;
}

/* AddPrim(ot, p): p->tag = (p->len << 24) | (*ot & 0xFFFFFF); *ot = (*ot & 0xFF000000) | p */
int bfm_psyq_AddPrim(uint32_t *r) {
    uint32_t ot = A(0), p = A(1), ov, pv;
    if (!rd32(ot, &ov) || !rd32(p, &pv)) return 0;
    wr32(p, (pv & 0xFF000000u) | (ov & 0x00FFFFFFu));
    wr32(ot, (ov & 0xFF000000u) | (p & 0x00FFFFFFu));
    return 1;
}

/* CatPrim(p0, p1): p0's link points at p1 */
int bfm_psyq_CatPrim(uint32_t *r) {
    uint32_t p0 = A(0), v;
    if (!rd32(p0, &v)) return 0;
    wr32(p0, (v & 0xFF000000u) | (A(1) & 0x00FFFFFFu));
    return 1;
}

/* SetSemiTrans(p, abe): code bit 1 of the command byte (tag + 7) */
int bfm_psyq_SetSemiTrans(uint32_t *r) {
    uint8_t *code = (uint8_t *)bfm_psyq_ptr(A(0) + 7u, 1);
    if (!code) return 0;
    if (A(1)) *code |= 2u; else *code &= (uint8_t)~2u;
    return 1;
}

/* setlen(p, len) = byte 3 of the tag; setcode(p, code) = byte 7 */
static int set_header(uint32_t *r, uint8_t len, uint8_t code) {
    uint8_t *p = (uint8_t *)bfm_psyq_ptr(A(0), 8);
    if (!p) return 0;
    p[3] = len;
    p[7] = code;
    return 1;
}

int bfm_psyq_SetPolyF3(uint32_t *r) { return set_header(r, 4, 0x20); }
int bfm_psyq_SetPolyFT3(uint32_t *r) { return set_header(r, 7, 0x24); }
int bfm_psyq_SetPolyG3(uint32_t *r) { return set_header(r, 6, 0x30); }
int bfm_psyq_SetPolyGT3(uint32_t *r) { return set_header(r, 9, 0x34); }
int bfm_psyq_SetPolyF4(uint32_t *r) { return set_header(r, 5, 0x28); }
int bfm_psyq_SetPolyFT4(uint32_t *r) { return set_header(r, 9, 0x2C); }
int bfm_psyq_SetPolyG4(uint32_t *r) { return set_header(r, 8, 0x38); }
int bfm_psyq_SetPolyGT4(uint32_t *r) { return set_header(r, 12, 0x3C); }
int bfm_psyq_SetLineF2(uint32_t *r) { return set_header(r, 3, 0x40); }
int bfm_psyq_SetLineG2(uint32_t *r) { return set_header(r, 4, 0x50); }

static int set_polyline(uint32_t *r, uint8_t len, uint8_t code, uint32_t term_off) {
    if (!set_header(r, len, code)) return 0;
    return wr32(A(0) + term_off, 0x55555555u);
}

/* LineG3 is GP0 0x58 (3-vertex gouraud polyline), LineG4 0x5C */
int bfm_psyq_SetLineG3(uint32_t *r) { return set_polyline(r, 7, 0x58, 7u * 4u); }
int bfm_psyq_SetLineG4(uint32_t *r) { return set_polyline(r, 9, 0x5C, 9u * 4u); }

/* SetDefDispEnv(env, x, y, w, h): disp = {x,y,w,h}, screen = 0, flags 0 */
int bfm_psyq_SetDefDispEnv(uint32_t *r) {
    uint8_t *e = (uint8_t *)bfm_psyq_ptr(A(0), 20);
    if (!e) return 0;
    memset(e, 0, 20);
    wr16(e + 0, (uint16_t)A(1)); wr16(e + 2, (uint16_t)A(2));
    wr16(e + 4, (uint16_t)A(3)); wr16(e + 6, (uint16_t)A(4));
    RET(A(0));
    return 1;
}

/* ClearOTagR(ot, n), following retail func_80059BFC:
 *   - at libgpu debug level >= 2 (u8 at 0x8007278A) it prints first, so
 *     refuse and let the retail code run;
 *   - the driver's OTC clear (DMA6) links ot[i] -> &ot[i-1] and ends ot[0]
 *     with 0x00FFFFFF;
 *   - ot[0] is then relinked to the static terminator primitive at
 *     0x80072844, as a 24-bit address.
 * Returns ot. n == 0 is left to the retail code (DMA6 BCR 0 semantics). */
#define PSYQ_GPU_DEBUG_LEVEL 0x8007278Au
#define PSYQ_OT_TERMINATOR   0x80072844u
int bfm_psyq_ClearOTagR(uint32_t *r) {
    uint32_t ot = A(0), n = A(1), i;
    const uint8_t *level = (const uint8_t *)bfm_psyq_ptr(PSYQ_GPU_DEBUG_LEVEL, 1);
    if (!level || *level >= 2u) return 0;
    if (n == 0 || n > 0x100000u || !bfm_psyq_ptr(ot, n * 4u)) return 0;
    for (i = 1; i < n; i++) wr32(ot + i * 4u, (ot + (i - 1u) * 4u) & 0x00FFFFFFu);
    wr32(ot, PSYQ_OT_TERMINATOR & 0x00FFFFFFu);
    RET(ot);
    return 1;
}

static int read_rect(uint32_t addr, BfmPlatRect *rc) {
    uint8_t *p = (uint8_t *)bfm_psyq_ptr(addr, 8);
    if (!p) return 0;
    rc->x = rd16s(p); rc->y = rd16s(p + 2); rc->w = rd16s(p + 4); rc->h = rd16s(p + 6);
    return bfm_plat_rect_valid(rc);
}

int bfm_psyq_LoadImage(uint32_t *r) {
    BfmPlatRect rc;
    uint8_t *src;
    uint16_t *px;
    size_t n, i;
    if (!read_rect(A(0), &rc)) return 0;
    n = (size_t)rc.w * (size_t)rc.h;
    src = (uint8_t *)bfm_psyq_ptr(A(1), (uint32_t)(n * 2u));
    if (!src) return 0;
    px = (uint16_t *)malloc(n * 2u);
    if (!px) return 0;
    for (i = 0; i < n; i++) px[i] = (uint16_t)(src[i * 2] | (src[i * 2 + 1] << 8));
    bfm_plat_renderer_upload_vram(&rc, px);
    free(px);
    RET(0);
    return 1;
}

/* 80059888 ClearImage(rect, r, g, b): the GPU fill (GP0 02) through the
 * renderer, with the fill's 16-pixel x/width granularity. Not a compat row:
 * the strict frame driver's HLE calls it (B27). */
int bfm_psyq_ClearImage(uint32_t *r) {
    BfmPlatRect rc;
    uint16_t *px, c;
    size_t n, i;
    if (!read_rect(A(0), &rc)) return 0;
    rc.x &= 0x3F0;
    rc.w = (int16_t)(((rc.w & 0x3FF) + 0xF) & ~0xF);
    if (rc.x + rc.w > 1024) rc.w = (int16_t)(1024 - rc.x);
    if (rc.w <= 0 || rc.h <= 0) { RET(0); return 1; }
    if (!bfm_plat_rect_valid(&rc)) return 0;
    c = (uint16_t)(((A(3) & 0xF8u) << 7) | ((A(2) & 0xF8u) << 2) | ((A(1) & 0xFFu) >> 3));
    n = (size_t)rc.w * (size_t)rc.h;
    px = (uint16_t *)malloc(n * 2u);
    if (!px) return 0;
    for (i = 0; i < n; i++) px[i] = c;
    bfm_plat_renderer_upload_vram(&rc, px);
    free(px);
    RET(0);
    return 1;
}

int bfm_psyq_StoreImage(uint32_t *r) {
    BfmPlatRect rc;
    uint8_t *dst;
    uint16_t *px;
    size_t n, i;
    if (!read_rect(A(0), &rc)) return 0;
    n = (size_t)rc.w * (size_t)rc.h;
    dst = (uint8_t *)bfm_psyq_ptr(A(1), (uint32_t)(n * 2u));
    px = (uint16_t *)malloc(n * 2u);
    if (!dst || !px) { free(px); return 0; }
    if (bfm_plat_renderer_download_vram(&rc, px) != BFM_PLAT_OK) { free(px); return 0; }
    for (i = 0; i < n; i++) { dst[i * 2] = (uint8_t)px[i]; dst[i * 2 + 1] = (uint8_t)(px[i] >> 8); }
    free(px);
    RET(0);
    return 1;
}

/* MoveImage(rect, x, y) */
int bfm_psyq_MoveImage(uint32_t *r) {
    BfmPlatRect rc, to;
    uint16_t *px;
    if (!read_rect(A(0), &rc)) return 0;
    to = rc;
    to.x = (int16_t)A(1);
    to.y = (int16_t)A(2);
    if (!bfm_plat_rect_valid(&to)) return 0;
    px = (uint16_t *)malloc((size_t)rc.w * (size_t)rc.h * 2u);
    if (!px) return 0;
    if (bfm_plat_renderer_download_vram(&rc, px) == BFM_PLAT_OK)
        bfm_plat_renderer_upload_vram(&to, px);
    free(px);
    RET(0);
    return 1;
}

int bfm_psyq_DrawSync(uint32_t *r) { RET(0); return 1; }
int bfm_psyq_SetDispMask(uint32_t *r) { (void)r; return 1; }

/* MUSASHI_TRACE_DRAWOTAG=N: log the Nth DrawOTag call (draw env in effect,
 * GP0 env words E1-E6 met in the OT, first prims' coordinates) and the
 * PutDrawEnv/PutDispEnv calls around it (N-2..N+1). Diagnostic only. */
static long g_ot_trace_at = -2, g_ot_calls;
static BfmPlatDrawEnv g_last_draw_env;
static int ot_trace_on(long call) {
    if (g_ot_trace_at == -2) {
        const char *e = getenv("MUSASHI_TRACE_DRAWOTAG");
        g_ot_trace_at = e ? atol(e) : -1;
    }
    return g_ot_trace_at > 0 && call >= g_ot_trace_at - 2 && call <= g_ot_trace_at + 1;
}

/* DRAWENV: RECT clip, short ofs[2], RECT tw, u16 tpage, u8 dtd, dfe, isbg, r0, g0, b0, DR_ENV */
int bfm_psyq_PutDrawEnv(uint32_t *r) {
    uint8_t *e = (uint8_t *)bfm_psyq_ptr(A(0), 28);
    BfmPlatDrawEnv d;
    if (!e) return 0;
    d.clip.x = rd16s(e); d.clip.y = rd16s(e + 2); d.clip.w = rd16s(e + 4); d.clip.h = rd16s(e + 6);
    d.offset_x = rd16s(e + 8); d.offset_y = rd16s(e + 10);
    d.texture_window.x = rd16s(e + 12); d.texture_window.y = rd16s(e + 14);
    d.texture_window.w = rd16s(e + 16); d.texture_window.h = rd16s(e + 18);
    d.tpage = (uint16_t)rd16s(e + 20);
    d.dither = e[22]; d.draw_on_display = e[23]; d.clear_bg = e[24];
    d.bg_r = e[25]; d.bg_g = e[26]; d.bg_b = e[27];
    if (ot_trace_on(g_ot_calls + 1))
        fprintf(stderr, "native_boot: OT_TRACE PutDrawEnv before_call=%ld clip=%d,%d,%d,%d ofs=%d,%d "
                "tw=%d,%d,%d,%d tpage=%04x dtd=%u dfe=%u isbg=%u bg=%u,%u,%u\n", g_ot_calls + 1,
                d.clip.x, d.clip.y, d.clip.w, d.clip.h, d.offset_x, d.offset_y,
                d.texture_window.x, d.texture_window.y, d.texture_window.w, d.texture_window.h,
                d.tpage, d.dither, d.draw_on_display, d.clear_bg, d.bg_r, d.bg_g, d.bg_b);
    g_last_draw_env = d;
    bfm_plat_renderer_set_draw_env(&d);
    RET(A(0));
    return 1;
}

/* DISPENV: RECT disp, RECT screen, u8 isinter, isrgb24, pad, pad */
int bfm_psyq_PutDispEnv(uint32_t *r) {
    uint8_t *e = (uint8_t *)bfm_psyq_ptr(A(0), 20);
    BfmPlatDispEnv d;
    if (!e) return 0;
    d.disp.x = rd16s(e); d.disp.y = rd16s(e + 2); d.disp.w = rd16s(e + 4); d.disp.h = rd16s(e + 6);
    d.screen.x = rd16s(e + 8); d.screen.y = rd16s(e + 10);
    d.screen.w = rd16s(e + 12); d.screen.h = rd16s(e + 14);
    d.interlaced = e[16]; d.rgb24 = e[17];
    if (ot_trace_on(g_ot_calls + 1))
        fprintf(stderr, "native_boot: OT_TRACE PutDispEnv before_call=%ld disp=%d,%d,%d,%d screen=%d,%d,%d,%d\n",
                g_ot_calls + 1, d.disp.x, d.disp.y, d.disp.w, d.disp.h,
                d.screen.x, d.screen.y, d.screen.w, d.screen.h);
    bfm_plat_renderer_set_disp_env(&d);
    RET(A(0));
    return 1;
}

/* ---- GP0 packet decoder --------------------------------------------- */

static void vtx(BfmPlatVertex *v, uint32_t xy) {
    v->x = (int16_t)(uint16_t)(xy & 0xFFFFu);
    v->y = (int16_t)(uint16_t)(xy >> 16);
}

static void col(BfmPlatVertex *v, uint32_t c) {
    v->r = (uint8_t)c; v->g = (uint8_t)(c >> 8); v->b = (uint8_t)(c >> 16);
}

static void uv(BfmPlatVertex *v, uint32_t w) {
    v->u = (uint8_t)w; v->v = (uint8_t)(w >> 8);
}

/* *tpage is the GP0 draw state carried across packets: bits 0-13 the E1
 * texpage, bit 14 E6 mask-set, bit 15 E6 mask-check. Every prim gets the
 * texpage in effect (untextured prims need its abr) and the mask flags. */
#define STATE_TPAGE(s) ((uint16_t)((s) & 0x3FFFu))
static uint8_t state_mask_flags(uint16_t s) {
    return (uint8_t)(((s & 0x4000u) ? BFM_PRIM_FLAG_MASK_SET : 0) |
                     ((s & 0x8000u) ? BFM_PRIM_FLAG_MASK_CHECK : 0));
}

size_t bfm_psyq_decode_packet(const uint32_t *w, size_t n, uint16_t *tpage,
                              BfmPlatPrim *out, size_t max) {
    size_t i = 0, count = 0;
    while (i < n && count < max) {
        uint32_t cmd = w[i];
        uint8_t code = (uint8_t)(cmd >> 24);
        BfmPlatPrim *p = &out[count];
        memset(p, 0, sizeof *p);
        if (code >= 0x20 && code < 0x40) {                 /* polygons */
            int gouraud = code & 0x10, quad = code & 0x08, tex = code & 0x04;
            unsigned nv = quad ? 4u : 3u, k;
            size_t need = 1 + nv * (1u + (tex ? 1u : 0u)) + (gouraud ? nv - 1u : 0u);
            if (i + need > n) break;
            p->kind = (uint8_t)(gouraud ? (tex ? (quad ? BFM_PRIM_POLY_GT4 : BFM_PRIM_POLY_GT3)
                                               : (quad ? BFM_PRIM_POLY_G4 : BFM_PRIM_POLY_G3))
                                        : (tex ? (quad ? BFM_PRIM_POLY_FT4 : BFM_PRIM_POLY_FT3)
                                               : (quad ? BFM_PRIM_POLY_F4 : BFM_PRIM_POLY_F3)));
            p->flags = (uint8_t)(((code & 2) ? BFM_PRIM_FLAG_SEMI_TRANS : 0) |
                                 ((tex && (code & 1)) ? BFM_PRIM_FLAG_RAW_TEXTURE : 0) |
                                 state_mask_flags(*tpage));
            p->tpage = STATE_TPAGE(*tpage);
            {
                size_t j = i + 1;
                for (k = 0; k < nv; k++) {
                    uint32_t c = (k == 0) ? cmd : (gouraud ? w[j++] : cmd);
                    col(&p->v[k], c);
                    vtx(&p->v[k], w[j++]);
                    if (tex) {
                        uv(&p->v[k], w[j]);
                        if (k == 0) p->clut = (uint16_t)(w[j] >> 16);
                        if (k == 1) p->tpage = (uint16_t)(w[j] >> 16);
                        j++;
                    }
                }
                i = j;
                /* a textured polygon's texpage becomes the current one */
                if (tex)
                    *tpage = (uint16_t)((*tpage & 0xC000u) | (p->tpage & 0x09FFu) |
                                        (*tpage & 0x3600u));
            }
            count++;
        } else if (code >= 0x40 && code < 0x60) {          /* lines */
            int gouraud = code & 0x10, poly = code & 0x08;
            BfmPlatVertex a, b;
            size_t j = i + 1;
            memset(&a, 0, sizeof a);
            memset(&b, 0, sizeof b);
            if (j >= n) break;
            col(&a, cmd);
            vtx(&a, w[j++]);
            for (;;) {
                uint32_t c = cmd;
                if (j >= n) break;
                if (poly && (w[j] & 0xF000F000u) == 0x50005000u) { j++; break; }
                if (gouraud) { c = w[j++]; if (j >= n) break; }
                memset(&b, 0, sizeof b);
                col(&b, c);
                vtx(&b, w[j++]);
                if (count < max) {
                    p = &out[count++];
                    memset(p, 0, sizeof *p);
                    p->kind = (uint8_t)(gouraud ? BFM_PRIM_LINE_G : BFM_PRIM_LINE_F);
                    p->flags = (uint8_t)(((code & 2) ? BFM_PRIM_FLAG_SEMI_TRANS : 0) |
                                         state_mask_flags(*tpage));
                    p->tpage = STATE_TPAGE(*tpage);
                    p->v[0] = a;
                    p->v[1] = b;
                }
                a = b;
                if (!poly) break;
            }
            i = j;
        } else if (code >= 0x60 && code < 0x80) {          /* rectangles */
            int tex = code & 0x04, size = (code >> 3) & 3;
            size_t need = 2 + (tex ? 1u : 0u) + (size == 0 ? 1u : 0u);
            size_t j = i + 1;
            if (i + need > n) break;
            p->kind = (uint8_t)(tex ? BFM_PRIM_SPRITE : BFM_PRIM_TILE);
            p->flags = (uint8_t)(((code & 2) ? BFM_PRIM_FLAG_SEMI_TRANS : 0) |
                                 ((tex && (code & 1)) ? BFM_PRIM_FLAG_RAW_TEXTURE : 0) |
                                 state_mask_flags(*tpage));
            p->tpage = STATE_TPAGE(*tpage);
            col(&p->v[0], cmd);
            vtx(&p->v[0], w[j++]);
            if (tex) {
                uv(&p->v[0], w[j]);
                p->clut = (uint16_t)(w[j] >> 16);
                j++;
            }
            if (size == 0) {
                p->w = (uint16_t)(w[j] & 0x3FFu);
                p->h = (uint16_t)((w[j] >> 16) & 0x1FFu);
                j++;
            } else {
                p->w = p->h = (uint16_t)(size == 1 ? 1 : size == 2 ? 8 : 16);
            }
            i = j;
            count++;
        } else if (code == 0x02) {                        /* VRAM fill */
            if (i + 3 > n) break;
            p->kind = BFM_PRIM_FILL;
            col(&p->v[0], cmd);
            vtx(&p->v[0], w[i + 1]);
            p->w = (uint16_t)(w[i + 2] & 0x3FFu);
            p->h = (uint16_t)((w[i + 2] >> 16) & 0x1FFu);
            i += 3;
            count++;
        } else if (code == 0xE1) {                        /* texpage */
            *tpage = (uint16_t)((*tpage & 0xC000u) | (cmd & 0x3FFFu));
            i++;
        } else if (code == 0xE6) {                        /* mask bit setting */
            *tpage = (uint16_t)((*tpage & 0x3FFFu) | ((cmd & 1u) ? 0x4000u : 0) |
                                ((cmd & 2u) ? 0x8000u : 0));
            i++;
        } else if (code == 0x00 || code == 0x01 || (code >= 0xE2 && code <= 0xE5)) {
            i++;                                          /* nop, cache, env words: renderer env comes from PutDrawEnv */
        } else {
            stats.unknown_commands++;
            stats.last_unknown_code = code;
            i++;
        }
    }
    return count;
}

/* Read-only re-walk of one OT for MUSASHI_TRACE_DRAWOTAG. */
static void ot_trace_walk(uint32_t ot, long call, unsigned pkts) {
    uint32_t addr = ot & 0x00FFFFFFu, tag, w[256];
    unsigned guard = 0, idx = 0, shown = 0, k;
    BfmPlatPrim one[64];
    uint16_t tp = 0;
    BfmPlatProjection pj;
    bfm_plat_projection_get(&pj);
    fprintf(stderr, "native_boot: OT_TRACE DrawOTag call=%ld ot=%08x packets=%u\n", call, ot, pkts);
    fprintf(stderr, "native_boot: OT_TRACE drawenv clip=%d,%d,%d,%d ofs=%d,%d dfe=%u dtd=%u isbg=%u; "
            "gte h=%d ofx=%d ofy=%d updates=%u\n",
            g_last_draw_env.clip.x, g_last_draw_env.clip.y, g_last_draw_env.clip.w, g_last_draw_env.clip.h,
            g_last_draw_env.offset_x, g_last_draw_env.offset_y, g_last_draw_env.draw_on_display,
            g_last_draw_env.dither, g_last_draw_env.clear_bg, pj.h, pj.ofx, pj.ofy, pj.updates);
    {
        extern void bfm_psyq_gte_trace(void) __attribute__((weak));
        if (bfm_psyq_gte_trace) bfm_psyq_gte_trace();
    }
    while (addr != 0x00FFFFFFu && guard++ < 0x40000u) {
        uint32_t len;
        if (!rd32(0x80000000u | addr, &tag)) break;
        len = tag >> 24;
        if (len) {
            size_t np;
            idx++;
            if (len > 256) len = 256;
            for (k = 0; k < len; k++) rd32(0x80000000u | (addr + 4u + 4u * k), &w[k]);
            for (k = 0; k < len; k++) {
                uint8_t c = (uint8_t)(w[k] >> 24);
                if (c >= 0xE1 && c <= 0xE6)
                    fprintf(stderr, "native_boot: OT_TRACE env pkt=%u word=%08x\n", idx, w[k]);
            }
            np = bfm_psyq_decode_packet(w, len, &tp, one, 64);
            if (shown < 40 && np) {
                shown++;
                fprintf(stderr, "native_boot: OT_TRACE pkt=%u kind=%u v0=%d,%d v1=%d,%d v2=%d,%d v3=%d,%d wh=%u,%u tpage=%04x clut=%04x rgb=%u,%u,%u\n",
                        idx, one[0].kind, one[0].v[0].x, one[0].v[0].y, one[0].v[1].x, one[0].v[1].y,
                        one[0].v[2].x, one[0].v[2].y, one[0].v[3].x, one[0].v[3].y, one[0].w, one[0].h,
                        one[0].tpage, one[0].clut, one[0].v[0].r, one[0].v[0].g, one[0].v[0].b);
            }
        }
        addr = tag & 0x00FFFFFFu;
    }
}

/* DrawOTag(p): walk tags from p until the 0xFFFFFF terminator */
int bfm_psyq_DrawOTag(uint32_t *r) {
    BfmPlatPrim prims[128];
    uint32_t addr = A(0) & 0x00FFFFFFu, tag, words[256];
    uint16_t tpage = 0;
    unsigned guard = 0;
    size_t n = 0;
    long call = ++g_ot_calls;
    unsigned pkts = 0;
    (void)ot_trace_on(call);
    while (addr != 0x00FFFFFFu && guard++ < 0x40000u) {
        uint32_t len, k;
        if (!rd32(0x80000000u | addr, &tag)) return n ? 1 : 0;
        len = tag >> 24;
        if (len) {
            stats.ot_packets++;
            if (len > 256) len = 256;
            for (k = 0; k < len; k++) rd32(0x80000000u | (addr + 4u + 4u * k), &words[k]);
            pkts++;
            if (n + 64 > 128) { bfm_plat_renderer_submit(prims, n); stats.prims += n; n = 0; }
            n += bfm_psyq_decode_packet(words, len, &tpage, prims + n, 128 - n);
        }
        addr = tag & 0x00FFFFFFu;
    }
    if (n) { bfm_plat_renderer_submit(prims, n); stats.prims += n; }
    if (g_ot_trace_at > 0 && call >= g_ot_trace_at && pkts >= 50u) {
        g_ot_trace_at = -1; /* once */
        ot_trace_walk(A(0), call, pkts);
    }
    return 1;
}

/* ---- libetc --------------------------------------------------------- */

#define VSYNC_TICK 0x8006CBB8u
#define VSYNC_HCOUNT_LATCH 0x8006BA9Cu

/* VSync(mode) for mode < 0 only (retail func_8004239C): returns the guest
 * vblank tick at 8006CBB8, which the 80042CE8 handler increments. Nothing
 * else of the retail routine is observable on this path except what is
 * reproduced here:
 *   v0 = *(u32 *)8006CBB8        v1 = *(u32 *)8006BA9C (the hcount latch the
 *   routine loaded last; callers treat v1 as dead, kept for exact parity)
 *   the three dead stack slots the retail prologue fills below the caller's
 *   sp: [sp-0x10] = s0, [sp-0x0C] = s1, [sp-0x08] = ra.
 * The retail routine also reads GPUSTAT (*8006BA94) and Timer1 (*8006BA98)
 * and discards both values; this path does not (docs/KNOWN-DIVERGENCES.md).
 * Every other mode refuses before any write: modes 0 and n > 1 wait on the
 * vblank IRQ through the guest clock and mode 1 returns a live hcount delta,
 * so the interpreter runs the retail words for them. The wrapper runs
 * device_sync first (native_lane_psyq.c), so the tick read sees the device
 * epoch committed. No private counter, no host pacing. */
int bfm_psyq_VSync(uint32_t *r) {
    uint32_t tick, latch, sp = r[29];
    uint8_t *frame;
    if ((int32_t)A(0) >= 0) return 0;
    /* Validate every address before the first write, so a refusal is clean. */
    if ((sp & 3u) || !bfm_psyq_ptr(VSYNC_TICK, 4) || !bfm_psyq_ptr(VSYNC_HCOUNT_LATCH, 4)) return 0;
    /* bfm_psyq_ptr mirrors RAM over the whole 512 MiB window; the retail
     * stores fault outside the 2 MiB (or the scratchpad), so refuse there. */
    {
        const uint32_t phys = (sp - 0x10u) & 0x1FFFFFFFu;
        if (phys >= 0x200000u && !(phys >= 0x1F800000u && phys < 0x1F800400u)) return 0;
    }
    frame = (uint8_t *)bfm_psyq_ptr(sp - 0x10u, 12);
    if (!frame) return 0;
    {   /* retail stores the frame first, then loads latch and tick */
        const uint32_t saved[3] = {r[16], r[17], r[31]};
        unsigned i;
        for (i = 0; i < 3; ++i) {
            frame[4 * i] = (uint8_t)saved[i];
            frame[4 * i + 1] = (uint8_t)(saved[i] >> 8);
            frame[4 * i + 2] = (uint8_t)(saved[i] >> 16);
            frame[4 * i + 3] = (uint8_t)(saved[i] >> 24);
        }
    }
    if (!rd32(VSYNC_HCOUNT_LATCH, &latch) || !rd32(VSYNC_TICK, &tick)) return 0;
    RET(tick);
    r[3] = latch;
    return 1;
}

/* ---- libcd ---------------------------------------------------------- */

static uint8_t to_bcd(uint32_t v) { return (uint8_t)(((v / 10u) << 4) | (v % 10u)); }
static uint32_t from_bcd(uint8_t v) { return (uint32_t)(v >> 4) * 10u + (v & 15u); }

/* CdIntToPos(i, loc): loc = BCD {m, s, f} of LBA i + 150 */
/* signed BCD as the retail code forms it: ((x / 10) << 4) + x % 10, low byte */
static uint8_t to_bcd_s(int32_t x) {
    return (uint8_t)((uint32_t)(x / 10) << 4) + (uint8_t)(x % 10);
}

/* Retail func_80043A18 divides signed: s = (i + 150) / 75, frame = rest,
 * minute = s / 60, second = s - 60 * minute (truncating toward zero), so
 * negative LBAs produce the same bytes as the retail code. */
int bfm_psyq_CdIntToPos(uint32_t *r) {
    uint8_t *p = (uint8_t *)bfm_psyq_ptr(A(1), 3);
    int32_t i = (int32_t)A(0) + 150, s, mm;
    if (!p) return 0;
    s = i / 75;
    mm = s / 60;
    p[2] = to_bcd_s(i - s * 75);
    p[1] = to_bcd_s(s - mm * 60);
    p[0] = to_bcd_s(mm);
    RET(A(1));
    return 1;
}

int bfm_psyq_CdPosToInt(uint32_t *r) {
    uint8_t *p = (uint8_t *)bfm_psyq_ptr(A(0), 3);
    if (!p) return 0;
    RET((from_bcd(p[0]) * 60u + from_bcd(p[1])) * 75u + from_bcd(p[2]) - 150u);
    return 1;
}

/* CdSearchFile(fp, name): CdlFILE = {CdlLOC pos[4], u32 size, char name[16]} */
int bfm_psyq_CdSearchFile(uint32_t *r) {
    uint8_t *fp = (uint8_t *)bfm_psyq_ptr(A(0), 24);
    char *name = (char *)bfm_psyq_ptr(A(1), 1);
    char path[64];
    uint32_t lba, size, i;
    if (!fp || !name) return 0;
    for (i = 0; i < sizeof path - 1u && name[i] && bfm_psyq_ptr(A(1) + i, 1); i++) path[i] = name[i];
    path[i] = '\0';
    if (bfm_plat_disc_find_file(path, &lba, &size) != BFM_PLAT_OK) { RET(0); return 1; }
    lba += 150u;
    fp[0] = to_bcd(lba / 4500u); fp[1] = to_bcd((lba / 75u) % 60u); fp[2] = to_bcd(lba % 75u); fp[3] = 0;
    fp[4] = (uint8_t)size; fp[5] = (uint8_t)(size >> 8); fp[6] = (uint8_t)(size >> 16); fp[7] = (uint8_t)(size >> 24);
    memset(fp + 8, 0, 16);
    {
        const char *base = path;
        const char *s;
        for (s = path; *s; s++) if (*s == '\\' || *s == '/') base = s + 1;
        size_t len = strlen(base);
        memcpy(fp + 8, base, len > 15 ? 15 : len);   /* CdlFILE.name[16], zeroed above */
    }
    RET(A(0));
    return 1;
}

/* StGetNext(u_long **addr, u_long **header): the next complete frame of the
 * libcd2 sector stream, from the ring StSetRing(ring, size) set up.
 *
 * Ring layout (retail StSetRing func_80043088, StFreeRing func_80046B44, the
 * stream interrupt func_80046D1C): `size` 32-byte sector headers at `ring`,
 * then `size` 2016-byte (0x7E0) sector bodies. Header +0 is a u16 slot
 * status: 0 free or still filling, 1 a wrap marker the interrupt leaves when
 * the next frame does not fit before the ring's end, 2 the first sector of a
 * complete frame, 4 handed to the game until StFreeRing releases it (header
 * +6 is the frame's sector count). Library globals in guest RAM: */
#define ST_READ_INDEX 0x800C6D40u   /* slot the reader looks at next */
#define ST_RING_BASE  0x800C7C94u   /* ring (StSetRing a0) */
#define ST_RING_SIZE  0x800C7F00u   /* slots (StSetRing a1) */
#define ST_END_FRAME  0x800C7C84u   /* StSetMask's end argument (func_80046CFC a2) */

/* Behaviour of retail func_80046C38: if the reader's slot is a wrap marker,
 * the read index goes back to 0 and, only when an end frame is set, the
 * marker is cleared to 0; then the (new) slot is examined. Status 2: mark it
 * 4, *addr = ring + size*32 + index*2016, *header = the slot's header, return
 * 0. Anything else: return 1 and write nothing more (the not-ready path the
 * game's polling loop spins on). Addresses wrap at 32 bits like the guest's.
 *
 * Refuses, with nothing written, whenever the retail code would fault (a
 * header or output outside guest RAM/scratchpad, a misaligned halfword or
 * word) or a header slot overlaps the library globals; the interpreter then
 * runs the retail code. The caller-saved registers are left as the retail
 * code leaves them (at, v1, a0-a3, t0), so the whole register file matches;
 * the game's only caller (0x800D27C4) uses v0 and the two outputs.
 *
 * The call runs as one step: the stream interrupt that fills the ring
 * (interpreted retail StCdInterrupt) lands before or after it, never inside,
 * which is one of the orders the retail code allows. */

/* Guest RAM (first 2 MB, through KUSEG/KSEG0/KSEG1) or the scratchpad
 * (KUSEG/KSEG0); anything else (RAM mirrors, I/O, KSEG2) is refused rather
 * than folded into RAM the way bfm_psyq_ptr's physical mask would. */
static uint8_t *st_ptr(uint32_t addr, uint32_t len) {
    const uint32_t phys = addr & 0x1FFFFFFFu;
    const uint32_t seg = addr >> 29;                     /* 0-3 KUSEG, 4 KSEG0, 5 KSEG1 */
    if (seg > 5u || (seg < 4u && addr >= 0x20000000u)) return NULL;
    if (phys >= 0x1F800000u && phys < 0x1F800400u) {
        if (seg == 5u) return NULL;
        return (uint8_t *)bfm_psyq_ptr(addr, len);
    }
    if (phys >= 0x00200000u || phys + len > 0x00200000u) return NULL;
    return (uint8_t *)bfm_psyq_ptr(addr, len);
}

static int st_overlaps(const uint8_t *a, uint32_t alen, const uint8_t *b, uint32_t blen) {
    return a < b + blen && b < a + alen;
}

int bfm_psyq_StGetNext(uint32_t *r) {
    const uint32_t addr_out = A(0), head_out = A(1);
    const uint32_t globals[4] = {ST_READ_INDEX, ST_RING_BASE, ST_RING_SIZE, ST_END_FRAME};
    uint32_t index, base, size, end, head, wrapped = 0, k;
    uint8_t *slot, *slot0 = NULL, *pa = NULL, *ph = NULL;
    uint16_t status;
    if (!rd32(ST_READ_INDEX, &index) || !rd32(ST_RING_BASE, &base) ||
        !rd32(ST_RING_SIZE, &size) || !rd32(ST_END_FRAME, &end))
        return 0;
    head = base + (index << 5);
    if ((head & 1u) || !(slot = st_ptr(head, 2))) return 0;
    status = (uint16_t)(slot[0] | (slot[1] << 8));
    if (status == 1u) {
        if ((base & 1u) || !(slot0 = st_ptr(base, 2))) return 0;
        wrapped = 1;
        /* Marker at slot 0 and cleared: the re-read sees the 0 written. */
        status = (end != 0u && slot0 == slot) ? 0u : (uint16_t)(slot0[0] | (slot0[1] << 8));
    }
    if (status == 2u) {
        if ((addr_out & 3u) || (head_out & 3u) ||
            !(pa = st_ptr(addr_out, 4)) || !(ph = st_ptr(head_out, 4)))
            return 0;
    }
    /* The retail code reads the globals again after its header stores; a
     * header aliasing them would change what it reads. Leave that to it. */
    for (k = 0; k < 4u; k++) {
        const uint8_t *g = (const uint8_t *)bfm_psyq_ptr(globals[k], 4);
        if (st_overlaps(slot, 2, g, 4) || (slot0 && st_overlaps(slot0, 2, g, 4))) return 0;
    }

    r[7] = addr_out;                                    /* a3, t0: the arguments */
    r[8] = head_out;
    if (wrapped) {
        wr32(ST_READ_INDEX, 0);
        if (end != 0u) wr16(slot, 0);
        index = 0;
        head = base;
        slot = slot0;
        r[1] = 0x800C0000u;                             /* at: %hi of the globals */
    }
    r[6] = head;                                        /* a2 */
    if (status != 2u) {
        r[2] = 1;
        r[3] = 2;
        return 1;
    }
    wr16(slot, 4);
    {
        const uint32_t body = (index << 6) - index;     /* index * 63 */
        const uint32_t data = base + (size << 5) + (body << 5);
        pa[0] = (uint8_t)data; pa[1] = (uint8_t)(data >> 8);
        pa[2] = (uint8_t)(data >> 16); pa[3] = (uint8_t)(data >> 24);
        ph[0] = (uint8_t)head; ph[1] = (uint8_t)(head >> 8);
        ph[2] = (uint8_t)(head >> 16); ph[3] = (uint8_t)(head >> 24);
        r[4] = data;
        r[5] = index;
        r[3] = body << 5;
    }
    r[2] = 0;
    return 1;
}

/* ---- libc2 ---------------------------------------------------------- */

/* The seed is the guest's own word (D_80078980 in src/main/8005c49c.c), so
 * native and interpreted callers share one sequence. */
#define PSYQ_RAND_SEED 0x80078980u

int bfm_psyq_rand(uint32_t *r) {
    uint32_t s;
    if (!rd32(PSYQ_RAND_SEED, &s)) return 0;
    s = s * 0x41C64E6Du + 0x3039u;
    wr32(PSYQ_RAND_SEED, s);
    RET((s >> 16) & 0x7FFFu);
    return 1;
}

/* The retail libc rules (func_8005C324 / 8005C358 / 8005C2C8):
 * - a NULL destination writes nothing and returns 0;
 * - a signed count <= 0 writes nothing and returns dst (memcpy) or 0
 *   (memset, bzero);
 * - otherwise the copy is a forward byte loop, so overlapping ranges
 *   propagate bytes exactly as on hardware (not memmove), and the result
 *   is dst. */
int bfm_psyq_memcpy(uint32_t *r) {
    uint32_t dst = A(0), src = A(1), i;
    int32_t n = (int32_t)A(2);
    volatile uint8_t *d, *s; /* volatile: keep the byte loop (no memmove idiom) */
    if (!dst) { RET(0); return 1; }
    if (n <= 0) { RET(dst); return 1; }
    d = (volatile uint8_t *)bfm_psyq_ptr(dst, (uint32_t)n);
    s = (volatile uint8_t *)bfm_psyq_ptr(src, (uint32_t)n);
    if (!d || !s) return 0;
    for (i = 0; i < (uint32_t)n; i++) d[i] = s[i];
    RET(dst);
    return 1;
}

static int fill(uint32_t *r, uint32_t dst, int32_t n, uint8_t value) {
    uint8_t *d;
    if (!dst || n <= 0) { RET(0); return 1; }
    d = (uint8_t *)bfm_psyq_ptr(dst, (uint32_t)n);
    if (!d) return 0;
    memset(d, value, (size_t)n);
    RET(dst);
    return 1;
}

int bfm_psyq_memset(uint32_t *r) { return fill(r, A(0), (int32_t)A(2), (uint8_t)A(1)); }

int bfm_psyq_bzero(uint32_t *r) { return fill(r, A(0), (int32_t)A(1), 0); }

static int guest_strlen(uint32_t a, uint32_t *len) {
    uint32_t i;
    for (i = 0; i < 0x10000u; i++) {
        char *c = (char *)bfm_psyq_ptr(a + i, 1);
        if (!c) return 0;
        if (!*c) { *len = i; return 1; }
    }
    return 0;
}

/* strcpy (func_8005C540): NULL dst or src returns 0 without copying;
 * otherwise a forward byte copy (overlap behaves as the retail loop) and
 * returns dst. */
int bfm_psyq_strcpy(uint32_t *r) {
    uint32_t len, k;
    uint8_t *d;
    const uint8_t *s;
    if (!A(0) || !A(1)) { RET(0); return 1; }
    if (!guest_strlen(A(1), &len)) return 0;
    d = (uint8_t *)bfm_psyq_ptr(A(0), len + 1u);
    s = (const uint8_t *)bfm_psyq_ptr(A(1), len + 1u);
    if (!d || !s) return 0;
    for (k = 0; k <= len; k++) {
        d[k] = s[k];
        if (!s[k]) break;
    }
    RET(A(0));
    return 1;
}

/* strcmp (func_8005C4DC): both NULL or equal -> 0; NULL a0 -> -1, NULL a1
 * -> 1; else the difference of the first differing bytes (unsigned). */
int bfm_psyq_strcmp(uint32_t *r) {
    uint32_t la, lb;
    const unsigned char *a, *b;
    size_t i;
    if (!A(0) || !A(1)) {
        RET(A(0) == A(1) ? 0u : A(0) ? 1u : (uint32_t)-1);
        return 1;
    }
    if (!guest_strlen(A(0), &la) || !guest_strlen(A(1), &lb)) return 0;
    a = (const unsigned char *)bfm_psyq_ptr(A(0), la + 1u);
    b = (const unsigned char *)bfm_psyq_ptr(A(1), lb + 1u);
    if (!a || !b) return 0;
    for (i = 0; a[i] && a[i] == b[i]; i++) {}
    RET((uint32_t)((int32_t)a[i] - (int32_t)b[i]));
    return 1;
}

/* srand (func_8005C4CC): the seed goes to D_80078980 */
int bfm_psyq_srand(uint32_t *r) {
    if (!wr32(0x80078980u, A(0))) return 0;
    return 1;
}

static char line[256];
static size_t line_len;

int bfm_psyq_putchar(uint32_t *r) {
    char c = (char)A(0);
    if (c == '\n' || line_len + 1 >= sizeof line) {
        line[line_len] = '\0';
        bfm_plat_mods_log("guest", 2, line);
        line_len = 0;
    }
    if (c != '\n') line[line_len++] = c;
    RET((uint32_t)(uint8_t)c);
    return 1;
}
