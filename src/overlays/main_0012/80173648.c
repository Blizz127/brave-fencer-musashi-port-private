/* Overlay range [80173648,801736A8) from MAIN.CD member 0012.
 * SHA256(span)=7a59aa460b7c533c1e3c55def3c8868f500feb1e8b145a35c6758617c3adc9b0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80171A1C(s32);                               /* static */
void func_80171CC4(s16 *);                             /* static */
s32 func_80172664(s32);                             /* static */
void func_80174650(s32);                               /* static */
extern s16 D_80126B3E;

void func_80173648(s32 arg0) {
    if (D_80126B3E != 0) {
        func_80171CC4(&D_80126B3E - 6);
    }
    if (func_80172664(arg0) == 0) {
        func_80171A1C(arg0);
        func_80174650(arg0);
    }
}
