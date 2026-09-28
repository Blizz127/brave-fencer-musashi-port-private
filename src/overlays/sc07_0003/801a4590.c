/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4590 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C218(void *a0);
extern s32 func_80134510(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_801A4680(void *a0);
extern u8 D_801152A8[];
extern s16 D_801152AA;
extern s16 D_801152AC;

void func_801A4590(s32 a0) {
    s32 v0 = *(s32 *)(a0 + 0x64);
    s16 sp[3];

    if (*(s16 *)(v0 + 0x36) != *(s16 *)(a0 + 0x10A)) {
        func_8012C218((void *)a0);
        return;
    }

    sp[0] = *(u16 *)(v0 + 6);
    sp[1] = *(u16 *)(v0 + 0xA) - 0x10;
    sp[2] = *(u16 *)(v0 + 0xE);
    if (func_80134510((s32)&sp[0]) == 0) {
        return;
    }

    *(s16 *)(a0 + 6) = sp[0];
    *(s16 *)(a0 + 0xA) = sp[1];
    *(s16 *)(a0 + 0xE) = sp[2];

    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = func_8004CFEC(D_801152AC, D_801152AA) + 0x400;
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) = func_8004CFEC(*(s16 *)D_801152A8, D_801152AA);
    func_801A4680((void *)a0);
}
