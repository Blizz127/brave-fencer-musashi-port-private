/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017DD10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188900[])(void *);
extern void func_80162D28(s32*);

void func_8017DD10(void *a0) {
        D_80188900[*(u16 *)((s32)a0 + 0x2)](a0);
        if (*(s32 *)((s32)a0 + 0x20) != 0) {
            ((void (*)(void *))func_80162D28)(a0);
        }
    }
