/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014891C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_8014891C(s32 a0) {
    u8 v1;
    v1 = *(u8*)(a0 + 0xA9);
    switch (v1) {
    case 0x41:
        return *(u16*)(a0 + 0xAA) & 0x1000;
    case 0x53:
    case 0x73:
        return (*(u16*)(a0 + 0xAE) >> 8) < 0x40;
    }
    return 0;
}
