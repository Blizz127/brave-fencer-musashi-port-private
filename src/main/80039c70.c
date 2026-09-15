/* Main-exec range [80039C70,80039DEC) from the SLUS executable.
 * SHA256(span)=2974127bbec6bb377e42af0ace2f91b503637fc87bf8a65955eb65797d81aa28.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006ADD8[];
extern s32 D_8006B008[];
void func_8003B45C(s32 *, s32);                  /* static */
extern s32 D_80079A68;
extern s32 D_800A4ECC;
extern s32 D_800A4ED0;
extern u16 D_800A4ED4;
extern u16 D_800A4ED6;

void func_80039C70(void *arg0, s16 arg1, s32 arg2) {
    s32 temp_a1;
    u16 temp_v0_2;
    u8 temp_v0;
    void *temp_s0;

    temp_s0 = arg0 + ((arg1 * 0x1A) + 0x1A);
    if ((M2C_FIELD(temp_s0, u16 *, 6) & 0x300) != 0x300) {
        M2C_FIELD(arg0, s8 *, 0x1F9) = 1;
        return;
    }
    temp_v0 = M2C_FIELD(temp_s0, u8 *, 8);
    if ((u32) (temp_v0 - 0x10) < 0xBU) {
        switch (temp_v0) {
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
            break;
        case 16:
            temp_a1 = *(D_8006B008 + ((s32) (arg2 << 0x10) >> 0xE));
            if (D_80079A68 != temp_a1) {
                D_80079A68 = temp_a1;
                D_800A4ECC = 1;
                D_800A4ED0 = temp_a1;
                func_8003B45C(&D_800A4ECC, temp_a1);
            }
            break;
        case 17:
            D_800A4ECC = 6;
            temp_v0_2 = *(D_8006ADD8 + ((s32) (arg2 << 0x10) >> 0xF));
            D_800A4ED4 = temp_v0_2;
            D_800A4ED6 = temp_v0_2;
            func_8003B45C(&D_800A4ECC, (s32) arg1);
            break;
        }
    }
    M2C_FIELD(temp_s0, u8 *, 7) = (u8) (M2C_FIELD(temp_s0, u8 *, 7) & 0xFC);
}
