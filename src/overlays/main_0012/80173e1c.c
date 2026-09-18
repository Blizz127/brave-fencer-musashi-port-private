/* Overlay range [80173E1C,80173EF8) from MAIN.CD member 0012.
 * SHA256(span)=8bdb67da56ffdd506fc748d4fe80733bb9ca85e416018134157e176041a48b80.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80173E1C - 55 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_801484B0(s32 a0, s32 a1);
extern void func_80149350(s32 arg0);
extern void func_80015954(s32 a0, s32 a1);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern s32 D_80127508;
extern u8 D_800D5DC0[];

void func_80173E1C(s32 a0)
{
    register s32 s0 __asm__("$16");
    register s32 *s1 __asm__("$17");
    s32 sp10[2];
    s32 sp18[2];
    s1 = &D_80127508;
    s0 = a0;
    if (*s1 != 0) {
        func_801484B0((s32)sp10, (s32)sp18);
        ((void (*)(s32, s32, s32))func_80149350)(s0, (s32)sp10, (s32)sp10);
        func_80015954((s32)sp10, *s1 + 4);
    }
    if (*(s32 *)(s0 + 0x198) != 0) {
        if (func_801399F0(*(s32 *)(s0 + 0x198)) == 0) {
            return;
        }
        func_80139914(*(s32 *)(s0 + 0x198));
        *(s32 *)(s0 + 0x198) = 0;
        func_80154274((s32 *)s0, (s32)&D_800D5DC0);
        func_80171A1C((u8 *)s0);
    } else {
        s32 iVar1 = *(s32 *)(s0 + 0x200) - 1;
        *(s32 *)(s0 + 0x200) = iVar1;
        if (iVar1 != -1) {
            return;
        }
        func_80154274((s32 *)s0, (s32)&D_800D5DC0);
        func_80171A1C((u8 *)s0);
    }
}
