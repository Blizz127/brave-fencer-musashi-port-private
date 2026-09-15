/* Exact retail word export for [8005B7B0,8005BA90); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8007288C;
extern s32 D_80072890;
extern s32 D_80072894;
extern s32 D_80072790;
extern s32 D_80072794;
extern s32 D_80072884;
extern s32 *D_8007285C;
extern s32 *D_80072868;
extern s32 D_8007287C;
void func_800425E0(s32, s32 (*)());                        /* static */
s32 func_800426FC(s32);                             /* static */
void func_8005BA90();                                  /* static */
void func_8005C020();                                  /* static */
s32 func_8005C054();                                /* static */
extern s32 func_80072880;
extern u8 D_80072789;
extern s32 *D_800C5510;
extern s32 *D_800C5514;
extern s32 *D_800C5518;
extern s32 *D_800C551C;

s32 func_8005B7B0(s32 (*arg0)(), s32 *arg1, s32 arg2, s32 arg3) {
    s32 *var_a3;
    s32 temp_a0;
    s32 temp_a1;
    s32 var_a2;
    s32 var_v0;

    func_8005C020();
loop_3:
    if (((D_8007288C + 1) & 0x3F) != D_80072890) {
        D_80072894 = func_800426FC(0);
        D_80072790 = 1;
        if ((D_80072789 == 0) || ((D_8007288C == D_80072890) && !(*D_80072868 & 0x01000000) && (D_80072794 == 0))) {
            do {

            } while (!(*D_8007285C & 0x04000000));
            arg0(arg1, arg3);
            D_8007287C = arg0;
            func_80072880 = arg1;
            D_80072884 = arg3;
            func_800426FC(D_80072894);
            return 0;
        }
        func_800425E0(2, func_8005BA90);
        var_a2 = 0;
        if (arg2 != 0) {
            var_a3 = arg1;
loop_13:
            temp_a0 = var_a2 * 4;
            if (var_a2 < (arg2 / 4)) {
                temp_a1 = *var_a3;
                var_a3 += 4;
                var_a2 += 1;
                *(temp_a0 + ((D_8007288C * 0x60) + &D_800C551C)) = temp_a1;
                goto loop_13;
            }
            *(&D_800C5514 + (D_8007288C * 0x60)) = (D_8007288C * 0x60) + &D_800C551C;
        } else {
            *(&D_800C5514 + (D_8007288C * 0x60)) = arg1;
        }
        *(&D_800C5518 + (D_8007288C * 0x60)) = arg3;
        *(&D_800C5510 + (D_8007288C * 0x60)) = arg0;
        D_8007288C = (D_8007288C + 1) & 0x3F;
        func_800426FC(D_80072894);
        func_8005BA90();
        var_v0 = (D_8007288C - D_80072890) & 0x3F;
        /* Duplicate return node #18. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = -1;
    if (func_8005C054() == 0) {
        func_8005BA90();
        goto loop_3;
    }
    return var_v0;
}
