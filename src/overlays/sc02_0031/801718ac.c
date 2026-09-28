/* SC02.CD FILE_031 / ov_SC02_031 retail span [801718AC,80171904).
 * Offset 0x49754 at overlay base 80128158. SHA256(span)=91678cc339280536a46a211dc7995e6bb7aec54783138475f45638b17d4b7081.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801718ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801718AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 D_80126B58;
extern s32 D_80126D50;
extern s32 D_80126D54;
extern u8 D_80126D6C;
extern void func_80171A1C(u8 *a0);

void func_801718AC(void *arg0) {
    D_80126D54 = (s32)arg0;
    D_80126D6C = 0;
    D_80126D50 = *(s32 *)arg0 | (D_80126D50 & 0x7F000000);
    func_80171A1C((u8 *)&D_80126B58);
}
