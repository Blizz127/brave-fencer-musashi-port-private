/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157580,801575E4).
 * Offset 0x2F428 at overlay base 80128158. SHA256(span)=12f107eaea8af7ce70aff1dfc83d9f7c88bceaf6bbac4cb61fb60bea081dbb15.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157580.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157580 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern void func_8015BDD0(s32 *a0);
extern void func_801575E4(void *a0);

void func_80157580(s32 arg0) {
    s32 temp_s1;
    /* return-cast: canonical func_8014CC28 is void, but its $v0 is used here */
    temp_s1 = ((s32 (*)(s32))func_8014CC28)(arg0);
    /* return-cast: canonical func_8014F3E8 is void, but its $v0 is tested here */
    if ((((s32 (*)(s32))func_8014F3E8)(arg0) == 0) && (temp_s1 == 0)) {
        func_8015BDD0((s32 *)arg0);
        return;
    }
    func_801575E4((void *)arg0);
}
