/* Exact retail word export for [8005A870,8005AB00); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8007278C;
s32 func_8005AB00(u8, u8, u16);                     /* static */
s32 func_8005AB58(s16, s16);                        /* static */
s32 func_8005AC24(s16, s16);                        /* static */
s32 func_8005ACF0(s16, s16);                        /* static */
s32 func_8005AD34(void *);                          /* static */
extern s16 D_8007278E;

void func_8005A870(void *arg0, void *arg1) {
    u16 sp16;                                       /* compiler-managed */
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s16 var_v0_2;
    s32 var_t0;
    u16 temp_a0;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 var_v0;

    arg0->unk4 = func_8005AB58(arg1->unk0, arg1->unk2);
    arg0->unk8 = func_8005AC24((s16) ((arg1->unk4 + (u16) arg1->unk0) - 1), (s16) (((u16) arg1->unk2 + arg1->unk6) - 1));
    arg0->unkC = func_8005ACF0(arg1->unk8, arg1->unkA);
    arg0->unk10 = func_8005AB00(arg1->unk17, arg1->unk16, arg1->unk14);
    arg0->unk14 = func_8005AD34(arg1 + 0xC);
    arg0->unk18 = 0xE6000000;
    var_t0 = 7;
    if (arg1->unk18 != 0) {
        sp10 = (u16) arg1->unk0;
        sp12 = (u16) arg1->unk2;
        temp_a0 = arg1->unk4;
        sp14 = temp_a0;
        sp16 = arg1->unk6;
        var_v0 = 0;
        if ((s16) temp_a0 >= 0) {
            var_v0 = D_8007278C - 1;
            if ((D_8007278C - 1) >= (s16) temp_a0) {
                var_v0 = temp_a0;
            }
        }
        sp14 = var_v0;
        if ((s16) sp16 >= 0) {
            var_v0_2 = D_8007278E - 1;
            if ((D_8007278E - 1) >= (s16) sp16) {
                var_v0_2 = (s16) sp16;
            }
        } else {
            var_v0_2 = 0;
        }
        sp16 = var_v0_2;
        if ((sp10 & 0x3F) || (sp14 & 0x3F)) {
            temp_v0 = sp10 - (u16) arg1->unk8;
            sp10 = temp_v0;
            temp_v0_2 = sp12 - (u16) arg1->unkA;
            sp12 = temp_v0_2;
            *((7 * 4) + arg0) = (arg1->unk1B << 0x10) | ((arg1->unk1A << 8) | 0x60000000) | arg1->unk19;
            *((8 * 4) + arg0) = (s32) sp10;
            *((9 * 4) + arg0) = (s32) sp14;
            sp10 = temp_v0 + (u16) arg1->unk8;
            var_t0 = 0xA;
            sp12 = temp_v0_2 + (u16) arg1->unkA;
        } else {
            var_t0 = 0xA;
            *((7 * 4) + arg0) = (arg1->unk1B << 0x10) | ((arg1->unk1A << 8) | 0x02000000) | arg1->unk19;
            *((8 * 4) + arg0) = (s32) sp10;
            *((9 * 4) + arg0) = (s32) sp14;
        }
    }
    arg0->unk3 = (s8) (var_t0 - 1);
}
