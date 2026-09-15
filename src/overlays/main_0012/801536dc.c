/* Overlay range [801536DC,80153800) from MAIN.CD member 0012.
 * SHA256(span)=e39fd972c30329fa8225c30acbf61a9c69384342bf7161c5a6c7bb8a89ab2e0c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012C6C(s16, s16, s32);               /* extern */
s32 func_80013294(void *, void *);               /* extern */
void func_80015954(void *, void *);              /* extern */
void func_80015978(void *, void *);           /* extern */
extern s32 (*D_8011DB28)();

s32 func_801536DC(void *arg0) {
    s32 sp10;
    s32 var_v0;
    u8 temp_v0;
    void *temp_s1;
    void *temp_s2;

    if (D_8011DB28 != 0) {
        D_8011DB28(arg0 + 0xA0);
    }
    M2C_FIELD(arg0, s16 *, 6) = func_80012C6C(M2C_FIELD(arg0, s16 *, 6), M2C_FIELD(arg0, s16 *, 0xA0), 8);
    M2C_FIELD(arg0, s16 *, 0xA) = func_80012C6C(M2C_FIELD(arg0, s16 *, 0xA), M2C_FIELD(arg0, s16 *, 0xA2), 8);
    M2C_FIELD(arg0, s16 *, 0xE) = func_80012C6C(M2C_FIELD(arg0, s16 *, 0xE), M2C_FIELD(arg0, s16 *, 0xA4), 8);
    if (D_8011DB28 != 0) {
        temp_s2 = arg0 + 4;
        func_80015978(temp_s2, &sp10);
        temp_s1 = arg0 + 0xA0;
        if (func_80013294(&sp10, temp_s1) >= 0x40) {
            temp_v0 = M2C_FIELD(arg0, u8 *, 0xDE);
            if (temp_v0 == 0) {
                goto block_6;
            }
            M2C_FIELD(arg0, u8 *, 0xDE) = (u8) (temp_v0 - 1);
            goto block_8;
        }
block_6:
        func_80015954(temp_s1, temp_s2);
        return 0;
    }
block_8:
    var_v0 = 1;
    if ((M2C_FIELD(arg0, s16 *, 6) == M2C_FIELD(arg0, s16 *, 0xA0)) && (M2C_FIELD(arg0, s16 *, 0xA) == M2C_FIELD(arg0, s16 *, 0xA2))) {
        var_v0 = M2C_FIELD(arg0, s16 *, 0xE) != M2C_FIELD(arg0, s16 *, 0xA4);
    }
    return var_v0;
}
