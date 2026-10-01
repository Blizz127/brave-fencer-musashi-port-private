/* CPU controller vs gl executor: do the shipped cpu rasteriser
 * (native_boot's gpu_controller.c) and the gl renderer draw the same GP0
 * stream to the same VRAM pixels?
 *
 *   bfm_gl_ctl_probe LIBOSMESA [scale] [scenes]
 *
 * One synthetic stream (texture uploads, draw environment, then per scene a
 * grid of random polygons/rects of every kind over per-cell backdrops) runs
 * through the controller into a CPU VRAM image, and through
 * bfm_plat_gpu_bridge -> BfmGlBatch -> bfm_gl_exec on a headless OSMesa
 * context into the gl VRAM target, which is read back. Every differing pixel
 * is classified:
 *   mask      same colour, different bit 15;
 *   edge      the integer pixel lies exactly on an edge of the polygon drawn
 *             in its cell: the controller's inclusive edge rule against the
 *             gl (PS1) top-left rule, KNOWN-DIVERGENCES D-030;
 *   col=1     both drew it, one 5-bit step apart in some channel;
 *   cover     one side drew the pixel and the other kept the backdrop;
 *   col>1     both drew it, more than one step apart.
 * Opaque scenes must have no difference besides edge pixels; semi-
 * transparent scenes may differ by one step where the gl blend is 8-bit
 * (D-033). Edge differences are reported, not failed. Synthetic data only. */

#include "bfm_plat.h"
#include "bfm_plat_gpu_bridge.h"
#include "bfm_plat_renderer.h"
#include "backends/gl/bfm_gl_core.h"
#include "backends/gl/bfm_gl_exec.h"
#include "musashi_gpu_controller.h"

#include <dlfcn.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int fails;
#define CHECK(c)                                                              \
    do {                                                                      \
        if (!(c)) {                                                           \
            printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #c);               \
            fails++;                                                          \
        }                                                                     \
    } while (0)

#define LOADFN(dst, obj)                                                      \
    do {                                                                      \
        void *o_ = (obj);                                                     \
        memcpy(&(dst), &o_, sizeof o_);                                       \
    } while (0)

/* ---- the gl side: bridge backend -> batch -> executor ------------------- */

typedef void *OSMesaContext;
typedef OSMesaContext (*CreateAttribsFn)(const int *, OSMesaContext);
typedef unsigned char (*MakeCurrentFn)(OSMesaContext, void *, unsigned, int, int);
typedef void *(*GetProcFn)(const char *);
typedef void (*DestroyFn)(OSMesaContext);
static GetProcFn osmesa_getproc;
static void *getproc(const char *n) { return osmesa_getproc(n); }
static uint8_t winbuf[64 * 64 * 4];

static BfmGlExec *X;
static BfmGlBatch B;
static BfmGlVram glvram;
static size_t gl_prims;

static void gl_flush(void) {
    bfm_gl_exec_sync_vram(X, &glvram);
    CHECK(bfm_gl_exec_run(X, &B, 0) == BFM_PLAT_OK);
    bfm_gl_batch_clear(&B);
}

static int gb_init(void *s, const BfmPlatOutput *o) { (void)s; (void)o; return BFM_PLAT_OK; }
static int gb_env(void *s, const BfmPlatDrawEnv *e) {
    (void)s;
    bfm_gl_batch_set_env(&B, e);
    return BFM_PLAT_OK;
}
static int gb_disp(void *s, const BfmPlatDispEnv *e) { (void)s; (void)e; return BFM_PLAT_OK; }
static int gb_submit(void *s, const BfmPlatPrim *p, size_t n) {
    (void)s;
    gl_prims += n;
    bfm_gl_batch_add(&B, p, n);
    return BFM_PLAT_OK;
}
static int gb_upload(void *s, const BfmPlatRect *r, const uint16_t *px) {
    (void)s;
    gl_flush();   /* earlier draws must not see the new texels */
    if (bfm_gl_vram_upload(&glvram, r, px) != BFM_PLAT_OK) return BFM_PLAT_ERROR;
    bfm_gl_batch_add_copy(&B, r);
    return BFM_PLAT_OK;
}
/* As renderer_gl.c: rendered tiles are resolved into the mirror first. */
static int gb_download(void *s, const BfmPlatRect *r, uint16_t *px) {
    (void)s;
    bfm_gl_batch_add_resolve(&B, r);
    gl_flush();
    return bfm_gl_vram_download(&glvram, r, px);
}
static int gb_present(void *s) { (void)s; return BFM_PLAT_OK; }

static const BfmPlatRendererBackend gl_backend = {
    "ctlprobe", gb_init, NULL, NULL, NULL, gb_env, gb_disp, gb_submit, gb_upload, NULL,
    gb_download, gb_present, NULL, NULL
};

/* ---- the cpu side: native_boot's controller ------------------------------ */

static uint16_t cvram[512][1024];
static int c_ok(void *u) { (void)u; return 1; }
static int c_word(void *u, uint32_t w) { (void)u; (void)w; return 1; }
static int c_en(void *u, int e) { (void)u; (void)e; return 1; }
static int c_disp(void *u, const MusashiGpuDisplayState *d) { (void)u; (void)d; return 1; }
static int c_fill(void *u, const MusashiGpuFill *f) {
    unsigned x, y;
    (void)u;
    for (y = 0; y < f->height; y++)
        for (x = 0; x < f->width; x++) cvram[(f->y + y) & 511][(f->x + x) & 1023] = f->color;
    return 1;
}
static int c_store(void *u, uint16_t x, uint16_t y, uint16_t p) {
    (void)u;
    cvram[y & 511][x & 1023] = p;
    return 1;
}
static int c_load(void *u, uint16_t x, uint16_t y, uint16_t *p) {
    (void)u;
    *p = cvram[y & 511][x & 1023];
    return 1;
}
static MusashiGpuController ctl;
static BfmGpuBridge bridge;

/* ---- the stream ------------------------------------------------------------ */

typedef struct Stream { uint32_t addr[65536], word[65536]; unsigned n, refused; } Stream;
static Stream st;
static void gp0(uint32_t w) { st.addr[st.n] = BFM_GPU_BRIDGE_GP0; st.word[st.n++] = w; }
static void gp1(uint32_t w) { st.addr[st.n] = BFM_GPU_BRIDGE_GP1; st.word[st.n++] = w; }

static void run_stream(void) {
    unsigned i;
    for (i = 0; i < st.n; i++) {
        if (!musashi_gpu_controller_write32(&ctl, st.addr[i], st.word[i])) st.refused++;
        CHECK(bfm_gpu_bridge_write32(&bridge, st.addr[i], st.word[i]));
    }
    CHECK(bfm_gpu_bridge_flush(&bridge) == BFM_PLAT_OK);
    gl_flush();
    st.n = 0;
}

static uint32_t seed;
static unsigned rnd(unsigned n) {
    seed = seed * 1103515245u + 12345u;
    return ((seed >> 16) & 0x7FFF) % n;
}

static uint32_t xy(int x, int y) { return ((uint32_t)(uint16_t)y << 16) | (uint16_t)x; }
static uint32_t rgb(uint32_t op, unsigned r, unsigned g, unsigned b) {
    return (op << 24) | (b << 16) | (g << 8) | r;
}
static uint32_t uv(unsigned u, unsigned v, unsigned hi) { return (hi << 16) | (v << 8) | u; }

/* texture pages: 15-bit at VRAM x 512, 8-bit at 768, 4-bit at 896, each
 * 256x256 texels from row 0; CLUTs on row 511 */
#define TP15 0x108u
#define TP8 0x08Cu
#define TP4 0x00Eu
#define CLUT8 0x7FC0u
#define CLUT4 0x7FD0u

static void upload_words(int x, int y, int w, int h, uint16_t (*texel)(int, int)) {
    int i, n = w * h;
    gp0(0xA0000000u);
    gp0(xy(x, y));
    gp0(xy(w, h));
    for (i = 0; i < n; i += 2) {
        uint16_t lo = texel(i % w, i / w), hi = texel((i + 1) % w, (i + 1) / w);
        gp0((uint32_t)lo | ((uint32_t)hi << 16));
    }
}

/* 1/16 transparent, some STP, otherwise any colour */
static uint16_t tex15(int x, int y) {
    unsigned h = (unsigned)(x * 7919 + y * 104729 + 17) * 2654435761u;
    uint16_t c = (uint16_t)((h >> 9) & 0x7FFF);
    if ((h & 15) == 0) return 0;
    if (!c) c = 1;
    return (uint16_t)(c | ((h & 0xF0) == 0x10 ? 0x8000 : 0));
}
static uint16_t tex8(int x, int y) {   /* two 8-bit indices per halfword */
    unsigned a = (unsigned)(x * 2 + y * 613) * 2246822519u >> 24;
    unsigned b = (unsigned)(x * 2 + 1 + y * 613) * 2246822519u >> 24;
    return (uint16_t)(a | (b << 8));
}
static uint16_t tex4(int x, int y) {   /* four 4-bit indices per halfword */
    unsigned h = (unsigned)(x + y * 1031) * 3266489917u;
    return (uint16_t)(h >> 16);
}
static uint16_t clut8(int x, int y) {
    unsigned h = (unsigned)(x + 3) * 2654435761u;
    (void)y;
    if (x == 0) return 0;   /* index 0 transparent */
    return (uint16_t)(((h >> 8) & 0x7FFF) | ((h & 7) == 1 ? 0x8000 : 0) | 1);
}
static uint16_t clut4(int x, int y) {
    unsigned h = (unsigned)(x + 11) * 2246822519u;
    (void)y;
    if (x == 0) return 0;
    return (uint16_t)(((h >> 8) & 0x7FFF) | ((h & 7) == 2 ? 0x8000 : 0) | 1);
}

static void build_setup(void) {
    gp1(0x00000000u);   /* reset */
    upload_words(512, 0, 256, 256, tex15);
    upload_words(768, 0, 128, 256, tex8);
    upload_words(896, 0, 64, 256, tex4);
    upload_words(0, 511, 256, 1, clut8);
    upload_words(256, 511, 16, 1, clut4);
    gp0(0xE2000000u);   /* no texture window */
    gp0(0xE6000000u);   /* no mask */
}

/* One test prim per 40x40 cell; what the probe needs to classify a pixel
 * difference. Vertices are in drawing-area coordinates (the offset moves
 * them to VRAM, which does not change the edge test). */
typedef struct Cell {
    int kind;        /* K_* */
    int nv;          /* 3, 4 or 0 for rects */
    int vx[4], vy[4];
    int u[4], v[4];  /* texture coordinates (textured polygons) */
    unsigned tpage, clut, rgb0;
    uint16_t bg;     /* backdrop colour (15-bit) */
} Cell;
enum {
    K_F3, K_F4, K_G3, K_G4, K_FT3, K_FT4, K_GT3, K_GT4, K_FT4_RAW, K_FT3_1TO1, K_SPRT,
    K_TILE, K_COUNT
};
static const char *kind_name[K_COUNT] = {
    "F3", "F4", "G3", "G4", "FT3", "FT4", "GT3", "GT4", "FT4raw", "FT3-1:1", "SPRT", "TILE"
};
#define CELL 40
#define COLS 8
#define ROWS 6
static Cell cells[COLS * ROWS];
static unsigned scene_tpage;   /* the E1 texpage rects use */

static unsigned pick_tpage(unsigned abr) {
    static const unsigned tp[3] = {TP15, TP8, TP4};
    return tp[rnd(3)] | (abr << 5);
}
static unsigned clut_for(unsigned tpage) {
    switch ((tpage >> 7) & 3) {
    case 1: return CLUT8;
    case 0: return CLUT4;
    default: return 0;
    }
}
static unsigned colour8(void) {
    /* mostly PS1-typical shading (<= 0x80), some brighter to exercise clamps */
    return rnd(8) == 0 ? 0x80 + rnd(0x80) : rnd(0x81);
}

/* Reorders four random points into a simple quad in PS1 vertex order
 * (0 1 / 2 3) whose two triangles do not overlap: the points are taken in
 * angular order about their centroid and split along an interior diagonal
 * (through the reflex vertex when the quad is concave). A pixel of a semi-
 * transparent quad then blends once, so the 8-bit blend's one-step
 * tolerance (D-033) is not compounded, and the gl mode-2 split (all non-STP
 * texels of a draw, then all STP texels) keeps the controller's order. */
static void convex_quad(Cell *k) {
    int i, j, cxs = 0, cys = 0, px[4], py[4], order[4] = {0, 1, 2, 3}, reflex = -1;
    double ang[4];
    for (i = 0; i < 4; i++) { cxs += k->vx[i]; cys += k->vy[i]; }
    for (i = 0; i < 4; i++)
        ang[i] = atan2(4.0 * k->vy[i] - cys, 4.0 * k->vx[i] - cxs);
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 4; j++)
            if (ang[order[j]] < ang[order[i]]) { int t = order[i]; order[i] = order[j]; order[j] = t; }
    for (i = 0; i < 4; i++) { px[i] = k->vx[order[i]]; py[i] = k->vy[order[i]]; }
    for (i = 0; i < 4; i++) {           /* the vertex whose turn goes the other way */
        int a = (i + 3) & 3, b = (i + 1) & 3;
        long cross = (long)(px[i] - px[a]) * (py[b] - py[i]) - (long)(py[i] - py[a]) * (px[b] - px[i]);
        if (cross < 0) reflex = i;
    }
    if (reflex == 0 || reflex == 2) {   /* interior diagonal is p0-p2: rotate */
        int tx = px[0], ty = py[0];
        for (i = 0; i < 3; i++) { px[i] = px[i + 1]; py[i] = py[i + 1]; }
        px[3] = tx; py[3] = ty;
    }
    /* p0 p1 p2 p3 around, diagonal p1-p3: v0 p0, v1 p1, v2 p3, v3 p2 */
    k->vx[0] = px[0]; k->vy[0] = py[0];
    k->vx[1] = px[1]; k->vy[1] = py[1];
    k->vx[2] = px[3]; k->vy[2] = py[3];
    k->vx[3] = px[2]; k->vy[3] = py[2];
}

/* The scene's prims: area_y is the drawing area's VRAM row (and the drawing
 * offset); semi adds the semi-transparency bit to every prim, drawn over a
 * flat backdrop; e1_abr is the blend mode of untextured prims and rects. */
static void build_scene(int area_y, int semi, unsigned e1_abr) {
    int c;
    scene_tpage = pick_tpage(e1_abr) & 0x1FFu;   /* no dither bit */
    gp0(0xE3000000u | ((uint32_t)area_y << 10) | 0u);
    gp0(0xE4000000u | ((uint32_t)(area_y + ROWS * CELL - 1) << 10) | (COLS * CELL - 1));
    gp0(0xE5000000u | ((uint32_t)(area_y & 0x7FF) << 11) | 0u);
    gp0(0xE1000000u | scene_tpage);
    for (c = 0; c < COLS * ROWS; c++) {
        Cell *k = &cells[c];
        int cx = (c % COLS) * CELL, cy = (c / COLS) * CELL, i;
        unsigned op, tp, cl, semibit = semi ? 2u : 0u;
        memset(k, 0, sizeof *k);
        k->kind = (c + (semi ? 5 : 0)) % K_COUNT;
        /* The bridge takes a textured polygon's texpage as the current one
         * (hardware behaviour); the controller keeps the E1 one. Restate E1
         * before every prim so rects and untextured blends use the same
         * page and mode on both sides and the comparison is about pixels. */
        gp0(0xE1000000u | scene_tpage);
        /* backdrop: a flat TILE of a random colour (exact in both rasterisers) */
        k->bg = (uint16_t)rnd(0x8000);
        gp0(rgb(0x60, (k->bg & 31) << 3, ((k->bg >> 5) & 31) << 3, ((k->bg >> 10) & 31) << 3));
        gp0(xy(cx, cy));
        gp0(xy(CELL, CELL));
        k->nv = k->kind == K_F3 || k->kind == K_G3 || k->kind == K_FT3 || k->kind == K_GT3 ||
                k->kind == K_FT3_1TO1 ? 3
                : k->kind == K_SPRT || k->kind == K_TILE ? 0 : 4;
        for (i = 0; i < 4; i++) {
            k->vx[i] = cx + 1 + (int)rnd(CELL - 2);
            k->vy[i] = cy + 1 + (int)rnd(CELL - 2);
        }
        if (k->nv == 4) convex_quad(k);
        tp = pick_tpage(rnd(4));
        cl = clut_for(tp);
        k->tpage = tp; k->clut = cl;
        switch (k->kind) {
        case K_F3:
        case K_F4:
            op = (k->kind == K_F3 ? 0x20u : 0x28u) | semibit;
            gp0(rgb(op, colour8(), colour8(), colour8()));
            for (i = 0; i < k->nv; i++) gp0(xy(k->vx[i], k->vy[i]));
            break;
        case K_G3:
        case K_G4:
            op = (k->kind == K_G3 ? 0x30u : 0x38u) | semibit;
            for (i = 0; i < k->nv; i++) {
                gp0(rgb(i ? 0 : op, colour8(), colour8(), colour8()));
                gp0(xy(k->vx[i], k->vy[i]));
            }
            break;
        case K_FT3:
        case K_FT4:
        case K_FT4_RAW:
        case K_FT3_1TO1:
            op = (k->nv == 3 ? 0x24u : 0x2Cu) | semibit | (k->kind == K_FT4_RAW ? 1u : 0u);
            gp0(rgb(op, colour8(), colour8(), colour8()));
            for (i = 0; i < k->nv; i++) {
                unsigned u, v;
                if (k->kind == K_FT3_1TO1) {   /* a texel per pixel, texel = pixel */
                    u = (unsigned)(k->vx[i] - cx + 8 * (c % 16));
                    v = (unsigned)(k->vy[i] - cy + 8 * (c % 7));
                } else {
                    u = rnd(256);
                    v = rnd(256);
                }
                k->u[i] = (int)u; k->v[i] = (int)v;
                gp0(xy(k->vx[i], k->vy[i]));
                gp0(uv(u, v, i == 0 ? cl : i == 1 ? tp : 0));
            }
            break;
        case K_GT3:
        case K_GT4:
            op = (k->nv == 3 ? 0x34u : 0x3Cu) | semibit;
            for (i = 0; i < k->nv; i++) {
                k->u[i] = (int)rnd(256); k->v[i] = (int)rnd(256);
                gp0(rgb(i ? 0 : op, colour8(), colour8(), colour8()));
                gp0(xy(k->vx[i], k->vy[i]));
                gp0(uv((unsigned)k->u[i], (unsigned)k->v[i], i == 0 ? cl : i == 1 ? tp : 0));
            }
            break;
        case K_SPRT: {
            int w = 4 + (int)rnd(30), h = 4 + (int)rnd(30);
            op = 0x64u | semibit | (rnd(2) ? 1u : 0u);
            gp0(rgb(op, colour8(), colour8(), colour8()));
            gp0(xy(cx + 2 + (int)rnd(6), cy + 2 + (int)rnd(6)));
            gp0(uv(rnd(256), rnd(256), clut_for(scene_tpage)));
            gp0(xy(w, h));
            break;
        }
        default: {
            int w = 4 + (int)rnd(30), h = 4 + (int)rnd(30);
            op = 0x60u | semibit;
            gp0(rgb(op, colour8(), colour8(), colour8()));
            gp0(xy(cx + 2 + (int)rnd(6), cy + 2 + (int)rnd(6)));
            gp0(xy(w, h));
            break;
        }
        }
    }
}

/* ---- comparison ---------------------------------------------------------- */

/* Is the integer point exactly on an edge of (and inside) a triangle? */
static int tri_on_edge(int x, int y, int x0, int y0, int x1, int y1, int x2, int y2) {
    long long area = (long long)(x1 - x0) * (y2 - y0) - (long long)(y1 - y0) * (x2 - x0);
    long long w0 = (long long)(x1 - x) * (y2 - y) - (long long)(y1 - y) * (x2 - x);
    long long w1 = (long long)(x2 - x) * (y0 - y) - (long long)(y2 - y) * (x0 - x);
    long long w2 = (long long)(x0 - x) * (y1 - y) - (long long)(y0 - y) * (x1 - x);
    if (!area) return 0;
    if (area > 0 ? (w0 < 0 || w1 < 0 || w2 < 0) : (w0 > 0 || w1 > 0 || w2 > 0)) return 0;
    return w0 == 0 || w1 == 0 || w2 == 0;
}
static int cell_on_edge(const Cell *k, int x, int y) {
    if (k->nv == 3)
        return tri_on_edge(x, y, k->vx[0], k->vy[0], k->vx[1], k->vy[1], k->vx[2], k->vy[2]);
    if (k->nv == 4)
        return tri_on_edge(x, y, k->vx[0], k->vy[0], k->vx[1], k->vy[1], k->vx[2], k->vy[2]) ||
               tri_on_edge(x, y, k->vx[1], k->vy[1], k->vx[3], k->vy[3], k->vx[2], k->vy[2]);
    return 0;
}

typedef struct Stat { long pixels, same, mask, edge, colour1, coverage, colour2; } Stat;
static Stat stats[2][K_COUNT];   /* [semi][kind] */

static int step5(uint16_t a, uint16_t b) {
    int ch, d = 0;
    for (ch = 0; ch < 3; ch++) {
        int e = abs(((a >> (5 * ch)) & 31) - ((b >> (5 * ch)) & 31));
        if (e > d) d = e;
    }
    return d;
}

static void compare_scene(int area_y, int semi, int report) {
    static uint16_t out[ROWS * CELL][COLS * CELL];
    BfmPlatRect r;
    int x, y, shown = 0;
    r.x = 0; r.y = (int16_t)area_y; r.w = COLS * CELL; r.h = ROWS * CELL;
    /* a display-sized drawing area is a scene target (as in the game): read
     * it the way the renderer serves VRAM reads, resolved into the mirror */
    CHECK(gb_download(NULL, &r, &out[0][0]) == BFM_PLAT_OK);
    for (y = 0; y < ROWS * CELL; y++)
        for (x = 0; x < COLS * CELL; x++) {
            const Cell *k = &cells[(y / CELL) * COLS + x / CELL];
            Stat *s = &stats[semi][k->kind];
            uint16_t c = cvram[area_y + y][x], g = out[y][x];
            const char *why;
            s->pixels++;
            if (c == g) { s->same++; continue; }
            if (cell_on_edge(k, x, y)) { s->edge++; why = "edge"; }
            else if ((c & 0x7FFF) == (g & 0x7FFF)) { s->mask++; why = "mask"; }
            else if (step5(c, g) == 1) { s->colour1++; why = "col=1"; }
            else if (((c & 0x7FFF) == k->bg) != ((g & 0x7FFF) == k->bg)) {
                s->coverage++; why = "cover";
            } else { s->colour2++; why = "col>1"; }
            if ((report || getenv("BFM_CTL_VERBOSE")) && strcmp(why, "edge") != 0 &&
                (!semi || strcmp(why, "col=1") != 0) && shown++ < 40) {
                int i;
                printf("  %s %s %s (%d,%d): cpu %04x gl %04x bg %04x tpage %03x clut %04x verts",
                       semi ? "semi" : "opaque", kind_name[k->kind], why, x, y, c, g, k->bg,
                       k->tpage, k->clut);
                for (i = 0; i < k->nv; i++)
                    printf(" (%d,%d uv %d,%d)", k->vx[i], k->vy[i], k->u[i], k->v[i]);
                printf("\n");
            }
        }
}

/* ---- main ------------------------------------------------------------------ */

int main(int argc, char **argv) {
    static const int attribs[] = {0x22, 0x1908, 0x30, 0, 0x31, 0, 0x33, 0x34, 0x36, 3, 0x37, 3, 0};
    const char *lib = argc > 1 ? argv[1] : NULL;
    int scale = argc > 2 ? atoi(argv[2]) : 1, scenes = argc > 3 ? atoi(argv[3]) : 6;
    void *h;
    CreateAttribsFn create;
    MakeCurrentFn make;
    DestroyFn destroy;
    OSMesaContext ctx;
    MusashiGpuBackend be;
    BfmPlatOutput out;
    char err[512];
    int sc, k, semi;
    long opaque_bad = 0, semi_bad = 0, semi_step = 0, edges = 0;

    if (!lib) {
        printf("usage: bfm_gl_ctl_probe LIBOSMESA [scale] [scenes]\n");
        return 2;
    }
    if (!(h = dlopen(lib, RTLD_NOW | RTLD_LOCAL))) {
        printf("skip exec: %s\n", dlerror());
        return 0;
    }
    LOADFN(create, dlsym(h, "OSMesaCreateContextAttribs"));
    LOADFN(make, dlsym(h, "OSMesaMakeCurrent"));
    LOADFN(destroy, dlsym(h, "OSMesaDestroyContext"));
    LOADFN(osmesa_getproc, dlsym(h, "OSMesaGetProcAddress"));
    if (!create || !make || !destroy || !osmesa_getproc) {
        printf("skip exec: not an OSMesa library\n");
        return 0;
    }
    if (!(ctx = create(attribs, NULL))) {
        printf("skip exec: no GL 3.3 core OSMesa context\n");
        return 0;
    }
    if (!make(ctx, winbuf, 0x1401, 64, 64)) {
        printf("FAIL OSMesaMakeCurrent\n");
        return 1;
    }
    if (!(X = bfm_gl_exec_create(getproc, scale, err, sizeof err))) {
        printf("FAIL exec create: %s\n", err);
        return 1;
    }
    bfm_gl_vram_init(&glvram);
    bfm_gl_batch_init(&B);
    B.vram = &glvram;

    memset(&out, 0, sizeof out);
    CHECK(bfm_plat_renderer_register(&gl_backend) == BFM_PLAT_OK);
    CHECK(bfm_plat_renderer_open("ctlprobe", &out, NULL) == BFM_PLAT_OK);
    bfm_gpu_bridge_init(&bridge);

    memset(&be, 0, sizeof be);
    be.reset = c_ok; be.draw_mode = c_word; be.display_enable = c_en; be.clear_fifo = c_ok;
    be.ready = c_ok; be.environment = c_word; be.display = c_disp; be.fill_vram = c_fill;
    be.store_vram = c_store; be.read_vram = c_load;
    CHECK(musashi_gpu_controller_init(&ctl, &be));

    seed = 20261001u;
    build_setup();
    run_stream();
    for (sc = 0; sc < scenes; sc++) {
        build_scene(0, 0, (unsigned)(sc & 3));
        run_stream();
        compare_scene(0, 0, sc == 0);
        build_scene(256, 1, (unsigned)(sc & 3));
        run_stream();
        compare_scene(256, 1, sc == 0);
    }
    CHECK(st.refused == 0);
    CHECK(bfm_gl_exec_error(X) == 0);

    printf("gl %dx vs controller, %d scenes, %zu gl prims:\n", scale, scenes, gl_prims);
    printf("  %-8s %-5s %8s %8s %6s %7s %7s %7s %7s\n", "kind", "semi", "pixels", "same",
           "mask", "edge", "col=1", "cover", "col>1");
    for (semi = 0; semi < 2; semi++)
        for (k = 0; k < K_COUNT; k++) {
            const Stat *s = &stats[semi][k];
            if (!s->pixels) continue;
            printf("  %-8s %-5s %8ld %8ld %6ld %7ld %7ld %7ld %7ld\n", kind_name[k],
                   semi ? "yes" : "no", s->pixels, s->same, s->mask, s->edge, s->colour1,
                   s->coverage, s->colour2);
            edges += s->edge;
            if (semi) {
                semi_bad += s->coverage + s->colour2 + s->mask;
                semi_step += s->colour1;
            } else {
                opaque_bad += s->coverage + s->colour1 + s->colour2 + s->mask;
            }
        }
    printf("opaque non-edge differences: %ld; semi coverage/mask/>1-step: %ld, one-step: %ld; "
           "edge-rule pixels (D-030): %ld\n", opaque_bad, semi_bad, semi_step, edges);
    CHECK(opaque_bad == 0);
    CHECK(semi_bad == 0);

    bfm_gl_batch_free(&B);
    bfm_gl_exec_destroy(X);
    bfm_gpu_bridge_free(&bridge);
    bfm_plat_renderer_close();
    destroy(ctx);
    if (!fails) printf("ok ctl\n");
    return fails ? 1 : 0;
}
