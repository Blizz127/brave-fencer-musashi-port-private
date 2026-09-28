/* Exact retail overlay 0010 export [800CFAD0,800CFBBC), offset 0x20CD8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFAD0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_800CFAD0;
typedef struct { u8 b0, b1, b2, b3; } BYTES_800CFAD0;

void func_800CFAD0(void)
{
    extern u32 D_80114E7C;
    extern u32 D_80114E80;
    extern u8  D_80114E84;
    extern u8  D_80114E85;
    extern u8  D_80114E86;
    extern u8  D_80114E87;
    extern s16 D_80114E88;
    extern s16 D_80114E8A;
    extern u8  D_80114E8C;
    extern u8  D_80114E8D;
    extern s16 D_80114E8E;
    extern s16 D_80114E90;
    extern s16 D_80114E92;
    extern u8  D_800AA60C[];
    extern u16 D_800B9A02;

    u32 *ot;

    ((BYTES_800CFAD0 *)&D_80114E7C)->b3 = 5;
    D_80114E80 = 0xE1000085;
    D_80114E87 = 0x64;
    D_80114E84 = D_80114E85 = D_80114E86 = 0x80;
    D_80114E88 = -0x80;
    D_80114E8A = -0x48;
    D_80114E8E = 0x7800;
    D_80114E90 = 0x100;
    D_80114E92 = 0x90;
    D_80114E8C = 0;
    D_80114E8D = 0;

    ot = (u32 *)&D_800AA60C[D_800B9A02 << 14];

    ((P_TAG_800CFAD0 *)&D_80114E7C)->addr = *(u32 *)ot;
    *(u32 *)ot = (*(u32 *)ot & 0xFF000000u) | ((u32)&D_80114E7C & 0x00FFFFFFu);
}
