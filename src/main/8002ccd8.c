/* Main-exec range [8002CCD8,8002CDD8) from the SLUS executable.
 * SHA256(span)=55c92e29d34da8f11d9794c0219b1af3af9df09e62e78e76e1a0a3abd2d888b4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003B170();                            /* static */
void func_8003C23C(s32, s32);            /* static */
void func_8003C598(void *);                   /* static */
void func_8003D3B4(s32, s32);                /* static */
void func_8003D3F8(s16, s16);                    /* static */
void func_8003D434(s16 *, s16 *);                /* static */
void func_8003D454();                            /* static */
void func_8003D630();                            /* static */
void func_8004239C();                     /* static */
void func_80042610();                     /* static */
extern s32 *D_800A4EA4;

void func_8002CCD8(void) {
    s16 sp12;
    s16 sp10;
    s16 var_s1;
    s32 temp_lo;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s0_2;

    func_80042610(0);
    func_8004239C(0);
    var_s0 = 0;
    do {
        func_8003D3B4(var_s0, 8);
        var_s0 += 1;
    } while (var_s0 < 0x18);
    func_8003C23C(0, 0xFFFFFF);
    func_8003D434(&sp10, &sp12);
    var_s0_2 = 0xF;
    var_s1 = 0x3BF1;
    do {
        func_8004239C(0);
        temp_lo = sp10 * var_s0_2;
        var_s0_2 -= 1;
        temp_v0 = temp_lo >> 4;
        sp12 = (s16) temp_v0;
        func_8003D3F8((s16) temp_v0, (s16) temp_v0);
        M2C_FIELD(&D_800A4EA4, s32 *, 0) = 3;
        M2C_FIELD(&D_800A4EA4, s16 *, 4) = var_s1;
        M2C_FIELD(&D_800A4EA4, s16 *, 6) = var_s1;
        func_8003C598(&D_800A4EA4);
        var_s1 -= 0x3FF;
    } while (var_s0_2 != 0);
    func_8003D454();
    func_8003D630();
    func_8003B170();
}
