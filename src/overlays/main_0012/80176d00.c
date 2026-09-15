/* Overlay range [80176D00,80176D94) from MAIN.CD member 0012.
 * SHA256(span)=9015ab0c7745c43f81ecd199a658c4649e4331c82c44fd6e2e68a9ddf6adbf0c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80178004(s32, s16, s16);                   /* static */
extern u16 D_80078EA6;
extern s32 *D_8011F7A8;
extern u8 D_8011F7B1;
extern u16 D_8011F7B4;
extern u16 D_8011F7B6;
extern u16 D_8011F81E;

void func_80176D00(s32 arg0) {
    s32 temp_a0;
    void *temp_s0;

    if (D_8011F7B1 == 0) {
        temp_s0 = ((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8;
        temp_a0 = M2C_FIELD(temp_s0, s32 *, 0x20) + 0x14;
        M2C_FIELD(temp_s0, s32 *, 0x38) = temp_a0;
        D_8011F81E = D_80078EA6;
        M2C_FIELD(temp_s0, s32 *, 0x40) = (s32) (func_80178004(temp_a0, (s16) (D_8011F7B4 - 0x17), (s16) (D_8011F7B6 + 0x65)) - 0x14);
    }
}
