/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA9D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801AA9D4(s32 a0, s32 a1) {
    extern u8 *func_8012913C(s32 a0);

    typedef struct { u16 w0, w1, w2, w3; } Blk8;

    s32 work;
    s32 ptr;

    work = (s32)func_8012913C(0x71);

    if (a0 != 0) {
        *(u16 *)(work + 0x6) = *(u16 *)(a0 + 0x6);
        *(u16 *)(work + 0xA) = *(u16 *)(a0 + 0xA);
        *(u16 *)(work + 0xE) = *(u16 *)(a0 + 0xE);
        ptr = *(s32 *)(work + 0x20);
        *(Blk8 *)(ptr + 0x10) = *(Blk8 *)a1;
        *(u16 *)(work + 0x30) = 5;
        *(u16 *)(work + 0x32) = 1;
        *(u32 *)(work + 0x34) = 0x180F0F0;
    }
}
