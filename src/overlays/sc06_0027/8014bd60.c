/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BD60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_80078EB8;

void func_8014BD60(s32 param_1, s32 param_2)
{
  int new_var;
  int v1;
  v1 = (int) ((unsigned short) D_80078EB8);
  if (v1 < param_2)
  {
    D_80078EB8 = 0;
  }
  else
  {
    D_80078EB8 = (unsigned short) ((new_var = v1) - param_2);
  }
  return;
}
