/* Main-exec range [80047BD8,80047CAC) from the SLUS executable.
 * SHA256(span)=eaf04d39616425ff8f2c3da1e87d6f34ac6409f72c0741a6f6e8c1a138836585.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006D8AC;

s32 func_80047BD8(s32 arg0) {
    s32 sp74;
    s32 sp70;
    s32 sp3C;
    s32 sp38;
    s32 sp0;
    s32 (*var_t0)();
    s32 *var_a3;
    s32 *var_t1;
    s32 temp_v1;
    s32 var_a2;
    s32 var_v0;
    void *var_a1;

    var_a2 = 0;
    var_t1 = &sp74;
    var_t0 = D_8006D8AC;
    var_a3 = &sp3C;
    var_a1 = sp;
    sp0 = 0x1000;
    sp38 = arg0;
    sp70 = 0;
    do {
        temp_v1 = var_a1->unk38;
        if (temp_v1 < 0) {
            var_a1->unk4 = (s32) (var_a1->unk0 - (temp_v1 >> var_a2));
            *var_a3 = var_a1->unk38 + ((s32) var_a1->unk0 >> var_a2);
            var_v0 = var_a1->unk70 - *var_t0;
        } else {
            var_a1->unk4 = (s32) (var_a1->unk0 + (temp_v1 >> var_a2));
            *var_a3 = var_a1->unk38 - ((s32) var_a1->unk0 >> var_a2);
            var_v0 = var_a1->unk70 + *var_t0;
        }
        *var_t1 = var_v0;
        var_t1 += 4;
        var_t0 += 4;
        var_a3 += 4;
        var_a2 += 1;
        var_a1 += 4;
    } while (var_a2 < 0xC);
    return spA0;
}
