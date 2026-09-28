/* CPU side of the `gl` renderer backend. See bfm_gl_core.h. */

#include "bfm_gl_core.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

/* ---- VRAM mirror ---------------------------------------------------- */

void bfm_gl_vram_init(BfmGlVram *v) {
    memset(v, 0, sizeof *v);
}

void bfm_gl_vram_mark(BfmGlVram *v, int x, int y, int w, int h) {
    int x1 = x + w, y1 = y + h;
    if (w <= 0 || h <= 0) return;
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x1 > BFM_GL_VRAM_W) x1 = BFM_GL_VRAM_W;
    if (y1 > BFM_GL_VRAM_H) y1 = BFM_GL_VRAM_H;
    if (x >= x1 || y >= y1) return;
    if (!v->dirty) {
        v->dirty = 1;
        v->dx0 = x; v->dy0 = y; v->dx1 = x1; v->dy1 = y1;
        return;
    }
    if (x < v->dx0) v->dx0 = x;
    if (y < v->dy0) v->dy0 = y;
    if (x1 > v->dx1) v->dx1 = x1;
    if (y1 > v->dy1) v->dy1 = y1;
}

int bfm_gl_vram_upload(BfmGlVram *v, const BfmPlatRect *r, const uint16_t *px) {
    int row;
    if (!v || !px || !bfm_plat_rect_valid(r)) return BFM_PLAT_INVALID;
    for (row = 0; row < r->h; row++)
        memcpy(&v->px[(size_t)(r->y + row) * BFM_GL_VRAM_W + r->x],
               px + (size_t)row * r->w, (size_t)r->w * 2u);
    bfm_gl_vram_mark(v, r->x, r->y, r->w, r->h);
    return BFM_PLAT_OK;
}

int bfm_gl_vram_download(const BfmGlVram *v, const BfmPlatRect *r, uint16_t *px) {
    int row;
    if (!v || !px || !bfm_plat_rect_valid(r)) return BFM_PLAT_INVALID;
    for (row = 0; row < r->h; row++)
        memcpy(px + (size_t)row * r->w,
               &v->px[(size_t)(r->y + row) * BFM_GL_VRAM_W + r->x],
               (size_t)r->w * 2u);
    return BFM_PLAT_OK;
}

int bfm_gl_vram_move(BfmGlVram *v, const BfmPlatRect *src, int x, int y) {
    uint16_t *tmp;
    int i, j, wraps;
    if (!v || !bfm_plat_rect_valid(src)) return BFM_PLAT_INVALID;
    tmp = (uint16_t *)malloc((size_t)src->w * (size_t)src->h * 2u);
    if (!tmp) return BFM_PLAT_ERROR;
    bfm_gl_vram_download(v, src, tmp);
    x &= BFM_GL_VRAM_W - 1;
    y &= BFM_GL_VRAM_H - 1;
    for (j = 0; j < src->h; j++)
        for (i = 0; i < src->w; i++)
            v->px[(size_t)((y + j) & (BFM_GL_VRAM_H - 1)) * BFM_GL_VRAM_W +
                  ((x + i) & (BFM_GL_VRAM_W - 1))] = tmp[(size_t)j * src->w + i];
    free(tmp);
    wraps = x + src->w > BFM_GL_VRAM_W || y + src->h > BFM_GL_VRAM_H;
    if (wraps) bfm_gl_vram_mark(v, 0, 0, BFM_GL_VRAM_W, BFM_GL_VRAM_H);
    else bfm_gl_vram_mark(v, x, y, src->w, src->h);
    return BFM_PLAT_OK;
}

int bfm_gl_vram_fill(BfmGlVram *v, const BfmPlatRect *r, uint16_t color) {
    int i, j, x0, y0, x1, y1;
    if (!v || !r || r->w <= 0 || r->h <= 0) return BFM_PLAT_INVALID;
    x0 = r->x < 0 ? 0 : r->x;
    y0 = r->y < 0 ? 0 : r->y;
    x1 = r->x + r->w > BFM_GL_VRAM_W ? BFM_GL_VRAM_W : r->x + r->w;
    y1 = r->y + r->h > BFM_GL_VRAM_H ? BFM_GL_VRAM_H : r->y + r->h;
    for (j = y0; j < y1; j++)
        for (i = x0; i < x1; i++) v->px[(size_t)j * BFM_GL_VRAM_W + i] = color;
    bfm_gl_vram_mark(v, x0, y0, x1 - x0, y1 - y0);
    return BFM_PLAT_OK;
}

void bfm_gl_decode_rgb24(const BfmGlVram *v, const BfmPlatRect *d, uint8_t *rgba) {
    int x, y, c;
    for (y = 0; y < d->h; y++) {
        const uint16_t *row = &v->px[(size_t)((d->y + y) & (BFM_GL_VRAM_H - 1)) * BFM_GL_VRAM_W];
        for (x = 0; x < d->w; x++) {
            uint8_t *o = &rgba[((size_t)y * d->w + x) * 4u];
            for (c = 0; c < 3; c++) {
                int byte = x * 3 + c;
                uint16_t h = row[(d->x + byte / 2) & (BFM_GL_VRAM_W - 1)];
                o[c] = (uint8_t)(byte & 1 ? h >> 8 : h & 0xFF);
            }
            o[3] = 255;
        }
    }
}

/* ---- texture pages ---------------------------------------------------- */

BfmGlTpage bfm_gl_decode_tpage(uint16_t tp) {
    BfmGlTpage t;
    int d = (tp >> 7) & 3;
    t.base_x = (tp & 0xF) * 64;
    t.base_y = ((tp >> 4) & 1) * 256;
    t.abr = (tp >> 5) & 3;
    t.depth = d == 0 ? 4 : d == 1 ? 8 : 15;
    return t;
}

void bfm_gl_decode_clut(uint16_t clut, int *x, int *y) {
    *x = (clut & 0x3F) * 16;
    *y = (clut >> 6) & 0x1FF;
}

int bfm_gl_window(int u, int off, int size) {
    if (size <= 0) return u;
    return (u & (size - 1)) | (off & ~(size - 1) & 0xFF);
}

static uint16_t at(const BfmGlVram *v, int x, int y) {
    return v->px[(size_t)(y & (BFM_GL_VRAM_H - 1)) * BFM_GL_VRAM_W +
                 (x & (BFM_GL_VRAM_W - 1))];
}

uint16_t bfm_gl_sample(const BfmGlVram *v, uint16_t tpage, uint16_t clut,
                       int u, int vv, const BfmPlatRect *win) {
    BfmGlTpage t = bfm_gl_decode_tpage(tpage);
    int cx, cy, idx;
    u &= 0xFF;
    vv &= 0xFF;
    if (win) {
        u = bfm_gl_window(u, win->x, win->w);
        vv = bfm_gl_window(vv, win->y, win->h);
    }
    bfm_gl_decode_clut(clut, &cx, &cy);
    switch (t.depth) {
    case 4:
        idx = (at(v, t.base_x + u / 4, t.base_y + vv) >> ((u & 3) * 4)) & 0xF;
        return at(v, cx + idx, cy);
    case 8:
        idx = (at(v, t.base_x + u / 2, t.base_y + vv) >> ((u & 1) * 8)) & 0xFF;
        return at(v, cx + idx, cy);
    default:
        return at(v, t.base_x + u, t.base_y + vv);
    }
}

static int round_i(double x) { return (int)floor(x + 0.5); }

void bfm_gl_modulate(uint16_t texel, int r, int g, int b, int raw,
                     uint8_t out[3]) {
    int c[3], i;
    c[0] = r; c[1] = g; c[2] = b;
    for (i = 0; i < 3; i++) {
        double t = (double)((texel >> (5 * i)) & 31) / 31.0;
        double o = raw ? t : t * (double)c[i] / 128.0;
        if (o > 1.0) o = 1.0;
        out[i] = (uint8_t)round_i(o * 255.0);
    }
}

/* ---- semi-transparency ---------------------------------------------- */

uint16_t bfm_gl_blend_ref(int mode, uint16_t back, uint16_t front) {
    uint16_t out = 0;
    int i;
    for (i = 0; i < 3; i++) {
        int b = (back >> (5 * i)) & 31, f = (front >> (5 * i)) & 31, o;
        switch (mode & 3) {
        case 0: o = (b + f) >> 1; break;
        case 1: o = b + f; break;
        case 2: o = b - f; break;
        default: o = b + (f >> 2); break;
        }
        if (o < 0) o = 0;
        if (o > 31) o = 31;
        out |= (uint16_t)(o << (5 * i));
    }
    return out;
}

BfmGlBlendState bfm_gl_blend_state(int mode) {
    BfmGlBlendState s;
    s.equation = BFM_GL_FUNC_ADD;
    s.src = s.dst = BFM_GL_ONE;
    s.constant = 1.0f;
    switch (mode & 3) {
    case 0:  /* 0.5 * F + 0.5 * B */
        s.src = s.dst = BFM_GL_CONSTANT_COLOR;
        s.constant = 0.5f;
        break;
    case 1:  /* F + B */
        break;
    case 2:  /* B - F */
        s.equation = BFM_GL_FUNC_REVERSE_SUBTRACT;
        break;
    default: /* 0.25 * F + B */
        s.src = BFM_GL_CONSTANT_COLOR;
        s.constant = 0.25f;
        break;
    }
    return s;
}

uint16_t bfm_gl_blend_emulate(const BfmGlBlendState *s, uint16_t back,
                              uint16_t front) {
    uint16_t out = 0;
    int i;
    for (i = 0; i < 3; i++) {
        /* dst: what an RGBA8 target holds for a 5-bit value; src: shader
         * output (float) */
        double b = (double)round_i(((back >> (5 * i)) & 31) * 255.0 / 31.0) / 255.0;
        double f = (double)((front >> (5 * i)) & 31) / 31.0;
        double sf = s->src == BFM_GL_CONSTANT_COLOR ? s->constant : 1.0;
        double df = s->dst == BFM_GL_CONSTANT_COLOR ? s->constant : 1.0;
        double o = s->equation == BFM_GL_FUNC_REVERSE_SUBTRACT
                       ? b * df - f * sf : f * sf + b * df;
        int q;
        if (o < 0.0) o = 0.0;
        if (o > 1.0) o = 1.0;
        q = round_i(o * 255.0) >> 3;   /* stored RGB8, read back as 5-bit */
        out |= (uint16_t)(q << (5 * i));
    }
    return out;
}

/* ---- dither ------------------------------------------------------------ */

const int8_t bfm_gl_dither_matrix[4][4] = {
    {-4, +0, -3, +1},
    {+2, -2, +3, -1},
    {-3, +1, -4, +0},
    {+3, -1, +2, -2},
};

int bfm_gl_dither5(int c8, int x, int y) {
    int c = c8 + bfm_gl_dither_matrix[y & 3][x & 3];
    if (c < 0) c = 0;
    if (c > 255) c = 255;
    return c >> 3;
}

/* ---- HD replacements ----------------------------------------------------- */

static int rect_eq(const BfmPlatRect *a, const BfmPlatRect *b) {
    return a->x == b->x && a->y == b->y && a->w == b->w && a->h == b->h;
}

static int rect_overlap(const BfmPlatRect *a, const BfmPlatRect *b) {
    return a->x < b->x + b->w && b->x < a->x + a->w &&
           a->y < b->y + b->h && b->y < a->y + a->h;
}

int bfm_gl_repl_add(BfmGlReplacements *set, const BfmPlatRect *rect,
                    uint32_t width, uint32_t height, uint32_t id,
                    uint32_t *old_id) {
    int i, slot = -1;
    if (old_id) *old_id = 0;
    if (!set || !bfm_plat_rect_valid(rect) || !width || !height) return -1;
    for (i = 0; i < BFM_GL_MAX_REPLACEMENTS; i++)
        if (set->r[i].live && rect_eq(&set->r[i].rect, rect)) { slot = i; break; }
    if (slot < 0)
        for (i = 0; i < BFM_GL_MAX_REPLACEMENTS; i++)
            if (!set->r[i].live) { slot = i; break; }
    if (slot < 0) return -1;
    if (old_id && set->r[slot].live) *old_id = set->r[slot].id;
    set->r[slot].rect = *rect;
    set->r[slot].width = width;
    set->r[slot].height = height;
    set->r[slot].id = id;
    set->r[slot].live = 1;
    return slot;
}

int bfm_gl_repl_invalidate(BfmGlReplacements *set, const BfmPlatRect *rect,
                           uint32_t *dead, int max) {
    int i, n = 0;
    if (!set || !rect) return 0;
    for (i = 0; i < BFM_GL_MAX_REPLACEMENTS; i++) {
        if (!set->r[i].live || !rect_overlap(&set->r[i].rect, rect)) continue;
        set->r[i].live = 0;
        if (dead && n < max) dead[n] = set->r[i].id;
        n++;
    }
    return n;
}

static int texel_factor(uint16_t tpage) {
    int d = bfm_gl_decode_tpage(tpage).depth;
    return d == 4 ? 4 : d == 8 ? 2 : 1;
}

static int prim_textured(int kind) {
    return kind == BFM_PRIM_POLY_FT3 || kind == BFM_PRIM_POLY_FT4 ||
           kind == BFM_PRIM_POLY_GT3 || kind == BFM_PRIM_POLY_GT4 ||
           kind == BFM_PRIM_SPRITE;
}

static int prim_verts(int kind) {
    switch (kind) {
    case BFM_PRIM_POLY_F3: case BFM_PRIM_POLY_G3:
    case BFM_PRIM_POLY_FT3: case BFM_PRIM_POLY_GT3: return 3;
    case BFM_PRIM_POLY_F4: case BFM_PRIM_POLY_G4:
    case BFM_PRIM_POLY_FT4: case BFM_PRIM_POLY_GT4: return 4;
    case BFM_PRIM_LINE_F: case BFM_PRIM_LINE_G: return 2;
    default: return 1;
    }
}

int bfm_gl_repl_find(const BfmGlReplacements *set, const BfmPlatPrim *p) {
    BfmGlTpage t;
    int umin, umax, vmin, vmax, f, x0, x1, y0, y1, i;
    if (!set || !p || !prim_textured(p->kind)) return -1;
    if (p->kind == BFM_PRIM_SPRITE) {
        umin = p->v[0].u; umax = umin + p->w;
        vmin = p->v[0].v; vmax = vmin + p->h;
    } else {
        int n = prim_verts(p->kind);
        umin = umax = p->v[0].u;
        vmin = vmax = p->v[0].v;
        for (i = 1; i < n; i++) {
            if (p->v[i].u < umin) umin = p->v[i].u;
            if (p->v[i].u > umax) umax = p->v[i].u;
            if (p->v[i].v < vmin) vmin = p->v[i].v;
            if (p->v[i].v > vmax) vmax = p->v[i].v;
        }
        if (umax == umin) umax++;  /* one texel column */
        if (vmax == vmin) vmax++;
    }
    if (umax > 256 || vmax > 256) return -1;   /* wraps inside the page */
    t = bfm_gl_decode_tpage(p->tpage);
    f = texel_factor(p->tpage);
    x0 = t.base_x + umin / f;
    x1 = t.base_x + (umax + f - 1) / f;
    y0 = t.base_y + vmin;
    y1 = t.base_y + vmax;
    for (i = 0; i < BFM_GL_MAX_REPLACEMENTS; i++) {
        const BfmPlatRect *r = &set->r[i].rect;
        if (!set->r[i].live) continue;
        if (x0 >= r->x && x1 <= r->x + r->w && y0 >= r->y && y1 <= r->y + r->h)
            return i;
    }
    return -1;
}

void bfm_gl_repl_coords(const BfmGlReplacement *r, uint16_t tpage, float u,
                        float v, float *s, float *t) {
    BfmGlTpage tp = bfm_gl_decode_tpage(tpage);
    float f = (float)texel_factor(tpage);
    *s = ((float)tp.base_x * f + u - (float)r->rect.x * f) / ((float)r->rect.w * f);
    *t = ((float)tp.base_y + v - (float)r->rect.y) / (float)r->rect.h;
}

/* ---- batching --------------------------------------------------------- */

void bfm_gl_batch_init(BfmGlBatch *b) {
    memset(b, 0, sizeof *b);
    b->disp.w = 320;
    b->disp.h = 240;
    b->env.clip.w = BFM_GL_VRAM_W;
    b->env.clip.h = BFM_GL_VRAM_H;
    b->scissor = b->env.clip;
}

void bfm_gl_batch_free(BfmGlBatch *b) {
    free(b->v);
    free(b->c);
    b->v = NULL;
    b->c = NULL;
    b->nv = b->cap_v = b->nc = b->cap_c = 0;
}

void bfm_gl_batch_clear(BfmGlBatch *b) {
    b->nv = 0;
    b->nc = 0;
}

void bfm_gl_batch_target_size(const BfmGlBatch *b, int target, int *w, int *h) {
    if (target == BFM_GL_TARGET_SCENE0 || target == BFM_GL_TARGET_SCENE1) {
        *w = b->disp.w + 2 * b->margin;
        *h = b->disp.h;
    } else if (target == BFM_GL_TARGET_WINDOW) {
        *w = b->disp.w;
        *h = b->disp.h;
    } else {
        *w = BFM_GL_VRAM_W;
        *h = BFM_GL_VRAM_H;
    }
}

int bfm_gl_batch_scene_at(const BfmGlBatch *b, int x, int y) {
    int i;
    for (i = 0; i < BFM_GL_SCENE_SLOTS; i++)
        if (b->scene[i].used && b->scene[i].x == x && b->scene[i].y == y) return i;
    return -1;
}

static int scene_claim(BfmGlBatch *b, int x, int y) {
    int i, pick = -1;
    i = bfm_gl_batch_scene_at(b, x, y);
    if (i >= 0) {
        b->scene[i].stamp = ++b->tick;
        return i;
    }
    for (i = 0; i < BFM_GL_SCENE_SLOTS; i++)
        if (!b->scene[i].used) { pick = i; break; }
    if (pick < 0) {
        pick = 0;
        for (i = 1; i < BFM_GL_SCENE_SLOTS; i++)
            if (b->scene[i].stamp < b->scene[pick].stamp) pick = i;
    }
    b->scene[pick].used = 1;
    b->scene[pick].x = x;
    b->scene[pick].y = y;
    b->scene[pick].stamp = ++b->tick;
    return pick;
}

void bfm_gl_batch_set_display(BfmGlBatch *b, const BfmPlatRect *disp, int margin) {
    if (!disp || disp->w <= 0 || disp->h <= 0) return;
    if (margin < 0) margin = 0;
    if (disp->w != b->disp.w || disp->h != b->disp.h || margin != b->margin)
        memset(b->scene, 0, sizeof b->scene);
    b->disp = *disp;
    b->margin = margin;
    if (!b->overlay) scene_claim(b, disp->x, disp->y);
    bfm_gl_batch_set_env(b, &b->env);   /* re-route the current env */
}

/* The scene slot whose frame buffer contains rect, claiming one when the
 * rect has the display's size; -1 = plain VRAM. */
static int scene_for(BfmGlBatch *b, const BfmPlatRect *r) {
    int i;
    for (i = 0; i < BFM_GL_SCENE_SLOTS; i++) {
        const BfmGlScene *s = &b->scene[i];
        if (s->used && r->x >= s->x && r->y >= s->y &&
            r->x + r->w <= s->x + b->disp.w && r->y + r->h <= s->y + b->disp.h)
            return i;
    }
    if (r->w == b->disp.w && r->h == b->disp.h) return scene_claim(b, r->x, r->y);
    return -1;
}

/* rect (VRAM) -> target-local rect in scene slot i, widened by the margin
 * where it touches the frame buffer's left/right edge. */
static BfmPlatRect scene_local(const BfmGlBatch *b, int i, const BfmPlatRect *r) {
    const BfmGlScene *s = &b->scene[i];
    BfmPlatRect o;
    int x0 = r->x, x1 = r->x + r->w, y0 = r->y, y1 = r->y + r->h;
    if (x0 < s->x) x0 = s->x;
    if (y0 < s->y) y0 = s->y;
    if (x1 > s->x + b->disp.w) x1 = s->x + b->disp.w;
    if (y1 > s->y + b->disp.h) y1 = s->y + b->disp.h;
    x0 = x0 - s->x + b->margin;
    x1 = x1 - s->x + b->margin;
    if (x0 == b->margin) x0 = 0;
    if (x1 == b->margin + b->disp.w) x1 += b->margin;
    o.x = (int16_t)x0;
    o.y = (int16_t)(y0 - s->y);
    o.w = (int16_t)(x1 - x0);
    o.h = (int16_t)(y1 - y0);
    return o;
}

static BfmGlCmd *push_cmd(BfmGlBatch *b) {
    if (b->nc == b->cap_c) {
        size_t cap = b->cap_c ? b->cap_c * 2 : 256;
        BfmGlCmd *c = (BfmGlCmd *)realloc(b->c, cap * sizeof *c);
        if (!c) { b->oom = 1; return NULL; }
        b->c = c;
        b->cap_c = cap;
    }
    memset(&b->c[b->nc], 0, sizeof b->c[0]);
    return &b->c[b->nc++];
}

static void emit_fill(BfmGlBatch *b, int target, const BfmPlatRect *r, uint32_t rgb) {
    BfmGlCmd *c;
    if (r->w <= 0 || r->h <= 0) return;
    if (!(c = push_cmd(b))) return;
    c->kind = BFM_GL_CMD_FILL;
    c->target = (uint8_t)target;
    c->blend = -1;
    c->rect = *r;
    c->rgb = rgb;
}

static uint16_t rgb_to_15(uint32_t rgb) {
    return (uint16_t)(((rgb >> 3) & 31) | (((rgb >> 11) & 31) << 5) |
                      (((rgb >> 19) & 31) << 10));
}

/* A VRAM-space fill: mirror, VRAM target, and the scene slots it touches. */
static void fill_route(BfmGlBatch *b, const BfmPlatRect *r, uint32_t rgb) {
    int i;
    if (b->overlay) {
        emit_fill(b, BFM_GL_TARGET_WINDOW, r, rgb);
        return;
    }
    if (b->vram) bfm_gl_vram_fill(b->vram, r, rgb_to_15(rgb));
    emit_fill(b, BFM_GL_TARGET_VRAM, r, rgb);
    for (i = 0; i < BFM_GL_SCENE_SLOTS; i++) {
        BfmPlatRect area, l;
        if (!b->scene[i].used) continue;
        area.x = (int16_t)b->scene[i].x; area.y = (int16_t)b->scene[i].y;
        area.w = b->disp.w; area.h = b->disp.h;
        if (!rect_overlap(&area, r)) continue;
        l = scene_local(b, i, r);
        emit_fill(b, BFM_GL_TARGET_SCENE0 + i, &l, rgb);
    }
}

void bfm_gl_batch_set_env(BfmGlBatch *b, const BfmPlatDrawEnv *env) {
    int s;
    if (!env) return;
    if (env != &b->env) b->env = *env;
    if (b->overlay) {
        b->target = BFM_GL_TARGET_WINDOW;
        b->org_x = b->org_y = 0;
        b->scissor.x = b->scissor.y = 0;
        b->scissor.w = b->disp.w;
        b->scissor.h = b->disp.h;
    } else if ((s = scene_for(b, &b->env.clip)) >= 0) {
        b->target = BFM_GL_TARGET_SCENE0 + s;
        b->org_x = b->scene[s].x - b->margin;
        b->org_y = b->scene[s].y;
        b->scissor = scene_local(b, s, &b->env.clip);
    } else {
        b->target = BFM_GL_TARGET_VRAM;
        b->org_x = b->org_y = 0;
        b->scissor = b->env.clip;
    }
    if (env != &b->env && env->clear_bg)
        fill_route(b, &b->env.clip, (uint32_t)env->bg_r | ((uint32_t)env->bg_g << 8) |
                                        ((uint32_t)env->bg_b << 16));
}

static int rect_same(const BfmPlatRect *a, const BfmPlatRect *b) {
    return rect_eq(a, b);
}

/* Current DRAW command for this state, reusing the last one if it matches. */
static BfmGlCmd *draw_cmd(BfmGlBatch *b, int target, int blend, int split,
                          int repl, int dither, const BfmPlatRect *sc, int copy) {
    static const BfmPlatRect none = {0, 0, 0, 0};
    const BfmPlatRect *win = target == BFM_GL_TARGET_WINDOW ? &none
                                                            : &b->env.texture_window;
    BfmGlCmd *c;
    if (b->nc) {
        c = &b->c[b->nc - 1];
        if (c->kind == BFM_GL_CMD_DRAW && c->target == target && c->blend == blend &&
            c->split_stp == split && c->repl == repl && c->copy == copy &&
            rect_same(&c->rect, sc) && rect_same(&c->win, win) &&
            c->first + c->count == b->nv) {
            c->dither |= (uint8_t)dither;   /* vertex flags decide per prim */
            return c;
        }
    }
    if (!(c = push_cmd(b))) return NULL;
    c->kind = BFM_GL_CMD_DRAW;
    c->target = (uint8_t)target;
    c->blend = (int8_t)blend;
    c->split_stp = (uint8_t)split;
    c->repl = (uint16_t)repl;
    c->dither = (uint8_t)dither;
    c->copy = (uint8_t)copy;
    c->rect = *sc;
    c->win = *win;
    c->first = (uint32_t)b->nv;
    return c;
}

static BfmGlVertex *push_verts(BfmGlBatch *b, size_t n) {
    if (b->nv + n > b->cap_v) {
        size_t cap = b->cap_v ? b->cap_v : 1024;
        BfmGlVertex *v;
        while (cap < b->nv + n) cap *= 2;
        v = (BfmGlVertex *)realloc(b->v, cap * sizeof *v);
        if (!v) { b->oom = 1; return NULL; }
        b->v = v;
        b->cap_v = cap;
    }
    b->nv += n;
    return &b->v[b->nv - n];
}

typedef struct Corner {
    float x, y, u, v;
    uint8_t r, g, bl;
} Corner;

static void put_tri(BfmGlBatch *b, BfmGlCmd *c, const Corner *k0, const Corner *k1,
                    const Corner *k2, const BfmPlatPrim *p, uint16_t flags, int repl) {
    const Corner *k[3];
    BfmGlVertex *v = push_verts(b, 3);
    int i;
    if (!v) return;
    k[0] = k0; k[1] = k1; k[2] = k2;
    for (i = 0; i < 3; i++) {
        memset(&v[i], 0, sizeof v[i]);
        v[i].x = k[i]->x;
        v[i].y = k[i]->y;
        v[i].r = k[i]->r; v[i].g = k[i]->g; v[i].b = k[i]->bl; v[i].a = 255;
        v[i].u = (uint16_t)k[i]->u;
        v[i].v = (uint16_t)k[i]->v;
        v[i].clut = p ? p->clut : 0;
        v[i].tpage = p ? p->tpage : 0;
        v[i].flags = flags;
        v[i].repl = (uint16_t)(repl + 1);
        if (repl >= 0 && b->repl && p)
            bfm_gl_repl_coords(&b->repl->r[repl], p->tpage, k[i]->u, k[i]->v,
                               &v[i].s, &v[i].t);
    }
    c->count += 3;
}

static void put_quad(BfmGlBatch *b, BfmGlCmd *c, const Corner *k, const BfmPlatPrim *p,
                     uint16_t flags, int repl) {
    /* k in PS1 order: 0 1 / 2 3 */
    put_tri(b, c, &k[0], &k[1], &k[2], p, flags, repl);
    put_tri(b, c, &k[1], &k[3], &k[2], p, flags, repl);
}

static int is_gouraud(int kind) {
    return kind == BFM_PRIM_POLY_G3 || kind == BFM_PRIM_POLY_G4 ||
           kind == BFM_PRIM_POLY_GT3 || kind == BFM_PRIM_POLY_GT4 ||
           kind == BFM_PRIM_LINE_G;
}

static void corner(Corner *k, float x, float y, const BfmPlatVertex *src,
                   float u, float v) {
    k->x = x; k->y = y; k->u = u; k->v = v;
    k->r = src->r; k->g = src->g; k->bl = src->b;
}

size_t bfm_gl_batch_add(BfmGlBatch *b, const BfmPlatPrim *prims, size_t n) {
    size_t i, tris = 0;
    for (i = 0; i < n; i++) {
        const BfmPlatPrim *p = &prims[i];
        int kind = p->kind, textured = prim_textured(kind);
        int raw = textured && (p->flags & BFM_PRIM_FLAG_RAW_TEXTURE);
        int semi = (p->flags & BFM_PRIM_FLAG_SEMI_TRANS) != 0;
        int blend = semi ? bfm_gl_decode_tpage(p->tpage).abr : -1;
        int rect_kind = kind == BFM_PRIM_TILE || kind == BFM_PRIM_SPRITE;
        int dither = b->env.dither && !rect_kind &&
                     (is_gouraud(kind) || (textured && !raw));
        int repl = textured && b->repl ? bfm_gl_repl_find(b->repl, p) : -1;
        float ox = (float)(b->env.offset_x - b->org_x);
        float oy = (float)(b->env.offset_y - b->org_y);
        uint16_t flags = (uint16_t)((textured ? BFM_GLV_TEXTURED : 0) |
                                    (raw ? BFM_GLV_RAW : 0) |
                                    (dither ? BFM_GLV_DITHER : 0));
        Corner k[4];
        BfmGlCmd *c;
        int j, nv;

        if (kind == BFM_PRIM_FILL) {
            BfmPlatRect r;
            r.x = p->v[0].x; r.y = p->v[0].y;
            r.w = (int16_t)p->w; r.h = (int16_t)p->h;
            fill_route(b, &r, (uint32_t)p->v[0].r | ((uint32_t)p->v[0].g << 8) |
                                  ((uint32_t)p->v[0].b << 16));
            continue;
        }
        if (kind <= 0 || kind >= BFM_PRIM_KIND_COUNT) continue;
        c = draw_cmd(b, b->target, blend, textured && semi && repl < 0, repl + 1,
                     dither, &b->scissor, 0);
        if (!c) break;
        switch (kind) {
        case BFM_PRIM_TILE:
        case BFM_PRIM_SPRITE: {
            float x = p->v[0].x + ox, y = p->v[0].y + oy;
            float w = p->w, h = p->h, u = p->v[0].u, v = p->v[0].v;
            corner(&k[0], x, y, &p->v[0], u, v);
            corner(&k[1], x + w, y, &p->v[0], u + w, v);
            corner(&k[2], x, y + h, &p->v[0], u, v + h);
            corner(&k[3], x + w, y + h, &p->v[0], u + w, v + h);
            put_quad(b, c, k, p, flags, repl);
            tris += 2;
            break;
        }
        case BFM_PRIM_LINE_F:
        case BFM_PRIM_LINE_G: {
            const BfmPlatVertex *a = &p->v[0], *e = &p->v[1];
            const BfmPlatVertex *ca, *ce;
            float x0, y0, x1, y1;
            if (abs(e->x - a->x) >= abs(e->y - a->y) ? e->x < a->x : e->y < a->y) {
                const BfmPlatVertex *t = a; a = e; e = t;
            }
            ca = a;
            ce = kind == BFM_PRIM_LINE_G ? e : a;
            if (kind == BFM_PRIM_LINE_F) ca = ce = &p->v[0];
            x0 = a->x + ox; y0 = a->y + oy; x1 = e->x + ox; y1 = e->y + oy;
            if (abs(e->x - a->x) >= abs(e->y - a->y)) {
                /* x-major: one pixel tall, endpoints inclusive */
                corner(&k[0], x0, y0, ca, 0, 0);
                corner(&k[1], x1 + 1, y1, ce, 0, 0);
                corner(&k[2], x0, y0 + 1, ca, 0, 0);
                corner(&k[3], x1 + 1, y1 + 1, ce, 0, 0);
            } else {
                corner(&k[0], x0, y0, ca, 0, 0);
                corner(&k[1], x0 + 1, y0, ca, 0, 0);
                corner(&k[2], x1, y1 + 1, ce, 0, 0);
                corner(&k[3], x1 + 1, y1 + 1, ce, 0, 0);
            }
            put_quad(b, c, k, p, flags, repl);
            tris += 2;
            break;
        }
        default:
            nv = prim_verts(kind);
            for (j = 0; j < nv; j++) {
                const BfmPlatVertex *src = is_gouraud(kind) ? &p->v[j] : &p->v[0];
                corner(&k[j], p->v[j].x + ox, p->v[j].y + oy, src, p->v[j].u,
                       p->v[j].v);
            }
            if (nv == 3) {
                put_tri(b, c, &k[0], &k[1], &k[2], p, flags, repl);
                tris += 1;
            } else {
                put_quad(b, c, k, p, flags, repl);
                tris += 2;
            }
            break;
        }
    }
    return tris;
}

void bfm_gl_batch_add_copy(BfmGlBatch *b, const BfmPlatRect *r) {
    const uint16_t flags = BFM_GLV_TEXTURED | BFM_GLV_RAW | BFM_GLV_ABS;
    BfmPlatVertex white;
    BfmPlatRect full;
    Corner k[4];
    BfmGlCmd *c;
    int i;
    if (b->overlay || !r || r->w <= 0 || r->h <= 0) return;
    memset(&white, 0xFF, sizeof white);
    full.x = full.y = 0;
    full.w = BFM_GL_VRAM_W;
    full.h = BFM_GL_VRAM_H;
    for (i = -1; i < BFM_GL_SCENE_SLOTS; i++) {
        BfmPlatRect sc = full;
        float ox = 0, oy = 0;
        int target = BFM_GL_TARGET_VRAM;
        if (i >= 0) {
            BfmPlatRect area;
            if (!b->scene[i].used) continue;
            area.x = (int16_t)b->scene[i].x; area.y = (int16_t)b->scene[i].y;
            area.w = b->disp.w; area.h = b->disp.h;
            if (!rect_overlap(&area, r)) continue;
            target = BFM_GL_TARGET_SCENE0 + i;
            ox = (float)(b->margin - b->scene[i].x);
            oy = (float)-b->scene[i].y;
            sc.x = (int16_t)b->margin; sc.y = 0;
            sc.w = b->disp.w; sc.h = b->disp.h;
        }
        if (!(c = draw_cmd(b, target, -1, 0, 0, 0, &sc, 1))) return;
        corner(&k[0], r->x + ox, r->y + oy, &white, r->x, r->y);
        corner(&k[1], r->x + r->w + ox, r->y + oy, &white, r->x + r->w, r->y);
        corner(&k[2], r->x + ox, r->y + r->h + oy, &white, r->x, r->y + r->h);
        corner(&k[3], r->x + r->w + ox, r->y + r->h + oy, &white, r->x + r->w,
               r->y + r->h);
        put_quad(b, c, k, NULL, flags, -1);
    }
}
