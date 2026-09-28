/* SC02.CD FILE_031 / ov_SC02_031 retail span [801723C4,80172414).
 * Offset 0x4A26C at overlay base 80128158. SHA256(span)=6cbd881d1707994f579f71a8129198d583f1395f208327b75df6911b3ed7cd84.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801723c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801723C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801599A4(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8014A1B0(s32 a0, s32 a1);

void func_801723C4(s32 param_1, s32 param_2)
{
    ((void (*)(void))func_801599A4)();
    ((void (*)(int, int))func_80147078)(param_1, 0xd);
    *(int *)(param_1 + 0x178) = param_2;
    func_8014A1B0(param_1, param_2);
}
