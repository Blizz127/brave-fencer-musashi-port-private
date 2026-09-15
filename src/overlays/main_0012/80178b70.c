/* Overlay range [80178B70,80178BB8) from MAIN.CD member 0012.
 * SHA256(span)=6195aca52f7c72ebe8eb395af4e54331577430578e487a3badb4b57cf581f3f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80181CBC;
void func_80178BF8();                                  /* static */
void func_80178CBC(s32, void *);                       /* static */

void func_80178B70(s32 arg0, s32 arg1) {
    D_80181CBC = arg1;
    func_80178BF8();
    func_80178CBC(arg0, D_80181CBC - 0xC);
}
