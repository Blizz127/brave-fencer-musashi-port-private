/* Overlay range [80154F9C,801550FC) from MAIN.CD member 0012.
 * SHA256(span)=7edb80a446de4725cb4ed27ae63a05f67fd518039e25f4daf1286646ebc00846.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801550FC(void *);                   /* static */
s32 func_8016F1AC();                                /* static */
extern s32 *D_80078E78;
extern s16 D_80078E96;
extern s16 D_80078E9E;
extern s16 D_80078EA6;
extern s32 *D_800D8D10;

void func_80154F9C(void *arg0) {
    s32 var_a0;
    s32 var_v0;

    if (M2C_FIELD(arg0, s32 *, 0xC8) & 0x01000000) {
        if ((!(D_80078E96 & 0x8000) && (D_80078E9E >= 0x10) && (D_80078EA6 >= 0x10)) || (func_8016F1AC() != 0)) {
            var_a0 = M2C_FIELD(arg0, s32 *, 0xC8) & 0xC0FFFFFF;
            M2C_FIELD(arg0, s32 *, 0xC8) = var_a0;
            goto block_15;
        }
    } else {
        if ((D_80078E96 & 0x8000) && (func_8016F1AC() == 0)) {
            var_a0 = (s32) &D_800D8D10;
            var_v0 = M2C_FIELD(arg0, s32 *, 0xC8) | 0x01000000;
            goto block_14;
        }
        if (((M2C_FIELD(&D_80078E78, s16 *, 0x26) < 0x10) || (M2C_FIELD(&D_80078E78, s16 *, 0x2E) < 0x10)) && !(M2C_FIELD(arg0, s32 *, 0x44) & 0xC0) && (func_8016F1AC() == 0)) {
            var_a0 = 0x40000002;
            var_v0 = M2C_FIELD(arg0, s32 *, 0xC8) | 0x01000000;
block_14:
            M2C_FIELD(arg0, s32 *, 0xC8) = var_v0;
block_15:
            func_801550FC((void *) var_a0);
        }
    }
}
