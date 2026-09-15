/* Overlay range [801387B8,80138948) from MAIN.CD member 0012.
 * SHA256(span)=07658098e7355610b39f162ebce66a1227a6b5a0420491773e24fae7136c1bb0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80138948(void *, u8, u8);              /* static */
s32 func_80138DE0(void *, u8, u8);                  /* static */
void func_80139220(void *, u8, u8);              /* static */
void func_80139A8C(void *);                      /* static */
void func_80139B18(void *);                      /* static */
extern s32 *D_80127530;

void func_801387B8(void *arg0) {
    s32 temp_v1;
    s32 var_s2;
    s32 var_v1;
    u16 *var_s1;
    u16 var_v0;
    u8 temp_a1;
    u8 temp_a2;
    void *temp_v0;

    do {
        var_s2 = 0;
        if (M2C_FIELD(arg0, s32 *, 8) & 0x400) {
            var_v1 = *(&D_80127530 + (M2C_FIELD(arg0, u16 *, 0x4A) * 4));
            var_s1 = arg0 + 0x44;
        } else {
            var_s1 = arg0 + 0x10;
            var_v1 = M2C_FIELD(arg0, s32 *, 0);
        }
        temp_v0 = var_v1 + *var_s1;
        temp_a1 = M2C_FIELD(temp_v0, u8 *, 0);
        temp_a2 = M2C_FIELD(temp_v0, u8 *, 1);
        if (temp_a1 >= 0x20U) {
            var_s2 = func_80138DE0(arg0, temp_a1, temp_a2);
            if (!(M2C_FIELD(arg0, s32 *, 8) & 0x80220)) {
                var_s2 = 0;
            }
        } else if (temp_a1 != 0) {
            if (temp_a1 != 7) {
                if ((s32) temp_a1 < 8) {
                    var_s2 = 1;
                    if (temp_a1 != 1) {
                        goto block_20;
                    }
                    M2C_FIELD(arg0, u8 *, 0x23) = temp_a2;
                    *var_s1 += 2;
                } else {
                    switch (temp_a1) {              /* irregular */
                    case 10:
                        func_80139220(arg0, temp_a1, temp_a2);
                        var_v0 = *var_s1 + 1;
                        break;
                    case 23:
                        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 2);
block_20:
                        var_s2 = 1;
                        var_v0 = *var_s1 + 1;
                        break;
                    }
                    *var_s1 = var_v0;
                }
            } else {
                temp_v1 = M2C_FIELD(arg0, s32 *, 8);
                if (!(temp_v1 & 0x20000)) {
                    M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_v1 & ~0x20);
                }
                goto block_22;
            }
        } else {
block_22:
            func_80138948(arg0, temp_a1, temp_a2);
        }
    } while (var_s2 != 0);
    func_80139A8C(arg0);
    func_80139B18(arg0);
}
