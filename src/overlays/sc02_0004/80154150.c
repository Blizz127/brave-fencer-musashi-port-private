/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80154150 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154190(u8 *a0, s32 a1);

void func_80154150(s32 a0, s32 a1)
{
    if (*(s32 *)(a0 + 0xB4) != ((s32 *)*(s32 *)(a0 + 0xB0))[a1]) {
        func_80154190(a0, a1);
    }
}
