/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C8C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct up { int a; int b; } __attribute__((packed));

void func_8014C8C8(s32 dst, s32 * src)
{
    *(struct up *)(dst + 0x15c) = *(struct up *)(src + 0);
    *(s16 *)(dst + 0x162) = 0;
}
