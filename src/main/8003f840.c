/* Main-exec range [8003F840,8003FA54) from the SLUS executable.
 * SHA256(span)=4e8956f5f3df685279c9a17a5dbfc14507cd52c2980ab4e5f4c03e6c5a7ee3ee.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8007958E;
extern s32 *D_800A4620;
extern u16 D_800A5F60;
extern s32 D_800A6578;
extern s32 D_800A6584;
extern u8 D_800B9B27;
extern u8 D_800B9B2C;
extern u16 D_800B9B38;
extern s16 D_800B9B3A;
extern s16 D_800B9B3C;
extern s16 D_800B9B3E;
extern s32 *D_800B9B5E;
extern s32 *D_800B9B60;
extern s32 *D_800B9B62;
extern s32 *D_800C7EC0;

void func_8003F840(void) {
    s32 *var_a1;
    s32 var_a2;
    s32 var_v1;
    u16 var_v0;

    var_a2 = 0;
    var_a1 = &D_800C7EC0;
    D_800B9B3C = D_800B9B3A * 8;
    D_800B9B3E = D_800B9B2C + (D_800B9B27 * 0x10);
    *(&D_8007958E + (D_800B9B3A * 0x34)) = 0x7FFF;
    do {
        var_a2 += 1;
        *var_a1 &= ~(1 << *(&D_800B9B3C - 2));
        var_a1 += 4;
    } while (var_a2 < 0x10);
    if ((D_800B9B38 & 1) > 0) {
        var_v0 = ((((s32) ((s16) D_800B9B38 - 1) / 2) * 0x10) + D_800A6578)->unkC;
        var_v1 = D_800B9B3C * 2;
    } else {
        var_v0 = ((((s32) ((s16) D_800B9B38 - 1) / 2) * 0x10) + D_800A6578)->unkE;
        var_v1 = D_800B9B3C * 2;
    }
    *(&D_800B9B5E + var_v1) = var_v0;
    *(&D_800A4620 + D_800B9B3A) = *(&D_800A4620 + D_800B9B3A) | 8;
    *(&D_800B9B60 + (D_800B9B3C * 2)) = ((((D_800B9B27 * 0x10) + D_800B9B2C) << 5) + D_800A6584)->unk10;
    *(&D_800B9B62 + (D_800B9B3C * 2)) = ((((D_800B9B27 * 0x10) + D_800B9B2C) << 5) + D_800A6584)->unk12 + D_800A5F60;
    *(&D_800A4620 + D_800B9B3A) = *(&D_800A4620 + D_800B9B3A) | 0x30;
}
