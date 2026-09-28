/* SC02 resident retail span [8013C9C4,8013CA14). Offset 0x1486C at base 80128158.
 * SHA256(span)=39574d33410846cba45b5bbad8151beea1f7b2018350a2a433f164c1b24b825f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * retargeted for this member: D_801A44C0->D_801B6350; D_801A44C4->D_801B6354; D_801A44C5->D_801B6355.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013C9C4 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void func_80019064(void *);
extern M2C_UNK D_80062BC0;
extern s32 D_801B6350;
extern s8 D_801B6354;
extern s8 D_801B6355;

void func_8013C9C4(void * arg0)
{
    D_801B6350 = arg0;
    D_801B6354 = 0;
    D_801B6355 = 0;
    if (func_80019198() == 0) {
        func_80019064(&D_80062BC0);
    }
}
