/* Overlay range [8014FD54,8014FDF4) from MAIN.CD member 0012.
 * SHA256(span)=af63cdd965d25481ff9443812a6f0a28d266d5c7b14b74dec1bbe07477e6bc2f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80133784(s32, s16 *, s16 *);                 /* static */
void func_80149290(s16 *, s16 *, s16 *);               /* static */

s32 func_8014FD54(s16 *arg0) {
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s32 temp_v0;

    sp10 = 0;
    sp12 = 0;
    sp14 = 7;
    func_80149290(&sp10, &sp10);
    sp18 = 0;
    sp1A = 0;
    sp1C = -0x18;
    func_80149290(arg0, &sp18, &sp18);
    temp_v0 = func_80133784(1, &sp10, &sp18);
    if (temp_v0 != 0) {
        if (temp_v0 & 0x8000) {
            return sp1E == 0x15;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
