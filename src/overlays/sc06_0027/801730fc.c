/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801730FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S801730FC {
    u8 pad[0xB8];
    u16 unkB8;     /* 0xB8 */
};
extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_80174650(s32);
extern s16 D_80126B30;

void func_801730FC(struct S801730FC *a0) {
    if (a0->unkB8 & 0x8000) {
        func_80171A1C((u8 *)a0);
        if (D_80126B30 != 0) {
            func_80147060(a0);
            func_80154150(a0, 0);
        }
        func_80174650((s32)a0);
    }
}
