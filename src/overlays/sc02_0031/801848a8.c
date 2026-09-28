/* Complete SC02 retail span [801848A8,801848E4).
 * D_801AB158 dispatch (STOP).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801848A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801AB158[])(void);

void func_801848A8(void *a0) {
    D_801AB158[*(u16 *)((s32)a0 + 0x2)]();
}
