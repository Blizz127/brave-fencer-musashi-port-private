/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB874 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB874(s32 arg0)
{
    register u8 *p __asm__("$4");
    s16 t;
    s32 d;
    u8 x;

    p = *(u8 **)(arg0 + 0x20);
    t = p[0x24];
    d = t - 4;
    __asm__ volatile("" : : "r"(t));
    if (d < 0)
        t = 0;
    else
        t = d;
    x = t;
    p[0x26] = x;
    p[0x25] = x;
    p[0x24] = x;
}
