/* MSAA tests for the `gl` renderer's executor (bfm_gl_exec_set_msaa) on a real
 * GL 3.3 core context made through SDL: a display, xvfb, or SDL's offscreen
 * driver with EGL. No OSMesa needed. Prints "skip ..." and exits 0 when no
 * context (or no multisampling) is available. Synthetic scenes only.
 *
 * Every scene is drawn twice, on a single-sample executor and on an MSAA one,
 * from the same primitives, and compared pixel by pixel after the resolve:
 *   - flat / Gouraud / textured polygons: the MSAA image may differ only
 *     within two pixels of a silhouette edge; every pixel further in or out is
 *     identical, and edge pixels really blend (resolved data);
 *   - pixel-aligned rects (tiles, sprites, fills, copies, semi-transparency):
 *     the whole image is identical;
 *   - a textured triangle whose texture has a magenta frame just outside the
 *     texels it uses: no pixel shows magenta (no bleed from fringe pixels);
 *   - the E6 mask bit: a mask-check draw over a mask-set triangle edge leaves
 *     exactly the samples the triangle covered (a per-sample stencil);
 *   - render feedback: a sprite sampling a rendered area (SNAPSHOT) copies
 *     its resolved pixels, and the 16-bit readback agrees with the RGBA one;
 *   - present: the window shows the resolved image;
 *   - set_msaa(0) restores the single-sample executor; the GPU clamp; the
 *     internal scale 2; the memory fit.
 * The same scenes run on the single-sample executor print "HASH name fnv";
 * build with -DBFM_MSAA_PROBE_BASE against an executor without
 * bfm_gl_exec_set_msaa (the code before MSAA) and the hashes of the two builds
 * must be equal: msaa = 0 is the old renderer, pixel for pixel. */

#include "backends/gl/bfm_gl_core.h"
#include "backends/gl/bfm_gl_exec.h"

#include <SDL.h>

#include <stdint.h>
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

#define WIN_W 640
#define WIN_H 480
#define AREA_W 160    /* the draw area of the VRAM-target scenes */
#define AREA_H 120

static void *getproc(const char *n) { return SDL_GL_GetProcAddress(n); }

static BfmPlatRect R(int x, int y, int w, int h) {
    BfmPlatRect r;
    r.x = (int16_t)x; r.y = (int16_t)y; r.w = (int16_t)w; r.h = (int16_t)h;
    return r;
}
static uint16_t rgb15(int r, int g, int b) { return (uint16_t)(r | (g << 5) | (b << 10)); }
static uint16_t tp(int depth_code, int abr, int x, int y) {
    return (uint16_t)(((depth_code & 3) << 7) | ((abr & 3) << 5) | ((y & 0x100) >> 4) |
                      ((x & 0x3FF) >> 6));
}

/* ---- a rig: one executor with its own batch and VRAM mirror ---- */
/* A rig draws either into the VRAM target (scene = 0: the display is elsewhere, so the 160x120 draw area at VRAM
 * (0, 0) is plain VRAM) or into scene slot 0 (scene = 1: the display is at (0, 0) and the clip is display-sized, which
 * is how the game draws its frame buffers). The batcher routes by exactly that, so the target a scene lands in is
 * the rig's `target`; cw x ch is its clip. */
typedef struct Rig {
    BfmGlExec *x;
    BfmGlBatch b;
    BfmGlVram *v;
    int scale, eff, scene, target, cw, ch;
} Rig;

static int rig_open(Rig *r, int scale, int msaa, int scene) {
    char err[256] = "";
    BfmPlatRect disp = scene ? R(0, 0, 320, 240) : R(0, 256, 320, 240);
    memset(r, 0, sizeof *r);
    r->scale = scale;
    r->scene = scene;
    r->target = scene ? BFM_GL_TARGET_SCENE0 : BFM_GL_TARGET_VRAM;
    r->cw = scene ? 320 : AREA_W;
    r->ch = scene ? 240 : AREA_H;
    if (!(r->x = bfm_gl_exec_create(getproc, scale, err, sizeof err))) {
        printf("FAIL exec create: %s\n", err);
        fails++;
        return 0;
    }
    if (!(r->v = (BfmGlVram *)malloc(sizeof *r->v))) {
        fails++;
        return 0;
    }
    bfm_gl_vram_init(r->v);
    bfm_gl_batch_init(&r->b);
    r->b.vram = r->v;
    bfm_gl_batch_set_display(&r->b, &disp, 0);
#ifndef BFM_MSAA_PROBE_BASE
    if (msaa) r->eff = bfm_gl_exec_set_msaa(r->x, msaa);
#else
    (void)msaa;
#endif
    return 1;
}

static void rig_close(Rig *r) {
    CHECK(bfm_gl_exec_error(r->x) == 0);
    bfm_gl_batch_free(&r->b);
    free(r->v);
    bfm_gl_exec_destroy(r->x);
}

static void rig_flush(Rig *r) {
    bfm_gl_exec_sync_vram(r->x, r->v);
    CHECK(bfm_gl_exec_run(r->x, &r->b, 0) == BFM_PLAT_OK);
    bfm_gl_batch_clear(&r->b);
}

/* RGBA8 at device resolution of the target-local 1x rect (row 0 = its top). */
static uint8_t *rig_rgba(Rig *r, int target, int x, int y, int w, int h) {
    BfmPlatRect rc = R(x, y, w, h);
    uint8_t *out = (uint8_t *)malloc((size_t)w * h * r->scale * r->scale * 4u);
    rig_flush(r);
    CHECK(out && bfm_gl_exec_readback_rgba(r->x, &r->b, target, &rc, out) == BFM_PLAT_OK);
    return out;
}

/* ---- primitives ---- */
static BfmPlatPrim prim(int kind) {
    BfmPlatPrim p;
    memset(&p, 0, sizeof p);
    p.kind = (uint8_t)kind;
    return p;
}
static void vtx(BfmPlatVertex *v, int x, int y, int u, int w, int r, int g, int b) {
    v->x = (int16_t)x; v->y = (int16_t)y; v->u = (uint8_t)u; v->v = (uint8_t)w;
    v->r = (uint8_t)r; v->g = (uint8_t)g; v->b = (uint8_t)b;
}
static void add(Rig *r, const BfmPlatPrim *p) { bfm_gl_batch_add(&r->b, p, 1); }

static void env_clip(Rig *r, int x, int y, int w, int h, int clear, int br, int bg, int bb) {
    BfmPlatDrawEnv e;
    memset(&e, 0, sizeof e);
    e.clip = R(x, y, w, h);
    e.clear_bg = (uint8_t)clear;
    e.bg_r = (uint8_t)br; e.bg_g = (uint8_t)bg; e.bg_b = (uint8_t)bb;
    bfm_gl_batch_set_env(&r->b, &e);
}
static void f3(Rig *r, int x0, int y0, int x1, int y1, int x2, int y2, int cr, int cg, int cb,
               int flags) {
    BfmPlatPrim p = prim(BFM_PRIM_POLY_F3);
    vtx(&p.v[0], x0, y0, 0, 0, cr, cg, cb);
    vtx(&p.v[1], x1, y1, 0, 0, 0, 0, 0);
    vtx(&p.v[2], x2, y2, 0, 0, 0, 0, 0);
    p.flags = (uint8_t)flags;
    add(r, &p);
}
static void f4(Rig *r, const int xy[8], int cr, int cg, int cb) {
    BfmPlatPrim p = prim(BFM_PRIM_POLY_F4);
    vtx(&p.v[0], xy[0], xy[1], 0, 0, cr, cg, cb);
    vtx(&p.v[1], xy[2], xy[3], 0, 0, 0, 0, 0);
    vtx(&p.v[2], xy[4], xy[5], 0, 0, 0, 0, 0);
    vtx(&p.v[3], xy[6], xy[7], 0, 0, 0, 0, 0);
    add(r, &p);
}
static void g3(Rig *r, const int xy[6], const int rgb[9]) {
    BfmPlatPrim p = prim(BFM_PRIM_POLY_G3);
    int i;
    for (i = 0; i < 3; i++) vtx(&p.v[i], xy[i * 2], xy[i * 2 + 1], 0, 0, rgb[i * 3], rgb[i * 3 + 1], rgb[i * 3 + 2]);
    add(r, &p);
}
static void ft3(Rig *r, const int xy[6], const int uv[6], uint16_t tpage) {
    BfmPlatPrim p = prim(BFM_PRIM_POLY_FT3);
    int i;
    for (i = 0; i < 3; i++) vtx(&p.v[i], xy[i * 2], xy[i * 2 + 1], uv[i * 2], uv[i * 2 + 1], 128, 128, 128);
    p.tpage = tpage;
    p.flags = BFM_PRIM_FLAG_RAW_TEXTURE;
    add(r, &p);
}
static void rect(Rig *r, int kind, int x, int y, int w, int h, int cr, int cg, int cb, int flags,
                 uint16_t tpage) {
    BfmPlatPrim p = prim(kind);
    vtx(&p.v[0], x, y, 0, 0, cr, cg, cb);
    p.w = (uint16_t)w; p.h = (uint16_t)h;
    p.flags = (uint8_t)flags;
    p.tpage = tpage;
    add(r, &p);
}
static void sprite(Rig *r, int x, int y, int w, int h, uint16_t tpage, int u, int v, int flags) {
    BfmPlatPrim p = prim(BFM_PRIM_SPRITE);
    vtx(&p.v[0], x, y, u, v, 128, 128, 128);
    p.w = (uint16_t)w; p.h = (uint16_t)h;
    p.tpage = tpage;
    p.flags = (uint8_t)flags;
    add(r, &p);
}

/* A 64x64 15-bit texture at VRAM (640, 0): texels 16..47 in both directions
 * hold a smooth gradient (never 0x0000, never blue, neighbouring texels at most one
 * step apart); everything outside is magenta, so anything a fringe pixel fetches
 * beyond the used texels shows. */
static void upload_texture(Rig *r) {
    static uint16_t px[64 * 64];
    BfmPlatRect rc = R(640, 0, 64, 64);
    int u, v;
    for (v = 0; v < 64; v++)
        for (u = 0; u < 64; u++)
            px[v * 64 + u] = (u >= 16 && u < 48 && v >= 16 && v < 48)
                                 ? rgb15(2 + (u - 16) * 27 / 31, 2 + (v - 16) * 27 / 31, 0)
                                 : rgb15(31, 0, 31);
    rig_flush(r);   /* queued prims still sample the old texels */
    CHECK(bfm_gl_vram_upload(r->v, &rc, px) == BFM_PLAT_OK);
    bfm_gl_batch_add_copy(&r->b, &rc);
}

/* ---- scenes (draw area 160x120 on the VRAM target unless the clip is the display) ---- */
static void scene_flat(Rig *r) {
    static const int quad[8] = {52, 85, 90, 82, 50, 110, 88, 112};
    env_clip(r, 0, 0, r->cw, r->ch, 1, 0, 0, 0);
    f3(r, 8, 8, 80, 20, 30, 70, 248, 24, 24, 0);          /* big, slanted */
    f3(r, 90, 10, 150, 14, 92, 16, 24, 248, 24, 0);       /* thin sliver: all edge */
    f3(r, 100, 40, 112, 110, 150, 60, 24, 24, 248, 0);    /* steep */
    rect(r, BFM_PRIM_TILE, 10, 80, 30, 25, 248, 248, 24, 0, 0);   /* pixel-aligned */
    f4(r, quad, 248, 24, 248);
}

static void scene_gouraud(Rig *r) {
    static const int xy[6] = {12, 10, 140, 22, 50, 105};
    static const int rgb[9] = {248, 24, 24, 24, 248, 24, 24, 24, 248};
    env_clip(r, 0, 0, r->cw, r->ch, 1, 0, 0, 0);
    g3(r, xy, rgb);
}

static void scene_textured(Rig *r) {
    static const int xy[6] = {24, 16, 120, 20, 40, 100};
    static const int uv[6] = {16, 16, 47, 16, 16, 47};   /* inside the gradient, 1 texel from the magenta */
    upload_texture(r);
    env_clip(r, 0, 0, r->cw, r->ch, 1, 0, 0, 0);
    ft3(r, xy, uv, tp(2, 0, 640, 0));
}

static void scene_aligned(Rig *r) {
    upload_texture(r);
    env_clip(r, 0, 0, r->cw, r->ch, 1, 0, 0, 0);
    rect(r, BFM_PRIM_TILE, 10, 10, 40, 30, 248, 24, 24, 0, 0);
    sprite(r, 60, 10, 32, 32, tp(2, 0, 640, 0), 16, 16, BFM_PRIM_FLAG_RAW_TEXTURE);
    rect(r, BFM_PRIM_FILL, 100, 10, 40, 30, 24, 248, 24, 0, 0);
    rect(r, BFM_PRIM_TILE, 30, 25, 40, 20, 24, 24, 248, BFM_PRIM_FLAG_SEMI_TRANS, tp(2, 1, 0, 0));
    rect(r, BFM_PRIM_TILE, 20, 60, 100, 40, 200, 100, 24, 0, 0);
    rect(r, BFM_PRIM_TILE, 40, 70, 50, 20, 24, 96, 24, BFM_PRIM_FLAG_SEMI_TRANS, tp(2, 0, 0, 0));
    sprite(r, 70, 62, 32, 32, tp(2, 2, 640, 0), 16, 16, BFM_PRIM_FLAG_RAW_TEXTURE | BFM_PRIM_FLAG_SEMI_TRANS);
}

/* The E6 mask bit. X: blue background, then the red mask-set triangle. Y: black
 * background, the same triangle, then a blue tile with mask-check over the lot.
 * A per-sample stencil makes the two images identical, edge samples included.
 * Pure channels (0 / 255): a fill writes its byte as given, a draw the byte of its
 * 5-bit value, and only 0 and 255 are the same byte both ways. */
static void scene_mask(Rig *r, int variant_y) {
    static const int xy[6] = {20, 20, 120, 30, 50, 100};
    if (!variant_y) {
        env_clip(r, 0, 0, r->cw, r->ch, 1, 0, 0, 255);
        f3(r, xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], 255, 0, 0, BFM_PRIM_FLAG_MASK_SET);
    } else {
        env_clip(r, 0, 0, r->cw, r->ch, 1, 0, 0, 0);
        f3(r, xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], 255, 0, 0, BFM_PRIM_FLAG_MASK_SET);
        rect(r, BFM_PRIM_TILE, 0, 0, r->cw, r->ch, 0, 0, 255, BFM_PRIM_FLAG_MASK_CHECK, 0);
    }
}

/* ---- image analysis ---- */
static uint64_t fnv(const uint8_t *p, size_t n) {
    uint64_t h = 1469598103934665603ULL;
    size_t i;
    for (i = 0; i < n; i++) {
        h ^= p[i];
        h *= 1099511628211ULL;
    }
    return h;
}
static void hash_line(const char *name, const uint8_t *p, size_t n) {
    printf("HASH %s %016llx\n", name, (unsigned long long)fnv(p, n));
}

/* ---- the msaa = 0 scenes, hashed (also what a build against the pre-MSAA executor prints) ---- */
typedef void (*SceneFn)(Rig *);
static void sc_flat(Rig *r) { scene_flat(r); }
static void sc_gouraud(Rig *r) { scene_gouraud(r); }
static void sc_textured(Rig *r) { scene_textured(r); }
static void sc_aligned(Rig *r) { scene_aligned(r); }
static void sc_mask_x(Rig *r) { scene_mask(r, 0); }
static void sc_mask_y(Rig *r) { scene_mask(r, 1); }

static const struct { const char *name; SceneFn fn; } SCENES[] = {
    {"flat", sc_flat}, {"gouraud", sc_gouraud}, {"textured", sc_textured},
    {"aligned", sc_aligned}, {"mask_x", sc_mask_x}, {"mask_y", sc_mask_y}};

static uint8_t *render(Rig *r, SceneFn fn) {
    fn(r);
    return rig_rgba(r, r->target, 0, 0, AREA_W, AREA_H);
}

static int count_lit(const uint8_t *p, size_t n) {
    size_t i;
    int c = 0;
    for (i = 0; i < n; i++) c += p[i * 4] || p[i * 4 + 1] || p[i * 4 + 2];
    return c;
}

/* Every scene, both targets, 1x and 2x, single-sample: "HASH name fnv" and how many pixels the scene lit (a scene
 * that drew nothing would hash like every other empty one). */
static void hashes(void) {
    size_t i;
    int scale, scene;
    for (scene = 0; scene <= 1; scene++)
        for (scale = 1; scale <= 2; scale++)
            for (i = 0; i < sizeof SCENES / sizeof SCENES[0]; i++) {
                Rig r;
                uint8_t *img;
                char name[64];
                size_t n = (size_t)AREA_W * AREA_H * scale * scale;
                if (!rig_open(&r, scale, 0, scene)) return;
                img = render(&r, SCENES[i].fn);
                snprintf(name, sizeof name, "%s@%dx%s", SCENES[i].name, scale, scene ? "/scene" : "");
                hash_line(name, img, n * 4u);
                printf("LIT %s %d\n", name, count_lit(img, n));
                CHECK(count_lit(img, n) > 1000);
                free(img);
                rig_close(&r);
            }
}

#ifndef BFM_MSAA_PROBE_BASE

static const uint8_t BLACK[3] = {0, 0, 0};

static int is_bg(const uint8_t *p, const uint8_t *bg) { return p[0] == bg[0] && p[1] == bg[1] && p[2] == bg[2]; }

/* 1 when every pixel within Chebyshev radius rad of (x, y) has the coverage of (x, y). */
static int uniform_cov(const uint8_t *cov, int w, int h, int x, int y, int rad) {
    int i, j;
    for (j = y - rad; j <= y + rad; j++)
        for (i = x - rad; i <= x + rad; i++)
            if (i >= 0 && j >= 0 && i < w && j < h && cov[j * w + i] != cov[y * w + x]) return 0;
    return 1;
}

typedef struct Cmp {
    int diff, interior_diff, edge_diff, blended, bluish, max_interior_delta;
} Cmp;

/* a = single-sample image, b = MSAA image (RGBA, w x h). Differences are classified by the coverage of a (the pixels
 * that are not the background): interior = no coverage change within rad pixels, edge = the rest. flat: a is made of a
 * few flat colours (the distinct colours of a), so a pixel of b outside them and the background is a blend of
 * resolved samples. bluish: pixels of b with a blue channel above 100 (the magenta sentinel's, in a scene that draws
 * no blue). max_interior_delta: the largest channel difference among interior differences. */
static Cmp compare(const uint8_t *a, const uint8_t *b, int w, int h, const uint8_t *bg, int rad, int flat) {
    Cmp c;
    uint8_t pal[32][3];
    int npal = 0, x, y, k;
    uint8_t *cov = (uint8_t *)malloc((size_t)w * h);
    memset(&c, 0, sizeof c);
    CHECK(cov != NULL);
    if (!cov) return c;
    for (y = 0; y < h; y++)
        for (x = 0; x < w; x++) {
            const uint8_t *pa = &a[((size_t)y * w + x) * 4];
            cov[y * w + x] = !is_bg(pa, bg);
            if (flat && npal <= 32) {
                int known = 0;
                for (k = 0; k < npal; k++) known |= pa[0] == pal[k][0] && pa[1] == pal[k][1] && pa[2] == pal[k][2];
                if (!known && npal < 32) { pal[npal][0] = pa[0]; pal[npal][1] = pa[1]; pal[npal][2] = pa[2]; npal++; }
                else if (!known) npal = 33;   /* too many colours for a flat scene */
            }
        }
    for (y = 0; y < h; y++)
        for (x = 0; x < w; x++) {
            const uint8_t *pa = &a[((size_t)y * w + x) * 4], *pb = &b[((size_t)y * w + x) * 4];
            if (pb[2] > 100) c.bluish++;
            if (memcmp(pa, pb, 4) != 0) {
                c.diff++;
                if (uniform_cov(cov, w, h, x, y, rad)) {
                    int d = 0;
                    c.interior_diff++;
                    for (k = 0; k < 4; k++) {
                        int e = abs((int)pa[k] - (int)pb[k]);
                        if (e > d) d = e;
                    }
                    if (d > c.max_interior_delta) c.max_interior_delta = d;
                } else {
                    c.edge_diff++;
                }
            }
            if (flat && npal <= 32 && !is_bg(pb, bg)) {
                int known = 0;
                for (k = 0; k < npal; k++) known |= pb[0] == pal[k][0] && pb[1] == pal[k][1] && pb[2] == pal[k][2];
                if (!known) c.blended++;
            }
        }
    free(cov);
    return c;
}

static void report(const char *name, int eff, int scale, const Cmp *c) {
    printf("msaa %s eff=%d scale=%d: diff=%d interior_diff=%d (max delta %d) edge_diff=%d blended=%d bluish=%d\n", name,
           eff, scale, c->diff, c->interior_diff, c->max_interior_delta, c->edge_diff, c->blended, c->bluish);
}

/* ---- window readback for the present test ---- */
typedef void (*ReadPixelsFn)(int, int, int, int, unsigned, unsigned, void *);
typedef void (*FinishFn)(void);

static uint8_t *present_flat(Rig *r) {
    static ReadPixelsFn rp;
    static FinishFn fin;
    void *o;
    uint8_t *win = (uint8_t *)malloc((size_t)WIN_W * WIN_H * 4u);
    if (!rp) {
        o = getproc("glReadPixels"); memcpy(&rp, &o, sizeof o);
        o = getproc("glFinish"); memcpy(&fin, &o, sizeof o);
    }
    scene_flat(r);                       /* a scene rig: the display-sized clip */
    rig_flush(r);
    CHECK(bfm_gl_exec_present(r->x, &r->b, NULL, WIN_W, WIN_H, 4.0 / 3.0, 0) == BFM_PLAT_OK);
    fin();
    rp(0, 0, WIN_W, WIN_H, 0x1908 /* GL_RGBA */, 0x1401 /* GL_UNSIGNED_BYTE */, win);
    return win;
}

static void test_polygons(int scale, int scene) {
    static const struct { const char *name; SceneFn fn; int flat, no_blue; } T[] = {
        {"flat", sc_flat, 1, 0}, {"gouraud", sc_gouraud, 0, 0}, {"textured", sc_textured, 0, 1}};
    size_t i;
    for (i = 0; i < sizeof T / sizeof T[0]; i++) {
        Rig a, b;
        uint8_t *ia, *ib;
        Cmp c;
        char name[48];
        if (!rig_open(&a, scale, 0, scene) || !rig_open(&b, scale, 4, scene)) return;
        CHECK(b.eff >= 2);
        ia = render(&a, T[i].fn);
        ib = render(&b, T[i].fn);
        c = compare(ia, ib, AREA_W * scale, AREA_H * scale, BLACK, 2 * scale + 1, T[i].flat);
        snprintf(name, sizeof name, "%s@%dx%s", T[i].name, scale, scene ? "/scene" : "");
        report(name, b.eff, scale, &c);
        if (scale == 1 || T[i].flat) CHECK(c.interior_diff == 0);   /* only edge pixels change */
        else CHECK(c.max_interior_delta <= 12);   /* 2x: the sample point of a gradient / a texel moved half a device
                                                    * pixel: at most one step of a channel, never garbage */
        CHECK(c.diff > 0 && c.edge_diff > 0);     /* ... and they do change */
        if (T[i].no_blue) CHECK(c.bluish == 0);   /* no magenta (texture bleed) anywhere */
        if (T[i].flat) CHECK(c.blended > 0);      /* edge pixels hold blends: resolved data */
        free(ia);
        free(ib);
        rig_close(&a);
        rig_close(&b);
    }
}

static void test_aligned(int scene) {
    Rig a, b;
    uint8_t *ia, *ib;
    if (!rig_open(&a, 1, 0, scene) || !rig_open(&b, 1, 4, scene)) return;
    ia = render(&a, sc_aligned);
    ib = render(&b, sc_aligned);
    CHECK(count_lit(ia, (size_t)AREA_W * AREA_H) > 4000);   /* the shapes are there */
    printf("msaa aligned%s eff=%d: %s\n", scene ? "/scene" : "", b.eff,
           memcmp(ia, ib, (size_t)AREA_W * AREA_H * 4u) == 0 ? "whole image identical" : "DIFFERS");
    CHECK(memcmp(ia, ib, (size_t)AREA_W * AREA_H * 4u) == 0);
    free(ia);
    free(ib);
    rig_close(&a);
    rig_close(&b);
}

static void test_mask(int scene) {
    int eff;
    for (eff = 0; eff <= 4; eff += 4) {
        Rig x, y;
        uint8_t *ix, *iy;
        BfmGlMsaaStats st;
        int diff = 0, n = AREA_W * AREA_H, i, edge = 0;
        const uint8_t *blue, *red;
        if (!rig_open(&x, 1, eff, scene) || !rig_open(&y, 1, eff, scene)) return;
        ix = render(&x, sc_mask_x);
        iy = render(&y, sc_mask_y);
        blue = &ix[0];                          /* the background */
        red = &ix[(50 * AREA_W + 63) * 4];      /* inside the triangle */
        for (i = 0; i < n; i++) {
            diff += memcmp(&ix[i * 4], &iy[i * 4], 4) != 0;
            edge += memcmp(&ix[i * 4], blue, 3) != 0 && memcmp(&ix[i * 4], red, 3) != 0;   /* neither colour: a blend */
        }
        bfm_gl_exec_msaa_stats(y.x, &st);
        printf("msaa mask%s eff=%d: tile with mask-check over the mask-set triangle vs triangle over blue: %d px differ, "
               "%d blended edge px, stencil_builds=%u\n", scene ? "/scene" : "", y.eff, diff, edge,
               st.stencil_builds);
        CHECK(diff == 0);
        if (eff) {
            CHECK(edge > 0 && st.stencil_builds == 1);
        } else {
            CHECK(st.stencil_builds == 0);
        }
        free(ix);
        free(iy);
        rig_close(&x);
        rig_close(&y);
    }
}

/* Render feedback and readback: a triangle drawn into area A, then a sprite in area B (same VRAM target) sampling A as
 * a 15-bit page, which makes the batch SNAPSHOT A. B must hold A's resolved pixels (the blends of its edges too). */
static void test_feedback(int scene) {
    Rig r;
    static const int xy[6] = {4, 4, 60, 14, 20, 58};
    uint8_t *a, *b;
    uint16_t px[64 * 64];
    BfmPlatRect ra = R(0, 0, 64, 64);
    int i, bad = 0, nonbg = 0, blended = 0, by;
    BfmGlMsaaStats st;
    if (!rig_open(&r, 1, 4, scene)) return;
    if (scene) env_clip(&r, 0, 0, r.cw, r.ch, 1, 0, 0, 0);   /* A is part of the frame buffer: scene slot 0 */
    else env_clip(&r, 0, 0, 64, 64, 1, 0, 0, 0);               /* A is plain VRAM */
    f3(&r, xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], 248, 24, 24, 0);
    by = scene ? 300 : 190;                                    /* B: plain VRAM, outside this rig's display rect */
    env_clip(&r, 0, by, 64, 64, 1, 0, 0, 0);
    sprite(&r, 0, by, 64, 64, tp(2, 0, 0, 0), 0, 0, BFM_PRIM_FLAG_RAW_TEXTURE);
    a = rig_rgba(&r, r.target, 0, 0, 64, 64);
    b = rig_rgba(&r, BFM_GL_TARGET_VRAM, 0, by, 64, 64);
    for (i = 0; i < 64 * 64; i++) {
        bad += memcmp(&a[i * 4], &b[i * 4], 3) != 0;   /* RGB: the alpha (mask bit) is a threshold in a snapshot */
        nonbg += a[i * 4] != 0 || a[i * 4 + 1] != 0 || a[i * 4 + 2] != 0;
        blended += a[i * 4] > 0 && a[i * 4] < 255;
    }
    bfm_gl_exec_msaa_stats(r.x, &st);
    printf("msaa feedback%s eff=%d: snapshot copy of the rendered triangle: %d of %d px differ, %d lit, %d blended, "
           "snapshots=%u\n", scene ? "/scene" : "", r.eff, bad, 64 * 64, nonbg, blended, st.snapshots);
    CHECK(bad == 0 && nonbg > 500 && blended > 0 && st.snapshots >= 1);
    /* the 16-bit readback is the resolved image, 5 bits a channel, mask bit from alpha */
    CHECK(bfm_gl_exec_readback(r.x, &r.b, r.target, &ra, px) == BFM_PLAT_OK);
    for (i = 0; i < 64 * 64; i++) {
        uint16_t want = (uint16_t)((a[i * 4] >> 3) | ((a[i * 4 + 1] >> 3) << 5) | ((a[i * 4 + 2] >> 3) << 10) |
                                   (a[i * 4 + 3] >= 128 ? 0x8000 : 0));
        if (px[i] != want) bad++;
    }
    CHECK(bad == 0);
    printf("msaa readback%s eff=%d: 16-bit readback equals the resolved RGBA image over %d px\n", scene ? "/scene" : "",
           r.eff, 64 * 64);
    free(a);
    free(b);
    rig_close(&r);
}

static void test_present(void) {
    Rig a, b;
    uint8_t *wa, *wb;
    Cmp c;
    BfmGlMsaaStats st;
    if (!rig_open(&a, 1, 0, 1) || !rig_open(&b, 1, 4, 1)) return;
    wa = present_flat(&a);
    wb = present_flat(&b);
    c = compare(wa, wb, WIN_W, WIN_H, BLACK, 4, 1);
    bfm_gl_exec_msaa_stats(b.x, &st);
    report("present", b.eff, 1, &c);
    CHECK(c.interior_diff == 0 && c.diff > 0 && c.blended > 0 && st.presents == 1);
    free(wa);
    free(wb);
    rig_close(&a);
    rig_close(&b);
}

/* set_msaa(0) goes back to the single-sample executor; clamps; the memory fit. */
static void test_lifecycle(void) {
    Rig r, ref;
    uint8_t *i0, *i1;
    int got;
    if (!rig_open(&ref, 1, 0, 0) || !rig_open(&r, 1, 4, 0)) return;
    CHECK(bfm_gl_exec_msaa(r.x) == r.eff && r.eff >= 2);
    printf("msaa note: %s\n", bfm_gl_exec_msaa_note(r.x));
    /* off again: the very same pixels as an executor that never had MSAA */
    CHECK(bfm_gl_exec_set_msaa(r.x, 0) == 0 && bfm_gl_exec_msaa(r.x) == 0);
    i0 = render(&ref, sc_flat);
    i1 = render(&r, sc_flat);
    CHECK(memcmp(i0, i1, (size_t)AREA_W * AREA_H * 4u) == 0);
    free(i0);
    free(i1);
    /* a request beyond the GPU's limit is clamped; the result is what the framebuffer holds */
    got = bfm_gl_exec_set_msaa(r.x, 16);
    printf("msaa clamp: request 16 -> %d (%s)\n", got, bfm_gl_exec_msaa_note(r.x));
    CHECK(got >= 2 && got <= 16 && got == bfm_gl_exec_msaa(r.x));
    /* a request of 2 holds what the driver allocated (llvmpipe rounds it up to 4) */
    got = bfm_gl_exec_set_msaa(r.x, 2);
    printf("msaa clamp: request 2 -> %d\n", got);
    CHECK(got >= 2 && got == bfm_gl_exec_msaa(r.x));
    /* off for good with < 2 samples; not a request */
    CHECK(bfm_gl_exec_set_msaa(r.x, 1) == 0 && bfm_gl_exec_msaa(r.x) == 0);
    /* internal scale 5 with 8 samples: the VRAM target's multisample colour is held to 256 MiB, so fewer are asked for */
    got = bfm_gl_exec_set_msaa(r.x, 8);
    CHECK(got >= 2);
    CHECK(bfm_gl_exec_set_scale(r.x, 5) == BFM_PLAT_OK);
    printf("msaa fit: 8 samples at 1x held %d; at 5x the VRAM target holds %d (%s)\n", got, bfm_gl_exec_msaa(r.x),
           bfm_gl_exec_msaa_note(r.x));
    CHECK(bfm_gl_exec_msaa(r.x) > 0);
    if (got == 8) CHECK(bfm_gl_exec_msaa(r.x) == 4);   /* 5x: 8 samples would be 400 MiB, 4 are 200 */
    CHECK(bfm_gl_exec_set_scale(r.x, 1) == BFM_PLAT_OK && bfm_gl_exec_msaa(r.x) == got);   /* and back */
    rig_close(&r);
    rig_close(&ref);
}

static int run_msaa(void) {
    Rig probe;
    if (!rig_open(&probe, 1, 4, 0)) return 1;
    if (probe.eff < 2) {
        printf("skip msaa: %s\n", bfm_gl_exec_msaa_note(probe.x));
        rig_close(&probe);
        return 0;
    }
    printf("msaa probe: effective samples %d (%s)\n", probe.eff, bfm_gl_exec_msaa_note(probe.x));
    rig_close(&probe);
    test_polygons(1, 0);
    test_polygons(1, 1);
    test_polygons(2, 0);
    test_polygons(2, 1);
    test_aligned(0);
    test_aligned(1);
    test_mask(0);
    test_mask(1);
    test_feedback(0);
    test_feedback(1);
    test_present();
    test_lifecycle();
    return fails;
}
#endif

int main(void) {
    SDL_Window *win;
    SDL_GLContext ctx;
    typedef const unsigned char *(*GetStringFn)(unsigned);
    GetStringFn gs;
    void *o;
    int rc = 0;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("skip msaa: SDL video: %s\n", SDL_GetError());
        return 0;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    win = SDL_CreateWindow("bfm_gl_msaa_probe", 0, 0, WIN_W, WIN_H, SDL_WINDOW_OPENGL);
    if (!win || !(ctx = SDL_GL_CreateContext(win))) {
        printf("skip msaa: no GL 3.3 core context: %s\n", SDL_GetError());
        return 0;
    }
    o = getproc("glGetString");
    memcpy(&gs, &o, sizeof o);
    printf("GL: %s | %s (SDL video driver %s)\n", gs(0x1F02), gs(0x1F01), SDL_GetCurrentVideoDriver());
    hashes();
#ifndef BFM_MSAA_PROBE_BASE
    rc = run_msaa();
#endif
    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(win);
    SDL_Quit();
    if (rc || fails) {
        printf("%d failure(s)\n", rc ? rc : fails);
        return 1;
    }
    printf("ok msaa\n");
    return 0;
}
