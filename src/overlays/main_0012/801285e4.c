/* Overlay range [801285E4,80128678) from MAIN.CD member 0012.
 * SHA256(span)=fc839e66252606d7989292f60f6114d98603d99a51b2e70216b27874696be43b.
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
s32 func_800D18DC();                                /* extern */
void func_801287B8();                                  /* static */
void func_8014607C();                                  /* static */
extern s32 D_801840B4;

void func_801285E4(void) {
    *(void **)0x1F8003FC = sp;
    D_801840B4 = func_800D18DC();
    func_8014607C();
    *(void *)0x1F8003FC = (void *) subroutine_arg0;
    func_801287B8();
    if (D_801840B4 != 0) {
        func_80011A3C();
    }
}
