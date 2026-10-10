/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801820D0[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_80170150(void *a0) {
    D_801820D0[*(u8 *)((s32)a0 + 0x216)](a0);
}
