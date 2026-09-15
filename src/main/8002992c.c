/* Main-exec range [8002992C,80029A58) from the SLUS executable.
 * SHA256(span)=94cc5e6378b873fc26373efa1d3ac8d66ef81cfeafa8258425806eba69dba077.
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
extern u16 D_800A6588;
extern s32 *D_800AE648;
extern s32 *D_800BA1B8;
extern s32 *D_800BA2B8;

void func_8002992C(s32 arg0) {
    void *var_t0;
    void *var_t0_2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a2_4;
    s32 var_a2_5;
    u16 *var_a0;
    u16 temp_v0;
    void *temp_a3;
    void *var_a2;
    void *var_v0;
    void *var_v0_2;
    void *var_v1;

    var_t0 = &D_80078E78;
    temp_a3 = (arg0 * 0x2DC) + &D_80078F28;
    var_a2 = temp_a3 + 0x24;
    do {
        var_t0->unk0 = (s32) var_a2->unk0;
        var_t0->unk4 = (s32) var_a2->unk4;
        var_t0->unk8 = (s32) var_a2->unk8;
        var_t0->unkC = (s32) var_a2->unkC;
        var_a2 += 0x10;
        var_t0 += 0x10;
    } while (var_a2 != (temp_a3 + 0xB4));
    var_t0->unk0 = (s32) var_a2->unk0;
    var_t0->unk4 = (s32) var_a2->unk4;
    var_a2_2 = 0;
    var_a0 = &D_800A6588;
    var_v1 = temp_a3;
    do {
        temp_v0 = var_v1->unkBC;
        var_v1 += 2;
        var_a2_2 += 1;
        *var_a0 = temp_v0;
        var_a0 += 2;
    } while (var_a2_2 < 0x40);
    var_a2_3 = 0;
    var_v0 = temp_a3;
    do {
        *(&D_800AE648 + var_a2_3) = var_v0->unk13C;
        var_a2_3 += 1;
        var_v0 = temp_a3 + var_a2_3;
    } while (var_a2_3 < 0x40);
    var_a2_4 = 0;
    var_v0_2 = temp_a3;
    do {
        *(&D_800BA1B8 + var_a2_4) = var_v0_2->unk17C;
        var_a2_4 += 1;
        var_v0_2 = temp_a3 + var_a2_4;
    } while (var_a2_4 < 0x100);
    var_a2_5 = 0;
    var_t0_2 = &D_800BA2B8;
    do {
        var_t0_2->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        var_t0_2 += 4;
        var_a2_5 += 1;
    } while (var_a2_5 < 0x18);
}
