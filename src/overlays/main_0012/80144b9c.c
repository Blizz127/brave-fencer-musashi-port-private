/* Overlay range [80144B9C,8014562C) from MAIN.CD member 0012.
 * SHA256(span)=d52744104daba2cc0a736a57e5b62cebac85c91b1b563e381db2356b33569e2c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80011E84(s32);                               /* extern */
void func_80015978(void *, void *, u16);                  /* extern */
void func_80018E78();                                  /* extern */
void func_80019018();                                  /* extern */
void func_8002850C(s16, s16, s16);                     /* extern */
void func_80028620(s32, s32 *);                          /* extern */
void func_8002AB64();                                  /* extern */
void func_800D02C0(s32);                               /* extern */
void func_80129398();                                  /* static */
void func_8012944C();                                  /* static */
void func_8012A1BC();                                  /* static */
void func_801336E8(s32, s32, s32);                     /* static */
void func_8013B568(s32);                               /* static */
void func_8013B83C(s32, s32, s32);                     /* static */
void func_8014562C();                                  /* static */
void *func_801457A4(s16);                           /* static */
extern s32 *D_80078E50;
extern s32 *D_80078E78;
extern s32 D_800A5E88;
extern s32 D_800A5E8C;
extern s32 D_800A5E90;
extern u8 D_800A5E94;
extern u8 D_800A5E95;
extern u8 D_800A5E96;
extern s32 D_800A5E98;
extern s32 D_800A5E9C;
extern s32 D_800A5EA0;
extern u8 D_800A5EA4;
extern u8 D_800A5EA5;
extern u8 D_800A5EA6;
extern s32 D_800A5EA8;
extern s32 D_800A5EAC;
extern s32 D_800A5EB0;
extern u8 D_800A5EB4;
extern u8 D_800A5EB5;
extern u8 D_800A5EB6;
extern s32 D_800AE6A8;
extern s32 D_800AF630;
extern u16 D_800B9AAC;
extern u16 D_800B9AB2;
extern u16 D_800B9AB6;
extern u8 D_800B9ABC;
extern u8 D_800B9ABD;
extern u8 D_800B9ABE;
extern u8 D_800B9ABF;
extern u8 D_800B9AC0;
extern u8 D_800B9AC1;
extern s32 D_800B9AC4;
extern s32 D_800B9AC8;
extern u16 D_800B9B00;
extern u16 D_800B9B06;
extern u16 D_800B9B0A;
extern u8 D_800B9B10;
extern u8 D_800B9B11;
extern u8 D_800B9B12;
extern u8 D_800B9B13;
extern u8 D_800B9B14;
extern u8 D_800B9B15;
extern s32 D_800B9B18;
extern s32 D_800B9B1C;
extern s32 *D_8010F5C8;
extern void *D_801151D4;
extern s32 *D_801151F0;
extern s32 D_8011DB08;
extern s32 D_8011DB14;
extern s32 D_8011DB1C;
extern s32 D_80126728;
extern s32 *D_80126948;
extern s32 D_80126AEC;
extern s32 *D_80126B58;
extern s32 *D_80126DB0;
extern u16 D_80126DB6;
extern s32 D_80128150;

void func_80144B9C(void) {
    s32 sp34;
    s16 sp2C;
    s32 sp28;
    void *sp24;
    void *sp20;
    void *sp1C;
    void *sp18;
    void *sp14;
    void *sp10;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a2_3;
    u16 temp_a2_4;
    u16 var_a2;

    sp10 = &D_80126B58;
    sp14 = &D_80078E78;
    sp18 = &D_800AE6A8;
    sp1C = &D_80126948;
    func_80019018();
    func_80018E78();
    if (D_800AE6A8.unk8 == 0) {
        sp20 = func_801457A4(D_800AF630.unkA3D8);
        sp18->unk16 = 0U;
        sp34 = 1;
        D_8011DB14 = (s32) sp14->unk3A;
        D_8011DB1C = (s32) sp14->unk3E;
        D_80128150 = 0x64;
        func_8002AB64();
    } else {
        sp20 = func_801457A4(D_800AF630.unkA3D8);
        sp34 = 0;
    }
    sp18->unk1C = (s32) sp20->unkC8;
    sp28 = sp20->unkC8;
    if (sp18->unk16 == 0xFF) {
        sp24 = &D_80078E50;
    } else {
        sp24 = *((sp18->unk16 * 4) + sp28);
    }
    sp18->unkC = (s32) sp24->unk8;
    sp18->unk14 = 0;
    sp10->unk4D = 0;
    if (sp24->unkC != &D_8010F5C8) {
        sp10->unk198 = (s32) sp24->unkC;
    }
    if ((D_800AF630.unkA3DA == 0x1000) && (D_800AF630.unkA3DC == 0x1000)) {
        temp_a2 = sp18->unk20;
        sp10->unk90 = temp_a2;
        sp10->unk88 = temp_a2;
        sp10->unk6 = temp_a2;
        temp_a2_2 = sp18->unk22;
        sp10->unk92 = temp_a2_2;
        sp10->unk8A = temp_a2_2;
        sp10->unkA = temp_a2_2;
        var_a2 = sp18->unk24;
        sp10->unk94 = var_a2;
        sp10->unk8C = var_a2;
        sp10->unkE = var_a2;
        sp10->unk20->unk12 = (u16) sp18->unk26;
        sp18->unk18 = 0;
    } else {
        temp_a2_3 = sp24->unk10;
        sp10->unk90 = temp_a2_3;
        sp10->unk88 = temp_a2_3;
        sp10->unk6 = temp_a2_3;
        temp_a2_4 = sp24->unk12;
        sp10->unk92 = temp_a2_4;
        sp10->unk8A = temp_a2_4;
        sp10->unkA = temp_a2_4;
        var_a2 = sp24->unk14;
        sp10->unk94 = var_a2;
        sp10->unk8C = var_a2;
        sp10->unkE = var_a2;
        sp10->unk20->unk12 = (u16) sp24->unk16;
    }
    temp_a1 = sp10->unk6;
    sp10->unk15C = temp_a1;
    sp10->unk154 = temp_a1;
    temp_a1_2 = sp10->unkA;
    sp10->unk15E = temp_a1_2;
    sp10->unk156 = temp_a1_2;
    temp_a1_3 = sp10->unkE;
    sp10->unk160 = temp_a1_3;
    sp10->unk158 = temp_a1_3;
    func_80015978(sp10 + 4, &D_80126DB0, var_a2);
    D_80126DB6 = sp10->unk20->unk12;
    if (D_800AF630.unkA3DA == 0x1000) {
        if ((D_800AF630.unkA3DC != 0x1000) && (D_800AF630.unkA3DC != 0x2000)) {
            goto block_18;
        }
        if (sp34 == 0) {
            sp24->unk18();
            func_8012A1BC();
        } else {
            goto block_18;
        }
    } else {
block_18:
        if ((D_800AF630.unkA3DA == 0x1000) && (D_800AF630.unkA3DC == 0x3000)) {
            sp1C->unkA0 = (u8) sp24->unk3;
        } else {
            sp1C->unkA0 = 0U;
        }
        sp24->unk18();
    }
    if (D_800AF630.unkA3D8 == 0x3069) {
        sp1C->unkA0 = (u8) sp24->unk3;
    }
    D_801151D4 = sp1C;
    func_8002850C(sp20->unk0, sp20->unk2, sp20->unk4);
    D_800A5E88 = (s32) sp20->unk6;
    D_800A5E8C = (s32) sp20->unk8;
    D_800A5E90 = (s32) sp20->unkA;
    D_800A5E94 = sp20->unkC;
    D_800A5E95 = sp20->unkD;
    D_800A5E96 = sp20->unkE;
    func_80028620(0, &D_800A5E88);
    D_800A5E98 = (s32) sp20->unk10;
    D_800A5E9C = (s32) sp20->unk12;
    D_800A5EA0 = (s32) sp20->unk14;
    D_800A5EA4 = sp20->unk16;
    D_800A5EA5 = sp20->unk17;
    D_800A5EA6 = sp20->unk18;
    func_80028620(1, &D_800A5E98);
    D_800A5EA8 = (s32) sp20->unk1A;
    D_800A5EAC = (s32) sp20->unk1C;
    D_800A5EB0 = (s32) sp20->unk1E;
    D_800A5EB4 = sp20->unk20;
    D_800A5EB5 = sp20->unk21;
    D_800A5EB6 = sp20->unk22;
    func_80028620(2, &D_800A5EA8);
    func_80129398();
    D_800B9AAC = sp20->unk24;
    D_800B9B00 = sp20->unk26;
    D_800B9AC4 = sp20->unk28;
    D_800B9B18 = sp20->unk2C;
    D_800B9AC8 = sp20->unk30;
    D_800B9B1C = sp20->unk34;
    D_800B9AB2 = sp20->unk38;
    D_800B9B06 = sp20->unk3A;
    D_800B9AB6 = sp20->unk3C;
    D_800B9B0A = sp20->unk3E;
    D_800B9ABC = sp20->unk40;
    D_800B9ABD = sp20->unk41;
    D_800B9ABE = sp20->unk42;
    D_800B9B10 = sp20->unk43;
    D_800B9B11 = sp20->unk44;
    D_800B9B12 = sp20->unk45;
    D_800B9ABF = sp20->unk46;
    D_800B9AC0 = sp20->unk47;
    D_800B9AC1 = sp20->unk48;
    D_800B9B13 = sp20->unk49;
    D_800B9B14 = sp20->unk4A;
    D_800B9B15 = sp20->unk4B;
    func_8012944C();
    sp10->unkB0 = (s32) sp20->unk4C;
    sp10->unkCC = (s32) sp20->unk50;
    sp10->unk1E8 = (s32) sp20->unk54;
    sp10->unk1F0 = (s32) sp20->unk58;
    D_80126728 = sp20->unk5C;
    D_8011DB08 = sp20->unk60;
    D_80126AEC = sp20->unk64;
    sp10->unk19C = (void *) (sp20 + 0x68);
    func_801336E8(sp20->unk88, sp20->unk8C, sp20->unk90);
    func_8013B83C(sp20->unk94, sp20->unk98, sp20->unk9C);
    func_8013B568(sp20->unkA8);
    func_800D02C0(sp20->unkD4);
    func_80011E84(sp20->unkD8);
    sp2C = 0;
loop_26:
    if (sp2C < 8) {
        *(&D_801151F0 + sp2C) = (sp2C + sp20)->unkAC;
        sp2C = (u16) sp2C + 1;
        goto loop_26;
    }
    func_8014562C();
}
