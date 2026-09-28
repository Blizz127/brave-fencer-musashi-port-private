/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ADBB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801ADBB0(s32 x, s32 y, s32 z)
{
    extern u8 *func_8012913C(s32 a0);

    register s32 tx __asm__("$18") = x;
    register s32 ty __asm__("$19") = y;
    register s16 dup __asm__("$16") = z;
    u8 *work;

    work = func_8012913C(0x74);

    if (work != NULL) {
        *(u16 *)(work + 0x2C) = dup;
        *(u16 *)(*(s32 *)(work + 0x20) + 0x10) = tx;
        *(u16 *)(*(s32 *)(work + 0x20) + 0x12) = ty;
        *(u16 *)(*(s32 *)(work + 0x20) + 0x14) = (s16)z * 0x300;
    }
}
