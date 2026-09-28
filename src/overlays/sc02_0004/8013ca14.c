/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CA14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80195000;
extern s32 D_801269D4;
extern s32 D_801269C8;
extern s8 D_80195004;
extern s8 D_80195005;

void func_8013CA14(void)
{
  int *base = &D_80195000;
  signed char *p;
  unsigned char c;
  int t;
  if ((*base) != 0)
  {
    c = D_80195005;
    if (c == 0)
    {
      p = (signed char *) ((((unsigned int) ((unsigned char) D_80195004)) * 2) + D_80195000);
      t = (int) (*p);
      D_801269D4 = t;
      D_801269C8 = t;
      D_80195005 = (unsigned char) p[1];
      D_80195004 = D_80195004 + 1;
      if (D_80195005 == 0)
      {
        D_801269D4 = 0;
        D_801269C8 = 0;
        D_80195004 = 0;
        *base = 0;
      }
    }
    else
    {
      D_80195005 = c - 1;
    }
  }
  return;
}
