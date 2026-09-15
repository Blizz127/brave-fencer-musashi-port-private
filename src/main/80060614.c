/* Exact retail word export for [80060614,800606D4); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (48/48 words at 0x80060614). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 *D_800606D4;
extern s32 D_800744C0;
extern s32 D_80074590;
extern s32 D_800745EC;
void func_8005C604(s32 (*)());                           
void func_8006289C(void *);                               
extern s32 D_80078C80;
extern s32 D_80078C84;
extern s32 D_80078C88;
extern s32 D_80078C90;
extern s32 D_80078C94;
extern s32 D_80078C98;
extern s32 D_80078C9C;

s32 func_80060614(s32 arg0, s32 arg1, s32 arg2) {
    s32 (*var_a0)();

    if (D_80078C90 < 0) {
        var_a0 = (s32 (*)()) &D_80074590;
        goto block_7;
    }
    if (D_80078C80 != 0) {
        var_a0 = (s32 (*)()) &D_800744C0;
        goto block_7;
    }
    if (!(arg2 & 0x7F)) {
        D_80078C80 = 6;
        D_80078C84 = 0;
        D_80078C88 = 0;
        D_80078C94 = arg1;
        D_80078C9C = arg0;
        D_80078C98 = arg2;
        func_8006289C(&D_800606D4);
        return 1;
    }
    var_a0 = (s32 (*)()) &D_800745EC;
block_7:
    func_8005C604(var_a0);
    return 0;
}
