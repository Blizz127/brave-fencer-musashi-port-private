/* Main-exec range [8001BBBC,8001BC6C) from the SLUS executable.
 * SHA256(span)=3c72d6dc7239a27a2b5f81b0b3390f54bba424801d0e247e8de211b24ee6dd82.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern void *D_800A5E60;
extern s32 *D_800A6610;
extern u16 D_800B9A02;

void func_8001BBBC(s32 arg0, s32 arg1, s8 arg2) {
    s32 temp_a3;
    void *temp_t0;

    M2C_FIELD(D_800A5E60, s8 *, 3) = 4;
    M2C_FIELD(D_800A5E60, s8 *, 0xB) = 0x62;
    M2C_FIELD(D_800A5E60, s16 *, 0x10) = 0x140;
    M2C_FIELD(D_800A5E60, s16 *, 0x12) = 8;
    temp_t0 = (D_800B9A02 << 0xE) + &D_800A6610;
    M2C_FIELD(D_800A5E60, s16 *, 0xC) = (s16) (arg0 - 0xA0);
    M2C_FIELD(D_800A5E60, s32 *, 4) = 0xE1000040;
    M2C_FIELD(D_800A5E60, s8 *, 0xA) = arg2;
    M2C_FIELD(D_800A5E60, s8 *, 9) = arg2;
    M2C_FIELD(D_800A5E60, s8 *, 8) = arg2;
    M2C_FIELD(D_800A5E60, s16 *, 0xE) = (s16) (arg1 - 0x78);
    M2C_FIELD(D_800A5E60, s32 *, 0) = (s32) ((M2C_FIELD(D_800A5E60, s32 *, 0) & 0xFF000000) | (M2C_FIELD(temp_t0, s32 *, 4) & 0xFFFFFF));
    temp_a3 = (s32) D_800A5E60 & 0xFFFFFF;
    D_800A5E60 += 0x14;
    M2C_FIELD(temp_t0, s32 *, 4) = (s32) ((M2C_FIELD(temp_t0, s32 *, 4) & 0xFF000000) | temp_a3);
}
