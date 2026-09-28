/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E778,8016E7C8).
 * Offset 0x46620 at overlay base 80128158. SHA256(span)=c1fdee1743c7112fc75f69db20cf9d875d7e36adaf9f60b46ba15766b02d1138.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e778.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E778 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016E7C8(int param_1, short *p1, unsigned int *p2);

void func_8016E778(int param_1)
{
    short local_18[3];
    unsigned int local_10;
    unsigned short uVar1;
    int iVar2;
    uVar1 = *(unsigned short *)(param_1 + 0x12);
    local_18[2] = uVar1;
    local_18[1] = uVar1;
    local_18[0] = uVar1;
    iVar2 = *(short *)(param_1 + 0x16);
    local_10 = iVar2 | (iVar2 << 16 | iVar2 << 8);
    func_8016E7C8(param_1, local_18, &local_10);
}
