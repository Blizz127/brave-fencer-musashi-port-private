/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171520 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct B16 { s32 w[4]; };
extern void func_8012A568(void (*a0)(void));
extern void *D_8011F738;
extern struct B16 D_800A5E88;
extern struct B16 D_800A5E98;
extern struct B16 D_800A5EA8;
extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_8017162C(void *a0);

void func_80171520(s32 a0) {
    u8 *v1;
    s32 p;
    func_801719A4(a0, 1);
    v1 = (u8 *)D_8011F738;
    *(struct B16 *)(v1 + 0x0) = D_800A5E88;
    *(struct B16 *)(v1 + 0x10) = D_800A5E98;
    *(struct B16 *)(v1 + 0x20) = D_800A5EA8;
    v1[0xE] = 0;
    v1[0xD] = 0;
    v1[0xC] = 0;
    v1[0x1E] = 0;
    v1[0x1D] = 0;
    v1[0x1C] = 0;
    v1[0x2E] = 0;
    v1[0x2D] = 0;
    v1[0x2C] = 0;
    p = *(s32 *)(a0 + 0x20);
    *(u16 *)(p + 0x2C) = *(u16 *)(p + 0x2C) | 0x20;
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x80) = (s32)v1;
    func_80171990((u8 *)a0);
    func_8017162C((void *)a0);
}
