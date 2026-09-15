/* Overlay range [80156670,801567BC) from MAIN.CD member 0012.
 * SHA256(span)=31342aad98c484b5d2e4e25c1ffc8ad3a9c4640a3d4401f303a6efffdd39182d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80156B74(s32, s32);                            /* static */
s32 func_80157158(s32, s32, s32, void *, void *, void *, void *, void *, void *, s32, s32, void *, void *); /* static */
extern s32 *D_801150E0;
extern s32 *D_801151E0;
extern s32 *D_8011520C;
extern s32 *D_8011DAD8;
extern s32 *D_80126730;
extern s32 *D_80126AF0;
extern s32 *D_80126AF6;
extern s32 *D_801270A8;
extern s32 *D_80128120;
extern s32 *D_80128138;

void func_80156670(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5) {
    s32 *var_s2;
    s32 var_s0;
    u32 var_s1;

    func_80156B74(arg3, arg0 + 0x1A9);
    var_s1 = 0;
    var_s2 = &D_801151E0;
    var_s0 = 0;
    do {
        *var_s2 = 0;
        if (*(&D_80126AF6 + var_s0) == 0) {
            *var_s2 = func_80157158(arg0, arg1 & 0xFFFF, arg2 & 0xFFFF, &D_801270A8, var_s0 + &D_80126AF0, var_s0 + &D_80128120, var_s0 + &D_80128138, (var_s1 * 4) + &D_801150E0, var_s0 + &D_8011DAD8, arg4, (s32) arg5, var_s1 + &D_8011520C, var_s1 + &D_80126730);
        }
        var_s2 += 4;
        var_s1 += 1;
        var_s0 += 8;
    } while (var_s1 < 3U);
}
