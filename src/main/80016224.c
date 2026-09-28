/* Exact retail word export for [80016224,80016450); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80016224 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_800AF7BE;
extern u16 D_800AF7BC;
extern u8 D_800A6518[];
extern u16 D_800B9A02;
extern void *func_80010A08(s32 a0);
extern void func_80016638(void *a0, s32 a1, s32 a2);
extern u8 D_800AE7B8[];

void func_80016224(s32 a0, s32 a1)
{
    extern struct { s32 a; s32 b[4]; } D_800A651C[];
    extern struct { s32 a; s32 b[4]; } D_800AE7BC[];
    extern u8 D_800AE7B8[];

    void *p;
    s16 xl;
    s16 xr;
    s16 yl;
    s16 yr;
    s32 idx;

    p = func_80010A08(0x18);
    *(u8 *)((u8 *)p + 3) = 5;
    *(u8 *)((u8 *)p + 7) = 0x2A;
    *(u8 *)((u8 *)p + 6) = a0;
    *(u8 *)((u8 *)p + 5) = a0;
    *(u8 *)((u8 *)p + 4) = a0;
    xl = -(s32)D_800AF7BC / 2;
    *(s16 *)((u8 *)p + 0x10) = xl;
    *(s16 *)((u8 *)p + 0x08) = xl;
    __asm__ __volatile__("" ::: "memory");
    xr = D_800AF7BC / 2;
    *(s16 *)((u8 *)p + 0x14) = xr;
    *(s16 *)((u8 *)p + 0x0C) = xr;
    yl = -(s32)D_800AF7BE / 2;
    *(s16 *)((u8 *)p + 0x0E) = yl;
    *(s16 *)((u8 *)p + 0x0A) = yl;
    __asm__ __volatile__("" ::: "memory");
    yr = D_800AF7BE / 2;
    idx = a1 & 0xFFFF;
    *(s16 *)((u8 *)p + 0x16) = yr;
    *(s16 *)((u8 *)p + 0x12) = yr;
    if (idx != 0) {
        register u32 m24 __asm__("$7") = 0x00FFFFFF;
        register u32 mFF __asm__("$8") = 0xFF000000;
        register s32 i4 __asm__("$6") = idx * 4;
        register u32 pv __asm__("$4");
        pv = *(u32 *)p;
        *(u32 *)p = (pv & mFF) | (*(u32 *)(i4 + D_800A651C[D_800B9A02].a) & m24);
        i4 += D_800A651C[D_800B9A02].a;
        *(u32 *)i4 = (*(u32 *)i4 & mFF) | ((u32)p & m24);
        func_80016638(&D_800A6518[D_800B9A02 * 20], idx, 2);
    } else {
        register u32 m24 = 0x00FFFFFF;
        register u32 pv __asm__("$3");
        u32 *ot;
        pv = *(u32 *)p;
        *(u32 *)p = (pv & 0xFF000000) | (*(u32 *)D_800AE7BC[D_800B9A02].a & m24);
        __asm__ __volatile__("" : "=r"(pv));
        ot = (u32 *)D_800AE7BC[D_800B9A02].a;
        *ot = (*ot & 0xFF000000) | ((u32)p & m24);
        func_80016638(&D_800AE7B8[D_800B9A02 * 20], 0, 2);
    }
}
