/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016EE94 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801726D0(void *a0);
extern s32 D_80126D50;
extern s32 D_80126B58;
extern s32 D_80126D54;
extern u8 D_80126D6C;
extern u8 D_80126D6D;
extern u8 D_80126D6E;
extern s32 D_80126D5C;
extern s32 D_80126D60;
extern s16 D_80126D64;
extern s16 D_80126D66;
extern s16 D_80126D68;
extern s16 D_80126D6A;
extern u8 D_80126D1A;
extern s32 D_80127058;
extern s32 D_8012705C;
extern s32 D_80127060;
extern s32 D_80127064;
extern s32 D_80127068;
extern s32 D_8012706C;
extern s32 D_80127070;
extern s32 D_80127074;
extern u8 D_800B9A17;
extern s16 D_80126D20;
extern void func_8012A568(void (*a0)(void));

void func_8016EE94(s32 a0, s32 a1)
{
    a0 = a0 | 0x4000000;
    D_80126D50 = a0 | a1;
    D_80126D54 = 0;
    D_80126D6C = 0;
    D_80126D6D = 0;
    D_80126D6E = 0;
    D_80126D5C = 0;
    D_80126D60 = 0;
    D_80126D64 = 0;
    D_80126D66 = 0;
    D_80126D68 = 0;
    D_80126D6A = 0;
    D_80126D1A = 0;
    D_80127058 = 0;
    D_8012705C = 0;
    D_80127060 = 0;
    D_80127064 = 0;
    D_80127068 = 0;
    D_8012706C = 0;
    D_80127070 = 0;
    D_80127074 = 0;
    func_801726D0(&D_80126B58);
    D_800B9A17 = 0;
    D_80126D20 = 0;
}
