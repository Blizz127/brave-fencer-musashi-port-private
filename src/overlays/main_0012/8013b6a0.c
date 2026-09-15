/* Overlay range [8013B6A0,8013B7AC) from MAIN.CD member 0012.
 * SHA256(span)=37865125b76e7632047711c6e60036fe5bf75e74b3ad4e4525a2a2519a5a86cd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80185B58;
extern s32 D_80185B5E;
extern s32 D_80185B60;
extern s32 D_80185B64;
extern s32 *D_80185B5C;

void func_8013B6A0(s32 arg0, void *arg1, s32 arg2) {
    *(D_80185B58 + (arg0 * 0x1C)) = 1;
    *(&D_80185B5C + (arg0 * 0x1C)) = arg1->unk0;
    *(D_80185B5E + (arg0 * 0x1C)) = arg1->unk2;
    *(D_80185B60 + (arg0 * 0x1C)) = arg1->unk4;
    *(D_80185B64 + (arg0 * 0x1C)) = arg2;
}
