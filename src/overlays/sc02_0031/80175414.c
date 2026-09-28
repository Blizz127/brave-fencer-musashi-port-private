/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175414,80175454).
 * Offset 0x4D2BC at overlay base 80128158. SHA256(span)=f964a827c86a6b4cd52eacb9e6213c8c9afe39a5039afc17e37a2d23c5614029.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175414.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175414 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80175414(s32 _arg0)
{
    unsigned char *p = &D_8011F7A8;
    if (*p == 1) {
        *p = 0;
        D_8011F7AD = 10;
        D_8011F7A9 = 0;
        D_8011F7AE = 0x37;
    }
    return;
}
