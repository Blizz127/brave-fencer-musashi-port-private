/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80141B90 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u8 D_800B9A15;
extern unsigned short D_80115112;
extern void func_8013FAF8(s16 a0, s16 a1);
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_80115112;
extern void func_8013FAF8(s16, s16);
extern u16 D_80115116;

void func_80141B90(void)
{
  volatile char pad;
  D_801151D0 = ((s32 *) D_801151C8)[*((u16 *) (&D_800B9A02))];
  ((void (*)(s32, s32))func_8013FAF8)(2, 3);
  if (D_80115116 == 0)
  {
    *((s8 *) (&D_800B9A15)) = 0;
    D_80115112 = D_80115112 + 1;
  }
}
