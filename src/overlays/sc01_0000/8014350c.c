/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014350C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8014358C();
extern void func_8012931C(struct vec *a0);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_801292C8(u8 *a0);

void func_8014350C(s32 *a0) {
    if (*(u16 *)((u8 *)a0 + 2) == 0) {
        func_8014358C();
        return;
    }
    func_8012931C((struct vec *)a0);
    if (func_80128ED8((void *)a0[0x20 / 4], (void *)((u8 *)a0 + 0x24)) != 0) {
        func_801292C8((u8 *)a0);
        return;
    }
    *(u8 *)(a0[0x20 / 4] + 0x27) = *(u8 *)((u8 *)a0 + 0x28) - 0x70;
}
