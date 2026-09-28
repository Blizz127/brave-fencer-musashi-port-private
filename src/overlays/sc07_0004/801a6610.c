/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6610 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A3180(s32 a0, s32 a1);
extern void func_801A36A8(s32 a0);
extern s32 func_8012B8A4(s16 *a0);
extern void func_801A3624(s32 target, u16 *cur, s32 step);
extern s32 func_8012BEE8(s32 a0);
extern u16 D_8019FF8A;
extern void (*D_801AFC48[])(void);

void func_801A6610(s32 arg0) {
    s32 v0;

    func_801A3180(arg0, 0x100);
    func_801A36A8(arg0);
    v0 = func_8012B8A4((s16 *)arg0);
    *(u16 *)((s8 *)arg0 + 0xFE) = v0;
    func_801A3624((s16)v0, (u16 *)(*(s32 *)(arg0 + 0x20) + 0x12), 0x40);
    if (func_8012BEE8(arg0) != 0) {
        if (!(D_8019FF8A & 0x40)) {
            ((void (*)(s32))D_801AFC48[*(s16 *)((s8 *)arg0 + 0x104)])((s32)arg0);
            v0 = *(u16 *)((s8 *)arg0 + 0x104) + 1;
            *(u16 *)((s8 *)arg0 + 0x104) = v0;
            if ((s16)v0 >= 6) {
                *(u16 *)((s8 *)arg0 + 0x104) = 0;
            }
        }
    }
}
