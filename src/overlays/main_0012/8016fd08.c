/* Overlay range [8016FD08,8016FD7C) from MAIN.CD member 0012.
 * SHA256(span)=c87451266b7139822463fe5129d859ba065ad57ea55c3751a9ff81c928b7dd38.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146D90(void *);                      /* static */
void func_80171990(void *);                      /* static */
s32 func_80172658();                                /* static */
extern s32 D_8011F738;

void func_8016FD08(void *arg0) {
    s32 temp_v0;

    if (func_80172658() != 0) {
        func_80146D90(arg0);
        M2C_FIELD(arg0, u16 *, 0xAA) = (u16) (M2C_FIELD(arg0, u16 *, 0xAA) | 0x40);
        M2C_FIELD(arg0, u16 *, 0xAC) = (u16) (M2C_FIELD(arg0, u16 *, 0xAC) | 0x40);
        temp_v0 = D_8011F738 - 1;
        D_8011F738 = temp_v0;
        if (temp_v0 == 0) {
            func_80171990(arg0);
        }
    }
}
