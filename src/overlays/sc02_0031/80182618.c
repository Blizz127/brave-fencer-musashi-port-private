/* Complete SC02 retail span [80182618,80182674).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182618 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80029124(s32 a0, s32 a1);
extern void func_80175414(s32 _arg0);

s32 func_80182618(s32 a0)
{
    s32 s0 = a0;

    if (func_80178970() != 1) {
        goto ret0;
    }
    ((void (*)(s32))func_80178D18)(a0);
    *(u16 *)(s0 + 2) = 5;
    func_80029124(0x9C, 1);
    ((void (*)(void))func_80175414)();
    return 1;
ret0:
    return 0;
}
