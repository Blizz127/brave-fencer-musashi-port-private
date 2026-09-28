/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016B964,8016B984).
 * Offset 0x4380C at overlay base 80128158. SHA256(span)=841dd8668888a432a18c3d489cead666e0d2bd1fd53ccece6c8583587b2aa5b8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016b964.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B964 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u8 pad6[0x6];
    u16 h6;
    u16 h8;
    u16 hA;
} SrcB964;
typedef struct {
    u8 pad8[0x8];
    u16 h8;
    u16 hA;
    u16 hC;
} DstB964;
extern void func_8012A568(void (*a0)(void));

void func_8016B964(SrcB964 *a0, DstB964 *a1) {
    a1->h8 = a0->h6;
    a1->hA = a0->hA;
    a1->hC = 3;
}
