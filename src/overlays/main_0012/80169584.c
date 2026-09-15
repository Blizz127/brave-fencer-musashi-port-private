/* Overlay range [80169584,801696D8) from MAIN.CD member 0012.
 * SHA256(span)=d9d05f10b5bbc02b6d878afeb125ccdf78598e26e88fc23530a8e9ddc38d105e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017758(s16 *, void *, s16, void *);        /* extern */

void func_80169584(void *arg0) {
    s32 sp40;
    s8 sp3E;
    s8 sp3D;
    s8 sp3C;
    s8 sp3A;
    s8 sp39;
    s8 sp38;
    s8 sp36;
    s8 sp35;
    s8 sp34;
    s8 sp32;
    s8 sp31;
    s8 sp30;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp24;
    s16 sp22;
    s16 sp20;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s16 temp_a2;
    s8 temp_v1;
    s8 temp_v1_2;
    u32 var_v0;
    void *temp_s0;

    sp10 = 7;
    sp28 = -7;
    sp1A = 2;
    sp20 = 0;
    sp18 = 0;
    sp2A = 0;
    sp12 = 0;
    sp22 = -2;
    sp2C = 0;
    sp24 = 0;
    sp1C = 0;
    sp14 = 0;
    sp32 = 0;
    sp30 = 0;
    sp3E = 0;
    sp3C = 0;
    sp3D = 0;
    sp31 = 0;
    if (arg0->unk2C == 0) {
        temp_v1 = -0x40 - (arg0->unk1C * 0x10);
        var_v0 = (u32) (temp_v1 & 0xFF) >> 2;
        sp39 = temp_v1;
        sp35 = temp_v1;
        sp3A = (s8) var_v0;
        sp36 = (s8) var_v0;
    } else {
        temp_v1_2 = -0x40 - (arg0->unk1C * 0x10);
        var_v0 = (u32) (temp_v1_2 & 0xFF) >> 2;
        sp39 = temp_v1_2;
        sp35 = temp_v1_2;
        sp3A = temp_v1_2;
        sp36 = temp_v1_2;
    }
    sp38 = (s8) var_v0;
    sp34 = (s8) var_v0;
    temp_s0 = arg0 + 0x38;
    sp40 = 0x50000000;
    temp_a2 = arg0->unkE;
    arg0->unk4C = (s32) arg0->unk6;
    arg0->unk50 = (s32) arg0->unkA;
    arg0->unk54 = (s32) temp_a2;
    func_80017758(&sp10, temp_s0, temp_a2, arg0);
    sp12 = 7;
    sp2A = -7;
    sp18 = 2;
    sp22 = 0;
    sp1A = 0;
    sp28 = 0;
    sp10 = 0;
    sp20 = -2;
    func_80017758(&sp10, temp_s0);
}
