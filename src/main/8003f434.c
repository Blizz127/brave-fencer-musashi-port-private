/* Main-exec range [8003F434,8003F7C8) from the SLUS executable.
 * SHA256(span)=a5df8fcf49cf2cba029e92dfd084880c5b083dac4e2a3aa6d5dd04ee57ce0a6b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003F840(u8);                          /* static */
s32 func_800402A8(u16, u16);                        /* static */
void func_800403A4(s32);                         /* static */
void func_80040938(s32, s32);                /* static */
s32 func_800414E4(s16, s16);                        /* static */
extern s32 *D_80079588;
extern s32 *D_8007958A;
extern s32 *D_80079594;
extern s32 *D_80079596;
extern s32 *D_80079598;
extern s32 *D_8007959A;
extern s32 *D_8007959C;
extern s32 *D_8007959E;
extern s32 *D_800795A3;
extern s32 D_800A6510;
extern s32 D_800A6578;
extern s32 D_800A6584;
extern u8 D_800B9B20;
extern s8 D_800B9B22;
extern s8 D_800B9B23;
extern s8 D_800B9B24;
extern s8 D_800B9B25;
extern u8 D_800B9B27;
extern u8 D_800B9B2A;
extern u8 D_800B9B2B;
extern u8 D_800B9B2C;
extern u8 D_800B9B2D;
extern u8 D_800B9B2E;
extern u8 D_800B9B2F;
extern u8 D_800B9B30;
extern u8 D_800B9B31;
extern u8 D_800B9B32;
extern u8 D_800B9B33;
extern u8 D_800B9B34;
extern s16 D_800B9B36;
extern u16 D_800B9B38;
extern s16 D_800B9B3A;

s16 func_8003F434(s16 arg0, s16 arg1, s16 arg2, u8 arg3, u16 arg4, u16 arg5, s32 arg6, s32 arg7) {
    s16 sp10;
    s32 temp_v0_3;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a0;
    void *temp_v0;
    void *temp_v0_2;

    sp10 = arg1;
    if (D_800A6510 == 1) {
        return -1;
    }
    D_800A6510 = 1;
    if (((u32) (arg0 & 0xFFFF) < 0x18U) && (func_800414E4(arg1, arg2) == 0)) {
        D_800B9B36 = 0x21;
        D_800B9B22 = (s8) arg4;
        D_800B9B23 = (s8) arg5;
        D_800B9B2C = arg3;
        if ((s16) arg6 == (s16) arg7) {
            D_800B9B25 = 0x40;
            D_800B9B24 = (s8) arg6;
            var_v0 = arg2 << 0x10;
        } else {
            if ((s16) arg7 < (s16) arg6) {
                var_v0_2 = (s32) ((s16) arg7 << 6) / (s16) arg6;
                D_800B9B24 = (s8) arg6;
            } else {
                D_800B9B24 = (s8) arg7;
                var_v0_2 = 0x7F - ((s32) ((s16) arg6 << 6) / (s16) arg7);
            }
            D_800B9B25 = (s8) var_v0_2;
            var_v0 = arg2 << 0x10;
        }
        temp_v0 = (var_v0 >> 0xC) + D_800A6578;
        D_800B9B2A = M2C_FIELD(temp_v0, u8 *, 1);
        D_800B9B2B = M2C_FIELD(temp_v0, u8 *, 4);
        D_800B9B20 = M2C_FIELD(temp_v0, u8 *, 0);
        temp_v0_2 = ((D_800B9B2C + (D_800B9B27 * 0x10)) << 5) + D_800A6584;
        D_800B9B2F = M2C_FIELD(temp_v0_2, u8 *, 0);
        temp_a0 = M2C_FIELD(temp_v0_2, u16 *, 0x16);
        D_800B9B38 = temp_a0;
        D_800B9B2D = M2C_FIELD(temp_v0_2, u8 *, 2);
        D_800B9B2E = M2C_FIELD(temp_v0_2, u8 *, 3);
        D_800B9B30 = M2C_FIELD(temp_v0_2, u8 *, 4);
        D_800B9B31 = M2C_FIELD(temp_v0_2, u8 *, 5);
        D_800B9B34 = M2C_FIELD(temp_v0_2, u8 *, 1);
        D_800B9B32 = M2C_FIELD(temp_v0_2, u8 *, 6);
        D_800B9B33 = M2C_FIELD(temp_v0_2, u8 *, 7);
        if (temp_a0 == 0) {
            goto block_11;
        }
        temp_v0_3 = arg0 * 0x34;
        D_800B9B3A = arg0;
        *(&D_80079596 + temp_v0_3) = 0x21;
        *(&D_8007959E + temp_v0_3) = (u16) sp10;
        *(&D_8007959A + temp_v0_3) = arg2;
        *(&D_80079598 + temp_v0_3) = (s16) D_800B9B27;
        *(&D_80079588 + temp_v0_3) = D_800B9B38;
        *(&D_80079594 + temp_v0_3) = arg4;
        *(&D_800795A3 + temp_v0_3) = 1;
        *(&D_8007958A + temp_v0_3) = 0;
        *(&D_8007959C + temp_v0_3) = (s16) D_800B9B2C;
        func_8003F840(D_800B9B2C);
        if ((s16) D_800B9B38 == 0xFF) {
            func_800403A4(arg0 & 0xFF);
        } else {
            func_80040938(1, func_800402A8(arg4, arg5) & 0xFFFF);
        }
        D_800A6510 = 0;
        return arg0;
    }
block_11:
    D_800A6510 = 0;
    return -1;
}
