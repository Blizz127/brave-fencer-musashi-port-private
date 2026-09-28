/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013A8BC,8013A8FC).
 * Offset 0x12764 at overlay base 80128158. SHA256(span)=bf925b8851e214639fa071759454c4f35d93d27d4f9241634c3d15ce9eec75fb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013a8bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A8BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_8011DA80[];

s32 func_8013A8BC(void) {
    s32 p;
    s32 i;
    p = (s32)D_8011DA80;
    for (i = 0; i < 0x20; i += 0x10) {
        if (*(s16*)((s32)D_8011DA80 + i) == 0) {
            return p;
        }
        p += 0x10;
    }
    return 0;
}
