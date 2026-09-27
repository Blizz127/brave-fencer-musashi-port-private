/* Overlay range [801734BC,80173544) from MAIN.CD member 0012.
 * SHA256(span)=cacb47b540c132b4038d1fd39b859bf20cc4636eaee9e5aaa99c7bbab0e35170.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 func_80173544;
void func_80174684(s32 (*)());               /* static */
extern s16 D_80126B32;
extern s16 D_80126B3E;
extern s16 D_80126B40;

void func_801734BC(u32 arg0) {
    s16 var_v0;

    switch (arg0) {
    case 0:
        var_v0 = -4;
block_7:
        D_80126B32 = var_v0;
        break;
    case 1:
        var_v0 = -8;
        goto block_7;
    case 2:
        var_v0 = -0x12;
        goto block_7;
    case 3:
        var_v0 = -0x18;
        goto block_7;
    case 4:
        var_v0 = -0x1C;
        goto block_7;
    }
    D_80126B3E = 0;
    D_80126B40 = 0;
    func_80174684(func_80173544);
}
