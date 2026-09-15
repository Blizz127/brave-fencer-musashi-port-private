/* Overlay range [80128678,80128714) from MAIN.CD member 0012.
 * SHA256(span)=dcc0e85ac3a0c4223588a4a6a388c90e0dbb468187cad95160b2ff155d7265d8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80029444();                                  /* extern */
void func_800D1754();                                  /* extern */
void func_801287B8();                                  /* static */
void func_8014607C();                                  /* static */

void func_80128678(void) {
    *(void **)0x1F8003FC = sp;
    func_80029444();
    func_8014607C();
    *(void *)0x1F8003FC = (void *) subroutine_arg0;
    func_801287B8();
    *(void *)0x1F8003FC = (void *) subroutine_arg0;
    func_800D1754();
}
