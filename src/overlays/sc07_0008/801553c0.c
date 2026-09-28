/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801553C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32);
extern void func_8001D150(s32, s32);

void func_801553C0(s32 a0) {
    s32 *flags;
    flags = (s32 *)(a0 + 0x44);
    if ((*flags & 4) != 0 || (func_80029178(0x12F) & 0xFF) != 0) {
        *flags = *flags & 0xEFFFFFFF;
    } else {
        *flags = *flags | 0x10000000;
    }
    func_8001D150(*(s32 *)(*(s32 *)(a0 + 0x20) + 0x24), 0x15);
}
