/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130514,801305CC).
 * Offset 0x83BC at overlay base 80128158. SHA256(span)=480310b8de81e6c78e5f60395b41b7980dc63398379bbb11557a4ffe6741e93d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130514.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130514 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012CBF4(s32 a0);
extern void func_801319E0(int);
extern int func_80131D68(int, int);
extern int func_8012BEE8(int);
extern void func_80131CA8(int, int);

void func_80130514(int param_1)
{
    unsigned int uVar1;
    if ((*(unsigned int *)(param_1 + 0xb4) & 0x40) != 0) {
        uVar1 = ((int (*)(void))func_8012CBF4)();
        if (0xf < *(short *)(param_1 + 10)) {
            func_801319E0(param_1);
            return;
        }
        if (func_80131D68(param_1, uVar1) == 1) {
            return;
        }
        if (func_8012BEE8(param_1) != 0) {
            if ((uVar1 & 0x2000) != 0) {
                *(unsigned char *)(param_1 + 0xc1) = 0;
                *(unsigned short *)(param_1 + 0x5e) = 0;
                func_80131CA8(param_1, 0xe);
            }
        }
    }
    /* Scheduling barrier: blocks gcc-2.7.2 reorg from hoisting the join-block
       `move $a0,$s0` into the first branch's delay slot (target keeps a nop there). */
    __asm__ __volatile__("");
    func_80131CA8(param_1, 0x13);
}
