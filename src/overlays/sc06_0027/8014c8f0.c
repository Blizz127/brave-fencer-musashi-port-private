/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C8F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct UnalignedPair {
    int a;
    int b;
} __attribute__((packed, aligned(1)));

void func_8014C8F0(s32 arg0) {
    *(struct UnalignedPair *)(arg0 + 0x15c) = *(struct UnalignedPair *)(arg0 + 0x90);
}
