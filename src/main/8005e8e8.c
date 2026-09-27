/* Exact retail word export for [8005E8E8,8005EA34); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8005E980;
extern s32 *D_8005E9D4;
void D_80072978();                                     /* static */

s32 func_8005E8E8(void *arg0, s8 arg1, s8 arg2) {
    s32 var_v0;

    var_v0 = 0;
    if (D_80072978() == 0) {
        var_v0 = 1;
        arg0->unk46 = 1;
        arg0->unk14 = &D_8005E980;
        arg0->unk18 = &D_8005E9D4;
        arg0->unk51 = arg1;
        arg0->unk52 = arg2;
        arg0->unk53 = (s8) ((arg1 & 0xFF) == arg0->unkE4);
    }
    return var_v0;
}
