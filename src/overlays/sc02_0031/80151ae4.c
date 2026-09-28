/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151AE4,80151B98).
 * Offset 0x2998C at overlay base 80128158. SHA256(span)=e05d2fb3c09e6ba064409e9faedcfa27bf9952c2972b19ab56461ea863d84229.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151ae4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151AE4 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void func_80149020(s32 *a0);
extern void func_80151C54(s32 a0);
extern void func_80159B3C(void *a0);
extern void func_801542DC(s32 *a0, s32 a1);
extern void func_8014E934(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern void func_8014CC28(s32 a0);
extern void func_8015BDD0(s32 *a0);
extern void func_80165718(s32 a0);
extern u8 D_800D46E4[];
extern M2C_UNK D_800D5880;

void func_80151AE4(s32 arg0)
{
    func_80149020(arg0);
    if (*(u16 *)((s32)arg0 + 0xB8) == 0x8000) {
        func_80151C54(arg0);
        func_80159B3C(arg0);
        if (*(s32 *)((s32)arg0 + 0xB4) == (s32)&D_800D5880) {
            ((void (*)(s32, s32, s32))func_801542DC)(arg0, (s32)D_800D46E4, 0xE);
        }
    } else {
        func_8014E934(arg0);
        if (((s32 (*)(s32))func_8014F3E8)(arg0) != 0) {
            return;
        }
        if (((s32 (*)(s32))func_8014CC28)(arg0) != 0) {
            return;
        }
        func_80151C54(arg0);
        func_8015BDD0(arg0);
    }
    func_80165718(arg0);
}
