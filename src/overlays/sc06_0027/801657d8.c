/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801657D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80078E94;
extern s32 D_80078E9C;
extern s32 D_80078EA0;
extern s32 D_80078EA4;
extern s32 D_80078EA8;
extern u8 D_80078EBB;
extern s32 D_80078ECC;
extern s32 D_80078ED0;
extern s32 D_80078ED4;
extern s32 D_80078ED8;
extern s32 D_80078EDC;
extern u8 D_80078EE0;

void func_801657D8(void) {
    D_80078ECC = D_80078E94;
    D_80078ED0 = D_80078E9C;
    D_80078ED4 = D_80078EA0;
    D_80078ED8 = D_80078EA4;
    D_80078EDC = D_80078EA8;
    D_80078EE0 = D_80078EBB;
}
