/* Exact retail word export for [8005E79C,8005E8E8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8005E804;
extern s32 *D_8005E820;
void D_80072978();                                     /* static */

s32 func_8005E79C(void *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (D_80072978() == 0) {
        var_v0 = 1;
        arg0->unk46 = 1;
        arg0->unk14 = &D_8005E804;
        arg0->unk20 = arg1;
        arg0->unk18 = &D_8005E820;
    }
    return var_v0;
}
