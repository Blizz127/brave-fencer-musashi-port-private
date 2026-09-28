/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801378F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_8013A860(void);

void func_801378F0(void) {

    extern u8 D_80127520[];
    extern u8 aD801269F0[] __asm__("D_801269F0"); /* §37 alias: TU canon is `extern int D_801269F0` */
    extern u8 D_80126A28[];
    extern u8 D_8017F180[];
    s32 i;
    s32 si;
    s32 di;
    u8 *p;

    func_80016714(D_80127520, 0xBFC);
    i = 0;
    si = 0;
    p = aD801269F0;
    di = 0;
    do {
        func_80016714(p, 0x4C);
        *(u16 *)&D_80126A28[di]     = *(u16 *)&D_8017F180[si];
        *(u16 *)&D_80126A28[di + 2] = *(u16 *)&D_8017F180[si + 2];
        *(u16 *)&D_80126A28[di + 4] = *(u16 *)&D_8017F180[si + 4];
        *(u16 *)&D_80126A28[di + 6] = *(u16 *)&D_8017F180[si + 6];
        p += 0x4C;
        i += 1;
        si += 8;
        di += 0x4C;
    } while (i < 3);
    func_8013A860();
}
