/* Exact retail word export for [80059D68,80059E6C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072784();
extern s32 D_80072780;
extern s32 D_800741EC;
void func_8005A870(void *, void *);                    /* static */
extern u8 D_8007278A;

void *func_80059D68(void *arg0) {
    u8 *var_a3;
    void *temp_s0;
    void *var_a2;

    if ((u8) D_8007278A >= 2U) {
        D_80072784(D_800741EC, arg0);
    }
    temp_s0 = arg0 + 0x1C;
    func_8005A870(temp_s0, arg0);
    arg0->unk1C = (s32) (arg0->unk1C | 0xFFFFFF);
    D_80072780->unk8(D_80072780->unk18, temp_s0, 0x40, 0);
    var_a3 = &D_8007278A + 0xE;
    var_a2 = arg0;
    do {
        var_a3->unk0 = (s32) var_a2->unk0;
        var_a3->unk4 = (s32) var_a2->unk4;
        var_a3->unk8 = (s32) var_a2->unk8;
        var_a3->unkC = (s32) var_a2->unkC;
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != (arg0 + 0x50));
    var_a3->unk0 = (s32) var_a2->unk0;
    var_a3->unk4 = (s32) var_a2->unk4;
    var_a3->unk8 = (s32) var_a2->unk8;
    return arg0;
}
