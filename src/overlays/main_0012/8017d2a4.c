/* Overlay range [8017D2A4,8017D730) from MAIN.CD member 0012.
 * SHA256(span)=3cb0717623fdf54b4e8b403bed0d3496e112741aab6a4507f8397de4eca0eeca.
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
void func_8002D4C8(s32, s32);                              /* extern */
extern s32 D_80182638;
extern s32 D_801826D8;
extern s32 D_80185AD4;
extern s32 D_80185ADD;
extern s32 D_80185AE5;
extern s32 D_80185AEC;
extern s16 D_801150D4;
extern s16 D_80115118;
extern s16 D_8011512C;
extern s32 *D_80185ADC;
extern s32 *D_80185AE4;

void func_8017D2A4(void) {
    s16 temp_v1;
    s16 var_s1;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v0_2;

    if (D_80185AEC != 0) {
        if (D_80185AEC == 1) {
            if (D_8011512C == 3) {
                if (D_80185ADD == 8) {
                    func_80029774(0);
                    D_8011512C = 4;
                    D_80115118 = 0x4B;
                    D_801150D4 = 0;
                    D_801826D8 = 0xF;
                    func_8002D4C8(0xB3B, 0);
                } else {
                    goto block_7;
                }
            } else if (D_80185ADD == 6) {
                D_8011512C = 7;
                D_80115118 = 0x4B;
                D_801826D8 = 0x18;
            } else {
block_7:
                D_8011512C = 0;
            }
        } else {
            if ((D_80185AD4 & 3) == 1) {
                D_8011512C = 0xB;
                var_v0 = 0x12;
            } else {
                D_8011512C = 0xC;
                var_v0 = 0x1C;
            }
            D_801826D8 = var_v0;
            D_80115118 = 0x4B;
        }
        D_80185AD4 = 0;
        D_80185AE5 = 0xFFU;
    }
    if ((u32) ((u16) D_8011512C - 0xB) >= 2U) {
        var_s1 = 0;
        if (D_80185ADD != D_80185AE5) {
            var_v0_2 = 0 << 0x10;
            do {
                temp_v0 = var_v0_2 >> 0x10;
                temp_v1 = var_s1 + 1;
                var_s1 = temp_v1;
                *(&D_80185AE4 + temp_v0) = *(&D_80185ADC + temp_v0);
                var_v0_2 = var_s1 << 0x10;
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
