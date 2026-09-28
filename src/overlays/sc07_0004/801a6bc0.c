/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6BC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A46F0(s32 *a0);
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern s32 D_801B75EC;
extern u16 D_801AFF3C;
extern u16 D_801AFF3E;
extern u16 D_801AFF40;

void func_801A6BC0(void *a0) {
    s32 v0;
    s32 v1;

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
    } else {
        func_8001C214(v0, (s32)&D_801B75EC);

        v1 = *(s32 *)((s32)a0 + 0x20);
        *(s16 *)((s32)a0 + 0x6) = D_801AFF3C;
        *(s16 *)((s32)a0 + 0xA) = D_801AFF3E;
        *(s16 *)((s32)a0 + 0xE) = D_801AFF40;
        *(s32 *)(v1 + 0x4) |= 0x40;
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x2C) |= 0x10;

        if (*(s16 *)((s32)a0 + 0x70) == 0) {
            *(s32 *)((s32)a0 + 0x6C) =
                func_8012C658(0x32A, 1, *(s32 *)((s32)a0 + 0x64));
        }
        *(s32 *)((s32)a0 + 0xCC) =
            func_8012C658(0xB1, *(s16 *)((s32)a0 + 0x70), (s32)a0);
        func_801A46F0((s32 *)a0);
    }
}
