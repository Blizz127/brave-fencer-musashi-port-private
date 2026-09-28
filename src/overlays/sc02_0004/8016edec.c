/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016EDEC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern s32 D_80126B58;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_80159B3C(void * a0);
extern void func_8016EE94();

void func_8016EDEC(s32 _arg0, s32 _arg1, s32 _arg2)
{
  unsigned short *new_var;
  if (1)
  {
    ((M2C_UNK (*)(void)) func_8016EE94)();
    new_var = &D_80126B58;
    if (((u32) ((*new_var) - 0x19)) >= 2U)
    {
      ((M2C_UNK (*)(u16 *)) func_801599A4)(&D_80126B58);
      ((M2C_UNK (*)(u16 *)) func_80159B3C)(&D_80126B58);
    }
  }
}
