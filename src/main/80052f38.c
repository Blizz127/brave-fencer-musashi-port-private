/* Main-exec range [80052F38,80052FCC) from the SLUS executable.
 * SHA256(span)=3360c187cf55c2daa8ba2a479b3e16fc2cc5e48fe9274fcfa31942ae54911eb0.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004818C(void *, s32, void *);         /* static */
void func_800484EC(s32, s32);                    /* static */

void func_80052F38(void *arg0, s32 arg1, void *arg2) {
    func_800484EC(arg1 + 0x14, arg2 + 0x14);
    func_8004818C(arg0, arg1, arg2);
    M2C_FIELD(arg2, s32 *, 0x14) = (s32) (M2C_FIELD(arg2, s32 *, 0x14) + M2C_FIELD(arg0, s32 *, 0x14));
    M2C_FIELD(arg2, s32 *, 0x18) = (s32) (M2C_FIELD(arg2, s32 *, 0x18) + M2C_FIELD(arg0, s32 *, 0x18));
    M2C_FIELD(arg2, s32 *, 0x1C) = (s32) (M2C_FIELD(arg2, s32 *, 0x1C) + M2C_FIELD(arg0, s32 *, 0x1C));
}
