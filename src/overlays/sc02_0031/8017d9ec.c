/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D9EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u8 r; u8 g; u8 b; u8 pad; } Clr_8017C910_8017D9EC;
typedef struct { s32 w[8]; } Mtx8_8017C910_8017D9EC;
typedef struct { s16 x; s16 y; s16 z; s16 pad; } SVec_8017C910_8017D9EC;
typedef struct { SVec_8017C910_8017D9EC v[2]; Clr_8017C910_8017D9EC col[2]; s32 tag; s32 pad; } Prim_8017C910_8017D9EC;
extern void func_8012A568(void (*a0)(void));

void func_8017D9EC(void *a0)
{
    extern Mtx8_8017C910_8017D9EC aD800AE620 __asm__("D_800AE620");
    extern void aFunc80016A5C(void *arg0, void *arg1) __asm__("func_80016A5C");
    Prim_8017C910_8017D9EC prim;
    Mtx8_8017C910_8017D9EC mtx;
    s32 p;

    p = (s32)a0;
    if (*(s32 *)(p + 0x2C) != 0) {
        prim.v[0].y = *(u16 *)(p + 0xA) - 0x20;
        prim.v[1].y = *(u16 *)(p + 0xA) + 0x20;
    } else {
        prim.v[0].y = *(u16 *)(p + 0xA) + 0x20;
        prim.v[1].y = *(u16 *)(p + 0xA) - 0x20;
    }
    prim.v[0].x = *(u16 *)(p + 0x6);
    prim.v[0].z = *(u16 *)(p + 0xE);
    prim.v[1].x = *(u16 *)(p + 0x6);
    prim.v[1].z = *(u16 *)(p + 0xE);
    prim.col[0].b = 0;
    prim.col[0].g = 0;
    prim.col[0].r = 0;
    switch (*(u32 *)(p + 0x30)) {
    case 0:
        prim.col[1].r = 0xFF;
        prim.col[1].b = 0;
        prim.col[1].g = 0;
        break;
    case 1:
        prim.col[1].g = 0xFF;
        prim.col[1].b = 0;
        prim.col[1].r = 0;
        break;
    case 2:
        prim.col[1].b = 0xFF;
        prim.col[1].g = 0;
        prim.col[1].r = 0;
        break;
    case 3:
        prim.col[1].b = 0xFF;
        prim.col[1].g = 0xFF;
        prim.col[1].r = 0xFF;
        break;
    }
    mtx = aD800AE620;
    prim.tag = 0x50000000;
    aFunc80016A5C(&prim, &mtx);
}
