/* Overlay range [8013A380,8013A448) from MAIN.CD member 0012.
 * SHA256(span)=0e2df53ded31d4db92d80ce8f74fa8d81d7bd0f1d8ff6b7c26fe8597337bd647.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8013A448(s16 *);                             /* static */
void func_8013A4C4(s16 *);                             /* static */
void func_8013A530(s16 *);                             /* static */
extern s16 D_8011DA80;

void func_8013A380(void) {
    s16 *var_s0;
    s16 temp_v1;
    s32 var_s1;

    var_s0 = &D_8011DA80;
    var_s1 = 0;
    do {
        if (var_s0 != 0) {
            temp_v1 = *var_s0;
            if (temp_v1 != 2) {
                if (temp_v1 < 3) {
                    if (temp_v1 != 1) {
                        var_s1 += 1;
                    } else {
                        func_8013A448(var_s0);
                        var_s1 += 1;
                    }
                } else if (temp_v1 != 3) {
                    var_s1 += 1;
                } else {
                    func_8013A4C4(var_s0);
                    goto block_11;
                }
            } else {
                func_8013A530(var_s0);
                var_s1 += 1;
            }
        } else {
block_11:
            var_s1 += 1;
        }
        var_s0 += 0x10;
    } while (var_s1 < 2);
}
