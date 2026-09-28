/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801528B0 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80146CA0(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147324(s32 a0);
extern void func_801474EC(s32 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80149020(s32 *a0);
extern void func_8014CBF8(void *a0);
extern int func_80151204(int arg, int a1);
extern void func_80154274(s32 *a0, s32 a1);
extern u8 D_80062C04[];
extern M2C_UNK D_800D5880;
extern M2C_UNK D_8017FD50;

void func_801528B0(s32 arg0)
{
    func_80019064(&D_80062C04);
    func_80151204(arg0, M2C_FIELD(arg0, s16 *, 0xF2));
    func_80149020(arg0);
    func_80154274(arg0, &D_800D5880);
    func_80147324(0x451);
    M2C_FIELD(arg0, s8 *, 0xDE) = 0x10;
    func_80146DB8(arg0, &D_8017FD50);
    func_801477E8(arg0, 0xFFF00000);
    func_8014CBF8(arg0);
    func_801474EC(arg0);
    func_80146CA0(arg0);
}
