/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB21C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 a; s32 b[4]; } OtBlk_8018A974_801AADA8;
typedef struct {
    u8  addr[3];
    u8  len;
    u8  r0, g0, b0, code;
    s16 x0, y0;
    s16 x1, y1;
    s16 x2, y2;
    s16 x3, y3;
} F4_801AB21C;

void func_801AB21C(s32 a0, s32 a1, s32 a2, s32 a3)
{
    extern void *func_80010A08(s32);
    extern void func_80016638(void *a0, s32 a1, s32 a2);
    extern u16 D_800B9A02;
    extern OtBlk_8018A974_801AADA8 D_800A651C[];
    extern u8 D_800A6518[];
    extern OtBlk_8018A974_801AADA8 D_800AE7BC[];
    extern u8 D_800AE7B8[];

    F4_801AB21C *p;
    u32 *ot;
    s32 idx;

    p = (F4_801AB21C *)func_80010A08(0x18);

    p->len = 5;
    p->code = 0x2A;
    p->r0 = a1;
    p->g0 = a2;
    p->b0 = a3;
    p->x0 = p->x2 = -160;
    p->x1 = p->x3 = 160;
    p->y0 = p->y1 = -120;
    p->y2 = p->y3 = 120;
    idx = a0 & 0xFFFF;
    if (idx != 0) {
        register u32 m24 = 0x00FFFFFF;
        register u32 mFF = 0xFF000000;
        register s32 i4 __asm__("$6") = idx * 4;
        register u32 pv __asm__("$4");
        pv = *(u32 *)p;
        *(u32 *)p = (pv & mFF) | (*(u32 *)(i4 + D_800A651C[D_800B9A02].a) & m24);
        i4 += D_800A651C[D_800B9A02].a;
        *(u32 *)i4 = (*(u32 *)i4 & mFF) | ((u32)p & m24);
        func_80016638(&D_800A6518[D_800B9A02 * 20], idx, 1);
    } else {
        register u32 m24 = 0x00FFFFFF;
        register u32 pv __asm__("$3");
        pv = *(u32 *)p;
        *(u32 *)p = (pv & 0xFF000000) | (*(u32 *)D_800AE7BC[D_800B9A02].a & m24);
        __asm__ __volatile__("" : "=r"(pv));   /* zero-byte 2nd SET: kills the sched1 birthing boost */
        ot = (u32 *)D_800AE7BC[D_800B9A02].a;
        *ot = (*ot & 0xFF000000) | ((u32)p & m24);
        func_80016638(&D_800AE7B8[D_800B9A02 * 20], 0, 1);
    }
}
