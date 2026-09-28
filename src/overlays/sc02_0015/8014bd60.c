/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014BD60 - byte-exact against retail at -O2 (tools/register_match.py). */
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
