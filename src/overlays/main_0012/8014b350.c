/* Overlay range [8014B350,8014B4C4) from MAIN.CD member 0012.
 * SHA256(span)=b8aec7402cdbd79c92f3eac17899cda4b55cb7e86143ba4ef3b5f862c4ab6a58.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80019064(void *);                   /* extern */
void func_8014AD30(void *, u16 *, s32, s32); /* static */
void func_8014BC80(void *, s32);             /* static */
s32 func_8016F1C4();                                /* static */
extern s32 *D_80062BF4;
extern s32 *D_80078E78;
extern s32 D_80078E94;
extern s16 D_80078E96;

void func_8014B350(void *arg0) {
    u16 sp14;
    s16 sp12;
    u16 sp10;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_v1;

    if (func_8016F1C4() == 0) {
        temp_v1 = M2C_FIELD(arg0, u16 *, 0);
        if ((temp_v1 != 0x1E) && (temp_v1 != 0x1A)) {
            if (D_80078E96 & 0x8000) {
                if (M2C_FIELD(arg0, s32 *, 0x44) & 0x80) {
                    var_v0 = D_80078E94 + 0xAAA8;
                } else {
                    var_v0 = D_80078E94 + 0x1555;
                }
                D_80078E94 = var_v0;
                if ((M2C_FIELD(&D_80078E78, u16 *, 0x1E) & 0x7FFF) >= 0x3D) {
                    M2C_FIELD(&D_80078E78, s32 *, 0x1C) = 0x80000000;
                    func_8014BC80(arg0, 8);
                    sp10 = M2C_FIELD(arg0, u16 *, 6);
                    sp12 = M2C_FIELD(arg0, u16 *, 0xA) - 0x20;
                    sp14 = M2C_FIELD(arg0, u16 *, 0xE);
                    func_8014AD30(arg0, &sp10, 6, 0);
                    func_80019064(&D_80062BF4);
                }
            }
            if (M2C_FIELD(&D_80078E78, s16 *, 0x56) & 0x8000) {
                if (M2C_FIELD(arg0, s32 *, 0x44) & 0x80) {
                    var_v0_2 = M2C_FIELD(&D_80078E78, s32 *, 0x54) + 0xAAA8;
                } else {
                    var_v0_2 = M2C_FIELD(&D_80078E78, s32 *, 0x54) + 0x1555;
                }
                M2C_FIELD(&D_80078E78, s32 *, 0x54) = var_v0_2;
                if (((u16) M2C_FIELD(&D_80078E78, s16 *, 0x56) & 0x7FFF) >= 0x3D) {
                    M2C_FIELD(&D_80078E78, s32 *, 0x54) = 0x80000000;
                }
            }
        }
    }
}
