/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801722CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80172664(s32 *a0);

void func_801722CC(s32 *a0) {
    if (func_80172664(a0) == 0) {
        *(s16 *)((u8 *)a0 + 0xAC) = 0x40;
        *(s16 *)((u8 *)a0 + 0xAA) = 0x40;
    }
}
