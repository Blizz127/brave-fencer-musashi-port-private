/* SC02 resident retail span [80158FA4,80159070). Offset 0x30E4C at base 80128158.
 * SHA256(span)=dbee05f5c70a578b6650d51de7259890ee57a6e5f241678b9d6a699ac224e31d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184298->D_801B6450.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158FA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B6450;
extern u8 D_80110C3C[];
extern u16 func_80148800(s32 *a0);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_80159464(void);
extern void func_801594E8(s32, s32);
extern void func_80146C98(s32 *a0, s16 a1);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80158FA4(s32 param_1)
{
    s32 v0;
    s16 sVar1;

    v0 = *(s32 *)(param_1 + 0x20);
    *(u16 *)(v0 + 0x12) = (*(u16 *)(v0 + 0x12) + 0x16) & 0xfff;
    if (((s32 (*)(void))func_80148800)() & 0xf0) {
        D_801B6450 = 1;
    }
    if (func_801399F0(*(s32 *)(param_1 + 0x198)) != 0) {
        func_80139914(*(s32 *)(param_1 + 0x198));
        *(s32 *)(param_1 + 0x198) = 0;
        sVar1 = ((s32 (*)(s32))func_80159464)(param_1);
        if (sVar1 != 0) {
            func_801594E8(param_1, sVar1);
            ((void (*)(s32, s32))func_80146C98)(param_1, 0xc);
        } else {
            *(s32 *)(param_1 + 0x198) = ((s32 (*)(u8 *))func_8013767C)(&(*(u8 *)&D_80110C3C));
            ((void (*)(s32))func_80146CA0)(param_1);
        }
    }
}
