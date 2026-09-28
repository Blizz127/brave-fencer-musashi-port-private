/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170EAC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *D_8011F738;
extern void func_801718AC(void *a0);
extern s32 D_8011F73C;
extern s32 D_8011F740;
extern int func_800D0F8C(int a0);

void func_80170EAC(u8 * _arg0)
{
  s32 arg;
  if (((int (*)(volatile char))func_800D0F8C)(D_8011F738) != 0)
  {
    arg = D_8011F73C;
  }
  else
  {
    arg = D_8011F740;
  }
  ((void (*)(s32)) func_801718AC)(arg);
}
