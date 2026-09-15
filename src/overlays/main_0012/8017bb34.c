/* Overlay range [8017BB34,8017BC38) from MAIN.CD member 0012.
 * SHA256(span)=69dc3b6b1522fd11b4bef4ceb5874543b0bb2f73163b7557e1db3b3ad797f01e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004914C(void *, s16);                          /* extern */
void func_800491AC(void *);                               /* extern */
void func_8004945C(s16 *, void *, void *);                   /* extern */
void func_80049CAC(s16 *, void *, s32 (*)());               /* extern */
extern s32 D_8018536C;
extern s32 D_80185374;

void func_8017BB34(void *arg1) {
    s32 sp50;
    s32 sp48;
    s32 sp47;
    s32 sp43;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp18;
    s16 sp14;
    u16 sp12;
    s16 sp10;

    sp43 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp47 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_8018536C.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_8018536C.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp10 = -(s16) arg1->unkC;
    sp14 = 0;
    sp38 = 0;
    sp3A = 0;
    sp12 = arg1->unk8;
    sp3C = -(s16) arg1->unkA;
    func_80049CAC(&sp10, &sp18, D_8018536C);
    sp2C = (s32) sp40;
    sp30 = (s32) (s16) sp42;
    sp34 = (s32) sp44;
    func_8004914C(&sp18, sp44);
    func_800491AC(&sp18);
    func_8004945C(&sp38, &sp48, &sp50);
    D_80185374.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80185374.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
}
