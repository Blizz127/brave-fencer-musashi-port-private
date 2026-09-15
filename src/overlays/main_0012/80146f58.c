/* Overlay range [80146F58,80146FC4) from MAIN.CD member 0012.
 * SHA256(span)=651d802d8df86aedc6ff0f05cddf4b3562889bd5f54d1d498110d76ab957cec3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048FBC(void *, s32, s32);                       /* extern */
void func_8004978C(s16 *, void *);                        /* extern */
s16 func_8012A68C();                                /* static */
s16 func_8012A758();                                /* static */

void func_80146F58(s32 arg0, s32 arg1) {
    s32 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;

    sp10 = func_8012A68C();
    sp12 = func_8012A758();
    sp14 = 0;
    func_8004978C(&sp10, &sp18);
    func_80048FBC(&sp18, arg0, arg1);
}
