/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175590 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801757A0(s32 a0);
extern short D_800B9A02;

void func_80175590(void *arg0) {
    u8 temp_a0;
    register s16 temp_v1 __asm__("$3");
    s32 temp_v0;
    temp_a0 = *(u8 *)((u8 *)arg0 + 5);
    temp_v0 = *(u8 *)((u8 *)arg0 + 6) - temp_a0;
    temp_v1 = -(temp_v0 & 0xFF);
    *(u8 *)((u8 *)arg0 + 6) = (u8)temp_v0;
    __asm__ __volatile__("" : : : "memory");
    temp_v0 = *(u8 *)((u8 *)arg0 + 6);
    *(u8 *)((u8 *)arg0 + 5) = (u8)(temp_a0 + 0xFF);
    *(s16 *)((u8 *)arg0 + 0x10) = temp_v1;
    *(s16 *)((u8 *)arg0 + 0xC) = temp_v1;
    *(s16 *)((u8 *)arg0 + 0x16) = (s16)temp_v0;
    *(s16 *)((u8 *)arg0 + 0x12) = (s16)temp_v0;
    *(s16 *)((u8 *)arg0 + 0xE) = (s16)temp_v0;
    *(s16 *)((u8 *)arg0 + 0x14) = (s16)temp_v0;
    func_801757A0((s32)D_800B9A02);
    if (*(u8 *)((u8 *)arg0 + 5) == 0) {
        *(u8 *)((u8 *)arg0 + 8) = 0;
        *(u8 *)((u8 *)arg0 + 1) = (u8)(*(u8 *)((u8 *)arg0 + 1) + 1);
    }
}
