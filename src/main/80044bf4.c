/* Native retail instruction export [80044BF4,80044CE8).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8006CF4C;
extern s32 *D_8006CF50;
extern s32 *D_8006CF54;
extern s32 *D_8006CF58;
extern s32 D_8006CF60;

s32 func_80044BF4(void) {
    u8 sp3;
    u8 sp2;
    u8 sp1;
    u8 sp0;

    if (M2C_FIELD(D_8006CF60, u16 *, 0x1B8) == 0) {
        if (M2C_FIELD(D_8006CF60, u16 *, 0x1BA) == 0) {
            M2C_FIELD(D_8006CF60, s16 *, 0x180) = 0x3FFF;
            M2C_FIELD(D_8006CF60, s16 *, 0x182) = 0x3FFF;
        }
    }
    M2C_FIELD(D_8006CF60, s16 *, 0x1B0) = 0x3FFF;
    M2C_FIELD(D_8006CF60, s16 *, 0x1B2) = 0x3FFF;
    M2C_FIELD(D_8006CF60, s16 *, 0x1AA) = 0xC001;
    sp2 = 0x80;
    sp0 = 0x80;
    sp3 = 0;
    sp1 = 0;
    *D_8006CF4C = 2;
    *D_8006CF54 = 0x80;
    *D_8006CF58 = sp1;
    *D_8006CF4C = 3;
    *D_8006CF50 = 0x80;
    *D_8006CF54 = sp3;
    *D_8006CF58 = 0x20;
    return 0;
}
