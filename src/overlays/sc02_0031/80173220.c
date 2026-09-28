/* SC02 resident retail span [80173220,80173294). Offset 0x4B0C8 at base 80128158.
 * SHA256(span)=cbe51b1a180016100f5b89e7ff00dfdfb0695f96d0a7304ee10e64ce485194d4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818F8->D_801881E8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173220 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80019064(void *a0);
extern void func_80147324(s32 a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern M2C_UNK D_801881E8;

void func_80173220(void * arg0)
{
    if (M2C_FIELD(arg0, u16 *, 0xB8) & 0x4000) {
        func_80147324(0x516);
        func_80019064(&D_801881E8);
    }
    if (M2C_FIELD(arg0, u16 *, 0xB8) & 0x8000) {
        func_80171A1C(arg0);
        func_80174650(arg0);
    }
}
