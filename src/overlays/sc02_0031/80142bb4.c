/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142BB4,80142C7C).
 * Offset 0x1AA5C at overlay base 80128158. SHA256(span)=0d3ff7f589cd414a4864477c55319b9445672c0a225e0c70d1181c29cbe9d978.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142bb4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142BB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_801439C0(u8 *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_8012C218(void *a0);
extern void func_8012C098(void);

void func_80142BB4(s32 * param_1, s32 param_2, s32 param_3)
{
  void *new_var;
  new_var = param_1;
  if ((*((s16 *) (new_var + 0xfc))) == 1)
  {
    if ((param_2 != ((char) 0)) || ((*((s16 *) (new_var + 0x100))) == 0))
    {
      *((u16 *) (new_var + 0x5c)) = (*((u16 *) (new_var + 0x5c))) & 0xfefe;
      *((u32 *) ((*((s32 *) (new_var + 0x20))) + 4)) = (*((u32 *) ((*((s32 *) (new_var + 0x20))) + 4))) | 0x80000000;
      func_801439C0(*((u8 **) (new_var + 0xcc)));
      func_8012AD44((s32 *) new_var, param_3);
    }
  }
  else
    if ((param_2 != 0) || ((*((s16 *) (new_var + 0x100))) == 0))
  {
 do { func_8012C218(new_var = (void *) new_var); } while (0);
  }
  else
  {
    ((void (*)(void *)) func_8012C098)((void *) new_var);
  }
}
