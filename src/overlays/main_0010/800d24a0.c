/* Exact retail overlay 0010 export [800D24A0,800D25FC), offset 0x236A8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D24A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800596F4(s32 arg0);
extern void func_8002D4C8(s32 arg0, s32 arg1);
extern u8 D_80115110[];
typedef struct { s32 f0; } E4;
extern u8 D_800B9A13;

void func_800D24A0(s16 arg0) {
    extern void func_80018FC8(void);
    extern void func_800596F4(s32);
    extern void func_8002D4C8(s32, s32);
    extern u16 D_800B9A02;
    extern u8 D_800B9A13;
    extern u8 D_800A6518[];
    extern u8 D_8007BA70[];
    extern u8 D_800856B0[];
    extern u16 D_80115112;
    extern u16 D_8011512A;
    extern u16 D_80115124;
    extern u8 D_80115110[];
    extern u16 D_80115114;
    extern u8 *D_801151C8;
    extern u8 *D_801151CC;
    extern E4 D_80115168[];

    u16 i;
    u32 *src;
    u32 *dst;
    u16 *v;
    char *p;

    func_80018FC8();
    func_800596F4(0);

    src = (u32 *)&D_800A6518[(D_800B9A02 ^ 1) * 20];
    dst = (u32 *)&D_800A6518[D_800B9A02 * 20];
    for (i = 0; i < 5; i++) {
        *dst++ = *src++;
    }

    v = &D_80115112;
    *v = 0;
    D_8011512A = 0;
    D_80115124 = 0;
    (*(u16 *)D_80115110) = arg0;
    D_800B9A13 = arg0 + 1;
    D_80115114 = D_800B9A02;
    D_801151C8 = &D_8007BA70[D_800B9A02 * 80000];
    D_801151CC = &D_800856B0[D_800B9A02 * 80000];

    i = 0;
    p = (char *)v - 2;
    do {
        *(s32 *)(p + (s16)i * 4 + 0x78) = 0;
        D_80115168[(s16)i].f0 = 0;
        i++;
    } while ((s16)i < 8);

    func_8002D4C8(0x14, 0);
}
