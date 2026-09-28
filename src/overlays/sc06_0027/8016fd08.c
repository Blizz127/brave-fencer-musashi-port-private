/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FD08 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80172658(s32 *a0);
extern void func_80146D90(s32 a0);
extern s32 func_80171990(u8 *a0);
extern void *D_8011F738;
extern void func_8012A568(void (*a0)(void));

void func_8016FD08(u8 *s0) {
    s32 *p;
    if (func_80172658((s32 *)s0)) {
        func_80146D90((s32)s0);
        *(u16 *)(s0 + 0xAC) = *(u16 *)(s0 + 0xAC) | 0x40;
        *(u16 *)(s0 + 0xAA) = *(u16 *)(s0 + 0xAA) | 0x40;
        p = (s32 *)&D_8011F738;
        if ((*p = *p - 1) == 0) {
            func_80171990(s0);
        }
    }
}
