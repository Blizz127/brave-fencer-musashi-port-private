/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016EE40 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern s32 D_80126B58;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_80159B3C(void * a0);
extern void func_8016EF78(s32 a0);

void func_8016EE40(s32 _arg0, s32 _arg1, s32 _arg2)
{
  s32 *new_var;
  void (*new_var2)(void *a0);
  unsigned short new_var3;
  new_var = &D_80126B58;
  ((M2C_UNK (*)(void)) func_8016EF78)();
  new_var3 = *new_var;
  if (((u32) (new_var3 - 0x19)) >= 2U)
  {
    ((M2C_UNK (*)(u16 *)) func_801599A4)(&D_80126B58);
    new_var2 = func_80159B3C;
    ((M2C_UNK (*)(u16 *)) new_var2)(&D_80126B58);
  }
}
