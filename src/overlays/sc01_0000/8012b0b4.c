/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B0B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern int func_80047948(int a0);
extern int func_8004787C(int a0);

void func_8012B0B4(unsigned int *param_1, int param_2, int param_3)
{
    int iVar1, iVar2;
    register int prod __asm__("$7");          /* mflo dest = $a3 (both products) */
    register unsigned int *p __asm__("$2");    /* store addr copied into $v0 */
    register int sh1 __asm__("$2");            /* shares $v0 with p (non-overlapping) */
    register int sh2 __asm__("$3");            /* 2nd-product shift -> $v1 */
    unsigned int uVar3, result;
    uVar3 = (param_2 - 0x400U) & 0xfff;
    iVar1 = func_80047948(uVar3);
    result &= 0xFFFF0000;
    prod = iVar1 * param_3;
    sh1 = prod >> 0xc;
    result |= sh1 & 0xFFFF;
    iVar2 = func_8004787C(uVar3);
    prod = iVar2 * -param_3;
    result &= 0xFFFF;
    /* Force the param_1->$v0 copy AND let the scheduler hoist it into the
       mult->mflo delay slot (a plain `p = param_1` gets coalesced away). */
    __asm__ ("addu %0,%1,$zero" : "=r"(p) : "r"(param_1));
    sh2 = prod >> 0xc;
    result |= sh2 << 0x10;
    *p = result;
}
