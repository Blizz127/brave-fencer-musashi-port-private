/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130438 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131B14();
extern void func_80143CD4(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_800CB0E8(s32 a0);
extern s32 func_80131A34(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern s32 *D_80126B78;

void func_80130438(s32 a0) {
    s32 flag;
    flag = 0;
    *(u8 *)(a0 + 0xC1) = 6;
    if ((*(u32 *)(a0 + 0xB4) & 0x40) != 0) {
        flag = 1;
        func_80131B14();
        *(s32 *)(a0 + 0x1C) = 0x78;
        func_80143CD4(a0);
        func_8002D4C8(0x47B, 0);
        func_8002D4C8(0x478, 0);
        func_800CB0E8(a0);
        if (func_80131A34(a0, 0x14) == 0) {
            *(s16 *)(a0 + 0x98) = 0;
        }
    }
    if (((s32 (*)(s32, s32))func_80131CA8)(a0, 0x12) != 0) {
        flag = 1;
    }
    if (flag == 0) {
        *(s16 *)(a0 + 0x5E) = 2;
        *(s16 *)(a0 + 0x60) = 1;
        *(s16 *)(a0 + 0x62) = *(u16 *)((s32)D_80126B78 + 0x12);
        ((void (*)(s32, s32))func_80131E00)(a0, 1);
    }
}
