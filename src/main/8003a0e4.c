/* Main-exec range [8003A0E4,8003A234) from the SLUS executable.
 * SHA256(span)=bc583279b050683e7d37424fa3cf1cee40ae15539e133d41bda01d2c1bdde595.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006ABD8;
extern s32 *D_8006AB30;
extern s32 *D_800C6DD0;

void func_8003A0E4(u8 **arg0, s16 arg1) {
    s16 temp_a1;
    s32 var_a0;
    s32 var_a3;
    s32 var_t0;
    u32 temp_a0;
    u8 *temp_v1;
    u8 *var_t1;
    void *temp_a1_2;
    void *temp_a2;
    void *temp_t2;

    temp_t2 = arg0 + ((arg1 * 0x1A) + 0x1A);
    var_t1 = temp_t2 + 9;
    var_t0 = 0;
    temp_v1 = *arg0;
    *arg0 = temp_v1 + 1;
    var_a3 = 0;
    temp_t2->unk2 = (s16) (*temp_v1 & 0x7F);
    do {
        var_t1 += 1;
        if (*var_t1 != 0) {
            temp_a2 = var_a3 + &D_800C6DD0;
            temp_a1 = temp_t2->unk2;
            var_a0 = temp_a2->unk4 << 8;
            if (temp_a1 >= 0x41) {
                var_a0 += (temp_a1 - 0x40) * temp_a2->unk59 * 4;
            } else if (temp_a1 < 0x40) {
                var_a0 -= (0x40 - temp_a1) * temp_a2->unk58 * 4;
            }
            temp_a0 = var_a0 - (temp_a2->unk54 - 0x3C00);
            temp_a1_2 = temp_a2 + 0x10;
            if (temp_a0 >= 0x5301U) {
                temp_a2->unk24 = 0x3FFF;
            } else {
                temp_a2->unk24 = (s16) ((u32) (*(((temp_a0 >> 8) * 2) + &D_8006AB30) * *((temp_a0 & 0xFE) + D_8006ABD8)) >> 0xF);
            }
            temp_a1_2->unk4 = (s32) (temp_a1_2->unk4 | 0x10);
            temp_a2->unk5D = 1;
        }
        var_t0 += 1;
        var_a3 += 0x60;
    } while (var_t0 < 0x10);
}
