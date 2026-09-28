/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801776EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_8011F7AB;

void func_801776EC(u8 *a0)
{
    u8 *p;
    switch (D_8011F7AB) {
    default:
        D_8011F7AB = 0;
    case 0:
        a0[4] = 0xFF;
        a0[6] = 0x30;
        a0[5] = 0x30;
        break;
    case 1:
        a0[5] = 0xFF;
        a0[6] = 0x30;
        a0[4] = 0x30;
        break;
    case 2:
        a0[6] = 0xFF;
        a0[5] = 0x30;
        a0[4] = 0x30;
        break;
    }
    p = &D_8011F7AB;
    *p = *p + 1;
}
