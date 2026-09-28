/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170EAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void *D_8011F738;
extern s32 D_8011F73C;
extern s32 D_8011F740;
extern int func_800D0F8C(int a0);
extern void func_801718AC(void *a0);

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
