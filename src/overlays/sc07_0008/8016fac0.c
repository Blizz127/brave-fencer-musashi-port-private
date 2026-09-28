/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FAC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_8016FB10(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FAC0(u8 *a0) {
    u8 *v1;
    *(s16 *)(a0 + 0x136) = 2;
    v1 = *(u8 **)(a0 + 0x20);
    *(s16 *)(a0 + 0x132) = *(u16 *)(v1 + 0x12);
    func_801719A4((int)a0, 2);
    func_80171990(a0);
    func_8016FB10(a0);
}
