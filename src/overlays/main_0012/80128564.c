/* Overlay range [80128564,801285D4) from MAIN.CD member 0012.
 * SHA256(span)=b71c659e394e2d7bda30c660ae793eda52600aca1d52f44f03d99d147a91e2ae.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80011A3C();                                  /* extern */
void func_8002D4C8(s32, s32);                              /* extern */
void func_80178608();                                 /* static */
extern s16 D_800B99F2;
extern s16 D_800B9A08;

void func_80128564(void) {
    *(void **)0x1F8003FC = sp;
    func_80178608(0x1F8003FC);
    if (D_800B9A08 == 0x300A) {
        func_8002D4C8(6, 0);
    }
    func_80011A3C();
    D_800B99F2 = 1;
}
