/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80145A2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern void func_800D185C(u8 *a0);
extern void func_80145B24(void);
extern u8 D_80181194;
extern u8 D_80181074;
extern u8 D_80181050;
extern u8 D_8018102C;
extern u8 D_80181170;
extern u8 D_8018114C;
extern u8 D_80181008;
extern u8 D_80181128;

void func_80145A2C(void) {
    s32 v;
    void *p;

    v = func_80029504();
    if (v >= 0x6A4) {
        p = &D_80181194;
        /* §5a cross-jump barrier — LOAD-BEARING: keeps this D_80181194 load from being
         * tail-merged with the v>=0x384 D_80181194 load below (emits zero machine code). */
        __asm__ __volatile__("" ::: "memory");
    } else if (v >= 0x5DC) {
        p = &D_80181074;
    } else if (v >= 0x578) {
        p = &D_80181050;
    } else if (v >= 0x514) {
        p = &D_8018102C;
    } else if (v >= 0x384) {
        p = &D_80181194;
    } else if (v >= 0x258) {
        p = &D_80181170;
    } else if (v >= 0xC8) {
        p = &D_8018114C;
    } else {
        p = &D_80181008;
        if (v >= 0xA) {
            p = &D_80181128;
        }
    }
    ((void (*)(void *))func_800D185C)(p);
    func_80145B24();
}
