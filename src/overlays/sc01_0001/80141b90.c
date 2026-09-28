/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80141B90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8013FAF8(s16, s16);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_80115116;
extern u16 D_80115112;
extern u8 D_800B9A15;

void func_80141B90(void)
{
  volatile char pad;
  D_801151D0 = ((s32 *) D_801151C8)[*((u16 *) (&D_800B9A02))];
  ((void (*)(s32, s32))func_8013FAF8)(2, 3);
  if (D_80115116 == 0)
  {
    *((s8 *) (&D_800B9A15)) = 0;
    D_80115112 = D_80115112 + 1;
  }
}
