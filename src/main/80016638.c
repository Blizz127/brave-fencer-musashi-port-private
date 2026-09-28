/* Exact retail word export for [80016638,800166E8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80016638 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *func_80010A08(s32 a0);

void func_80016638(void *a0, s32 a1, s32 a2)
{
    void *s2 = a0;
    s32 s1 = a1;
    s32 s0 = a2;
    void *v0;
    register u32 mask1 __asm__("$5");
    register u32 mask2 __asm__("$6");
    register u32 pv __asm__("$4");
    u32 v1;
    register u32 tmp __asm__("$2");

    v0 = func_80010A08(8);

    mask1 = 0xFFFFFF;
    {
        u32 one = 1;
        s0 = (s0 << 5) & 0x9FF;
        *(u8 *)((u8 *)v0 + 3) = (u8)one;
        __asm__ __volatile__("" : "=r"(one) : "0"(one));
    }
    s0 = s0 | 0xE1000000;

    s1 = s1 << 2;
    mask2 = 0xFF000000;

    *(u32 *)((u8 *)v0 + 4) = s0;

    /* First addPrim RMW: new primitive's link = OT slot's current low24,
     * primitive keeps its own top-byte tag. Mirrors func_80015D4C /
     * func_80016450's matched addPrim idiom in this same TU. */
    v1 = *(u32 *)((u8 *)s2 + 4);
    pv = *(u32 *)v0;
    v1 = *(u32 *)(s1 + v1);
    pv = pv & mask2;
    v1 = v1 & mask1;
    pv = pv | v1;
    *(u32 *)v0 = pv;

    /* Second addPrim RMW: OT slot := (OT slot's own top-byte tag) |
     * (new primitive's address, masked to low24) — head-insert the new
     * primitive into the OT chain. */
    v1 = *(u32 *)((u8 *)s2 + 4);
    s1 = s1 + v1;
    v1 = *(u32 *)s1;
    tmp = (u32)v0 & mask1;
    v1 = v1 & mask2;
    v1 = v1 | tmp;
    *(u32 *)s1 = v1;
}
