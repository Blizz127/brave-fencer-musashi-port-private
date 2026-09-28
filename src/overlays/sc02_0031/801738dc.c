/* SC02.CD FILE_031 / ov_SC02_031 retail span [801738DC,8017390C).
 * Offset 0x4B784 at overlay base 80128158. SHA256(span)=7e2abc7f997678584a790ff0c5ec15565f6beb044f586c045912ee8da9595491.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801738dc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801738DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s16 D_80126B30;
extern s32 func_8017390C();
extern void func_80174684(void *);

void func_801738DC(s16 a0) {
    D_80126B30 = a0;
    func_80174684((void *)func_8017390C);
}
