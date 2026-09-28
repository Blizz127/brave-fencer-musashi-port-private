/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165FA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
extern void ApplyMatrixSV(void *a0, void *a1, void *a2);
extern void func_80013F3C(s32 a0);
extern void func_80020F34(s32 a0, s32 a1);

s32 func_80165FA4(s32 arg0, s32 arg1, s32 arg2)
{
    s32 buf[8];
    func_80013F3C((s32)buf);
    func_80020F34((s32)buf, *(s32 *)((u8 *)arg0 + 0x20) + 0x18);
    ApplyMatrixSV(buf, arg1, arg1);
    ApplyMatrixSV(buf, arg2, arg2);
}
