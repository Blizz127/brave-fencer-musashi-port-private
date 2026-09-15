/* Overlay range [8016432C,80164410) from MAIN.CD member 0012.
 * SHA256(span)=f752f5e3310488bc1492e335e1540d2be2769582817728437aa09713105cbae3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80146E98(void *);                          /* static */
void func_80147324();                     /* static */
void func_80147364(s32, s32);            /* static */
void func_801553C0(void *);                      /* static */
void func_80162CCC(void *);                      /* static */
void func_80164418();                            /* static */

void func_8016432C(void *arg0) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x4C);
    func_80164418();
    if (func_80146E98(arg0) != 0) {
        M2C_FIELD(temp_s0, s16 *, 0x18A) = 0;
        if ((M2C_FIELD(temp_s0, s32 *, 0x184) != 0) && (temp_a0 = M2C_FIELD(temp_s0, s32 *, 0x44), ((temp_a0 & 0x400) == 0)) && !(M2C_FIELD(temp_s0, s32 *, 0x1F8) & 0x80FFFFFF)) {
            M2C_FIELD(temp_s0, s32 *, 0x44) = (s32) (temp_a0 | 0x10);
            if (M2C_FIELD(temp_s0, s16 *, 0x188) < 0x80) {
                M2C_FIELD(temp_s0, s32 *, 0x184) = (s32) (M2C_FIELD(temp_s0, s32 *, 0x184) | 0x80000000);
            }
        } else {
            M2C_FIELD(temp_s0, s32 *, 0x184) = 0;
        }
        M2C_FIELD(temp_s0, s16 *, 0x188) = 0;
        M2C_FIELD(temp_s0, s32 *, 0x44) = (s32) (M2C_FIELD(temp_s0, s32 *, 0x44) & ~4);
        func_801553C0(temp_s0);
        func_80147364(4, 0x449);
        func_80147324(0x44B);
        func_80162CCC(arg0);
    }
}
