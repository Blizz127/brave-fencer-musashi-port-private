/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130278,80130314).
 * Offset 0x8120 at overlay base 80128158. SHA256(span)=464edec72f197a55b1fcb8d5500698f0436cf94d108c085237dea266f8d8a833.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130278.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130278 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80131CA8(int a0, int a1);
extern void func_80131170(s32 a0, s32 a1, s32 a2);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);

void func_80130278(s32 arg0) {
    s32 flag;
    flag = 0;
    *(u8 *)(arg0 + 0xC1) = 0xB;
    if (*(s32 *)(arg0 + 0xC4) & 1) {
        func_80131E00((struct S80131E00 *)arg0, 0xE);
        return;
    }
    if (*(s32 *)(arg0 + 0xB4) & 0x800) {
        func_80131170(arg0, 0, 0);
        flag = 1;
    }
    if (((s32 (*)(int, int))func_80131CA8)(arg0, 0x2C) != 0) {
        flag = 1;
    }
    if (flag == 0) {
        func_80131E00((struct S80131E00 *)arg0, 6);
    }
}
