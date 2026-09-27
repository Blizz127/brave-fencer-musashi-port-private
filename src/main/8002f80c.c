/* Main-exec range [8002F80C,8002FA3C) from the SLUS executable.
 * SHA256(span)=9983ee8799f00e2261bc9d9a2d1bd97eb085452dfcb410f09a5df05db716bfe4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A96E;
void func_8002D320();                                  /* static */
void func_8002DC68(s32, s32, s32);                       /* static */
void func_8002E138(s32, s32, s32);                           /* static */
void func_80030F80();                                  /* static */
void func_80031BE0();                                  /* static */
extern s16 D_8006A96C;
extern u8 D_800760D0;
extern u8 D_800760D4;
extern u8 D_800760D8;
extern u8 D_800760DC;
extern s16 D_800A4EFC;
extern u8 D_800A4F17;
extern u8 D_800A4F18;
extern s32 D_800A4F24;

void func_8002F80C(void) {
    s16 temp_v0;
    s32 var_a2;
    u8 temp_a0;
    u8 var_a1;
    u8 var_v0;

    var_a2 = 0;
    var_a1 = 0;
    if (D_8006A96E & 1) {
        var_a2 = 1;
        var_a1 = D_800760D0;
    }
    if (D_8006A96E & 2) {
        var_a2 = 1;
        if ((s32) var_a1 < (s32) D_800760D4) {
            var_a1 = D_800760D4 & 0xFF;
        }
    }
    if (D_8006A96E & 4) {
        var_a2 = 1;
        if ((s32) var_a1 < (s32) D_800760D8) {
            var_a1 = D_800760D8 & 0xFF;
        }
    }
    if (D_8006A96E & 8) {
        var_a2 = 1;
        if ((s32) var_a1 < (s32) D_800760DC) {
            var_a1 = D_800760DC & 0xFF;
        }
    }
    temp_a0 = D_8006A96E;
    D_8006A96E = (u8) (temp_a0 & 0xF0);
    if (var_a2 & 0xFF) {
        D_8006A96C = 0x10;
        if (var_a1 != 0) {
            func_8002DC68(0xBEB, var_a1 | 0x1000, var_a2);
            var_v0 = D_8006A96E | 0x10;
            goto block_26;
        }
        if (temp_a0 & 0x10) {
            D_800A4F17 = 1;
            func_8002E138(4, 0xBEB, 0);
            D_800A4F17 = D_800A4F18;
            if (D_800A4F18 != 0) {
                goto block_22;
            }
            goto block_25;
        }
    } else if (D_8006A96C != 0) {
        temp_v0 = D_8006A96C - 1;
        D_8006A96C = temp_v0;
        if (((temp_v0 << 0x10) == 0) && (temp_a0 & 0x10)) {
            D_800A4F17 = 1;
            func_8002E138(4, 0xBEB, 0);
            D_800A4F17 = D_800A4F18;
            if (D_800A4F18 != 0) {
block_22:
                if (D_800A4EFC != 0) {
                    D_800A4EFC -= 1;
                }
                func_80030F80();
                func_8002D320();
                func_80031BE0();
                D_800A4F18 = 0;
                D_800A4F17 = 0;
            }
block_25:
            D_800A4F24 = 0;
            var_v0 = D_8006A96E & 0xEF;
block_26:
            D_8006A96E = var_v0;
        }
    }
}
