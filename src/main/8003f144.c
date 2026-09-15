/* Exact retail word export for [8003F144,8003F380); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800414E4(s16, s16);                          /* static */
extern s32 D_800A6584;
extern u8 D_800B9B27;
extern s32 *D_800B9B40;

s32 func_8003F144(s16 arg0, s16 arg1, s32 arg2, void *arg3) {
    s32 temp_v1;
    void *temp_v1_2;

    if (*(&D_800B9B40 + arg0) != 1) {
        return -1;
    }
    func_800414E4(arg0, arg1);
    temp_v1 = (s32) ((arg2 + (D_800B9B27 * 0x10)) << 0x10) >> 0xB;
    arg3->unk0 = (u8) *(temp_v1 + D_800A6584);
    arg3->unk1 = (u8) (temp_v1 + D_800A6584)->unk1;
    arg3->unk2 = (u8) (temp_v1 + D_800A6584)->unk2;
    arg3->unk3 = (u8) (temp_v1 + D_800A6584)->unk3;
    arg3->unk4 = (u8) (temp_v1 + D_800A6584)->unk4;
    arg3->unk5 = (u8) (temp_v1 + D_800A6584)->unk5;
    arg3->unk7 = (u8) (temp_v1 + D_800A6584)->unk7;
    arg3->unk6 = (u8) (temp_v1 + D_800A6584)->unk6;
    arg3->unk8 = (u8) (temp_v1 + D_800A6584)->unk8;
    arg3->unk9 = (u8) (temp_v1 + D_800A6584)->unk9;
    arg3->unkA = (u8) (temp_v1 + D_800A6584)->unkA;
    arg3->unkB = (u8) (temp_v1 + D_800A6584)->unkB;
    arg3->unkC = (u8) (temp_v1 + D_800A6584)->unkC;
    arg3->unkD = (u8) (temp_v1 + D_800A6584)->unkD;
    temp_v1_2 = temp_v1 + D_800A6584;
    arg3->unk10 = (u16) temp_v1_2->unk10;
    arg3->unk12 = (u16) temp_v1_2->unk12;
    arg3->unk14 = (u16) temp_v1_2->unk14;
    arg3->unk16 = (u16) temp_v1_2->unk16;
    return 0;
}
