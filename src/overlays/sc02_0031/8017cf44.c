/* Complete SC02 retail span [8017CF44,8017CF98).
 * SC02 7CBxx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017CF44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8017C180(s32 a0, s32 a1);
extern s32 func_8005C49C(void);

void func_8017CF44(s32 a0) {
    extern int func_80178970(void);
    extern void func_80178D18(void);
    s32 rand_val = func_8005C49C();

    func_8017C180(a0, rand_val & 0xF);
    if (((s32 (*)(s32))func_80178970)(a0) == 0) {
        return;
    }
    ((void (*)(s32))func_80178D18)(a0);
    *(s16 *)(a0 + 0x2) = 1;
}
