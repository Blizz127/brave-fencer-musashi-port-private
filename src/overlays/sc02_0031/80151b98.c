/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151B98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern void func_80151C54(s32 a0);
extern void func_80159B3C(void *a0);
extern s32 func_801535F4(void *arg0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80165718(s32 a0);

void func_80151B98(int param_1)
{
    int iVar1;
    ((int (*)(int))func_80149020)(param_1);
    if (*(unsigned short *)(param_1 + 0xb8) == 0x8000) {
        func_80151C54(param_1);
        ((void (*)(int))func_80159B3C)(param_1);
        goto LAB_80151c38;
    }
    iVar1 = ((int (*)(int))func_801535F4)(param_1);
    if (iVar1 == 1) goto LAB_80151c04;
    if (iVar1 < 2) return;
    if (iVar1 == 2) goto LAB_80151c1c;
    return;
LAB_80151c04:
    func_80151C54(param_1);
    ((void (*)(int))func_80159B3C)(param_1);
    goto LAB_80151c30;
LAB_80151c1c:
    func_80151C54(param_1);
    ((void (*)(int))func_8015BF48)(param_1);
LAB_80151c30:
    func_8014C010(param_1, 1);
LAB_80151c38:
    func_80165718(param_1);
    return;
}
