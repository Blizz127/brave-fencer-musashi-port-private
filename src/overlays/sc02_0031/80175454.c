/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175454,80175494).
 * Offset 0x4D2FC at overlay base 80128158. SHA256(span)=e70a5b1d2eb9412a3231f0245b409acf1d912db4a19976fe3938f1678bf58b69.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175454.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175454 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_8011F7A8;
extern u8 D_8011F7A9;
extern u8 D_8011F7AD;
extern u8 D_8011F7AE;

void func_80175454(void) {
    u8 *p = &D_8011F7A8;
    if (*p == 0) {
        *p = 1;
        D_8011F7A9 = 0;
        D_8011F7AD = 0xA;
        D_8011F7AE = 0;
    }
}
