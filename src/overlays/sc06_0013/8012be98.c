/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012BE98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_800132BC(s32 a0, s32 a1);

void func_8012BE98(s32 arg0, u16 * arg1)
{
    s16 a[3];
    s16 b[3];
    a[0] = *(u16 *)((u8 *)arg0 + 0x6);
    a[1] = 0;
    a[2] = *(u16 *)((u8 *)arg0 + 0xE);
    b[0] = *(u16 *)((u8 *)arg1 + 0x0);
    b[1] = 0;
    b[2] = *(u16 *)((u8 *)arg1 + 0x4);
    func_800132BC((s32)a, (s32)b);
}
