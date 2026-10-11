/* Overlay range [80131CA8,80131CF4) from MAIN.CD member 0012.
 * SHA256(span)=78933c7d331de709f1fce0aabe0af38cbb8ace27b0ae6d8710b12532e7ea806b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80131CA8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80131CF4(s32 a0);
s32 aF80131CA8(int a0) __asm__("func_80131CA8");

s32 aF80131CA8(int a0)
{
    s32 (*fp)(int) = (s32 (*)(int))func_80131CF4(*(s32 *)((u8 *)a0 + 0xBC));
    if (fp != 0) {
        fp(a0);
        return 1;
    }
    return 0;
}
