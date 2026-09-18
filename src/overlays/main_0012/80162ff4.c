/* Overlay range [80162FF4,801630C4) from MAIN.CD member 0012.
 * SHA256(span)=9d9ecbba9758a886f99d8bef7f8d4a9c2d9f589b3fddffbbcb7c7477ad2ee328.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80162FF4 - 52 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80162F60(s32 arg0, s32 arg1);
extern void func_80162F80(s32 arg0, s32 arg1);
extern void func_80162FA0(s32 arg0, s32 arg1);
extern void func_80013F3C(s32 a0);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_80146D30(s32 a0);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");

void func_80162FF4(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 sp[16];
    s32 s2 = a0;
    s32 s0 = a2;
    s32 s3 = a3;
    s32 s1 = *(s32 *)(s2 + 0x20);
    s32 *q;
    func_80162F60(a0, a1);
    func_80162F80(s2, s0);
    func_80162FA0(s2, s3);
    q = &sp[8];
    func_80013F3C((s32)q);
    func_800126C4((s32)q, *(s16 *)(s1 + 0x10));
    func_80012558((s32)q, *(s16 *)(s1 + 0x12));
    func_800123F0((s32)q, *(s16 *)(s1 + 0x14));
    func_800484EC((s32)q, s2 + 0x24, (s32)&sp[4]);
    aD_80127090 = sp[4];
    aD_80127094 = sp[5];
    aD_80127098 = sp[6];
    func_80146D30(s2);
}
