/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801508B4 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_8014A2E4(s32 a0);
void func_8014A380(s32 a0, s32 a1);
extern s32 func_8014A2E4(s32 a0);
extern void func_8014A380(s32 a0, s32 a1);

s32 func_801508B4(s32 a0)
{
    s32 r;
    r = func_8014A2E4(a0);
    if (r != 0) {
        func_8014A380(a0, r);
        return 1;
    }
    return 0;
}
