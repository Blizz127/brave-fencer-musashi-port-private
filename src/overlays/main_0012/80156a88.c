/* Overlay range [80156A88,80156B74) from MAIN.CD member 0012.
 * SHA256(span)=8a592a7002ff58a1faab19d22bf618f164730462adeea1d399b5884545346d4b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80147324(s32);                         /* static */
void func_8014CA14(s32, s32);                    /* static */
void func_8014CA88(s32, s32);                    /* static */
extern s32 *D_801150E0;
extern s32 *D_801151E0;

void func_80156A88(void *arg1) {
    s32 *var_s0;
    s32 *var_s1;
    s32 temp_s3;
    s32 temp_v1;
    u32 var_s2;

    temp_v1 = M2C_FIELD(arg1, s32 *, 0xC);
    temp_s3 = temp_v1 & 0xF0FFFFFF;
    var_s2 = 0;
    if (temp_v1 != 0x80000000) {
        var_s0 = &D_801150E0;
        var_s1 = &D_801151E0;
        do {
            if (*var_s1 & 1) {
                if (temp_v1 & 0x01000000) {
                    func_80147324(temp_s3 & 0xFFFF);
                    var_s0 += 4;
                } else if (temp_v1 & 0x02000000) {
                    func_8014CA88(*var_s0, temp_s3);
                    var_s0 += 4;
                } else {
                    func_8014CA14(*var_s0, temp_s3);
                    goto block_8;
                }
            } else {
block_8:
                var_s0 += 4;
            }
            var_s2 += 1;
            var_s1 += 4;
        } while (var_s2 < 3U);
    }
}
