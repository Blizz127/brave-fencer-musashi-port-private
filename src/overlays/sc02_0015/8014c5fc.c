/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C5FC - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 func_80047D3C(s32 a0);
extern s32 ratan2(s32, s32);
extern s32 ratan2(s32 x, s32 y);
extern s32 ratan2(s32 dx, s32 dy);

s32 func_8014C5FC(s32 a0, s32 a1, void * a2)
{
    s32 dx;
    s32 dz;
    s32 dy;
    s32 r;
    dz = (s16)(*(u16 *)((s32)a1 + 0xE) + *(u16 *)((s32)a2 + 0x4) - *(u16 *)((s32)a0 + 0xE));
    dx = (s16)(*(u16 *)((s32)a1 + 0x6) + *(u16 *)((s32)a2 + 0x0) - *(u16 *)((s32)a0 + 0x6));
    r = func_80047D3C(dz * dz + dx * dx);
    dy = *(s16 *)((s32)a1 + 0xA) + *(s16 *)((s32)a2 + 0x2) - *(s16 *)((s32)a0 + 0xA);
    return ratan2(dy, (s16)r) & 0xFFF;
}
