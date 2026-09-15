/* Overlay range [801789AC,80178B18) from MAIN.CD member 0012.
 * SHA256(span)=843a4b33199e922756a9fa34d060c0d0b6592e6dd3a6a827f86aeee91ca3720f.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80184F38;
extern s32 D_80185350;
extern s32 D_80185B24;
s32 func_801399F0(s32);                             /* static */
void func_80178CBC(s32, s32);                    /* static */
void func_8017A4AC();                            /* static */
void func_8017AE2C(s32);                         /* static */
void func_8017BC38();                            /* static */
extern u16 D_80185C7C;

s32 func_801789AC(s32 arg0) {
    s16 temp_v0;
    s32 var_v0;

    func_8017BC38();
    func_8017A4AC();
    func_8017AE2C(arg0);
    temp_v0 = D_80185C7C - 1;
    switch ((u32) temp_v0) {                        /* irregular */
    case 0:
        var_v0 = func_801399F0(D_80185350);
        D_80185B24 = var_v0;
block_7:
        if (var_v0 != 0) {
        case 2:
            func_80178CBC(arg0, D_80184F38);
            return 0;
        }
    default:
        return 0;
    case 1:
        var_v0 = func_801399F0(D_80185350);
        D_80185B24 = var_v0;
        goto block_7;
    }
}
