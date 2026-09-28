/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D330 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801966D2;
extern u8 D_80196746;
extern u8 D_801965FA;
extern u8 D_801966B4;
extern u8 D_801965D8;
extern u8 D_801965F9;
extern s32 D_801966B8;

void func_8013D330(void) {
    if ((D_801966D2 & 0xff) != D_80196746) {
        D_801966D2 = ((D_801966D2 & 0xff) < D_80196746) ? (D_801966D2 + 1) : (D_801966D2 - 1);
    }
    if ((D_801965FA & 0xff) != D_801966B4) {
        D_801965FA = ((D_801965FA & 0xff) < D_801966B4) ? (D_801965FA + 1) : (D_801965FA - 1);
    }
    if ((D_801965D8 & 0xff) != D_801965F9) {
        D_801965D8 = ((D_801965D8 & 0xff) < D_801965F9) ? (D_801965D8 + 1) : (D_801965D8 - 1);
    }
    D_801966B8 = 1;
}
