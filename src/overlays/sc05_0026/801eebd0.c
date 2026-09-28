/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EEBD0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801EEBD0(s32 a0, s16 a1, s16 a2, s16 a3, s32 *out)
{
    extern u8 D_80115158[];
    s32 i;
    s32 ret = 0;

    *out = 0x808080;
    a2 = D_80115158[a2 * 2];

    if (a1 < 5) {
        if (a1 > 0) {
            goto compute;
        }
        if (a1 == 0) {
            goto end;
        }
        goto compute;
    } else {
        if (a1 == 5) {
            goto end;
        }
    }
compute:
    i = a3;
    if (i < a2) {
        ret = *(s32 *)(a0 + i * 4);
    }
end:
    return ret;
}
