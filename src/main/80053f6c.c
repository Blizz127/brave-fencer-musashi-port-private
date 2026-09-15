/* Exact retail word export for [80053F6C,80054340); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80047D3C(s32, s32);                        /* static */
void func_800484EC(s32 *, s32 *, s32 *);               /* static */
void func_80048D9C(s32 *, void *);                        /* static */
void func_8004974C(void *, s32 *);                        /* static */
void func_80052FCC(s32 *, s32 *);                      /* static */
void func_80053B20(s32 *, s32);                        /* static */
void func_80053E28(void *, s16, s16, s32);                  /* static */
void func_80054340(void *, s32 *);                     /* static */
void func_80054514(s32, void *);                          /* static */
extern s32 D_800A5EB8;
extern s32 D_800AE688;
extern s32 D_800AE7F0;

s32 func_80053F6C(void *arg0) {
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp50;
    s32 sp44;
    s32 sp30;
    s32 sp10;
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 var_v0;

    D_800AE688.unk0 = D_800AE7F0.unk0;
    D_800AE688.unk4 = (s32) D_800AE7F0.unk4;
    D_800AE688.unk8 = (s32) D_800AE7F0.unk8;
    D_800AE688.unkC = (s32) D_800AE7F0.unkC;
    D_800AE688.unk10 = (s32) D_800AE7F0.unk10;
    D_800AE688.unk14 = (s32) D_800AE7F0.unk14;
    D_800AE688.unk18 = (s32) D_800AE7F0.unk18;
    D_800AE688.unk1C = (s32) D_800AE7F0.unk1C;
    func_80053B20(&D_800AE688, -arg0->unk18);
    func_80054340(arg0, &sp10);
    temp_v0 = sp1C - sp10;
    temp_lo = temp_v0 * temp_v0;
    temp_v0_2 = sp20 - sp14;
    temp_v0_3 = sp24 - sp18;
    temp_v0_4 = func_80047D3C(temp_lo + (temp_v0_2 * temp_v0_2) + (temp_v0_3 * temp_v0_3), temp_lo);
    var_v0 = 1;
    if (temp_v0_4 != 0) {
        temp_v0_5 = sp1C - sp10;
        temp_v0_6 = sp24 - sp18;
        temp_v0_7 = func_80047D3C((temp_v0_5 * temp_v0_5) + (temp_v0_6 * temp_v0_6));
        func_80053E28(&sp30, (s16) (((s32) ((sp14 - sp20) << 0xC) / temp_v0_4) * -1), (s16) ((s32) (temp_v0_7 << 0xC) / temp_v0_4), 0x78);
        func_80048D9C(&D_800AE688, &sp30);
        if (temp_v0_7 != 0) {
            func_80053E28(&sp30, (s16) (((s32) ((sp1C - sp10) << 0xC) / temp_v0_7) * -1), (s16) ((s32) ((sp24 - sp18) << 0xC) / temp_v0_7), 0x79);
            func_80048D9C(&D_800AE688, &sp30);
        }
        sp90 = -arg0->unk0;
        sp94 = -arg0->unk4;
        sp98 = -arg0->unk8;
        func_800484EC(&D_800AE688, &sp90, &D_800AE688 + 0x14);
        temp_a0 = arg0->unk1C;
        if (temp_a0 != 0) {
            func_80054514(temp_a0, &sp30);
            func_8004974C(&sp30, &sp50);
            func_800484EC(&sp50, &sp44, &sp90);
            sp64 = -sp90;
            sp6C = -sp98;
            sp68 = -sp94;
            func_80052FCC(&D_800AE688, &sp50);
            D_800AE688.unk0 = sp50;
            D_800AE688.unk4 = sp54;
            D_800AE688.unk8 = sp58;
            D_800AE688.unkC = sp5C;
            D_800AE688.unk10 = sp60;
            D_800AE688.unk14 = sp64;
            D_800AE688.unk18 = sp68;
            D_800AE688.unk1C = sp6C;
        }
        D_800A5EB8.unk0 = (s32) D_800AE688.unk0;
        D_800A5EB8.unk4 = (s32) D_800AE688.unk4;
        D_800A5EB8.unk8 = (s32) D_800AE688.unk8;
        D_800A5EB8.unkC = (s32) D_800AE688.unkC;
        D_800A5EB8.unk10 = (s32) D_800AE688.unk10;
        D_800A5EB8.unk14 = (s32) D_800AE688.unk14;
        D_800A5EB8.unk18 = (s32) D_800AE688.unk18;
        D_800A5EB8.unk1C = (s32) D_800AE688.unk1C;
        var_v0 = 0;
    }
    return var_v0;
}
