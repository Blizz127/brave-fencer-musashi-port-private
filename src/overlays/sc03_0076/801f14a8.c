/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F14A8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801F14A8(val, n, dst, flag)
unsigned int val;
short n;
unsigned short *dst;
short flag;
{
    extern unsigned short *D_801F31E8[];
    register unsigned int d __asm__("$3");
    short i;
    int idx;

    for (i = 0; i < n; i++) {
        d = val >> 28;
        idx = d;
        if (flag != 0) {
            if (d != 0) {
                flag = 0;
            } else {
                idx = 10;
            }
        }
        val <<= 4;
        *dst = *D_801F31E8[idx];
        dst++;
    }
}
