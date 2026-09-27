/* Overlay range [8012E8E0,8012E9C0) from MAIN.CD member 0012.
 * SHA256(span)=228c73ca8cef62b2a9abbc96c2544e2f1217907ec15bbfced72754d894047697.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012E8E0 - 56 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80049CAC(s32 a0, s32 a1);

void func_8012E8E0(s32 a0, s32 a1)
{
    s32 v1;
    s32 p;
    s16 v;
    u16 e;
    v1 = *(s32 *)(a0 + 0x20);
    *(s16 *)(a0 + 0x6) = *(u16 *)(a1 + 0x0);
    *(s16 *)(a0 + 0xA) = *(u16 *)(a1 + 0x2);
    e = *(u16 *)(a1 + 0x4);
    *(s16 *)(a0 + 0xC) = 0;
    *(s16 *)(a0 + 0x8) = 0;
    *(s16 *)(a0 + 0x4) = 0;
    *(s16 *)(a0 + 0xE) = e;
    if (v1 != 0) {
        *(s16 *)(v1 + 0x12) = *(u16 *)(a1 + 0x6);
        a1 = *(s32 *)(a0 + 0x20);
        if (a1 != 0) {
            func_80049CAC(a1 + 0x10, a1 + 0x34);
            p = *(s32 *)(a0 + 0x20);
            v = *(u16 *)(a0 + 0x6) + *(u16 *)(a0 + 0x50);
            *(s16 *)(p + 0x8) = v;
            *(s32 *)(p + 0x48) = v;
            v = *(u16 *)(a0 + 0xA) + *(u16 *)(a0 + 0x52);
            *(s16 *)(p + 0xA) = v;
            *(s32 *)(p + 0x4C) = v;
            v = *(u16 *)(a0 + 0xE) + *(u16 *)(a0 + 0x54);
            *(s16 *)(p + 0xC) = v;
            *(u16 *)(p + 0x2C) = *(u16 *)(p + 0x2C) | 1;
            *(s32 *)(p + 0x50) = v;
        }
    }
}
