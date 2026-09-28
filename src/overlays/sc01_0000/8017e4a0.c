/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E4A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8017E4A0(void)
{
    register u8 *p __asm__("$3");
    register u32 u __asm__("$2");
    register u32 w __asm__("$4");
    register u32 mlo __asm__("$5");
    register u32 mhi __asm__("$6");
    register u32 ent __asm__("$4");
    register u32 c64 __asm__("$2");
    s32 frame_pad[2];
    extern u8 *D_800A5E60;
    extern s16 D_800B9A02;
    extern u8 D_800A6614[];

    (void)&frame_pad;
    w = 0xE100001E;
    mlo = 0xFFFFFF;
    __asm__ __volatile__("":::"memory");

    p = D_800A5E60;
    mhi = 0xFF000000;
    *(s8 *)(p + 3) = 5;
    __asm__ __volatile__("");
    __asm__ __volatile__("li\t%0,0x64\n\tsw\t%1,4(%2)"
                         : "=&r"(c64)
                         : "r"(w), "r"(p)
                         : "memory");
    *(s8 *)(p + 0xB) = c64;
    w = 0x80;
    *(s16 *)(p + 0xC) = -0x40;
    *(s16 *)(p + 0xE) = 0x50;
    *(s16 *)(p + 0x12) = 0x40D7;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x20;
    *(s16 *)(p + 0x14) = 0x80;
    *(s8 *)(p + 0xA) = w;
    *(s8 *)(p + 0x9) = w;
    *(s8 *)(p + 0x8) = w;
    *(s8 *)(p + 0x10) = 0;
    *(s8 *)(p + 0x11) = w;
    *(s16 *)(p + 0x16) = 0x10;

    u = D_800B9A02 & 0xFFFF;
    w = *(u32 *)p;
    u = *(u32 *)(D_800A6614 + (u << 14));
    w = (w & mhi) | (u & mlo);
    *(u32 *)p = w;

    u = (u32)D_800A6614;
    ent = (u32 *)(u + ((D_800B9A02 & 0xFFFF) << 14));
    mlo = (u32)p & mlo;
    u = *(u32 *)ent;
    p += 0x18;
    D_800A5E60 = p;
    u = (u & mhi) | mlo;
    *(u32 *)ent = u;
}
