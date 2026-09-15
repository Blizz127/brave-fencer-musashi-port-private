/* Overlay range [80169BBC,80169E44) from MAIN.CD member 0012.
 * SHA256(span)=a8eddeee8598d8f9be6126b9375376a99b8b2dbf463e0a484074dd9d8c936c8e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048D9C(s32 (*)(), s32 (*)());                  /* extern */
void func_80048FBC(s32 (*)(), u16 *, u16 *);             /* extern */
void func_80049A1C(u16 *, s32 (*)(), u16);               /* extern */
s16 func_8004CFEC(s32, s32);                        /* extern */
void func_8004D504(s32 (*)(), s32 *, s32 *);             /* extern */
void *func_800D222C(void *, s32 (*)(), s32);            /* extern */
void func_800D2318();                                  /* extern */
extern s32 D_801813AC;
extern s32 D_8018141C;
extern s32 D_8018144C;
extern s32 D_80185B38;
void func_80128EA8(void *, void *, s32 (*)(), s32);        /* static */
void *func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */
void func_80146C3C(void *);                            /* static */
extern s32 D_801269A4;
extern s32 D_801269A8;
extern s32 D_801269AC;

void func_80169BBC(void *arg0) {
    ? sp40();
    s32 sp38;
    s32 sp34;
    s32 sp30;
    u16 sp2C;
    u16 sp2A;
    u16 sp28;
    u16 sp24;                                       /* compiler-managed */
    u16 sp22;
    u16 sp20;
    u16 temp_a2;
    u16 temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    func_800D2318();
    sp20 = arg0->unk12;
    sp24 = 0;
    sp22 = arg0->unk16;
    func_80049A1C(&sp20, sp40);
    sp2A = -2U;
    sp28 = 0;
    sp2C = -0x14U;
    func_80048FBC(sp40, &sp28, &sp28);
    arg0->unk6 = (u16) (arg0->unk6 + sp28);
    arg0->unkA = (u16) (arg0->unkA + sp2A);
    temp_v0 = arg0->unkE + sp2C;
    arg0->unkE = temp_v0;
    temp_v0_2 = func_80146A6C(9, arg0, (s16) arg0->unk6, (s16) arg0->unkA, (s32) (s16) temp_v0, 0, 0);
    if (temp_v0_2 != 0) {
        temp_v0_2->unk12 = sp20;
        temp_v0_2->unk16 = sp22;
        temp_v0_2->unk1A = sp24;
    }
    func_80146A6C(0xC, arg0, (s16) arg0->unk6, (s16) arg0->unkA, (s32) (s16) arg0->unkE, 0, 0);
    temp_v0_3 = func_800D222C(arg0, D_8018144C, 0x17);
    if (temp_v0_3 != 0) {
        arg0->unk20 = temp_v0_3;
        sp22 -= 0x400;
        temp_a2 = sp20 + *(D_801813AC + (arg0->unk30 * 2));
        sp20 = temp_a2;
        func_80049A1C(&sp20, sp40, temp_a2);
        sp30 = D_801269A4 - (s16) arg0->unk6;
        sp34 = D_801269A8 - (s16) arg0->unkA;
        sp38 = D_801269AC - (s16) arg0->unkE;
        func_8004D504(sp40, &sp30, &sp30);
        sp24 = -func_8004CFEC(sp30, sp34);
        sp28 = 0x400;
        sp2A = -0x400U;
        sp2C = 0;
        func_80049A1C(&sp28, sp40);
        temp_v0_3->unk34 = D_80185B38;
        func_80049A1C(&sp20, D_80185B38);
        func_80048D9C(D_80185B38, sp40);
        temp_v0_3->unk18 = 0x5000;
        temp_v0_3->unk1A = 0x2000;
        temp_v0_3->unk4 = (s32) (temp_v0_3->unk4 | 0x0C000140);
        func_80128EA8(temp_v0_3, arg0 + 0x24, D_8018141C, 0x0C000140);
        arg0->unk2 = (u16) (arg0->unk2 + 1);
        return;
    }
    func_80146C3C(arg0);
}
