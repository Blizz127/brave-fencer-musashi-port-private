/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801508F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8015094C(s32 a0);

short func_801508F8(s32 a0)
{
  if ((*((u8 *) (a0 + 0x1BF))) != 0)
  {
    if ((*((u16 *) a0)) != 0x1A)
    {
      while (func_8015094C(a0) != 0)
      {
        ;
      }
    }
  }
}
