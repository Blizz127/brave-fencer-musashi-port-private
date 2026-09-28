/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016EE40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* m2c compat (vendor/bfm-decomp/include/common.h). */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))

extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8016EF78(s32 a0);
extern s32 D_80126B58;
extern void func_8012A568(void (*a0)(void));

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
