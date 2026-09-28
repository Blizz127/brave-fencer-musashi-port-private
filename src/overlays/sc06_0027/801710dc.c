/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801710DC - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern u16 D_8011F73A;

void func_801710DC(u8 * arg0)
{
    ((M2C_UNK (*)(u16, u16))func_8002D4C8)(D_8011F738, D_8011F73A);
    ((M2C_UNK (*)(s32))func_80171928)(arg0);
}
