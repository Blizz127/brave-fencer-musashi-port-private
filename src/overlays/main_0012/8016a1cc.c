/* Overlay range [8016A1CC,8016A290) from MAIN.CD member 0012.
 * SHA256(span)=fa99808137f59e4aa6c7ac689a45f76a6a06b36781295965362d880a222c8ae2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146C3C(void *);                      /* static */
void func_80147324();                     /* static */
void func_80147364(s32, s32);            /* static */
extern u8 D_80078EBF;

void func_8016A1CC(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (D_80078EBF != 0) {
        temp_v0 = D_80078EBF - 0x18;
        M2C_FIELD(arg0, s32 *, 0x30) = temp_v0;
        if (temp_v0 >= 0) {
            temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1C) + 1;
            M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0_2;
            if (temp_v0_2 == 4) {
                func_80147324(0x44C);
            }
            if ((u8) D_80078EBF >= 0x80U) {
                if (M2C_FIELD(arg0, s16 *, 0x2A) == 0) {
                    M2C_FIELD(arg0, s16 *, 0x2A) = 1;
                    M2C_FIELD(arg0, s32 *, 0x1C) = 0x100;
                }
                if (!(M2C_FIELD(arg0, s32 *, 0x1C) & 0x1F)) {
                    func_80147324(0x44D);
                }
            }
        }
    } else {
        func_80147364(4, 0x44C);
        func_80146C3C(arg0);
    }
}
