/* Exact retail word export for [80045090,80045190); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8006CF4C;
extern s32 *D_8006CF58;
extern s32 *D_8006CF5C;
extern s32 *D_8006CF80;
extern s32 *D_8006CF84;
extern s32 *D_8006CF88;
extern s32 *D_8006CF8C;
extern s32 *D_8006CF90;

s32 func_80045090(s32 arg0, s32 arg1) {
    *D_8006CF4C = 0;
    *D_8006CF58 = 0x80;
    *D_8006CF80 = 0x20943;
    *D_8006CF5C = 0x1323;
    *D_8006CF84 |= 0x8000;
    *D_8006CF88 = arg0;
    *D_8006CF8C = arg1 | 0x10000;
    do {

    } while (!(*D_8006CF4C & 0x40));
    *D_8006CF90 = 0x11000000;
    if (*D_8006CF90 & 0x01000000) {
        do {

        } while (*D_8006CF90 & 0x01000000);
    }
    *D_8006CF5C = 0x1325;
    return 0;
}
