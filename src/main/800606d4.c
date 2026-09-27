/* Main-exec range [800606D4,80060824) from the SLUS executable.
 * SHA256(span)=64ebd4264a89b0fd52d3b7cb80f26f7dcf2cced189ce547c019996de005ef9e2.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072A10;
s32 func_8005CF38(s32, s32, s32);                   /* static */
s32 func_80061678(s32);                             /* static */
void func_80061B58();                            /* static */
s32 func_80061C60();                                /* static */
s32 func_80061E18();                                /* static */
s32 func_80061F58(s32, s32, s32);               /* static */
extern s32 D_80078C84;
extern s32 *D_80078C90;

s32 func_800606D4(s32 *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 != 0xA) {
        if (temp_v1 < 0xB) {
            if (temp_v1 != 0) {
                return 0;
            }
            D_80072A10 = 0;
            *arg0 = 0xA;
            goto block_8;
        }
        switch (temp_v1) {                          /* irregular */
        case 20:
            func_80061B58();
            do {

            } while (func_8005CF38(M2C_FIELD(&D_80078C90, s32 *, 0), M2C_FIELD(&D_80078C90, s32 *, 0xC), M2C_FIELD(&D_80078C90, s32 *, 8)) != 0);
            *arg0 = 0x1E;
            goto block_19;
        case 30:
            if (func_80061E18() != 0) {
                temp_v0 = func_80061C60();
                if (temp_v0 == 1) {
                    temp_v0_2 = D_80072A10 + 1;
                    D_80072A10 = temp_v0_2;
                    if (temp_v0_2 < 0x10) {
                        *arg0 = 0xA;
                        goto block_19;
                    }
                }
                D_80078C84 = func_80061678(temp_v0);
                return 1;
            }
            /* Duplicate return node #20. Try simplifying control flow for better match */
            return 0;
        default:
            return 0;
        }
    } else {
block_8:
        do {

        } while (func_80061F58(M2C_FIELD(&D_80078C90, s32 *, 0), M2C_FIELD(&D_80078C90, s32 *, 4), 0) != M2C_FIELD(&D_80078C90, s32 *, 4));
        *arg0 = 0x14;
block_19:
        return 0;
    }
}
