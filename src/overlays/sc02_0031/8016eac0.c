/* SC02 resident retail span [8016EAC0,8016EB3C). Offset 0x46968 at base 80128158.
 * SHA256(span)=1f0dfb5a766d986330483885141f6703425e0edb21d3b4f6a4f729152bda106c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181740->D_80188030.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016EAC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    char _pad0;       /* 0x0 */
    unsigned char f1; /* 0x1 */
    unsigned char f2; /* 0x2 */
    char _pad3;       /* 0x3 */
    short f4;         /* 0x4 */
} Wave;
extern u16 D_80188030[];
extern void func_8016EC0C(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));

void func_8016EAC0(Wave *param_1)
{
    unsigned char bVar1;

    param_1->f4 = param_1->f4 + D_80188030[param_1->f2];
    ((void (*)(void *, int))func_8016EC0C)(param_1, 0x80);
    bVar1 = param_1->f2 + 1;
    param_1->f2 = bVar1;
    if (5 < bVar1) {
        param_1->f2 = 0x20;
        param_1->f1 = param_1->f1 + 1;
    }
}
