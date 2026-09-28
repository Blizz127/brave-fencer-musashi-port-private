/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80139BE0(int param_1)
{

    extern unsigned char D_8017D8CC[];
    int v;

    if ((*(unsigned int *)(param_1 + 8) & 0x2000) == 0) {
        int t = *(unsigned char *)(param_1 + 0x22) & 0x60;
        int h = *(unsigned short *)(param_1 + 0x18);
        unsigned int idx;

        __asm__("" : "=r"(t) : "0"(t));
        idx = (unsigned char)t;
        if (h < 7) {
            if (h >= 2) {
                v = D_8017D8CC[idx >> 5];
            } else {
                v = D_8017D8CC[0];
            }
        } else {
            v = D_8017D8CC[0];
        }
        *(short *)(param_1 + 0x2e) = 3;
        *(short *)(param_1 + 0x2c) = v;
    }
    *(short *)(param_1 + 0x34) = *(short *)(param_1 + 0x2c) * 6;
    {
        int x = *(short *)(param_1 + 0x2e);
        *(short *)(param_1 + 0x36) = x * 12 + (x - 1) * 2;
    }
}
