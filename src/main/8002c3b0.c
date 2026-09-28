/* Main-exec range [8002C3B0,8002C410) from the SLUS executable.
 * SHA256(span)=6d28d572fb003263bd945817c14f6d67ff76214641474b1d6dfccf1633ae5206.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002C3B0 - byte-exact against retail at -O2 (tools/register_match.py). */

s32 func_8002C3B0(s32 count, u8 *arr) {
    s32 i;
    s32 total = 0;
    for (i = 0; i < count; i++, arr += 0x28) {
        s32 v = *(s32 *)(arr + 0x18);
        s32 t;
        if (v >= 0) {
            t = v;
        } else {
            t = v + 0x1FFF;
        }
        t >>= 13;
        if (v & 0x1FFF) {
            total += t + 1;
        } else {
            total += t;
        }
    }
    return total;
}
