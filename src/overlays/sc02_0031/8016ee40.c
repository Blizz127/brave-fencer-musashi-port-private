/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016EE40,8016EE94).
 * Offset 0x46CE8 at overlay base 80128158. SHA256(span)=0218fa5f668cdcb1d3c299eeafbe514c8d59658ffa4407082002d3ae1993e9c1.
 * STOP pc=8016ee40 (func_8016EE40), CPU_BOUNDARY/REFUSED, ra=8018123c.
 * Callee from burned func_80181224 (jal 0C05BB90; a0=80188da4 a1=01000000).
 * Donor shape: Druthulu shared/ov/func_8016EE40.h (func_8016EF78 + range check on D_80126B58).
 * NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_8017AE2C / shared OV body.
 */
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
