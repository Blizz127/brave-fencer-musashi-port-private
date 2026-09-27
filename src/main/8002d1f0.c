/* Native retail instruction export [8002D1F0,8002D240).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003B45C(s32 *);                             /* static */
extern s32 D_800A4ECC;
extern s32 D_800A4ED0;
extern s16 D_800A4ED4;
extern s16 D_800A4ED6;

void func_8002D1F0(s16 arg0) {
    D_800A4ECC = 1;
    D_800A4ED0 = (s32) arg0;
    D_800A4ED4 = 0;
    D_800A4ED6 = 0;
    func_8003B45C(&D_800A4ECC);
}
