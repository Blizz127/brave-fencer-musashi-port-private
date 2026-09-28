/* SC02.CD FILE_031 / ov_SC02_031 retail span [80131D68,80131E00).
 * Offset 0x9C10 at overlay base 80128158. SHA256(span)=1ffe687b232fcef7e000113b5b2889d08bdba073e5414a43b0008d35866c661d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80131d68.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131D68 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80131CA8(int, int);
extern void func_8002A04C(s32 a0);
extern void func_8012C218(void *a0);

int func_80131D68(int a0, int a1)
{
    s32 s0 = a0;
    s32 c = a1 & 0xFF;
    if (c == 2 || c == 0x1B) {
        func_80131E00((struct S80131E00 *)s0, 0x12);
        return 1;
    }
    if (c == 0x1A || c == 0x1C) {
        if (((s32 (*)(int, int))func_80131CA8)(s0, 0x11) != 0) {
            return 1;
        }
        if (*(s32 *)(s0 + 0x78) != 0) {
            func_8002A04C(s0);
        }
        func_8012C218((void *)s0);
        return 1;
    }
    return 0;
}
