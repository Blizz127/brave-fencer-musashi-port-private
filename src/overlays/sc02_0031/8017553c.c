/* SC02 resident retail span [8017553C,80175590). Offset 0x4D3E4 at base 80128158.
 * SHA256(span)=f526f56f6281405f218d0fc0b11d372b8a497f4ca2e732dc58f8a7c0214f4171.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181B78->D_80188468.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017553C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188468[])(s32 *);
extern s32 func_801758FC(void);
extern s32 func_80175820(void);
extern s32 func_801759D8(void);

void func_8017553C(s32 *param) {
    D_80188468[*(u8 *)((s32)param + 1)](param);
    ((void (*)(void))func_801758FC)();
    ((void (*)(void))func_80175820)();
    ((void (*)(void))func_801759D8)();
}
