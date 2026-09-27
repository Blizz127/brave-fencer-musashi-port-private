/* Overlay range [800CF268,800CF2BC) from MAIN.CD member 0007.
 * SHA256(span)=d267ec497c77c884e0708bd1c0a6e1de8c528cf8d25ad54b08f76ca653f0ff66.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800167F0();                               /* extern */
extern s32 D_800D136C;
extern s32 D_800D1374;
void func_800CF6D0(s32, s32);                              /* static */

void func_800CF268(void) {
    func_800CF6D0(-0x400, 0);
    if (func_800167F0(0) & 0xFFFF) {
        D_800D136C = -0x340;
        D_800D1374 = (s32) (D_800D1374 + 1);
    }
}
