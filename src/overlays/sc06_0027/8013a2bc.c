/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A2BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80127524;
extern s32 D_80127528;
extern void func_80138C30(void *a0);

void func_8013A2BC(s32 a0) {
    s32 s0 = a0;
    s32 *v1;
    s32 *p;
    s32 v0;
    v1 = *(s32 **)(s0 + 0x40);
    if (v1 == 0 || *(u16 *)(s0 + 0x18) == 0 || *(s16 *)v1 == 4) {
        p = &D_80127524;
        if (*p == s0) {
            v0 = D_80127528;
            D_80127528 = 0;
            *p = v0;
            if (v0 != 0) {
                *(s16 *)(D_80127524 + 0x1A) = 1;
                __asm__ __volatile__("" : : : "memory");
                ((void (*)(s32))func_80138C30)(*p);
            }
        }
        if ((*(s32 *)(s0 + 8) & 0x8000) == 0) {
            *(s16 *)(s0 + 4) = 0xD;
        } else {
            *(s16 *)(s0 + 4) = 0xE;
        }
    }
}
