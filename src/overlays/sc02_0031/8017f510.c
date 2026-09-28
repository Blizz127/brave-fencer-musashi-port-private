/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017F510 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80126D54;
extern s32 D_80188C48;

s32 func_8017F510(void)
{
  int new_var;
  ;
  new_var++;
  new_var = (double) 1;
  new_var--;
  return ((u32) (D_80126D54 ^ ((u32) (&D_80188C48)))) == new_var;
}
