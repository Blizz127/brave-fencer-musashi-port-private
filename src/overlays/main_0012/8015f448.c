/* Overlay range [8015F448,8015F738) from MAIN.CD member 0012.
 * SHA256(span)=18659b2cb17ca768e19fa36b366b0b5c8da8f1d84b3b2796e6ba88daa2fadd6b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80019064(void *);                               /* extern */
extern s32 D_80180A1C;
extern s32 D_80180D28;
extern s32 D_80180D38;
extern s32 D_80180D48;
void func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */
void func_80146DB8(void *, s32 (*)());                   /* static */
void func_80146E90(void *, s32);                         /* static */
void func_80147324();                                 /* static */
void func_801473EC(void *);                            /* static */
void func_801477E8(void *, s32);                         /* static */
void func_80147A84(void *, u16);                       /* static */
void func_801484B0(void *, void *);                          /* static */
void func_80148534(void *, void *);                          /* static */
s32 func_80148800(void *);                          /* static */
s32 func_80148980(void *);                          /* static */
s32 func_801496D4(void *);                          /* static */
void func_80149724(void *);                            /* static */
s32 func_80149884();                                /* static */
void func_8014ED28(void *);                            /* static */
s32 func_8014F1F4(void *);                          /* static */
void func_8014FA04(void *);                            /* static */
s32 func_8014FCFC(void *);                          /* static */
void func_801725B8(void *);                            /* static */
extern s32 *D_80062BD0;

void func_8015F448(void *arg0) {
    s32 sp28;
    s32 sp20;
    s32 var_a0;
    u16 temp_a1;
    u16 temp_v1;

    if (((arg0->unk44 & 0x100) && (func_80149884() != 0)) || (func_801496D4(arg0) != 0)) {
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        arg0->unk1BE = 0xA;
        func_80149724(arg0);
        func_801477E8(arg0, 0);
        return;
    }
    if (arg0->unk245 == 0) {
        if (arg0->unk244 == 0) {
            if (func_80148800(arg0) & 0x10) {
                arg0->unk244 = 1U;
                goto block_10;
            }
        } else if (func_80148800(arg0) & 0x80) {
            arg0->unk244 = 0U;
block_10:
            arg0->unk245 = 1U;
        }
    }
    temp_v1 = arg0->unkB8;
    if (temp_v1 & 0x3000) {
        if (temp_v1 & 0x2000) {
            func_801484B0(&sp20, &sp28);
            var_a0 = 0x56D;
        } else {
            func_80148534(&sp20, &sp28);
            var_a0 = 0x56E;
        }
        func_80147324(var_a0);
        func_80019064(&D_80062BD0);
        func_80146A6C(0x25, arg0, arg0->unk6, (s16) (arg0->unkA - 0x14), (s32) arg0->unkE, 0, 0);
        func_80146A6C(0x25, arg0, arg0->unk6, (s16) (arg0->unkA - 0x14), (s32) arg0->unkE, 1, 0);
    }
    if (arg0->unkB8 & 0x8000) {
        if (arg0->unk245 != 0) {
            arg0->unk245 = 0U;
            arg0->unkB8 = (u16) arg0->unkBA;
            if (func_80148980(arg0) != 0) {
                func_80146DB8(arg0, D_80180D28);
            } else {
                func_80146DB8(arg0, D_80180D38);
            }
        }
    } else {
        temp_a1 = (u16) arg0->unkE;
        arg0->unk246 = (u16) arg0->unk6;
        arg0->unk248 = (u16) arg0->unkA;
        arg0->unk24A = temp_a1;
        func_80147A84(arg0, temp_a1);
        func_801473EC(arg0);
        if (func_8014F1F4(arg0) != 0) {
            arg0->unk6 = (s16) arg0->unk246;
            arg0->unkA = (u16) arg0->unk248;
            arg0->unkE = (s16) arg0->unk24A;
        }
    }
    if (func_8014FCFC(arg0) == 0) {
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        arg0->unk1BE = 0xA;
        func_80149724(arg0);
        func_801477E8(arg0, 0xFFE80000);
        func_80146DB8(arg0, D_80180D48);
        func_80146E90(arg0, 0x10);
        return;
    }
    func_8014ED28(arg0);
    func_8014FA04(arg0);
    func_801725B8(arg0);
}
