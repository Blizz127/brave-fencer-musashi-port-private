/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FB50,8016FB7C).
 * Offset 0x479F8 at overlay base 80128158. SHA256(span)=6aec008a3fc150f262fb3bad533f598f70b76baeba78bb51e0292eeef9d78ac3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fb50.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FB50 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FB50(void *a0) {
    s32 v1 = *(s32 *)((s32)a0 + 0x20);
    u16 v0 = *(u16 *)((s32)a0 + 0x132);
    *(s16 *)((s32)a0 + 0x136) = 0;
    *(s16 *)(v1 + 0x12) = v0;
    func_80171928(a0);
}
