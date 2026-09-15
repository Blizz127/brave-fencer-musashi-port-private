/* Native retail instruction export [8003B280,8003B350).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0EC;
extern s32 D_8006B0F0;
extern s32 D_8006B0F4;
extern s32 D_8006B54C;
s32 func_8003B3D0(s32);                             /* static */

s32 func_8003B280(s32 arg0) {
    s16 var_v1;

    switch (arg0) {                                 /* irregular */
    case 0:
        D_8006B0EC = 0;
        var_v1 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0xFF7F;
block_8:
        M2C_FIELD(D_8006B54C, s16 *, 0x1AA) = var_v1;
        break;
    case 1:
        if ((D_8006B0F0 != arg0) && (func_8003B3D0(D_8006B0F4) != 0)) {
            D_8006B0EC = 0;
            var_v1 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0xFF7F;
        } else {
            D_8006B0EC = arg0;
            var_v1 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) | 0x80;
        }
        goto block_8;
    }
    return D_8006B0EC;
}
