/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172358 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct U8 {
    char b[8];
} __attribute__((aligned(1)));
extern void func_8012A568(void (*a0)(void));

void func_80172358(u8 *a0, u8 *a1) {
    *(u16 *)(a0 + 6) = *(u16 *)(a1 + 0);
    *(u16 *)(a0 + 0xA) = *(u16 *)(a1 + 2);
    *(u16 *)(a0 + 0xE) = *(u16 *)(a1 + 4);
    *(struct U8 *)(a0 + 0x90) = *(struct U8 *)(a1 + 0);
    *(struct U8 *)(a0 + 0x88) = *(struct U8 *)(a0 + 0x90);
}
