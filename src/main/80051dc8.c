/* Main-exec range [80051DC8,80051EA0) from the SLUS executable.
 * SHA256(span)=3f56a62df186b06c6099961ac4ee17eea685ca51e31de9c9492b2d0874d99db7.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80051DC8 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u32 attribute; s16 x0, y0, x1, y1; u8 r, g, b; } GsLINE;
typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; s16 x0, y0, x1, y1; } LinePkt;
extern LinePkt *D_800A5E60;
extern s16 D_800A6548;
extern s16 D_800A654A;
extern LinePkt *func_80051EA0(void *, void *, u16, u8);
void func_80051DC8(GsLINE *lp, void *ot, u16 pri)
{
    s32 attr = lp->attribute;
    LinePkt *p;

    if (attr >= 0) {
        p = D_800A5E60;
        p->tpage = ((attr >> 23) & 0x60) | 0xE1000200;
        p->r0 = lp->r;
        p->g0 = lp->g;
        p->b0 = lp->b;
        p->code = ((attr >> 29) & 2) | 0x40;
        p->x0 = lp->x0 + D_800A6548;
        p->y0 = lp->y0 + D_800A654A;
        p->x1 = lp->x1 + D_800A6548;
        p->y1 = lp->y1 + D_800A654A;
        D_800A5E60 = func_80051EA0(p, ot, pri, 4);
    }
}
