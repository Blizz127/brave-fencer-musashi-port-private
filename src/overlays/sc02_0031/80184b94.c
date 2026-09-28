/* Complete SC02 retail span [80184B94,80184C24).
 * Range/id gate.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80184B94 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 D_801274D8;
extern s32 D_801274DC;
extern s16 D_80126CAC;
extern s32 func_800132BC(s32 a0, s32 a1);

s32 func_80184B94(s32 param_1)
{
    s32 iVar1;
    register s32 uVar2 __asm__("$2");

    if (*(u16 *) (param_1 + 6) == 0x31 || *(u16 *) (param_1 + 6) == 0x32) {
        return 1;
    }
    if (*(u16 *) (param_1 + 6) == 0x33 || *(u16 *) (param_1 + 6) == 0x27B) {
        return 1;
    }
    iVar1 = func_800132BC((s32)&D_80126CAC, param_1);
    uVar2 = 0;
    if (D_801274D8 < iVar1) {
        uVar2 = (iVar1 < D_801274DC);
    }
    return uVar2;
}
