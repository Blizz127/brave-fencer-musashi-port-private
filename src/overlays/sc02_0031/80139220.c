/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139220,801392C8).
 * Offset 0x110C8 at overlay base 80128158. SHA256(span)=5b84b9f7414f935cfa972eec84f6d67ee183a0d5f8620756285c8e1dfbc83240.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139220.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139220 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139DC8(void);
extern void func_801392C8(void *a0);

s32 func_80139220(s32 a0) {
    s32 v1;
    *(s16 *)(a0 + 0x14) = 0;
    *(s16 *)(a0 + 0x12) = (*(u16 *)(a0 + 0x12) + 1) % (*(s16 *)(a0 + 0x2E) + 1);
    func_80139DC8();
    v1 = *(u16 *)(a0 + 0x12) - *(u16 *)(a0 + 0x16);
    if (v1 != -1) {
        if (v1 < *(s16 *)(a0 + 0x2E)) {
            return 0;
        }
    }
    func_801392C8((void *)a0);
    return 1;
}
