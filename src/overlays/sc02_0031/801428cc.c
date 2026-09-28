/* SC02.CD FILE_031 / ov_SC02_031 retail span [801428CC,8014292C).
 * Offset 0x1A774 at overlay base 80128158. SHA256(span)=8e94e45febc00257b0d4fbc591dc811b93b283ffabb22e2429461fb9cd358cb5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801428cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801428CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80142DB8(s32 *a0);
extern s32 func_80142D38(s32 *a0);
extern void func_80142BB4(s32 *a0, s32 a1, s32 a2);

void func_801428CC(s32 *a0) {
    if (func_80142DB8(a0) == 1) {
        func_80142BB4(a0, 1, 3);
    } else if (func_80142D38(a0) == 1) {
        func_80142BB4(a0, 0, 3);
    }
}
