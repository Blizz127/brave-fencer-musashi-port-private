/* Overlay range [80173A60,80173B4C) from MAIN.CD member 0012.
 * SHA256(span)=8d0acb0792c2f5255c74cd871c31e3dca54f2c8928a255cf28c4b6afd89117e9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014C118(void *, s32, s16);                   /* static */
extern s32 func_80173B4C;
void func_80174684(s32 (*)());                           /* static */
extern s16 D_8011F9C8;
extern s16 D_80126938;
extern s32 D_80126B30;
extern s16 D_80126B38;
extern s16 D_80126B3A;
extern u16 D_80126B3C;
extern s32 D_80126B58;
extern s32 D_80127508;
extern s32 D_8012750C;

void func_80173A60(s16 arg0, s16 arg1, s32 arg2, s16 arg3, void *arg4) {
    if (arg2 != 0) {
        D_80127508 = func_8014C118(&D_80126B58, arg2, arg3);
    } else {
        D_80127508 = 0;
    }
    D_80126B30.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126B30.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126B38 = arg0;
    D_80126B3A = arg1;
    D_80126B3C = D_80126B58.unk20->unk12;
    func_80174684(func_80173B4C);
    D_8011F9C8 = 0;
    D_80126938 = 0;
    D_8012750C = 0;
}
