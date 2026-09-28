/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016EFC8,8016F094).
 * Offset 0x46E70 at overlay base 80128158. SHA256(span)=575e38d2f596ddccb75dc91f1c5f6abb78751981b7c497da9a8a6f1c442a7ef4.
 * STOP pc=8016efc8 (func_8016EFC8), CPU_BOUNDARY/REFUSED, ra=8016ef88.
 * Callee from burned func_8016EF78 (jal 0C05BBF2).
 * Donor shape: Druthulu shared/ov/func_8016EFC8.h (init OV state + D_80126D50 = *a0 | 0x04000000 | a1).
 * NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_8017AE2C / shared OV body.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016EFC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80126D6C;
extern s32 D_80126D54;
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
extern s32 D_80126D50;
extern void func_8012A568(void (*a0)(void));

s32 func_8016EFC8(s32 a0, s32 a1)
{
    s32 v1;
    s32 m;
    v1 = *(s32 *)a0;
    m = 0x4000000;
    D_80126D6C = 1;
    D_80126D54 = a0;
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
    D_800B9A17 = 0;
    D_80126D20 = 0;
    D_80126D50 = v1 | m | a1;
}
