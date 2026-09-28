/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2AD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800DB530[];
extern s32 D_800DB570[];
extern s32 D_800DB5B4[];

void *func_800D2AD8(void *a0) {
    s32 i;
    s32 *d;
    s32 *s;

    d = (s32 *) a0;
    s = D_800DB530;
    for (i = 15; i != -1; i--) {
        *d++ = *s++;
    }
    d = (s32 *) ((s32) a0 + 0x40);
    s = D_800DB570;
    for (i = 15; i != -1; i--) {
        *d++ = *s++;
    }
    d = (s32 *) ((s32) a0 + 0x80);
    s = D_800DB5B4;
    for (i = 31; i != -1; i--) {
        *d++ = *s++;
    }
    return a0;
}
