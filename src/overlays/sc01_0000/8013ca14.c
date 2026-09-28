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

extern s32 D_801A44C0;
extern s8 D_801A44C4;
extern s8 D_801A44C5;
extern s32 D_801269C8;
extern s32 D_801269D4;

void func_8013CA14(void)
{
  int *base = &D_801A44C0;
  signed char *p;
  unsigned char c;
  int t;
  if ((*base) != 0)
  {
    c = D_801A44C5;
    if (c == 0)
    {
      p = (signed char *) ((((unsigned int) ((unsigned char) D_801A44C4)) * 2) + D_801A44C0);
      t = (int) (*p);
      D_801269D4 = t;
      D_801269C8 = t;
      D_801A44C5 = (unsigned char) p[1];
      D_801A44C4 = D_801A44C4 + 1;
      if (D_801A44C5 == 0)
      {
        D_801269D4 = 0;
        D_801269C8 = 0;
        D_801A44C4 = 0;
        *base = 0;
      }
    }
    else
    {
      D_801A44C5 = c - 1;
    }
  }
  return;
}
