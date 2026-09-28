/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80145934 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern u8 D_8018050C;
extern u8 D_8018047C;
extern u8 D_80180458;
extern u8 D_80180434;
extern u8 D_801804E8;
extern u8 D_801804C4;
extern u8 D_801804A0;
extern u8 D_80180410;

void func_80145934(void) {
    s32 v;
    void *p;

    v = func_80029504();
    if (v >= 0x6A4) {
        p = &D_8018050C;
        /* §5a cross-jump barrier — LOAD-BEARING: keeps this D_8018050C load from being
         * tail-merged with the v>=0x384 D_8018050C load below (emits zero machine code). */
        __asm__ __volatile__("" ::: "memory");
    } else if (v >= 0x5DC) {
        p = &D_8018047C;
    } else if (v >= 0x578) {
        p = &D_80180458;
    } else if (v >= 0x514) {
        p = &D_80180434;
    } else if (v >= 0x384) {
        p = &D_8018050C;
    } else if (v >= 0x258) {
        p = &D_801804E8;
    } else if (v >= 0xC8) {
        p = &D_801804C4;
    } else if (v >= 0xA) {
        p = &D_801804A0;
    } else {
        p = &D_80180410;
    }
    ((void (*)(void *))func_800D185C)(p);
    func_80145B24();
}
