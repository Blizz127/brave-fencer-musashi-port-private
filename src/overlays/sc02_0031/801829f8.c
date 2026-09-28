/* Complete SC02 retail span [801829F8,80182A7C).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801829F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern s32 D_80188FD0;

void func_801829F8(void *a0) {
    s32 v0;
    s32 v1;
    s32 ptr;
    unsigned short a1;

    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
        return;
    }
    func_8001C214(v0, 0);
    *(unsigned short *)((s32)a0 + 0x5C) = 0xCC00;
    v1 = (s32)&D_80188FD0 | 0x40000000 | 0x20000000;
    ptr = *(s32 *)((s32)a0 + 0x64);
    a1 = *(unsigned short *)(ptr + 0x36);
    *(s32 *)((s32)a0 + 0x58) = v1;
    *(unsigned short *)((s32)a0 + 0x2) = 1;
    *(unsigned short *)((s32)a0 + 0xFC) = a1;
}
