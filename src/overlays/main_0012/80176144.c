/* Overlay range [80176144,80176218) from MAIN.CD member 0012.
 * SHA256(span)=dca61a9505bbde362796fc44ada9c5364319b34d8cc644480e6675c2416f99a3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80178004(s32, s16, s16);                   /* static */
extern s32 *D_800AF634;
extern s32 *D_800AF638;
extern s32 *D_8011F7A8;
extern u16 D_8011F7BC;
extern u16 D_8011F7BE;

void func_80176144(s16 arg0) {
    s32 temp_a0;
    s32 temp_s1;
    s32 temp_v0;
    void *temp_s0;

    temp_s1 = arg0 * 0xC;
    temp_a0 = *(&D_800AF638 + temp_s1) + (*(&D_800AF634 + temp_s1) * 4);
    temp_s0 = (arg0 * 4) + &D_8011F7A8;
    temp_s0->unk38 = temp_a0;
    temp_v0 = func_80178004(temp_a0, (s16) (D_8011F7BC - 0x17), (s16) (D_8011F7BE + 0x65));
    temp_s0->unk40 = (s32) (temp_v0 - 0x14);
    *(&D_800AF634 + temp_s1) = *(&D_800AF634 + temp_s1) + ((s32) ((temp_v0 + 0x14) - temp_s0->unk38) >> 2);
}
