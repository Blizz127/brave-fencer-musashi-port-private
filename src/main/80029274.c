/* Exact retail word export for [80029274,8002931C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072C84;
extern s32 *D_80078E78;

void func_80029274(void) {
    s32 sp90;
    s32 (*var_a2)();
    void *var_a3_2;
    void *var_a2_2;
    void *var_a3;

    var_a3 = sp;
    var_a2 = D_80072C84;
    do {
        var_a3->unk0 = (s32) var_a2->unk0;
        var_a3->unk4 = (s32) var_a2->unk4;
        var_a3->unk8 = (s32) var_a2->unk8;
        var_a3->unkC = (s32) var_a2->unkC;
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != (D_80072C84 + 0x90));
    var_a3->unk0 = (s32) var_a2->unk0;
    var_a3->unk4 = (s32) var_a2->unk4;
    var_a3_2 = &D_80078E78;
    var_a2_2 = sp;
    do {
        var_a3_2->unk0 = (s32) var_a2_2->unk0;
        var_a3_2->unk4 = (s32) var_a2_2->unk4;
        var_a3_2->unk8 = (s32) var_a2_2->unk8;
        var_a3_2->unkC = (s32) var_a2_2->unkC;
        var_a2_2 += 0x10;
        var_a3_2 += 0x10;
    } while (var_a2_2 != &sp90);
    var_a3_2->unk0 = (s32) var_a2_2->unk0;
    var_a3_2->unk4 = (s32) var_a2_2->unk4;
}
