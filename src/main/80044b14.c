/* Native retail instruction export [80044B14,80044BF4).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8006CF4C;
extern s32 *D_8006CF54;
extern s32 *D_8006CF58;
extern s32 *D_8006CF5C;
extern s32 D_8006CF65;
extern s32 D_8006CF66;
extern s8 D_8006CF64;

void func_80044B14(void) {
    *D_8006CF4C = 1;
    if (*D_8006CF58 & 7) {
        do {
            *D_8006CF4C = 1;
            *D_8006CF58 = 7;
            *D_8006CF54 = 7;
        } while (*D_8006CF58 & 7);
    }
    D_8006CF66 = 0U;
    D_8006CF65 = (u8) D_8006CF66;
    D_8006CF64 = 2;
    *D_8006CF4C = 0;
    *D_8006CF58 = 0;
    *D_8006CF5C = 0x1325;
}
