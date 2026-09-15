/* Overlay range [8012944C,8012956C) from MAIN.CD member 0012.
 * SHA256(span)=2636077d8b15e0073d1a83e48dffd1ffe52e9892271b5e3907b941411809ec49.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801298F4(void *);                   /* static */
void func_801299C8(s32, s32, void *);     /* static */
extern s32 D_8005128C;
extern s32 *D_800B9A78;
extern s16 D_80114EE0;

void func_8012944C(void) {
    void *var_s0;
    s32 var_a1;
    s32 var_s2;
    s32 var_s3;
    u16 temp_v1;
    void *var_s1;

    if (D_8005128C == 0x34420200) {
        D_8005128C = 0;
    }
    D_80114EE0 = 1;
    var_s0 = &D_800B9A78;
    var_s2 = 0;
    var_s3 = 0x30000;
    var_s1 = &D_800B9A78 + 0x1E;
    do {
        temp_v1 = M2C_FIELD(var_s1, u16 *, 0x16);
        if (temp_v1 != 0x7FFE) {
            if ((s32) temp_v1 < 0x7FFF) {
                if (temp_v1 != 0x7FFD) {
                    goto block_12;
                }
                if (var_s2 == 0) {
                    var_a1 = 1;
                    goto block_13;
                }
                goto block_14;
            }
            if (temp_v1 == 0x7FFF) {
                var_s1 += 0x54;
            } else {
block_12:
                func_801298F4(var_s0);
                var_a1 = var_s3 >> 0x10;
                M2C_FIELD(var_s1, s16 *, 0) = (s16) (M2C_FIELD(var_s1, u16 *, 0x24) + M2C_FIELD(var_s1, u16 *, 0x1C));
                goto block_13;
            }
        } else {
            var_a1 = (s32) (s16) (var_s2 * 2);
block_13:
            func_801299C8(1, var_a1, var_s0);
block_14:
            var_s1 += 0x54;
        }
        var_s3 += 0x10000;
        var_s2 += 1;
        var_s0 += 0x54;
    } while (var_s2 < 2);
}
