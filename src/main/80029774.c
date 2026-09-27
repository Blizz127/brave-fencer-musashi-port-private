/* Main-exec range [80029774,800298BC) from the SLUS executable.
 * SHA256(span)=60178c0ae6b305a7b3bd4f14702cdb013db141e42123b892a0ca531573294a95.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80078E78;
extern s32 *D_80078F28;
extern s32 *D_800A5E58;
extern u16 D_800A6588;
extern s32 *D_800AE648;
extern s32 *D_800BA1B8;

void func_80029774(s32 arg0) {
    void *var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a2_4;
    s32 var_a2_5;
    u16 *var_a0;
    u16 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    void *temp_t1;
    void *var_a3;
    void *var_a3_2;
    void *var_v1;
    void *var_v1_2;
    void *var_v1_3;

    temp_t1 = (arg0 * 0x2DC) + &D_80078F28;
    var_a3 = temp_t1 + 0x24;
    var_a2 = &D_80078E78;
    do {
        var_a3->unk0 = (s32) var_a2->unk0;
        var_a3->unk4 = (s32) var_a2->unk4;
        var_a3->unk8 = (s32) var_a2->unk8;
        var_a3->unkC = (s32) var_a2->unkC;
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != (&D_80078E78 + 0x90));
    var_a3->unk0 = (s32) var_a2->unk0;
    var_a3->unk4 = (s32) var_a2->unk4;
    var_a2_2 = 0;
    var_a0 = &D_800A6588;
    var_v1 = temp_t1;
    do {
        temp_v0 = *var_a0;
        var_a0 += 2;
        var_a2_2 += 1;
        var_v1->unkBC = temp_v0;
        var_v1 += 2;
    } while (var_a2_2 < 0x40);
    var_a2_3 = 0;
    var_v1_2 = temp_t1;
    do {
        temp_v0_2 = *(&D_800AE648 + var_a2_3);
        var_a2_3 += 1;
        var_v1_2->unk13C = temp_v0_2;
        var_v1_2 = temp_t1 + var_a2_3;
    } while (var_a2_3 < 0x40);
    var_a2_4 = 0;
    var_v1_3 = temp_t1;
    do {
        temp_v0_3 = *(&D_800BA1B8 + var_a2_4);
        var_a2_4 += 1;
        var_v1_3->unk17C = temp_v0_3;
        var_v1_3 = temp_t1 + var_a2_4;
    } while (var_a2_4 < 0x100);
    var_a2_5 = 0;
    var_a3_2 = temp_t1;
    do {
        var_a3_2->unk27F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        var_a2_5 += 1;
        var_a3_2 += 4;
    } while (var_a2_5 < 0x18);
    *(&D_800A5E58 + (arg0 * 4)) = 1;
}
