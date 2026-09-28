/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013CA14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8019BE10;
extern s8 D_8019BE14;
extern s8 D_8019BE15;
extern s32 D_801269C8;
extern s32 D_801269D4;

void func_8013CA14(void)
{
  int *base = &D_8019BE10;
  signed char *p;
  unsigned char c;
  int t;
  if ((*base) != 0)
  {
    c = D_8019BE15;
    if (c == 0)
    {
      p = (signed char *) ((((unsigned int) ((unsigned char) D_8019BE14)) * 2) + D_8019BE10);
      t = (int) (*p);
      D_801269D4 = t;
      D_801269C8 = t;
      D_8019BE15 = (unsigned char) p[1];
      D_8019BE14 = D_8019BE14 + 1;
      if (D_8019BE15 == 0)
      {
        D_801269D4 = 0;
        D_801269C8 = 0;
        D_8019BE14 = 0;
        *base = 0;
      }
    }
    else
    {
      D_8019BE15 = c - 1;
    }
  }
  return;
}
