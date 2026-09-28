/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801493D0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80015978(s32, s32*);
extern void func_80015978(int a0, int *a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);

void func_801493D0(s32 param_1, s32 param_2, s32 param_3)
{
  u8 buf1[8];
  u8 *new_var;
  u8 buf2[8];
  ((void (*)(s32, u8 *)) func_80015978)(param_2, buf1);
  new_var = buf2;
  ((void (*)(s32, u8 *, u8 *)) func_8012F14C)((*((s32 *) (param_1 + 0x20))) + 0x34, buf1, new_var);
  new_var++;
  new_var--;
  ((void (*)(u8 *, s32)) func_80015954)(buf2, param_3);
}
