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
