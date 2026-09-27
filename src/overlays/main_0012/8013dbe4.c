/* Overlay range [8013DBE4,8013DD68) from MAIN.CD member 0012.
 * SHA256(span)=c29b13b8bcdf065392b31b6550c8820ee0bfee8190e7795147796a25bb5a5aad.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_801841A8;
extern s32 D_801841AC;
extern s32 D_801841BC;
extern s32 D_801841DC;
extern s32 D_801841E0;
extern s32 D_801841E4;
void func_8013DD68(s32, s32, s32);               /* static */

void func_8013DBE4(s32 arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    void *temp_v0;

    if (D_801841AC != 0) {
        D_801841BC = 0;
        temp_v0 = (arg0 * 0xC) + D_801841A8;
        temp_a0 = M2C_FIELD(temp_v0, s32 *, 0);
        temp_a1 = M2C_FIELD(temp_v0, s32 *, 4);
        temp_a2 = M2C_FIELD(temp_v0, s32 *, 8);
        var_s0 = 0;
        if (D_801841DC != temp_a0) {
            var_s0 = 1;
            if (D_801841DC < temp_a0) {
                var_v0 = D_801841DC + 4;
                if ((temp_a0 - D_801841DC) >= 5) {
                    goto block_7;
                }
                goto block_6;
            }
            var_v0 = D_801841DC - 4;
            if ((D_801841DC - temp_a0) < 5) {
block_6:
                D_801841DC = temp_a0;
            } else {
block_7:
                D_801841DC = var_v0;
            }
        }
        if (D_801841E0 != temp_a1) {
            var_s0 = 1;
            if (D_801841E0 < temp_a1) {
                var_v0_2 = D_801841E0 + 4;
                if ((temp_a1 - D_801841E0) >= 5) {
                    goto block_14;
                }
                goto block_13;
            }
            var_v0_2 = D_801841E0 - 4;
            if ((D_801841E0 - temp_a1) < 5) {
block_13:
                D_801841E0 = temp_a1;
            } else {
block_14:
                D_801841E0 = var_v0_2;
            }
        }
        if (D_801841E4 != temp_a2) {
            var_s0 = 1;
            if (D_801841E4 < temp_a2) {
                var_v0_3 = D_801841E4 + 4;
                if ((temp_a2 - D_801841E4) >= 5) {
                    goto block_21;
                }
                goto block_20;
            }
            var_v0_3 = D_801841E4 - 4;
            if ((D_801841E4 - temp_a2) < 5) {
block_20:
                D_801841E4 = temp_a2;
            } else {
block_21:
                D_801841E4 = var_v0_3;
            }
        }
        if (var_s0 != 0) {
            func_8013DD68(temp_a0, temp_a1, temp_a2);
        }
        D_801841BC = var_s0;
    }
}
