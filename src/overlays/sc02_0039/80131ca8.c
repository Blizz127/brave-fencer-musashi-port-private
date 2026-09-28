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
