/* Overlay range [80149374,801493D0) from MAIN.CD member 0012.
 * SHA256(span)=0c36e904c5b85fe1b8357401a8af42467b327a6aea634b1191601da6f541a9f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015954(void *, s32);          /* extern */
void func_80015978(s32, void *);          /* extern */
void func_8012F14C(s32, void *, void *);   /* static */

void func_80149374(void *arg0, s32 arg1) {
    s32 sp18;
    s32 sp10;
    func_80015978(arg1, &sp10);
    func_8012F14C(M2C_FIELD(arg0, s32 *, 0x20) + 0x34, &sp10, &sp18);
    func_80015954(&sp18, arg1);
}
