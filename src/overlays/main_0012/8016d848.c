/* Overlay range [8016D848,8016D984) from MAIN.CD member 0012.
 * SHA256(span)=50cc4b871bb534c3e2faa7fd3970d3a8cb385f09443b8e4d96ab2929e13bd494.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8016D848 - 79 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_800D20C0();

void func_8016D848(s32 *a0) {
    s16 sp20[4];
    s16 sp28[4];
    s32 s2;
    s32 cnt;
    s16 i;
    s32 p;
    cnt = *(s32 *)((s32)a0 + 0x1C) - 1;
    *(s32 *)((s32)a0 + 0x1C) = cnt;
    if (cnt == 0) {
        func_80146C3C();
        return;
    }
    if (cnt < 4) {
        s2 = -0xC00;
    } else {
        s2 = 0x800;
        i = 0;
        do {
            func_80146A6C(0x33, a0, 0, 0, 0, 0x8000, 0);
            i = i + 1;
        } while (i < 5);
    }
    p = *(s32 *)((s32)a0 + 0x20);
    if ((s2 << 16) == 0) {
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x18) ^ 0x400;
        *(s16 *)(p + 0x1A) = *(u16 *)(p + 0x1A) ^ 0x200;
    } else {
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x18) + s2;
        *(s16 *)(p + 0x1A) = *(u16 *)(p + 0x1A) + s2;
    }
    sp20[0] = *(u16 *)((s32)a0 + 0x12);
    sp20[1] = *(u16 *)((s32)a0 + 0x16);
    sp20[2] = *(u16 *)((s32)a0 + 0x1A);
    func_800D20C0((s32)sp20, (s32)sp28, 0x6);
    *(s16 *)((s32)a0 + 0x6) = sp20[0];
    *(s16 *)((s32)a0 + 0xA) = sp20[1];
    *(s16 *)((s32)a0 + 0xE) = sp20[2];
}
