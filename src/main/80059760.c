/* Native retail instruction export [80059760,80059888).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8007278C;
void D_80072784();
extern s32 D_80074154;
extern s32 D_80074160;
extern s32 D_80074174;
extern u8 D_8007278A;
extern s16 D_8007278E;

void func_80059760(s16 arg0, void *arg1, s16 arg2, s16 arg3) {
    s32 (*var_a0)();
    s16 temp_a1;
    s16 temp_v1;
    s16 var_a2;
    s16 var_a3;

    var_a2 = arg2;
    var_a3 = arg3;
    switch (D_8007278A) {                           /* irregular */
    case 1:
        temp_a1 = M2C_FIELD(arg1, s16 *, 4);
        if ((D_8007278C < temp_a1) || (var_a3 = M2C_FIELD(arg1, s16 *, 0), ((D_8007278C < (temp_a1 + var_a3)) != 0)) || (temp_v1 = M2C_FIELD(arg1, s16 *, 2), ((D_8007278E < temp_v1) != 0)) || (var_a2 = M2C_FIELD(arg1, s16 *, 6), ((D_8007278E < (temp_v1 + var_a2)) != 0)) || (temp_a1 <= 0) || (var_a3 < 0) || (temp_v1 < 0) || (var_a2 <= 0)) {
            var_a0 = D_80074154;
block_13:
            D_80072784(var_a0, arg0, var_a2, var_a3);
            D_80072784(D_80074160, M2C_FIELD(arg1, s16 *, 0), M2C_FIELD(arg1, s16 *, 2), M2C_FIELD(arg1, s16 *, 4), (s32) M2C_FIELD(arg1, s16 *, 6));
        }
        return;
    case 2:
        var_a0 = D_80074174;
        goto block_13;
    }
}
