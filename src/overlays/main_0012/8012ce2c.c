/* Overlay range [8012CE2C,8012CEB0) from MAIN.CD member 0012.
 * SHA256(span)=fb3347e953cba5365a4c9257b661d7b8c0f70d83222652c0281290d54384f15a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80133784(s32, u16 *, void *);   /* static */

s32 func_8012CE2C(void *arg0) {
    s32 sp1F;
    s32 sp1B;
    s8 sp1A;
    s32 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;

    sp10 = M2C_FIELD(arg0, u16 *, 6);
    sp12 = M2C_FIELD(arg0, u16 *, 0xA);
    sp14 = M2C_FIELD(arg0, u16 *, 0xE);
    sp1B = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    sp1F = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    sp1A = (u16) sp1A + 8;
    func_80133784(1, &sp10, &sp18);
    return (s16) sp12 == (s16) sp1A;
}
