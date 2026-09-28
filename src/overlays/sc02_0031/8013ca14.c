/* SC02 resident image [8013CA14,8013CABC) at overlay base 0x80128158.
 * SHA256(span)=08daccf4dee0b48c48beb5b0cb7752b8b96cc04a80d831638ff328f47e81f1d7.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
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

extern s32 D_801B6350;
extern s8 D_801B6354;
extern s8 D_801B6355;
extern s32 D_801269C8;
extern s32 D_801269D4;

void func_8013CA14(void)
{
  int *base = &D_801B6350;
  signed char *p;
  unsigned char c;
  int t;
  if ((*base) != 0)
  {
    c = D_801B6355;
    if (c == 0)
    {
      p = (signed char *) ((((unsigned int) ((unsigned char) D_801B6354)) * 2) + D_801B6350);
      t = (int) (*p);
      D_801269D4 = t;
      D_801269C8 = t;
      D_801B6355 = (unsigned char) p[1];
      D_801B6354 = D_801B6354 + 1;
      if (D_801B6355 == 0)
      {
        D_801269D4 = 0;
        D_801269C8 = 0;
        D_801B6354 = 0;
        *base = 0;
      }
    }
    else
    {
      D_801B6355 = c - 1;
    }
  }
  return;
}
