/* Overlay range [801493D0,8014942C) from MAIN.CD member 0012.
 * SHA256(span)=7dcaaf9f4d91fd0675ee48a3d253e14fed74f3b64f29cbf13632d8ccaebd82b6.
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

void func_801493D0(void *arg0, s32 arg1, s32 arg2) {
    s32 sp18;
    s32 sp10;
    func_80015978(arg1, &sp10);
    func_8012F14C(M2C_FIELD(arg0, s32 *, 0x20) + 0x34, &sp10, &sp18);
    func_80015954(&sp18, arg2);
}
