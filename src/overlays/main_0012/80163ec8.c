/* Overlay range [80163EC8,80164270) from MAIN.CD member 0012.
 * SHA256(span)=7624327224e0eb5db018533dc14a9164832237da9126a6b359288025c192718e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012F74(s16, s16, s32, s32);                  /* extern */
void func_80015978(void *, void *);                       /* extern */
extern s32 D_80183944;
void func_80146994(s32, void *, s32, void *);              /* static */
void func_80146CA0(void *);                            /* static */
void func_80146E90(void *, s32);                         /* static */
void func_80147324();                                 /* static */
s32 func_80148800(void *);                          /* static */
void func_80149350(void *, void *, u16 *);                /* static */
void func_8014AD30(void *, void *, s32, s16);               /* static */
void func_8014C4AC(void *, s32, s32, void *, s32);          /* static */
s32 func_8014CA00(void *);                          /* static */
s32 func_80156370();                               /* static */
void func_80162D88(void *, s32 (*)());                   /* static */
s32 func_801656D0(void *, s32);                     /* static */
extern u16 D_800B99DA;

void func_80163EC8(void *arg0) {
    s16 sp2E;
    s32 sp28;
    u16 sp20;
    s32 sp1F;
    s32 sp1B;
    s32 sp18;
    s16 temp_v0_2;
    s16 temp_v0_4;
    u8 temp_a0;
    void *temp_s1;
    void *temp_s3;
    void *temp_s3_2;
    void *temp_s4;
    void *temp_v0;
    void *temp_v0_3;

    sp1B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp1F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    temp_s1 = arg0->unk4C;
    temp_s4 = arg0->unk20;
    func_80162D88(arg0, D_80183944);
    temp_v0 = temp_s1->unk184;
    if (temp_v0 == 0) {
        goto block_4;
    }
    if (temp_v0->unk36 != temp_s1->unk194) {
        temp_s1->unk184 = 0;
block_4:
        temp_s1->unk18A = 0U;
        temp_s1->unk188 = 0;
        temp_s1->unk44 = (s32) (temp_s1->unk44 & ~0x20);
        func_80146CA0(arg0);
        func_80146CA0(arg0);
        return;
    }
    temp_s1->unk18A = (u16) (temp_s1->unk18A + 1);
    if (!(D_800B99DA & 3)) {
        temp_v0_2 = temp_s1->unk188;
        temp_a0 = arg0->unk67;
        if (temp_v0_2 >= (s32) temp_a0) {
            temp_s1->unk188 = (s16) (temp_v0_2 - temp_a0);
        } else {
            temp_s1->unk188 = 0;
        }
        if (temp_s1->unk188 < 0) {
            temp_s1->unk188 = 0;
        }
    }
    arg0->unk66 = (u16) (arg0->unk66 + 0x40);
    if (func_80148800(temp_s1) & 0x80) {
        arg0->unk66 = 0U;
        temp_s1->unk188 = (s16) ((u16) temp_s1->unk188 + (func_801656D0(temp_s1, func_8014CA00(temp_s1->unk184) & 0xFF) & 0xFF));
        temp_s4->unk1A = 0x4000;
        temp_s4->unk18 = 0x4000;
        temp_s4->unk48 = (s32) arg0->unk58;
        temp_s4->unk4C = (s32) arg0->unk5A;
        temp_s4->unk50 = (s32) arg0->unk5C;
        func_80149350(arg0, &sp18, &sp20);
        arg0->unk6 = sp20;
        arg0->unkA = sp22;
        arg0->unkE = sp24;
    }
    if (temp_s1->unk188 >= 0x81) {
        temp_s1->unk188 = 0x80;
    }
    if (temp_s1->unk188 >= 0x80) {
        temp_s3 = temp_s1->unk184;
        if (temp_s3 != 0) {
            func_80015978(temp_s3 + 4, &sp28);
            sp2E = 0;
            func_8014C4AC(temp_s3, 0xE, func_80156370(0xE) & 0xFFFF, &sp28, (s32) temp_s4->unk12);
            func_80146994(0x33, arg0, 0, temp_s3);
        }
        goto block_23;
    }
    if (((s16) temp_s1->unk18A >= 0x80) || (temp_s1->unk0 == 0x19)) {
        temp_s3_2 = temp_s1->unk184;
        if (temp_s3_2 != 0) {
            func_80015978(temp_s3_2 + 4, &sp28);
            sp2E = 0;
            func_8014C4AC(temp_s3_2, 0x21, func_80156370(0x21) & 0xFFFF, &sp28, (s32) temp_s4->unk12);
            if (temp_s3_2->unkB4 & 0x40000) {
                func_8014AD30(arg0, &sp28, 0, temp_s3_2->unk60);
            }
        }
block_23:
        temp_v0_3 = func_8014CA00(temp_s1->unk184);
        temp_s1->unk184 = temp_v0_3;
        if ((u32) temp_v0_3 >= 0x1FU) {
            temp_s1->unk184 = 0;
        }
        func_80146E90(arg0, 0x20);
        temp_s1->unk44 = (s32) (temp_s1->unk44 & ~0x20);
        func_80147324(0x449);
        func_80146CA0(arg0);
        func_80146CA0(arg0);
    }
    temp_v0_4 = func_80012F74(temp_s4->unk1A, 0x1800, 3, 1);
    temp_s4->unk1A = temp_v0_4;
    temp_s4->unk18 = temp_v0_4;
    arg0->unk6 = func_80012F74((s16) arg0->unk6, arg0->unk58, 8, 1);
    arg0->unkA = func_80012F74((s16) arg0->unkA, arg0->unk5A, 8, 1);
    arg0->unkE = func_80012F74((s16) arg0->unkE, arg0->unk5C, 8, 1);
}
