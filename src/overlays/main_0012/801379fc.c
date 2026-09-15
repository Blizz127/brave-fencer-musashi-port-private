/* Overlay range [801379FC,80137B80) from MAIN.CD member 0012.
 * SHA256(span)=68af08ce9ce96315182b02587d020b3c2f2ade8695cfddf976c87e1ae4032e74.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80137BD8(s32 *);                             /* static */
void func_80138BE0(s32 *);                             /* static */
void func_8013A380();                                  /* static */
extern s32 *D_801269F0;
extern s32 *D_801269F4;
extern s32 *D_801269F8;
extern s32 *D_80127524;
extern s32 D_80127548;

void func_801379FC(void) {
    s32 *var_s0;
    s32 *var_s2_2;
    s32 *var_s2_3;
    s32 temp_v1;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;

    D_80127548 = 0x24;
    var_s1 = 0;
    if ((D_80127524 != 0) && (*D_80127524 != 0)) {
        var_s2 = 0;
        func_80138BE0(D_80127524);
        var_s0 = &D_801269F0;
        do {
            if ((var_s0 != D_80127524) && (*(&D_801269F0 + var_s2) != 0)) {
                func_80138BE0(var_s0);
            }
            var_s0 += 0x4C;
            var_s1 += 1;
            var_s2 += 0x4C;
        } while (var_s1 < 3);
        var_s1_2 = 0;
    } else {
        var_s2_2 = &D_801269F0;
        var_s0_2 = 0;
        do {
            if (*(&D_801269F0 + var_s0_2) != 0) {
                func_80138BE0(var_s2_2);
            }
            var_s2_2 += 0x4C;
            var_s1 += 1;
            var_s0_2 += 0x4C;
        } while (var_s1 < 3);
        var_s1_2 = 0;
    }
    var_s2_3 = &D_801269F0;
    var_s0_3 = 0;
    do {
        if ((*(&D_801269F4 + var_s0_3) != 0) && (*(&D_801269F0 + var_s0_3) != 0)) {
            temp_v1 = *(&D_801269F8 + var_s0_3);
            if ((temp_v1 & 0x1000) && !(temp_v1 & 0x2000)) {
                func_80137BD8(var_s2_3);
            }
        }
        var_s2_3 += 0x4C;
        var_s1_2 += 1;
        var_s0_3 += 0x4C;
    } while (var_s1_2 < 3);
    func_8013A380();
}
