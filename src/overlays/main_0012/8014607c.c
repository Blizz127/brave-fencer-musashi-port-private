/* Overlay range [8014607C,80146128) from MAIN.CD member 0012.
 * SHA256(span)=dca950468298006818ec400a61e2bdbadb57dda97e547058645fe952d41b64dd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80184240;
s32 func_80146128();                                /* static */
void func_80146360();                                  /* static */
void func_801463A0();                                  /* static */

void func_8014607C(void) {
    *(void **)0x1F8003FC = sp;
    D_80184240 = func_80146128();
    if (D_80184240 != 0) {
        *(void *)0x1F8003FC = (void *) subroutine_arg0;
        func_80146360();
        *(void *)0x1F8003FC = (void *) subroutine_arg0;
        func_801463A0();
    }
}
