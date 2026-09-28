/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FE70,8012FF00).
 * Offset 0x7D18 at overlay base 80128158. SHA256(span)=9845e2af3b1462b453f3845cb2f28a86c3b29fd8afe86f18f3dceb9559e15fcc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012fe70.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012FE70 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131170(s32 a0, s32 a1, s32 a2);
extern void func_80131CA8(int a0, int a1);

void func_8012FE70(s32 a0) {
    s32 v1 = *(s32 *)(a0 + 0xC4);
    *(u8 *)(a0 + 0xC1) = 9;
    if (v1 & 2) {
        *(u8 *)(a0 + 0xC1) = 1;
        func_80131CA8(a0, 3);
    } else if (v1 & 1) {
        func_80131E00((struct S80131E00 *)a0, 1);
    } else {
        if (*(s32 *)(a0 + 0xB4) & 0x200) {
            func_80131170(a0, 0, 0);
        }
        func_80131CA8(a0, 0x1E);
    }
}
