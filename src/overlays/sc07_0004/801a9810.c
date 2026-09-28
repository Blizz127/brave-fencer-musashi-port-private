/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A9810 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801439C0(u8*);
extern void func_801AA60C();
extern void func_801A99A4();
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_8012AD44(s32 *a0, s16 a1);
extern u8 D_801B0604[];
extern u8 D_801B061C[];
extern u8 D_801B0694[];

void func_801A9810(void *a0) {
    s32 s1;

    s1 = *(s32 *)((s32)a0 + 0xCC);
    if (*(s32 *)((s32)a0 + 0xD0) != 0) {
        ((void (*)(s32))func_801439C0)(*(s32 *)((s32)a0 + 0xD0));
        *(s32 *)((s32)a0 + 0xD0) = 0;
    }
    if (*(s16 *)((s32)a0 + 0xFE) != 0) {
        func_801AA60C(a0, 0xAB7);
        func_801A99A4(a0);
        func_80128EA8(s1, (s32)a0 + 0xF0, (s32)D_801B061C);
    } else {
        func_80128EA8(s1, (s32)a0 + 0xF0, (s32)D_801B0694);
    }
    *(s32 *)(s1 + 0x20) = (s32)D_801B0604;
    *(s16 *)(s1 + 0x28) = 0x340;
    *(s16 *)(s1 + 0x2A) = 0x100;
    func_8012AD44((s32 *)a0, 2);
}
