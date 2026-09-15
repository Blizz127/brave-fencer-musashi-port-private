/* Overlay range [80156370,801563EC) from MAIN.CD member 0012.
 * SHA256(span)=936255e6eb1d390936ba6d3b8261e30fa440ca7fd364166ab16633a604c8d2de.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005C49C();                                /* extern */
void *func_801563EC(s32);                           /* static */

s32 func_80156370(s32 arg0) {
    s32 temp_s1;
    u16 temp_s0;
    void *temp_v0;

    temp_v0 = func_801563EC(arg0 & 0xFFFF);
    temp_s0 = M2C_FIELD(temp_v0, u16 *, 2);
    temp_s1 = M2C_FIELD(temp_v0, u16 *, 0) & 0xFFF;
    return (temp_s1 + (func_8005C49C() % (s32) (temp_s0 + 1))) & 0xFFFF;
}
