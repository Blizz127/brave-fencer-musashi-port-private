/* Exact retail word export for [8004637C,80046480); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CFA0;
extern s32 D_8006CFA4;
extern s32 D_8006CFAC;
extern s32 D_8006CFB0;
extern s32 D_8006CFBC;
extern s32 D_8006CFC4;
extern s32 D_8006CFC8;
extern s32 D_8006CFCC;
extern s32 D_8006CFD0;
s32 func_8004239C();                               /* static */
s32 func_80043410();                                /* static */
s32 func_8004359C(s32, s32);                          /* static */
s32 func_800435B4();                               /* static */
void func_80043830(s32, s32, s32);                           /* static */
s32 func_800439D4();                               /* static */
s32 func_800460CC();                               /* static */

s32 func_8004637C(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    s32 var_v0;

    D_8006CFAC = arg2;
    temp_v1 = D_8006CFAC & 0x30;
    if (temp_v1 != 0) {
        var_v0 = 0x249;
        if (temp_v1 != 0x20) {
            var_v0 = 0x246;
        }
    } else {
        var_v0 = 0x200;
    }
    D_8006CFB0 = var_v0;
    D_8006CFAC = (s32) (D_8006CFAC | 0x20);
    D_8006CFA4 = arg1;
    D_8006CFA0 = arg0;
    D_8006CFC4 = func_8004359C(0, arg0);
    D_8006CFC8 = func_800435B4(0);
    if (D_8006CFD0 & 1) {
        D_8006CFCC = func_800439D4(0);
    }
    D_8006CFBC = func_8004239C(-1);
    if (func_80043410() & 0xE0) {
        func_80043830(9, 0, 0);
    }
    return func_800460CC(0) > 0;
}
