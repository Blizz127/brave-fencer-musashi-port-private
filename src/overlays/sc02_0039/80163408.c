/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80163408 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *memcpy(void *dst, const void *src, u32 n);

s32 func_80163408(s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    extern int func_8016345C(int, unsigned short, int, unsigned short, void *);
    extern unsigned char D_8019F3FC[8];

    unsigned char sp18[8];
    memcpy(sp18, D_8019F3FC, 8);
    return func_8016345C(((int)param_1), ((int)param_2), ((int)param_3), ((int)param_4), sp18);
}
