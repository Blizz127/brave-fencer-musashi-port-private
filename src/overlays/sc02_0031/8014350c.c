/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014350C,8014358C).
 * Offset 0x1B3B4 at overlay base 80128158. SHA256(span)=3b974d31f457f10532e277f289135e297738255991ddf7e812d9fd47f666a3a1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8014350c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
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
