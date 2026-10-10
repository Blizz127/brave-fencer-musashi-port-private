/* Complete SC02 retail span [80183314,80183458).
 * Live STOP after 832F4; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80183314 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801893D4[])(void *);
extern s32 func_80183B90(void);

void func_80183314(void *a0) {
    D_801893D4[*(u16 *)((s32)a0 + 0x2)](a0);
    if ((*(u16 *)((s32)a0 + 0x100) & 0x10) && func_80183B90() == 1) {
        *(u16 *)((s32)a0 + 0x100) &= ~0x10;
    }
}
