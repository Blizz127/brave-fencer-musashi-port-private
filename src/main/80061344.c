/* Main-exec range [80061344,80061524) from the SLUS executable.
 * SHA256(span)=00334bf8269321ffc07a92a3794eeb56a880cb0202051d4df61fdf1e06549bd0.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80060030;
extern s32 D_800744C0;
extern s32 D_80074610;
void func_8005C604(s32 (*)());               /* static */
s32 func_80061010(s32);                             /* static */
void func_80061770(s32, void *);              /* static */
void func_80061E90(void *, s32);          /* static */
s32 func_80061F98(void *);                       /* static */
void func_8006289C(void *);                   /* static */
extern s32 D_80078C7C;
extern s32 *D_80078C80;
extern s32 D_80078C84;
extern s32 D_80078C88;
extern s32 D_80078C8C;
extern s32 D_80078CC8;
extern s32 D_80078CD0;

s32 func_80061344(s32 arg0, s32 arg1) {
    s32 sp30;
    s32 sp10;
    s32 temp_v0;
    s32 var_s1;

    var_s1 = 0;
    if (M2C_FIELD(&D_80078C80, s32 *, 0) != 0) {
        func_8005C604(D_80074610);
        return -1;
    }
    func_80061770(arg0, &sp10);
    func_80061E90(&sp10, arg1);
    D_80078C7C |= 1 << D_80078C8C;
loop_3:
    temp_v0 = func_80061F98(&sp10);
    sp30 = temp_v0;
    if (temp_v0 == 0) {
        D_80078CD0 = func_80061010(0);
        if (M2C_FIELD(&D_80078C80, s32 *, 0) != 0) {
            func_8005C604(D_800744C0);
        } else {
            M2C_FIELD(&D_80078C80, s32 *, 0) = 2;
            D_80078C84 = 0;
            D_80078C88 = 0;
            D_80078C8C = arg0;
            func_8006289C(&D_80060030);
        }
        if ((M2C_FIELD(&D_80078C80, s32 *, 0) != 0) || (M2C_FIELD(&D_80078C80, s32 *, 8) != 0)) {
            if (M2C_FIELD(&D_80078C80, s32 *, 8) == 0) {
                do {

                } while (D_80078C88 == 0);
            }
            D_80078C88 = 0;
            sp30 = D_80078CC8;
        }
        func_80061010(D_80078CD0);
        if ((sp30 != 3) && ((sp30 != 2) || (var_s1 += 1, ((var_s1 < 0x10) == 0)))) {
            if (sp30 == 0) {
                sp30 = 5;
            }
            return sp30;
        }
        goto loop_3;
    }
    return 0;
}
