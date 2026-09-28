/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A072C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012C588(s32, s32);
extern s32 D_801F1FD8;
extern u16 D_801F43C0;
extern s32 D_801F436C[];

void func_801A072C(s32 arg0) {
    *(s16 *)(arg0 + 0x2) = 8;
    *(s32 *)(arg0 + 0x1C) = 0x80;
    *(s32 *)(arg0 + 0xE4) = 0x50;
    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x24) = (s32)D_801F436C;
    func_8012A828(arg0, &D_801F1FD8);
    D_801F43C0 = 0x11;
    func_8012C588(0x3D0, arg0);
}
