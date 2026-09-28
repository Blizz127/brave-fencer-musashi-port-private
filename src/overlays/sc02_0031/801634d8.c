/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801634D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_80163534(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, u16 * a5);
extern char D_801B5D48[8];
extern void *memcpy(void *dst, const void *src, unsigned int n);

void func_801634D8(s32 param_1, u16 param_2, u16 param_3, s32 param_4, u16 param_5)
{
    char buf[8];

    memcpy(buf, D_801B5D48, 8);
    ((void (*)(s32, u16, u16, s32, u16, s32))func_80163534)(param_1, param_2, param_3, param_4, param_5, (s32)buf);
}
