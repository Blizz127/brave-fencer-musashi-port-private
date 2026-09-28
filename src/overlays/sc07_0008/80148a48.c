/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148A48 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80148A48(s32 a0) {
    u8 v1;
    v1 = *(u8*)(a0 + 0xA9);
    switch (v1) {
    case 0x41:
        return *(u16*)(a0 + 0xAA) & 0x2000;
    case 0x53:
    case 0x73:
        return *(u8*)(a0 + 0xAE) >= 0xC1;
    }
    return 0;
}
