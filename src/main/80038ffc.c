/* Main-exec range [80038FFC,8003916C) from the SLUS executable.
 * SHA256(span)=01991d7380c3f5089d94f150c393d63029693647db8948d74df20cc4c75ab096.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80039308(s32);                         /* static */
void func_80039B20(s32);                         /* static */
void func_80039C5C(s32);                         /* static */
void func_80039F50(s32);                         /* static */
void func_8003A098(s32);                         /* static */
void func_8003A0D0(s32);                         /* static */
void func_8003A0E4(s32);                         /* static */
void func_8003A234(s32);                         /* static */

s32 func_80038FFC(void *arg0) {
    s16 temp_a1_2;
    s32 temp_a1;
    s32 var_a1_2;
    u32 temp_v0;
    u8 *temp_a2;
    u8 *temp_v0_2;
    u8 *temp_v1;
    u8 temp_v1_2;
    u8 var_a1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    var_a1 = *temp_v1;
    if (var_a1 & 0x80) {
        M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
        M2C_FIELD(arg0, u8 *, 0x1F7) = var_a1;
    } else {
        var_a1 = M2C_FIELD(arg0, u8 *, 0x1F7);
    }
    temp_v0 = var_a1 >> 4;
    switch (temp_v0) {                              /* switch 1 */
    case 8:                                         /* switch 1 */
        func_80039B20(var_a1 & 0xF);
        break;
    case 9:                                         /* switch 1 */
        func_80039308(var_a1 & 0xF);
        break;
    case 10:                                        /* switch 1 */
        func_80039C5C(var_a1 & 0xF);
        break;
    case 11:                                        /* switch 1 */
        func_80039F50(var_a1 & 0xF);
        break;
    case 12:                                        /* switch 1 */
        func_8003A098(var_a1 & 0xF);
        break;
    case 13:                                        /* switch 1 */
        func_8003A0D0(var_a1 & 0xF);
        break;
    case 14:                                        /* switch 1 */
        func_8003A0E4(var_a1 & 0xF);
        break;
    case 15:                                        /* switch 1 */
        temp_a1 = var_a1 & 0xF;
        switch (temp_a1) {                          /* switch 2; irregular */
        default:                                    /* switch 2 */
            var_a1_2 = 0;
            if (temp_a1 != 0) {

            } else {
loop_19:
                temp_v0_2 = M2C_FIELD(arg0, u8 **, 0);
                temp_v1_2 = *temp_v0_2;
                temp_a2 = temp_v0_2 + 1;
                M2C_FIELD(arg0, u8 **, 0) = temp_a2;
                temp_a1_2 = var_a1_2 + (temp_v1_2 & 0x7F);
                if (temp_v1_2 & 0x80) {
                    var_a1_2 = temp_a1_2 << 7;
                    goto loop_19;
                }
                M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_a2 + temp_a1_2);
            }
            break;
        case 7:                                     /* switch 2 */
            var_a1_2 = 0;
            goto loop_19;
        case 15:                                    /* switch 2 */
            func_8003A234(temp_a1);
            break;
        }
        break;
    }
    return 0;
}
