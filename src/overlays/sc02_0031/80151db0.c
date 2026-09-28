/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151DB0,80151E78).
 * Offset 0x29C58 at overlay base 80128158. SHA256(span)=c278d91d14398415e953abacddc1ac31580f3e74f548b66627ed1419ccc3e8ae.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151db0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151DB0 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void func_80019064(void *a0);
extern int func_80151204(int arg, int a1);
extern s32 func_80012A60(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80149020(s32 *a0);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(void *a0);
extern s32 func_80172630(u8 *a0);
extern s32 D_80062C14;
extern M2C_UNK D_800D5880;
extern s32 D_800D58AC;

void func_80151DB0(s32 param_1)
{
    short sVar1;
    unsigned short uVar2;
    int iVar3;
    func_80019064(&D_80062C14);
    ((void (*)(int, int))func_80151204)(param_1, (int)*(short *)(param_1 + 0xf2));
    sVar1 = ((short (*)(int, int))func_80012A60)((int)*(short *)(*(int *)(param_1 + 0x20) + 0x12),
                          (int)*(short *)(param_1 + 0xf4));
    if (sVar1 >= 0x401) {
        ((void (*)(int, void *))func_80154274)(param_1, &D_800D5880);
        iVar3 = *(int *)(param_1 + 0x20);
        uVar2 = 0xc00;
    } else {
        ((void (*)(int, void *))func_80154274)(param_1, &D_800D58AC);
        iVar3 = *(int *)(param_1 + 0x20);
        uVar2 = 0x400;
    }
    *(unsigned short *)(iVar3 + 0x10) = uVar2;
    *(unsigned short *)(param_1 + 100) = 0xcc;
    __asm__ __volatile__("" : : "r"(param_1));
    ((void (*)(int))func_80149020)(param_1);
    func_80147324(0x436);
    ((void (*)(int))func_80146CA0)(param_1);
    ((void (*)(int))func_80172630)(param_1);
}
