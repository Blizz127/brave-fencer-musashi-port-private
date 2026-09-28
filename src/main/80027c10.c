/* Main-exec range [80027C10,80027D20) from the SLUS executable.
 * SHA256(span)=bf87c333734cccdeeb1ce752c2a4a0d020246107e59bdc2183ec955620c5ca3e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80027C10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor typedefs this body depends on (copied from vendor/bfm-decomp). */
typedef struct { s16 vx, vy, vz, pad; } SVEC2;      /* 0x08 */
typedef struct {                                     /* 0x14 */
    u32 w0;      /* 0x00 */
    u32 rgb;     /* 0x04 */
    u16 n0;      /* 0x08 */
    u16 v0;      /* 0x0A */
    u16 n1;      /* 0x0C */
    u16 v1;      /* 0x0E */
    u16 n2;      /* 0x10 */
    u16 v2;      /* 0x12 */
} Face2;
typedef struct {                                     /* 0x1C */
    u32 tag;
    u32 rgb0;
    s16 x0, y0;
    u32 rgb1;
    s16 x1, y1;
    u32 rgb2;
    s16 x2, y2;
} G3P;
typedef struct {                                     /* 0x18 */
    u32 w0;      /* 0x00 */
    u32 rgb;     /* 0x04 */
    u16 n0;      /* 0x08 */
    u16 v0;      /* 0x0A */
    u16 n1;      /* 0x0C */
    u16 v1;      /* 0x0E */
    u16 n2;      /* 0x10 */
    u16 v2;      /* 0x12 */
    u16 n3;      /* 0x14 */
    u16 v3;      /* 0x16 */
} Face3;
typedef struct {                                     /* 0x24 */
    u32 tag;     /* 0x00 */
    u32 rgb0;    /* 0x04 */
    s16 x0, y0;  /* 0x08 */
    u32 rgb1;    /* 0x0C */
    s16 x1, y1;  /* 0x10 */
    u32 rgb2;    /* 0x14 */
    s16 x2, y2;  /* 0x18 */
    u32 rgb3;    /* 0x1C */
    s16 x3, y3;  /* 0x20 */
} G4P;

extern G3P *func_80027D20(Face2 *f, SVEC2 *verts, SVEC2 *norms, G3P *prims,
                           s32 count, s32 shift, s32 ot);
extern G4P *func_80027F4C(Face3 *f, SVEC2 *verts, SVEC2 *norms, G4P *prims,
                           s32 count, s32 shift, s32 ot);

void func_80027C10(void *a0, void *a1, s32 a2)
{
    void *geo;
    SVEC2 *verts;
    SVEC2 *norms;
    Face2 *f;
    G3P *p;
    u32 w0;
    s32 cnt;
    u32 opc;
    u32 masked;

    geo = *(void **)((s32)a0 + 0x8);
    p = *(G3P **)((s32)a0 + 0xC);
    verts = *(SVEC2 **)((s32)geo + 0x0);
    norms = *(SVEC2 **)((s32)geo + 0x8);
    f = *(Face2 **)((s32)geo + 0x10);

    do {
        w0 = p->tag;
        cnt = p->rgb0;
        p = (G3P *)((s32)p + 8);
        opc = (w0 >> 24) & 0xFC;
        switch (opc) {
        case 0x30:
            func_80027D20(f, verts, norms, p, cnt, a2, *(s32 *)((s32)a1 + 4));
            f = (Face2 *)((s32)f + cnt * 20);
            break;
        case 0x38:
            func_80027F4C((Face3 *)f, verts, norms, (G4P *)p, cnt, a2, *(s32 *)((s32)a1 + 4));
            f = (Face2 *)((s32)f + cnt * 24);
            break;
        }
        masked = w0 & 0xFFFFFF;
        p = (G3P *)(masked | 0x80000000);
    } while (masked != 0);
}
