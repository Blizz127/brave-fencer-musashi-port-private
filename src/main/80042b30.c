/* Main-exec range [80042B30,80042BDC) from the SLUS executable.
 * SHA256(span)=2e2555998d1583252b6005222542e9d255355740c95b9c953efcbd39d839afae.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006BB2E;
extern s32 D_8006BB30;
extern s32 *D_8006CB88;
extern s32 *D_8006CB8C;
extern s32 D_8006CB90;
void func_8005CEE8(s32 *);                             /* static */
void func_8005CF08();                                  /* static */
extern u16 D_8006BAFC;

u16 *func_80042B30(void) {
    u16 *var_v0;

    var_v0 = 0;
    if (D_8006BAFC != 0) {
        func_8005CF08();
        D_8006BB2E = (u16) *D_8006CB8C;
        D_8006BB30 = (s32) *D_8006CB90;
        *D_8006CB8C = 0;
        *D_8006CB88 = *D_8006CB8C;
        *D_8006CB90 &= 0x77777777;
        func_8005CEE8(D_8006CB90);
        var_v0 = &D_8006BAFC;
        D_8006BAFC = 0;
    }
    return var_v0;
}
