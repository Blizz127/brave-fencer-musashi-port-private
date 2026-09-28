/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2B64 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s32 D_800DB52C;
extern s32 D_800DB5B0;
extern void func_800D2E64();

void *func_800D2B64(void *arg0) {
    register void *base asm("$16");
    s32 *dst;
    s32 i;

    base = arg0;

    dst = D_800DB530;
    i = 15;
    do {
        *dst++ = *(s32 *) arg0;
        arg0 = (char *) arg0 + 4;
    } while (--i != -1);

    dst = D_800DB570;
    arg0 = (char *) base + 0x40;
    i = 15;
    do {
        *dst++ = *(s32 *) arg0;
        arg0 = (char *) arg0 + 4;
    } while (--i != -1);

    func_800D2E64((s32) &D_800DB52C, 0x20);
    func_800D2E64((s32) &D_800DB5B0, 0x20);
    return base;
}
