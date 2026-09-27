/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Exact retail word export for [800144D4,80014554); EXE and assembly verified. */
#include "psx_types.h"

void func_80053308();                                 /* static */
void func_80053F6C(s32 *);                             /* static */
extern s32 D_80126950;
extern s32 D_80126984;
extern s32 D_80126988;
extern s32 D_8012698C;
extern s32 D_80126990;
extern s32 D_80126994;
extern s32 D_80126998;
extern s32 D_8012699C;
extern s32 D_801269A0;

void func_800144D4(void) {
    D_80126950 = 0x12C;
    func_80053308(0x12C);
    D_80126984 = 0;
    D_80126988 = 0;
    D_8012698C = -0x12C;
    D_80126990 = 0;
    D_80126994 = 0;
    D_80126998 = 0;
    D_8012699C = 0;
    D_801269A0 = 0;
    func_80053F6C(&D_80126984);
}
