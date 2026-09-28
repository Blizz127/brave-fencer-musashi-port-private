/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152BF0,80152C40).
 * Offset 0x2AA98 at overlay base 80128158. SHA256(span)=9ce5502b292a0e8aad50b07b28f35afa5c5968850866cfb73a59c118b1cb6144.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152bf0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152BF0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80062C14;
extern void func_80019064(void *a0);
extern int func_80151204(int arg, int a1);
extern void func_80149020(s32 *a0);
extern void func_80146CA0(void *a0);

void func_80152BF0(s32 a0)
{
    func_80019064(&D_80062C14);
    func_80151204((int)a0, *(s16 *)((s32)a0 + 0xF2));
    func_80149020((s32 *)a0);
    func_80146CA0(a0);
}
