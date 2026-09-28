/* SC02 resident image [8017F53C,8017F590) at overlay base 0x80128158.
 * SHA256(span)=49a7d5c753230b26f124044e2118d2de962173ef50e57bff4750258485ae9176.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017F53C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80052D90(s32 a0, void *a1);
extern void func_80054514(s32 a0, s32 a1);

void func_8017F53C(s32 a0) {
    s32 sp10[8];

    func_80052D90(0, (void *)a0);
    func_80054514(a0, (s32)sp10);
    *(s32 *)(a0 + 0x18) = 0;
    *(s32 *)(a0 + 0x1C) = 0;
    *(s32 *)(a0 + 0x20) = 0;
    *(s16 *)(a0 + 0x50) = 0;
    *(s16 *)(a0 + 0x52) = 0;
    *(s16 *)(a0 + 0x54) = 0;
}
