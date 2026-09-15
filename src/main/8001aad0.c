/* Main-exec range [8001AAD0,8001ABB4) from the SLUS executable.
 * SHA256(span)=48c04aae7f0758c43b24083f99e5623d374bb1a95a2212460c8f7b3583f1bd70.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062C38;
void func_8001ABBC(s32, void *, s32, s32); /* static */
extern s32 D_800BA1B4;

void func_8001AAD0(u32 arg0) {
    s32 var_a0;

    switch (arg0) {
    case 0:
        var_a0 = 9;
        break;
    case 1:
        var_a0 = 0xA;
        break;
    case 2:
        var_a0 = 0xB;
        break;
    case 3:
        var_a0 = 0xC;
        break;
    case 4:
        var_a0 = 0xD;
        break;
    case 5:
        var_a0 = 0xE;
        break;
    case 6:
        var_a0 = 0xF;
        break;
    case 7:
        var_a0 = 0x10;
        break;
    case 8:
        var_a0 = 0x11;
        break;
    case 9:
        var_a0 = 0x12;
        break;
    case 10:
        var_a0 = 0x13;
        break;
    case 11:
        var_a0 = 0x14;
        break;
    default:
        var_a0 = 0;
        break;
    }
    if (D_800BA1B4 == 5) {
        D_800BA1B4 = 0;
    }
    func_8001ABBC(3, (var_a0 * 0x30) + D_80062C38, 0, 0);
}
