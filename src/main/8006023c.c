/* Main-exec range [8006023C,800603BC) from the SLUS executable.
 * SHA256(span)=3f31f312b09c8f38cf7b451dc7fe5b1be7d632c5ab7b826ccb7b3dbc8d52e946.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80060030;
extern s32 D_800744C0;
extern s32 D_80074568;
void func_8005C604(s32 (*)());                           /* static */
s32 func_80061010(s32);                             /* static */
void func_80061024(s32, s32, s32 *);                       /* static */
void func_80061770(s32, s32 *);                        /* static */
void func_80061E90(s32 *, s32);                          /* static */
s32 func_80061F48(s32 *, s32);                      /* static */
void func_8006289C(void *);                               /* static */
extern s32 D_80078C80;
extern s32 D_80078C84;
extern s32 D_80078C88;
extern s32 D_80078C8C;
extern s32 D_80078C90;
extern s32 D_80078CD0;

s32 func_8006023C(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp10;
    s32 *temp_s0;
    s32 temp_v0;
    s32 var_s1;
    s32 var_v0;

    var_s1 = 0;
    if (D_80078C90 >= 0) {
        func_8005C604(D_80074568);
        return -1;
    }
    temp_s0 = &D_80078C90 + 0x10;
    func_80061770(arg0, temp_s0);
    func_80061E90(temp_s0, arg1);
    D_80078C8C = arg0;
loop_3:
loop_4:
    temp_v0 = func_80061F48(temp_s0, arg2 | 0x8000);
    D_80078C90 = temp_v0;
    var_v0 = 0;
    if (temp_v0 < 0) {
        D_80078CD0 = func_80061010(0);
        if (D_80078C80 != 0) {
            func_8005C604(D_800744C0);
        } else {
            D_80078C80 = 2;
            D_80078C84 = 0;
            D_80078C88 = 0;
            D_80078C8C = arg0;
            func_8006289C(&D_80060030);
        }
        func_80061024(0, 0, &sp10);
        func_80061010(D_80078CD0);
        if (sp10 != 3) {
            if ((sp10 != 2) || (var_s1 += 1, ((var_s1 < 0x10) == 0))) {
                if (sp10 == 0) {
                    sp10 = 5;
                }
                var_v0 = sp10;
            } else {
                goto loop_3;
            }
        } else {
            goto loop_4;
        }
    }
    return var_v0;
}
