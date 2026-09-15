/* Main-exec range [80052460,800525DC) from the SLUS executable.
 * SHA256(span)=6b109c8549e37f7987e31ce27e8391740a4b89f975322cd523349c90cc9ef7a4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800A5E60;
extern u16 D_800A6548;
extern u16 D_800A654A;

void func_80052460(void *arg0, void *arg1, s32 arg2) {
    s32 *temp_a0;
    s32 temp_t4;

    temp_t4 = M2C_FIELD(arg0, s32 *, 0);
    if ((temp_t4 >= 0) && (M2C_FIELD(arg0, u16 *, 8) != 0) && (M2C_FIELD(arg0, u16 *, 0xA) != 0)) {
        M2C_FIELD(D_800A5E60, s32 *, 4) = (s32) ((M2C_FIELD(arg0, u16 *, 0xC) & 0x1F) | ((((u32) temp_t4 >> 0x11) & 0x180) | 0xE1000200) | (((u32) temp_t4 >> 0x17) & 0x60));
        M2C_FIELD(D_800A5E60, s32 *, 0xC) = (s32) (((M2C_FIELD(arg0, u16 *, 4) + D_800A6548) & 0xFFFF) | ((M2C_FIELD(arg0, u16 *, 6) + D_800A654A) << 0x10));
        M2C_FIELD(D_800A5E60, s32 *, 8) = (s32) ((((u32) temp_t4 >> 5) & 0x02000000) | (((temp_t4 << 0x12) & 0x01000000) | 0x64000000) | (M2C_FIELD(arg0, u8 *, 0x16) << 0x10) | (M2C_FIELD(arg0, u8 *, 0x15) << 8) | M2C_FIELD(arg0, u8 *, 0x14));
        M2C_FIELD(D_800A5E60, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, u8 *, 0xE) | (M2C_FIELD(arg0, u8 *, 0xF) << 8) | (M2C_FIELD(arg0, s16 *, 0x12) << 0x16) | ((M2C_FIELD(arg0, s16 *, 0x10) << 0xC) & 0x3F0000));
        M2C_FIELD(D_800A5E60, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, u16 *, 8) | (M2C_FIELD(arg0, u16 *, 0xA) << 0x10));
        temp_a0 = (M2C_FIELD(arg1, s32 *, 4) + ((arg2 & 0xFFFF) * 4)) - (M2C_FIELD(arg1, s32 *, 8) * 4);
        M2C_FIELD(D_800A5E60, s32 *, 0) = (s32) (*temp_a0 + 0x05000000);
        *temp_a0 = D_800A5E60 & 0xFFFFFF;
        D_800A5E60 += 0x18;
    }
}
