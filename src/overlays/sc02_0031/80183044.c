/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80183044 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_800183E0(s32 a0);

void func_80183044(s32 param_1) {

    extern u16 D_800B99DA;
    extern u8 D_80189008[];
    extern u8 D_801ABA28[];
    *(u8 *)(*(s32 *)(param_1 + 0xCC) + 0x27) = 0x83;
    func_800183E0((s32)&D_801ABA28[D_80189008[D_800B99DA & 0x1F] * 16]);
}
