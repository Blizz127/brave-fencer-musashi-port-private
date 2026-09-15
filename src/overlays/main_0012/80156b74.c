/* Overlay range [80156B74,80156ECC) from MAIN.CD member 0012.
 * SHA256(span)=b089bbd6e907161a46a1af5aecb48ee8cec36f1f16def25d19973291ee00269d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800139C8(s16, u16 *, u16 *);                 /* extern */
void func_801484B0(u16 *, void *);                        /* static */
void func_801484E8(u16 *, void *, u16);                   /* static */
void func_80148534(u16 *, void *);                        /* static */
void func_8014856C(u16 *, void *, u16);                   /* static */
void func_80156ECC(void *, s16 *, u16 *, u16 *, u16 *); /* static */
extern u16 D_80126AF0;
extern u16 D_80126AF2;
extern u16 D_80126AF4;
extern u16 D_80126AF8;
extern u16 D_80126AFA;
extern u16 D_80126AFC;
extern s16 D_801270A8;
extern s16 D_801270AA;
extern s16 D_801270AC;

void func_80156B74(void *arg0, s32 arg1, u8 *arg2) {
    s32 sp20;
    u16 sp18;
    s32 temp_a0;
    void *temp_v1;

    temp_v1 = arg0->unk20;
    D_801270A8 = 0;
    D_801270AA = -0x1E;
    D_801270AC = 0;
    if (arg1 == 0) {
        if (temp_v1->unk20 != 0) {
            func_801484B0(&sp18, &sp20);
            D_80126AF0 = sp18;
            D_80126AF2 = sp1A;
            D_80126AF4 = sp1C;
            func_801484E8(&sp18, &sp20, sp1C);
            D_80126AF8 = sp18;
            D_80126AFA = sp1A;
            D_80126AFC = sp1C;
        } else {
            goto block_6;
        }
    } else if (arg1 == 1) {
        if (temp_v1->unk20 != 0) {
            func_80148534(&sp18, &sp20);
            D_80126AF0 = sp18;
            D_80126AF2 = sp1A;
            D_80126AF4 = sp1C;
            func_8014856C(&sp18, &sp20, sp1C);
            D_80126AF8 = sp1A;
            D_80126AFA = sp1A;
            D_80126AFC = sp1C;
        } else {
block_6:
            D_80126AF0 = 0;
            D_80126AF2 = 0;
            D_80126AF4 = 0;
            D_80126AF8 = 0;
            D_80126AFA = 0;
            D_80126AFC = 0;
        }
    } else if (arg1 == 2) {
        D_80126AF0 = 0;
        D_80126AF2 = -0x1EU;
        D_80126AF4 = -0x52U;
        func_800139C8((s16) (arg0->unk24A - arg0->unk20->unk12), &D_80126AF0, &D_80126AF0);
        D_80126AF8 = 0;
        D_80126AFA = -0x1EU;
        D_80126AFC = -0x52U;
    } else {
        temp_a0 = arg1 & 0x80FFFFFF;
        D_80126AF0 = (u16) (s8) *((*arg2 * 3) + temp_a0);
        D_80126AF2 = (u16) (s8) ((*arg2 * 3) + temp_a0)->unk1;
        D_80126AF4 = (u16) (s8) ((*arg2 * 3) + temp_a0)->unk2;
        D_80126AF8 = (u16) (s8) ((*arg2 * 3) + temp_a0)->unk3;
        D_80126AFA = (u16) (s8) ((*arg2 * 3) + temp_a0)->unk4;
        D_80126AFC = (u16) (s8) ((*arg2 * 3) + temp_a0)->unk5;
    }
    if (!(arg1 & 0x0F000000)) {
        *arg2 += 1;
    }
    func_80156ECC(arg0, &D_801270A8, &D_80126AF0, &D_80126AF0 + 8, &D_80126AF0 + 0x10);
}
