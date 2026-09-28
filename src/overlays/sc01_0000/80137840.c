/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80137840 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139634(void *);
extern void func_80139DC8(void);

void func_80137840(s32 a0) {
    s32 s0 = a0;
    *(u8 *)(s0 + 0xC) = 1;
    *(u8 *)(s0 + 0x23) = 1;
    *(s16 *)(s0 + 0x1A) = 1;
    *(s16 *)(s0 + 0x2A) = 0x1000;
    *(s16 *)(s0 + 0x28) = 0x1000;
    *(s16 *)(s0 + 0x2C) = 0x24;
    *(s16 *)(s0 + 0x2E) = 3;
    *(s16 *)(s0 + 0x4) = 0;
    *(s16 *)(s0 + 0x6) = 0;
    *(s16 *)(s0 + 0x1C) = 0;
    *(s16 *)(s0 + 0x10) = 0;
    *(s16 *)(s0 + 0x14) = 0;
    *(s16 *)(s0 + 0x12) = 0;
    *(s16 *)(s0 + 0x16) = 0;
    *(s16 *)(s0 + 0x30) = 0;
    *(s16 *)(s0 + 0x32) = 0;
    *(s16 *)(s0 + 0x34) = 0;
    *(s16 *)(s0 + 0x36) = 0;
    *(u8 *)(s0 + 0x22) = 0;
    *(u8 *)(s0 + 0x20) = 0;
    *(s32 *)(s0 + 0x40) = 0;
    *(s8 *)(s0 + 0x1F) = -1;
    *(s16 *)(s0 + 0x44) = 0;
    *(s16 *)(s0 + 0x46) = 0;
    *(s16 *)(s0 + 0x48) = 0;
    *(s16 *)(s0 + 0x4A) = 0;
    func_80139634((void *)s0);
    *(u8 *)(s0 + 0xD) = 0;
    func_80139DC8();
}
