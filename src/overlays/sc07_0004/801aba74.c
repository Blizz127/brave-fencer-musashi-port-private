/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ABA74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A8990();
extern s32 func_8012BEE8(s32 a0);
extern void func_8017E5D4(void *a0);
extern void func_8012C218(void *a0);

void func_801ABA74(s32 arg0) {
    s32 v0;

    switch (*(u16 *)(arg0 + 0x34)) {
    case 0:
        *(u16 *)(arg0 + 0xFE) += 0x14;
        *(u16 *)(arg0 + 0x104) = *(u16 *)(*(s32 *)(arg0 + 0x64) + 6);
        *(u16 *)(arg0 + 0x106) = *(u16 *)(*(s32 *)(arg0 + 0x64) + 0xA);
        *(u16 *)(arg0 + 0x108) = *(u16 *)(*(s32 *)(arg0 + 0x64) + 0xE);
        func_801A8990(arg0);
        if (func_8012BEE8(arg0) != 0) {
            *(u16 *)(arg0 + 0x34) += 1;
        }
        break;
    case 1:
        v0 = *(u16 *)(arg0 + 0xFE) - 8;
        *(u16 *)(arg0 + 0xFE) = v0;
        if ((s16)v0 < 8) {
            if (*(s32 *)(arg0 + 0xCC) != 0) {
                func_8017E5D4(*(void **)(arg0 + 0xCC));
            }
            func_8012C218((void *)arg0);
            return;
        } else {
            *(u16 *)(arg0 + 0x104) = *(u16 *)(*(s32 *)(arg0 + 0x64) + 6);
            *(u16 *)(arg0 + 0x106) = *(u16 *)(*(s32 *)(arg0 + 0x64) + 0xA);
            *(u16 *)(arg0 + 0x108) = *(u16 *)(*(s32 *)(arg0 + 0x64) + 0xE);
            func_801A8990(arg0);
        }
        break;
    }
    *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x10) += *(u16 *)(arg0 + 0x102);
}
