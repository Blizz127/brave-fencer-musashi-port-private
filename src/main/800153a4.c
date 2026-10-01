/* Exact retail word export for [800153A4,800153CC); EXE and assembly verified. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800153A4(void *arg0, s32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5) {
    (*(s16 *) ((s8 *) (arg0) + (0))) = 1;
    (*(s16 *) ((s8 *) (arg0) + (2))) = arg2;
    (*(s16 *) ((s8 *) (arg0) + (4))) = arg3;
    (*(s32 *) ((s8 *) (arg0) + (8))) = arg1;
    (*(u8 *) ((s8 *) (arg0) + (0xC))) = arg4;
    (*(u8 *) ((s8 *) (arg0) + (0xD))) = arg5;
}
