/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174674,80174684).
 * Offset 0x4C51C at overlay base 80128158. SHA256(span)=0f1291b00bcc4c4bff16672efec439e8af6c259f3a91ae713e9fb97877509a76.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174674.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174674 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801270BC;

void func_80174674(void) {
    D_801270BC = 0;
}
