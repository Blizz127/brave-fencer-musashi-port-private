/* Overlay range [8016B234,8016B3F4) from MAIN.CD member 0012.
 * SHA256(span)=cf151674d774dd1c077ac1ebf306094a8274a2a6ea36b8e6d5e09c543f54b038.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016ED4(u16 *);                             /* extern */
void func_8004914C(void *);                               /* extern */
void func_800491AC(void *);                               /* extern */
void func_8004955C(u16 *, s32 *, void *, s32 *);          /* extern */
extern s32 D_801814E4;
extern s32 *D_800AF648;

void func_8016B234(void *arg0) {
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    u8 sp50;
    s32 sp4C;
    u8 sp4A;
    u8 sp49;
    u8 sp48;
    s16 sp46;
    s16 sp44;
    s16 sp42;
    s16 sp40;
    s16 sp3E;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s16 sp32;
    u16 sp30;
    s16 sp2A;
    u16 sp28;
    s16 sp22;
    u16 sp20;
    s16 sp1C;
    s16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s16 temp_v0_2;
    s16 temp_v0_5;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s16 var_s2;
    s32 temp_v0_4;
    s32 var_v0;
    u16 temp_a0;
    u16 temp_v0;
    u16 temp_v0_6;
    u16 temp_v1;
    u16 var_s0;
    u8 temp_v0_3;

    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    sp10 = arg0->unk6;
    sp12 = arg0->unkA;
    sp14 = arg0->unkE;
    func_8004955C(&sp10, &sp58, &sp5C, &sp60);
    if (!(sp60 & ~0x1000)) {
        sp1C = 0x10;
        temp_v0 = arg0->unk2A + sp58;
        temp_v1 = temp_v0 + 8;
        sp28 = temp_v0;
        sp18 = temp_v0;
        sp30 = temp_v1;
        sp20 = temp_v1;
        temp_v0_2 = unksp5A - arg0->unk26;
        sp22 = temp_v0_2;
        sp1A = temp_v0_2;
        sp3E = 0x1D0;
        sp3A = 0x1D0;
        sp46 = 0x1D8;
        sp42 = 0x1D8;
        temp_v1_2 = unksp5A + arg0->unk26;
        sp32 = temp_v1_2;
        sp2A = temp_v1_2;
        temp_v0_3 = arg0->unk24;
        sp4A = temp_v0_3;
        sp49 = temp_v0_3;
        sp48 = temp_v0_3;
        sp50 = *(D_801814E4 + arg0->unk2C);
        if ((s16) arg0->unk26 < 5) {
            sp4C = 0;
        } else {
            sp4C = 0x50000000;
        }
        var_s0 = arg0->unk30;
        var_s2 = 0;
        if ((arg0->unk28 + 1) > 0) {
            var_v0 = var_s0 + 1;
            do {
                temp_v0_4 = (var_v0 & 0xF) * 8;
                temp_v1_4 = temp_v0_4 + 0x620;
                temp_v0_5 = temp_v0_4 + 0x628;
                sp40 = temp_v1_4;
                sp38 = temp_v1_4;
                sp44 = temp_v0_5;
                sp3C = temp_v0_5;
                func_80016ED4(&sp18);
                var_s0 = (u16) ((s32) (var_s0 << 0x10) >> 0x14);
                temp_v1_3 = var_s2 + 1;
                var_s2 = temp_v1_3;
                temp_a0 = sp18;
                temp_v0_6 = temp_a0 - 8;
                sp18 = temp_v0_6;
                sp28 = temp_v0_6;
                sp30 = temp_a0;
                sp20 = temp_a0;
                var_v0 = var_s0 + 1;
            } while (temp_v1_3 < (arg0->unk28 + 1));
        }
    }
}
