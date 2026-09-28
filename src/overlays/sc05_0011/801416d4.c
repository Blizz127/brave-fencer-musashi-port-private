/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801416D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_8011514C;
extern u8 D_8011514D;
extern u8 D_8011515C;
extern s32 func_800D11F0(s32 a0);
extern s32 func_800D1658(s32 a0);
extern void func_80141C0C(s32);

s32 func_801416D4(s16 param_1) {
    s32 cVar2;
    register s32 iVar1 __asm__("$3");
    register s32 two __asm__("$6");
    two = 2;
    iVar1 = 0;
    cVar2 = *(u8 *)&D_8011514C + D_8011514D * D_8011515C;
    if (param_1 == 1) goto c1;
    if (param_1 < 2) {
        if (param_1 == 0) goto c0;
        goto ret;
    }
    if (param_1 == two) goto c2;
    goto ret;
c0:
    iVar1 = func_800D11F0(cVar2 & 0xFF);
    goto ret;
c1:
    iVar1 = func_800D1658(cVar2 & 0xFF);
    goto ret;
c2:
    func_80141C0C(6);
    iVar1 = 1;
ret:
    return (iVar1 << 0x10) >> 0x10;
}
