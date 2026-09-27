/* Overlay range [8013D178,8013D330) from MAIN.CD member 0012.
 * SHA256(span)=9eced75a2a1d4459943098835d99cb55c10f079eb1194664a5a573c9419396b7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80185B29;
extern s32 D_80185B2A;
extern s32 D_80185B2B;
extern s32 D_80185B2D;
extern s32 D_80185B2E;
extern s32 D_80185B2F;
extern s32 D_80185BC9;
extern s32 D_80185BCA;
extern s32 D_80185BCB;
extern s32 D_80185BCD;
extern s32 D_80185BCE;
extern s32 D_80185BCF;
extern s32 D_80185BD0;
extern u8 D_80185B28;
extern u8 D_80185B2C;
extern u8 D_80185B30;
extern u8 D_80185BC8;
extern u8 D_80185BCC;

void func_8013D178(void) {
    u32 temp_v0;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 temp_v0_4;
    u32 temp_v0_5;
    u32 temp_v0_6;
    u32 temp_v0_7;
    u32 temp_v0_8;
    u32 temp_v0_9;
    u8 var_v0;
    u8 var_v0_2;
    u8 var_v0_3;
    u8 var_v0_4;
    u8 var_v0_5;
    u8 var_v0_6;
    u8 var_v0_7;
    u8 var_v0_8;
    u8 var_v0_9;

    temp_v0 = D_80185B28 & 0xFF;
    if (temp_v0 != D_80185BC8) {
        var_v0 = D_80185B28 + 8;
        if (temp_v0 >= (u8) D_80185BC8) {
            var_v0 = D_80185B28 - 8;
        }
        D_80185B28 = var_v0;
    }
    temp_v0_2 = D_80185B29 & 0xFF;
    if (temp_v0_2 != D_80185BC9) {
        var_v0_2 = D_80185B29 + 8;
        if (temp_v0_2 >= (u8) D_80185BC9) {
            var_v0_2 = D_80185B29 - 8;
        }
        D_80185B29 = var_v0_2;
    }
    temp_v0_3 = D_80185B2A & 0xFF;
    if (temp_v0_3 != D_80185BCA) {
        var_v0_3 = D_80185B2A + 8;
        if (temp_v0_3 >= (u8) D_80185BCA) {
            var_v0_3 = D_80185B2A - 8;
        }
        D_80185B2A = var_v0_3;
    }
    temp_v0_4 = D_80185B2B & 0xFF;
    if (temp_v0_4 != D_80185BCB) {
        var_v0_4 = D_80185B2B + 8;
        if (temp_v0_4 >= (u8) D_80185BCB) {
            var_v0_4 = D_80185B2B - 8;
        }
        D_80185B2B = var_v0_4;
    }
    temp_v0_5 = D_80185B2C & 0xFF;
    if (temp_v0_5 != D_80185BCC) {
        var_v0_5 = D_80185B2C + 8;
        if (temp_v0_5 >= (u8) D_80185BCC) {
            var_v0_5 = D_80185B2C - 8;
        }
        D_80185B2C = var_v0_5;
    }
    temp_v0_6 = D_80185B2D & 0xFF;
    if (temp_v0_6 != D_80185BCD) {
        var_v0_6 = D_80185B2D + 8;
        if (temp_v0_6 >= (u8) D_80185BCD) {
            var_v0_6 = D_80185B2D - 8;
        }
        D_80185B2D = var_v0_6;
    }
    temp_v0_7 = D_80185B2E & 0xFF;
    if (temp_v0_7 != D_80185BCE) {
        var_v0_7 = D_80185B2E + 8;
        if (temp_v0_7 >= (u8) D_80185BCE) {
            var_v0_7 = D_80185B2E - 8;
        }
        D_80185B2E = var_v0_7;
    }
    temp_v0_8 = D_80185B2F & 0xFF;
    if (temp_v0_8 != D_80185BCF) {
        var_v0_8 = D_80185B2F + 8;
        if (temp_v0_8 >= (u8) D_80185BCF) {
            var_v0_8 = D_80185B2F - 8;
        }
        D_80185B2F = var_v0_8;
    }
    temp_v0_9 = D_80185B30 & 0xFF;
    if (temp_v0_9 != D_80185BD0) {
        var_v0_9 = D_80185B30 + 8;
        if (temp_v0_9 >= (u8) D_80185BD0) {
            var_v0_9 = D_80185B30 - 8;
        }
        D_80185B30 = var_v0_9;
    }
}
