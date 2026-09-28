/* SC02.CD FILE_031 / ov_SC02_031 retail span [801787D4,80178840).
 * Offset 0x5067C at overlay base 80128158. SHA256(span)=7ea9953cc0d7c4e0b6ad71ced335096b4b6854a3d882bd09bd8dc7b46feacaa5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801787d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801787D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801202A0[];
extern void func_80178840();

void func_801787D4(void) {
    u8 *p = D_801202A0;
    s32 i;
    for (i = 0; i < 0x60; i++) {
        if (*(u16 *)(p + 0) != 0 && p[0xC0] != 0) {
            func_80178840(p);
        }
        p += 0x10C;
    }
}
