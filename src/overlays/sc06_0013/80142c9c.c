/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142C9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012CBF4(s32 a0);

void func_80142C9C(s32 * arg0)
{
    u32 uVar1;
    if (*(s16 *)((u8 *)arg0 + 0x102) < 2) {
        uVar1 = ((s32 (*)(void))func_8012CBF4)();
        if (0x180000 < *(s32 *)((u8 *)arg0 + 0x14)) {
            *(s32 *)((u8 *)arg0 + 0x14) = 0x180000;
        }
        if (((uVar1 & 0x6000) != 0) || (0x100 < *(s16 *)((u8 *)arg0 + 0xA))) {
            if (*(s16 *)((u8 *)arg0 + 0x102) == 0) {
                *(s32 *)((u8 *)arg0 + 0x14) = 0xFFF80000;
            }
            *(s16 *)((u8 *)arg0 + 0x102) = *(s16 *)((u8 *)arg0 + 0x102) + 1;
        }
    }
}
