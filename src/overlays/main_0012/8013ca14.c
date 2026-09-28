/* Overlay range [8013CA14,8013CABC) from MAIN.CD member 0012.
 * SHA256(span)=2d64b130f5a14ff9a1795b951291fe906fb14d3ef7d8dca156c60b3b62e52296.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CA14 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8013CA14(void)
{

    extern s32 D_80184198;
    extern s8 D_8018419C;
    extern s8 D_8018419D;
    extern s32 D_801269C8;
    extern s32 D_801269D4;
  int *base = &D_80184198;
  signed char *p;
  unsigned char c;
  int t;
  if ((*base) != 0)
  {
    c = D_8018419D;
    if (c == 0)
    {
      p = (signed char *) ((((unsigned int) ((unsigned char) D_8018419C)) * 2) + D_80184198);
      t = (int) (*p);
      D_801269D4 = t;
      D_801269C8 = t;
      D_8018419D = (unsigned char) p[1];
      D_8018419C = D_8018419C + 1;
      if (D_8018419D == 0)
      {
        D_801269D4 = 0;
        D_801269C8 = 0;
        D_8018419C = 0;
        *base = 0;
      }
    }
    else
    {
      D_8018419D = c - 1;
    }
  }
  return;
}
