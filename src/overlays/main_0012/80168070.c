/* Overlay range [80168070,801681FC) from MAIN.CD member 0012.
 * SHA256(span)=7723b8d3b07d0a4aa49bab3aac546e44adf4e57639fbd427650ed66995c3f86e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017E68(s16 *, s32);              /* extern */
void func_80048FBC(s32, s16 *, s16 *);           /* extern */
void func_80049A1C(s16 *, s32);              /* extern */
s16 func_8004CFEC(s32, s32);                        /* extern */
void func_8004D504(s32, s32 *, s32 *, s16);  /* extern */
void func_800D20C0(s16 *, s16 *, s32);       /* extern */
void func_800D23D0(s16 *);                       /* extern */
void func_80149350(s16 *, s16 *);                /* static */
extern s32 D_801269A4;
extern s32 D_801269A8;
extern s32 D_801269AC;

void func_80168070(void *arg0, void *arg1, void *arg2, s32 arg3) {
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;

    sp10 = (s16) ((s32) (M2C_FIELD(arg1, s16 *, 0) + M2C_FIELD(arg2, s16 *, 0)) >> 1);
    sp12 = (s16) ((s32) (M2C_FIELD(arg1, s16 *, 2) + M2C_FIELD(arg2, s16 *, 2)) >> 1);
    sp14 = (s16) ((s32) (M2C_FIELD(arg1, s16 *, 4) + M2C_FIELD(arg2, s16 *, 4)) >> 1);
    func_80149350(&sp10, &sp10);
    func_800D20C0(&sp10, &sp18, 8);
    func_80017E68(&sp10, arg3);
    sp18 = (u16) M2C_FIELD(arg2, s16 *, 0) - (u16) M2C_FIELD(arg1, s16 *, 0);
    sp1A = (u16) M2C_FIELD(arg2, s16 *, 2) - (u16) M2C_FIELD(arg1, s16 *, 2);
    sp1C = (u16) M2C_FIELD(arg2, s16 *, 4) - (u16) M2C_FIELD(arg1, s16 *, 4);
    func_80048FBC(M2C_FIELD(arg0, s32 *, 0x20) + 0x34, &sp18, &sp18);
    func_800D23D0(&sp18);
    func_80049A1C(&sp18, arg3);
    sp20 = D_801269A4 - sp10;
    sp24 = D_801269A8 - sp12;
    sp28 = D_801269AC - sp14;
    func_8004D504(arg3, &sp20, &sp20, sp12);
    sp1C = -func_8004CFEC(sp20, sp24);
    func_80049A1C(&sp18, arg3);
}
