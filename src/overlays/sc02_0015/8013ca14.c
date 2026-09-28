/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CA14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8018F0D8;
extern s32 D_801269D4;
extern s32 D_801269C8;
extern s8 D_8018F0DC;
extern s8 D_8018F0DD;

void func_8013CA14(void)
{
  int *base = &D_8018F0D8;
  signed char *p;
  unsigned char c;
  int t;
  if ((*base) != 0)
  {
    c = D_8018F0DD;
    if (c == 0)
    {
      p = (signed char *) ((((unsigned int) ((unsigned char) D_8018F0DC)) * 2) + D_8018F0D8);
      t = (int) (*p);
      D_801269D4 = t;
      D_801269C8 = t;
      D_8018F0DD = (unsigned char) p[1];
      D_8018F0DC = D_8018F0DC + 1;
      if (D_8018F0DD == 0)
      {
        D_801269D4 = 0;
        D_801269C8 = 0;
        D_8018F0DC = 0;
        *base = 0;
      }
    }
    else
    {
      D_8018F0DD = c - 1;
    }
  }
  return;
}
