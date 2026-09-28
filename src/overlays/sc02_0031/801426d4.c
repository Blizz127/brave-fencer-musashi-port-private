/* SC02.CD FILE_031 / ov_SC02_031 retail span [801426D4,80142740).
 * Offset 0x1A57C at overlay base 80128158. SHA256(span)=34a5c8ea3e686cf00f774692f28eb5d525da2f08df76f3272200a8da5261a25d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801426d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801426D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012AD50(void *a0);

void func_801426D4(s32 a0) {
    s32 s0 = *(s32 *)(a0 + 0x20);
    s16 fc = *(s16 *)(a0 + 0xFC);
    if (fc != 0) {
        *(s16 *)(a0 + 0xFC) = fc - 0x10;
        *(u16 *)(s0 + 0x18) += 0x800;
        *(u16 *)(s0 + 0x1A) += 0x800;
    } else {
        *(s32 *)(a0 + 0x1C) = 0xC;
        func_8012AD50((void *)a0);
        *(u16 *)(s0 + 0x1A) = 0x1800;
        *(u16 *)(s0 + 0x18) = 0x1800;
    }
}
