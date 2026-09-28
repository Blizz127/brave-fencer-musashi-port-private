/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7604 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801B0368[];
extern u8 D_801B036A[];
extern u8 D_801B036C[];
extern void func_801AB21C(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8012BEE8(s32 a0);
extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);

void func_801A7604(void *arg0) {
    s16 idx;

    switch (*(u16 *)((u8 *)arg0 + 0x34)) {
    case 0:
        idx = *(s16 *)((u8 *)arg0 + 0x70);
        *(u16 *)((u8 *)arg0 + 0xFE) += *(u16 *)(D_801B0368 + idx * 8);
        idx = *(s16 *)((u8 *)arg0 + 0x70);
        *(u16 *)((u8 *)arg0 + 0x100) += *(u16 *)(D_801B036A + idx * 8);
        idx = *(s16 *)((u8 *)arg0 + 0x70);
        *(u16 *)((u8 *)arg0 + 0x102) += *(u16 *)(D_801B036C + idx * 8);
        func_801AB21C(1, *(u8 *)((u8 *)arg0 + 0xFF), *(u8 *)((u8 *)arg0 + 0x101), *(u8 *)((u8 *)arg0 + 0x103));
        if (func_8012BEE8((s32)arg0) != 0) {
            *(s32 *)((u8 *)arg0 + 0x1C) = 8;
            *(u16 *)((u8 *)arg0 + 0x34) = *(u16 *)((u8 *)arg0 + 0x34) + 1;
        }
        break;
    case 1:
        idx = *(s16 *)((u8 *)arg0 + 0x70);
        *(u16 *)((u8 *)arg0 + 0xFE) -= (s16)(*(u16 *)(D_801B0368 + idx * 8)) >> 1;
        idx = *(s16 *)((u8 *)arg0 + 0x70);
        *(u16 *)((u8 *)arg0 + 0x100) -= (s16)(*(u16 *)(D_801B036A + idx * 8)) >> 1;
        idx = *(s16 *)((u8 *)arg0 + 0x70);
        *(u16 *)((u8 *)arg0 + 0x102) -= (s16)(*(u16 *)(D_801B036C + idx * 8)) >> 1;
        func_801AB21C(1, *(u8 *)((u8 *)arg0 + 0xFF), *(u8 *)((u8 *)arg0 + 0x101), *(u8 *)((u8 *)arg0 + 0x103));
        if (func_8012BEE8((s32)arg0) != 0) {
            if (*(void **)((u8 *)arg0 + 0xCC) != NULL) {
                func_80016714(*(void **)((u8 *)arg0 + 0xCC), 0x38);
            }
            if (*(void **)((u8 *)arg0 + 0xD0) != NULL) {
                func_80016714(*(void **)((u8 *)arg0 + 0xD0), 0x38);
            }
            if (*(void **)((u8 *)arg0 + 0xD4) != NULL) {
                func_80016714(*(void **)((u8 *)arg0 + 0xD4), 0x38);
            }
            func_8012C218(arg0);
        }
        break;
    }
}
