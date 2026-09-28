/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCDC4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32 arg0);
extern void func_801599A4(void *arg0);
extern void func_80159B3C(void *arg0);
extern s32 func_80161208();

void func_800CCDC4(s32 a0)
{
    *(s32 *)(a0 + 0x44) |= 2;
    if (func_80146E98(a0) != 0) {
        func_801599A4((void *)a0);
        func_80159B3C((void *)a0);
    } else {
        func_80161208((void *)a0);
    }
}
