/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171D78 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8017248C(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_80171EC8(s32 a0);
extern void func_80146D90(s32 a0);

s32 func_80171D78(s32 a0, s32 a1)
{
    s32 ret;
    s32 ang;
    s32 p;
    ret = func_8017248C(a0, a1);
    if (ret != 0) {
        func_80146D90(a0);
        return ret;
    }
    ang = func_8004CFEC(*(s16 *)(a1 + 0) - *(s16 *)(a0 + 6),
                 *(s16 *)(a1 + 4) - *(s16 *)(a0 + 0xE));
    ang = (ang + 0x800) & 0xFFF;
    p = *(s32 *)(a0 + 0x20);
    *(s16 *)(p + 0x12) = ang;
    func_80171EC8(a0);
    return 0;
}
