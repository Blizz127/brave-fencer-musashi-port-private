/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E8630 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8018CDEC(void);
extern s32 D_801E7AAC;
extern s32 D_801E89F0;
extern s32 D_801E8A10;
extern s16 D_801E79D8;

void func_801E8630(void) {
    func_8018CDEC();
    if (D_801E79D8 == 0) {
        *(s32 *)(*(s32 *)&D_801E7AAC + 4) = (s32)&D_801E89F0;
    } else {
        *(s32 *)(*(s32 *)&D_801E7AAC + 4) = (s32)&D_801E8A10;
    }
}
