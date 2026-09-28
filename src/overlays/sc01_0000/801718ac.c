/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801718AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 D_80126B58;
extern s32 D_80126D50;
extern s32 D_80126D54;
extern u8 D_80126D6C;
extern void func_80171A1C(u8 *a0);

void func_801718AC(void *arg0) {
    D_80126D54 = (s32)arg0;
    D_80126D6C = 0;
    D_80126D50 = *(s32 *)arg0 | (D_80126D50 & 0x7F000000);
    func_80171A1C((u8 *)&D_80126B58);
}
