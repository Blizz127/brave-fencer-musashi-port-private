/* Complete SC02 retail span [80182848,80182994).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182848 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8017BEBC(s32 a0, s16 *a1, s16 a2);
extern s32 func_8005C49C(void);
typedef struct {
    s16 f0;
    s16 f1;
    s16 f2;
    s16 f3;
} Spawn8_80182848;

void func_80182848(void *a0, u8 *a1, s32 a2, s32 a3, s32 a4) {
    Spawn8_80182848 sp;
    s32 i;
    s32 t;
    s32 m;
    s32 b1;
    s32 b2;

    sp = *(Spawn8_80182848 *)a1;
    for (i = 0; i < a2; i++) {
        t = func_8005C49C() % 320;
        b1 = *(s16 *)a1;
        sp.f0 = (func_8005C49C() & 1) ? b1 + t : b1 - t;
        if (a3 != 0) {
            m = func_8005C49C() % 64;
            b2 = *(s16 *)((s32)a1 + 4);
            sp.f2 = (func_8005C49C() & 1) ? b2 + m : b2 - m;
        }
        func_8017BEBC(a0, (s16 *)&sp, (s16)a4);
    }
}
