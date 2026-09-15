/* Exact retail word export for [8002F714,8002F80C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A96E;
extern s32 func_8002F80C;
extern s8 D_800760D0;
extern s8 D_800760D4;
extern s8 D_800760D8;
extern s8 D_800760DC;
extern s32 (*D_800A4F24)();

void func_8002F714(s32 arg0, s32 arg1) {
    s32 temp_a0;
    u8 var_v0;

    temp_a0 = arg0 & 0xFFFF;
    switch (temp_a0) {                              /* irregular */
    case 0:
        D_800760D0 = arg1 & 0x7F;
        D_800A4F24 = func_8002F80C;
        var_v0 = D_8006A96E | 1;
block_11:
        D_8006A96E = var_v0;
        return;
    case 1:
        D_800760D4 = arg1 & 0x7F;
        D_800A4F24 = func_8002F80C;
        var_v0 = D_8006A96E | 2;
        goto block_11;
    case 2:
        D_800760D8 = arg1 & 0x7F;
        D_800A4F24 = func_8002F80C;
        var_v0 = D_8006A96E | 4;
        goto block_11;
    case 3:
        D_800760DC = arg1 & 0x7F;
        D_800A4F24 = func_8002F80C;
        var_v0 = D_8006A96E | 8;
        goto block_11;
    }
}
