/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80183394 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012CAE4(void *a0);
extern s32 func_80183AC8(s32 a0, s32 a1, s16 a2, s16 a3, s32 a4);

void func_80183394(s32 param_1) {
    extern u8 D_80189054[];
    s32 v0;
    s32 p;

    v0 = func_80183AC8(param_1, (s32)D_80189054, 0x300, 0x100, 0xA1);
    *(s32 *)(param_1 + 0xCC) = v0;
    if (v0 == 0) {
        goto fail;
    }
    v0 = func_80183AC8(param_1, (s32)D_80189054, 0x310, 0x100, 0xA2);
    *(s32 *)(param_1 + 0xD0) = v0;
    if (v0 == 0) {
        func_80016714((void *)*(s32 *)(param_1 + 0xCC), 0x38);
    fail:
        func_8012CAE4((void *)param_1);
        return;
    }
    p = *(s32 *)(param_1 + 0x68);
    *(u16 *)(*(s32 *)(param_1 + 0xCC) + 0x12) = *(u16 *)(p + 0xC);
    p = *(s32 *)(param_1 + 0x68);
    *(u16 *)(*(s32 *)(param_1 + 0xD0) + 0x12) = *(u16 *)(p + 0xC);
    *(s16 *)(param_1 + 0x2) = 1;
}
