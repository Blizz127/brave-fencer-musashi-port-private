/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B8E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { unsigned char b[8]; } S8_8017B8E8;
extern s16 D_801965AC;
extern s16 D_801965A4;

s32 func_8017B8E8(s32 src) {
    (*(S8_8017B8E8 *)&D_801965AC) = ((S8_8017B8E8 *)src)[0];
    (*(S8_8017B8E8 *)&D_801965A4) = ((S8_8017B8E8 *)src)[1];
}
