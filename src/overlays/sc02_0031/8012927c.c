/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012927C,801292C8).
 * Offset 0x1124 at overlay base 80128158. SHA256(span)=5dfa851c421f6574efc831adb85001c11505c0846129e38ac19302df45b26054.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012927c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012927C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801292C8(u8 *a0);
extern s16 D_8011DB30;

void func_8012927C(void) {
    s32 i;
    u8 *p = (u8 *)&D_8011DB30;
    for (i = 0; i < 0x80; i++) {
        func_801292C8(p);
        p += 0x38;
    }
}
