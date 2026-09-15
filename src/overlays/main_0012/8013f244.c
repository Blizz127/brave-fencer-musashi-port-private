/* Overlay range [8013F244,8013F350) from MAIN.CD member 0012.
 * SHA256(span)=ff1c0ee145ce4cd5cff34ed794dfc617092a99ea7f0c3b782622a0c20890ebdd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80141C0C(s32, u16 *);                          /* static */
extern u16 D_8011511A;
extern u16 D_8011511E;

void func_8013F244(void) {
    s32 var_v0;
    s32 var_v1;
    u16 temp_v0;
    u16 temp_v0_2;

    var_v1 = 0;
    if ((u16) D_8011511A < 3U) {
        temp_v0 = D_8011511A + 1;
        if (D_8011511E & 0x2000) {
            D_8011511A = temp_v0;
            var_v1 = 1;
            if ((u32) (temp_v0 & 0xFFFF) >= 3U) {
                D_8011511A = 0;
            }
        }
        if (D_8011511E & 0x8000) {
            temp_v0_2 = D_8011511A - 1;
            D_8011511A = temp_v0_2;
            if ((u32) (temp_v0_2 & 0xFFFF) >= 3U) {
                D_8011511A = 2;
            }
            var_v1 += 1;
        }
        if (D_8011511E & 0x5000) {
            D_8011511A = 3;
            var_v1 += 1;
        }
        goto block_12;
    }
    var_v0 = 0 << 0x10;
    if (D_8011511E & 0x5000) {
        D_8011511A = 0;
        var_v1 = 1;
block_12:
        var_v0 = var_v1 << 0x10;
    }
    if (var_v0 != 0) {
        func_80141C0C(2, &D_8011511A);
    }
}
