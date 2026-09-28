/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CA14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801BD680;
extern s32 D_801269D4;
extern s32 D_801269C8;
extern s8 D_801BD684;
extern s8 D_801BD685;

void func_8013CA14(void)
{
  int *base = &D_801BD680;
  signed char *p;
  unsigned char c;
  int t;
  if ((*base) != 0)
  {
    c = D_801BD685;
    if (c == 0)
    {
      p = (signed char *) ((((unsigned int) ((unsigned char) D_801BD684)) * 2) + D_801BD680);
      t = (int) (*p);
      D_801269D4 = t;
      D_801269C8 = t;
      D_801BD685 = (unsigned char) p[1];
      D_801BD684 = D_801BD684 + 1;
      if (D_801BD685 == 0)
      {
        D_801269D4 = 0;
        D_801269C8 = 0;
        D_801BD684 = 0;
        *base = 0;
      }
    }
    else
    {
      D_801BD685 = c - 1;
    }
  }
  return;
}
