/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170EAC,80170EFC).
 * Offset 0x48D54 at overlay base 80128158. SHA256(span)=a1cbfbb658223e90c6ed5b38fa84f857ce39f4080a62c1cac79cf9474c1d05cf.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170eac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
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
