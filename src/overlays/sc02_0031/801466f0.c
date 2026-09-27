/* Complete SC02 retail span [801466F0,80146750).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


typedef struct Rec801466F0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec801466F0;

extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);

void func_801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) {
    Rec801466F0 rec;

    rec.unk0 = a0;
    rec.unk8 = a1;
    rec.unk2 = a2;
    rec.unk4 = a3;
    rec.unk6 = sp5;
    rec.unkC = sp6;
    rec.unk10 = sp7;
    if (sp8 != 0) {
        func_80146750((u16 *)&rec);
    } else {
        func_8014680C((short *)&rec);
    }
}
