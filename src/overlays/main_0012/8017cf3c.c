/* Overlay range [8017CF3C,8017D2A4) from MAIN.CD member 0012.
 * SHA256(span)=b1a71e69b71551b42bba9ff10989c0a9ae31109378c44dcf36d1f96886be8b6f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80029774();                                 /* extern */
void func_8002B00C(s32 (*)());                           /* extern */
void func_8002D4C8(s32, s32);                              /* extern */
extern s32 D_80182638;
extern s32 D_801826D8;
extern s32 D_801857F8;
extern s32 D_80185AD4;
extern s32 D_80185ADD;
extern s32 D_80185AE5;
extern s32 D_80185AEC;
void func_8017DF40();                                 /* static */
extern u16 D_801150D4;
extern s16 D_80115118;
extern u16 D_8011511A;
extern s16 D_8011512C;
extern s32 *D_80185ADC;
extern s32 *D_80185AE4;

void func_8017CF3C(void) {
    s16 temp_v1;
    s16 var_s1;
    s32 temp_v0;
    s32 var_v0;

    if (D_80185AEC != 0) {
        if (D_80185AEC == 1) {
            if ((D_8011512C == 3) && (D_80185ADD == 8)) {
                func_8002B00C(D_801857F8);
                func_8017DF40(0);
                func_80029774(0);
                D_8011512C = 4;
                D_80115118 = 0x4B;
                D_801826D8 = 0x15;
                D_801150D4 = D_8011511A;
                func_8002D4C8(0xB3B, 0);
            } else {
                D_8011512C = 0;
            }
            D_80185AD4 = 0;
            D_80185AE5 = 0xFFU;
            goto block_9;
        }
        D_8011512C = 0xA;
        D_801826D8 = 0x1B;
        D_80115118 = 0x4B;
        D_80185AD4 = 0;
        return;
    }
block_9:
    if ((D_8011512C != 4) && (D_8011512C != 0xA)) {
        var_s1 = 0;
        if (D_80185ADD != D_80185AE5) {
            var_v0 = 0 << 0x10;
            do {
                temp_v0 = var_v0 >> 0x10;
                temp_v1 = var_s1 + 1;
                var_s1 = temp_v1;
                *(&D_80185AE4 + temp_v0) = *(&D_80185ADC + temp_v0);
                var_v0 = var_s1 << 0x10;
            } while (temp_v1 < 8);
            if ((u8) D_80185ADD < 9U) {
                switch (D_80185ADD) {
                case 0:
                    break;
                }
            }
            if (0 != 0) {
                D_80182638 = 0;
            }
        }
    }
}
