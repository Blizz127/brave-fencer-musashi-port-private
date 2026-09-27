/* Main-exec range [80061114,80061344) from the SLUS executable.
 * SHA256(span)=954eb3a2b47ca1f9a2fa1b9bbcc4a9f6e4bb9bb3f59eeb547b53e86eb809e98b.
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
extern s32 D_80074610;
void func_8005C604(s32 (*)());                           /* static */
s32 func_80061010(s32);                             /* static */
void func_80061770(s32, void *);                          /* static */
void func_80061E90(void *, s32);                            /* static */
s32 func_80061F48(void *, s32, s32);                   /* static */
void func_80061F68(s32);                               /* static */
void func_8006289C(void *);                               /* static */
extern s32 D_80078C7C;
extern s32 D_80078C80;
extern s32 D_80078C84;
extern s32 D_80078C88;
extern s32 D_80078C8C;
extern s32 D_80078CC8;
extern s32 D_80078CD0;

s32 func_80061114(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp30;
    s32 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_s1;

    var_s1 = 0;
    if (D_80078C80.unk0 != 0) {
        func_8005C604(D_80074610);
        return -1;
    }
    func_80061770(arg0, &sp10);
    func_80061E90(&sp10, arg1);
    D_80078C7C |= 1 << D_80078C8C;
    temp_v0 = func_80061F48(&sp10, 1, D_80078C8C);
    if (temp_v0 >= 0) {
        func_80061F68(temp_v0);
        return 6;
    }
loop_6:
    var_a1 = arg2 << 0x10;
loop_7:
    temp_v0_2 = func_80061F48(&sp10, var_a1 | 0x200);
    if (temp_v0_2 < 0) {
        D_80078CD0 = func_80061010(0);
        if (D_80078C80.unk0 != 0) {
            func_8005C604(D_800744C0);
        } else {
            D_80078C80.unk0 = 2;
            D_80078C84 = 0;
            D_80078C88 = 0;
            D_80078C8C = arg0;
            func_8006289C(&D_80060030);
        }
        if ((D_80078C80.unk0 != 0) || (D_80078C80.unk8 != 0)) {
            if (D_80078C80.unk8 == 0) {
                do {

                } while (D_80078C88 == 0);
            }
            D_80078C88 = 0;
            sp30 = D_80078CC8;
        }
        func_80061010(D_80078CD0);
        if (sp30 != 0) {
            if (sp30 != 3) {
                if ((sp30 != 2) || (var_s1 += 1, var_a1 = arg2 << 0x10, ((var_s1 < 0x10) == 0))) {
                    if (sp30 == 0) {
                        sp30 = 5;
                    }
                    return sp30;
                }
                goto loop_7;
            }
            goto loop_6;
        }
        return 7;
    }
    func_80061F68(temp_v0_2);
    return 0;
}
