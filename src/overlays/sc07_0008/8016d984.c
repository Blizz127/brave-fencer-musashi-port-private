/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D984 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146C3C();
extern void func_800D22E4(s32 a0);
extern void func_8012A568(void (*a0)(void));

void func_8016D984(s32 *a0) {
    if ((--*(s32 *)((char *)a0 + 0x1C)) == 0) {
        func_80146C3C();
    } else {
        func_800D22E4((s32)a0);
        *(s32 *)((char *)a0 + 0x10) -= *(s32 *)((char *)a0 + 0x10) >> 4;
        *(s32 *)((char *)a0 + 0x14) -= *(s32 *)((char *)a0 + 0x14) >> 4;
        *(s32 *)((char *)a0 + 0x18) -= *(s32 *)((char *)a0 + 0x18) >> 4;
    }
}
