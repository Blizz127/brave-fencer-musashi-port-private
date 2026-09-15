/* Overlay range [80144090,801442F8) from MAIN.CD member 0012.
 * SHA256(span)=3ceaf924bdc07e13c227b275c40bfb05a4a657c45c024fefc4f5f77468c7b688.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80010A08();                               /* extern */
s32 func_8004787C(s32);                             /* extern */
s32 func_80047948(s32);                             /* extern */
void func_8004914C(void *, s32);                          /* extern */
void func_800491AC(void *);                               /* extern */
s32 func_8004955C(u16 *, u16 *, void *, void *);          /* extern */
void func_80058C6C(s32, s32, s32, s32);                /* extern */
extern s32 *D_800A651C;
extern s32 *D_800AF648;
extern u16 D_800B9A02;

void func_80144090(void *arg0) {
    s32 sp20;
    s32 sp1C;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_lo;
    s32 temp_s0;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    void *var_s1;

    var_s4 = func_80010A08(0x140);
    if (var_s4 != 0) {
        temp_a1 = arg0->unk14;
        arg0->unk4 = (s32) (arg0->unk4 + arg0->unk10);
        arg0->unk8 = (s32) (arg0->unk8 + temp_a1);
        arg0->unkC = (s32) (arg0->unkC + arg0->unk18);
        sp10 = arg0->unk6;
        sp12 = arg0->unkA;
        sp14 = arg0->unkE;
        func_8004914C(&D_800AF648, temp_a1);
        func_800491AC(&D_800AF648);
        var_s5 = func_8004955C(&sp10, &sp18, &sp1C, &sp20) + 4;
        var_s3 = 0;
        if (var_s5 < 0) {
            var_s5 = 0;
        }
        var_s1 = var_s4 + 0xE;
        do {
            var_s1->unk-A = 0xFFFFFF;
            var_s1->unk-B = 4;
            var_s1->unk-7 = 0x20;
            if ((arg0->unk1C - 6) <= 0) {
                var_s1->unk-6 = sp18;
                var_s1->unk-4 = sp1A;
            } else {
                var_s1->unk-6 = (u16) (sp18 + ((s32) (func_8004787C(var_s3) * ((arg0->unk1C - 6) * 0x10)) >> 0xC));
                var_s1->unk-4 = (u16) (sp1A + ((s32) (func_80047948(var_s3) * ((arg0->unk1C - 6) * 0x10)) >> 0xC));
            }
            temp_s0 = func_8004787C(var_s3) * (arg0->unk1C * 0x10);
            temp_lo = func_80047948(var_s3) * (arg0->unk1C * 0x10);
            var_s3 += 0x100;
            temp_a1_2 = var_s4;
            var_s4 += 0x14;
            temp_a2 = temp_s0 >> 6;
            temp_a3 = temp_lo >> 6;
            var_s1->unk2 = (s16) (sp18 + ((s32) (temp_s0 + temp_a3) >> 0xC));
            var_s1->unk4 = (s16) (sp1A + ((s32) (temp_lo + temp_a2) >> 0xC));
            var_s1->unk-2 = (s16) (sp18 + ((s32) (temp_s0 - temp_a3) >> 0xC));
            var_s1->unk0 = (s16) (sp1A + ((s32) (temp_lo - temp_a2) >> 0xC));
            var_s1 += 0x14;
            func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + (var_s5 * 4), temp_a1_2, temp_a2, temp_a3);
        } while (var_s3 < 0x1000);
    }
}
