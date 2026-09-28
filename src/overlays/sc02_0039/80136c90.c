/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80136C90 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { char s[10]; } S10_80136C90;

s32 func_80136C90()
{
    extern void func_8001534C(int, void *, int, int, int, int);
    extern S10_80136C90 D_8019EA30;

    S10_80136C90 buf = D_8019EA30;
    func_8001534C(0, &buf, 0x78, 0x10, 0, 0);
}
