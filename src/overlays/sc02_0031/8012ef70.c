/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012EF70,8012EFB8).
 * Offset 0x6E18 at overlay base 80128158. SHA256(span)=bd9c9f952cefc04ff3caff08b59fc229d95998c0e9eb833fe6455008053a68c0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012ef70.c (recovery=assembly, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012EF70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012EFB8(s32 a0);

void func_8012EF70(s32 a0, s32 a1) {
    s32 sp10;
    register s32 v1 __asm__("$3");
    func_8012EFB8(a0);
    {
        register s32 *p __asm__("$3") = &sp10;
        __asm__ __volatile__(
            "mfc2 $12, $19\n"
            "nop\n"
            "sra $12, $12, 2\n"
            "sw $12, 0(%0)\n"
            : : "r"(p) : "memory", "$12");
    }
    v1 = sp10;
    *(s16 *)(a1 + 4) = v1;
}
