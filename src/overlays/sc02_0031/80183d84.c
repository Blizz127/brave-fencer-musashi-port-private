/* Complete SC02 retail span [80183D84,80183DC0).
 * Live STOP 83AC8 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80183D84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80189420[])(void *);

void func_80183D84(void *a0) {
    D_80189420[*(u16 *)((s32)a0 + 0x2)](a0);
}
