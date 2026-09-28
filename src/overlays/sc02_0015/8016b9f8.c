/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016B9F8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015954(s32 a0, s32 a1);
extern void func_8012EFB8(s32 a0);
extern int D_8018F5F8;
extern s32 D_8018F5F8;

s32 func_8016B9F8(s32 param_1)
{
    s32 buf[2];
    u32 v;

    v = ((u32 (*)(s32 *, s32 *))func_8012EFB8)(&D_8018F5F8, buf);
    ((void (*)(s32 *, s32 *))func_80015954)(buf, (s32 *)(param_1 + 4));
    return (v & 0xffffefff) != 0;
}
