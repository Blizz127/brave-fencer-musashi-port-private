/* Exact retail word export for [80058890,80058A4C); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80058890 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 x, y, w, h; } RECT;
extern void func_800599B8(RECT *, u32 *);
extern u16 func_80058B40(s32, s32, s32, s32);
u16 func_80058890(u32 *pix, s32 tp, s32 abr, s32 x, s32 y, s32 w, s32 h)
{
    RECT r;

    r.x = x;
    r.y = y;
    r.h = h;
    switch (tp) {
    case 0:
        r.w = w / 4;
        break;
    case 1:
        r.w = w / 2;
        break;
    case 2:
        r.w = w;
        break;
    }
    func_800599B8(&r, pix);
    return func_80058B40(tp, abr, x, y);
}
