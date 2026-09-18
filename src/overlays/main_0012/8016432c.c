/* Overlay range [8016432C,80164410) from MAIN.CD member 0012.
 * SHA256(span)=f752f5e3310488bc1492e335e1540d2be2769582817728437aa09713105cbae3.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8016432C - 57 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80164418();
extern s32 func_80146E98(s32 a0);
extern void func_801553C0(s32 a0);
extern void func_80147364();
extern void func_80147324(s32 arg0);
extern void func_80162CCC();

void func_8016432C(s32 a0) {
    s32 s1 = a0;
    s32 s0 = *(s32 *)(s1 + 0x4C);
    func_80164418();
    if (func_80146E98(s1) != 0) {
        u32 v44;
        *(u16 *)(s0 + 0x18A) = 0;
        if (*(s32 *)(s0 + 0x184) != 0 &&
            ((v44 = *(u32 *)(s0 + 0x44)) & 0x400) == 0 &&
            (*(u32 *)(s0 + 0x1F8) & 0x80FFFFFF) == 0) {
            *(u32 *)(s0 + 0x44) = v44 | 0x10;
            if (*(s16 *)(s0 + 0x188) < 0x80) {
                *(u32 *)(s0 + 0x184) = *(u32 *)(s0 + 0x184) | 0x80000000;
            }
        } else {
            *(s32 *)(s0 + 0x184) = 0;
        }
        *(u16 *)(s0 + 0x188) = 0;
        __asm__ __volatile__("" : : "r"(s0));
        *(u32 *)(s0 + 0x44) = *(u32 *)(s0 + 0x44) & 0xFFFFFFFB;
        func_801553C0(s0);
        func_80147364(4, 0x449);
        func_80147324(0x44B);
        ((void (*)(s32))func_80162CCC)(s1);
    }
}
