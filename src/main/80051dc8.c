/* Main-exec range [80051DC8,80051EA0) from the SLUS executable.
 * SHA256(span)=3f56a62df186b06c6099961ac4ee17eea685ca51e31de9c9492b2d0874d99db7.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80051EA0(void *, s32, s32, s32); /* static */
extern void *D_800A5E60;
extern u16 D_800A6548;
extern u16 D_800A654A;

void func_80051DC8(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_a1 >= 0) {
        M2C_FIELD(D_800A5E60, s32 *, 4) = (s32) (((temp_a1 >> 0x17) & 0x60) | 0xE1000200);
        M2C_FIELD(D_800A5E60, u8 *, 8) = (u8) M2C_FIELD(arg0, u8 *, 0xC);
        M2C_FIELD(D_800A5E60, u8 *, 9) = (u8) M2C_FIELD(arg0, u8 *, 0xD);
        M2C_FIELD(D_800A5E60, s8 *, 0xB) = (s8) (((temp_a1 >> 0x1D) & 2) | 0x40);
        M2C_FIELD(D_800A5E60, u8 *, 0xA) = (u8) M2C_FIELD(arg0, u8 *, 0xE);
        M2C_FIELD(D_800A5E60, s16 *, 0xC) = (s16) (M2C_FIELD(arg0, u16 *, 4) + D_800A6548);
        M2C_FIELD(D_800A5E60, s16 *, 0xE) = (s16) (M2C_FIELD(arg0, u16 *, 6) + D_800A654A);
        M2C_FIELD(D_800A5E60, s16 *, 0x10) = (s16) (M2C_FIELD(arg0, u16 *, 8) + D_800A6548);
        M2C_FIELD(D_800A5E60, s16 *, 0x12) = (s16) (M2C_FIELD(arg0, u16 *, 0xA) + D_800A654A);
        D_800A5E60 = func_80051EA0(D_800A5E60, arg1, arg2 & 0xFFFF, 4);
    }
}
