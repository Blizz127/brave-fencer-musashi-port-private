/* Owner re-derivation from retail assembly (clean room, clean input set; D2 grouped GTE macros). */
/* Projects the four corners of a sprite part's rectangle with the GTE (RTPT for three, RTPS for the fourth),
 * stores the screen x/y into the part's POLY_FT4, ORs the two GTE FLAG words into *flags and returns the
 * average depth (AVSZ4). */
#include "psx_types.h"
#include "gte_ops.h"

typedef struct {
    s16 vx;
    s16 vy;
    s16 vz;
    s16 pad;
} SVec;

typedef struct {
    u8 pad0[0x2E];
    u16 x;
    u16 y;
    u16 z;
} Obj;

typedef struct {
    u16 flags;
    u8 w;
    u8 h;
    s16 u;
    u16 v;
    u16 ox;
    u16 oy;
} Part;

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 u0, v0;
    u16 clut;
    s16 x1, y1;
    u8 u1, v1;
    u16 tpage;
    s16 x2, y2;
    u8 u2, v2;
    u16 pad2;
    s16 x3, y3;
    u8 u3, v3;
    u16 pad3;
} PolyFT4;

s32 func_8001E668(Obj *o, Part *p, PolyFT4 *q, u32 *flags)
{
    SVec v[4];
    u32 flag2;
    s32 otz;

    v[0].vx = o->x + p->ox;
    v[0].vy = o->y + p->oy;
    v[1].vx = o->x + p->ox + p->w;
    v[1].vy = o->y + p->oy;
    v[2].vx = o->x + p->ox;
    v[2].vy = o->y + p->oy + p->h;
    v[3].vx = o->x + p->ox + p->w;
    v[3].vy = o->y + p->oy + p->h;
    v[0].vz = v[1].vz = v[2].vz = v[3].vz = o->z;

    gte_g_ld_v3(&v[0], &v[1], &v[2]);
    gte_nop();
    gte_nop();
    gte_rtpt();
    gte_g_st_flag(flags);
    gte_g_st_sxy3(&q->x0, &q->x1, &q->x2);
    gte_lwc2(0, 0, &v[3]);
    gte_lwc2(1, 4, &v[3]);
    gte_nop();
    gte_nop();
    gte_rtps();
    gte_g_st_flag(&flag2);
    *flags |= flag2;
    gte_swc2(14, 0, &q->x3);
    gte_nop();
    gte_nop();
    gte_avsz4();
    gte_swc2(7, 0, &otz);
    return otz;
}
