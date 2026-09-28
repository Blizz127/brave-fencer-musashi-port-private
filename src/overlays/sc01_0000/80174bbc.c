/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174BBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_80174BBC(void *a0) {
    *(s32 *)((s32)a0 + 0xC) = 0x12C;
    *(s32 *)((s32)a0 + 0x14) = 0x12C;
    *(s16 *)((s32)a0 + 0x20) = 0x155;
    *(s16 *)((s32)a0 + 0x22) = 0x800;
    *(s16 *)((s32)a0 + 0x24) = 0;
    *(s16 *)((s32)a0 + 0x2E) = 0;
    *(s16 *)((s32)a0 + 0x30) = -0x28;
    *(s16 *)((s32)a0 + 0x32) = 0;
    *(s32 *)((s32)a0 + 0x54) = 0;
}
