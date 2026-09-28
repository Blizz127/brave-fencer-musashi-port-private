/* SC02.CD FILE_031 / ov_SC02_031 retail span [80131E7C,80131EE4).
 * Offset 0x9D24 at overlay base 80128158. SHA256(span)=db892807018af6377fb97dd9a6217bbf7ac6b22a3ab248302960728094d9731f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80131e7c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131E7C - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s32 func_8012E470(s32 a0);
extern void func_8012E4C8(s32 a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);

void func_80131E7C(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x40000) {
        if (func_8012E470(a0)) {
            func_8012E4C8(a0);
            func_80131E00((struct S80131E00 *)a0, 1);
        }
    }
    func_80131CA8(a0, 0x3A);
}
