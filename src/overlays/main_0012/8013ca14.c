/* Overlay range [8013CA14,8013CABC) from MAIN.CD member 0012.
 * SHA256(span)=2d64b130f5a14ff9a1795b951291fe906fb14d3ef7d8dca156c60b3b62e52296.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80184198;
extern s32 D_8018419D;
extern s32 D_801269C8;
extern s32 D_801269D4;
extern u8 D_8018419C;

void func_8013CA14(void) {
    s8 temp_v1;
    u8 temp_v0_2;
    void *temp_v0;

    if (D_80184198 != 0) {
        if (D_8018419D == 0) {
            temp_v0 = (D_8018419C * 2) + D_80184198;
            temp_v1 = M2C_FIELD(temp_v0, s8 *, 0);
            D_801269D4 = (s32) temp_v1;
            D_801269C8 = (s32) temp_v1;
            temp_v0_2 = M2C_FIELD(temp_v0, u8 *, 1);
            D_8018419C += 1;
            D_8018419D = temp_v0_2;
            if (temp_v0_2 == 0) {
                D_801269D4 = 0;
                D_801269C8 = 0;
                D_8018419C = 0;
                D_80184198 = 0;
            }
        } else {
            D_8018419D = (u8) (D_8018419D - 1);
        }
    }
}
