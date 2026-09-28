/* SC02 resident retail span [8012DB84,8012DBD0). Offset 0x5A2C at base 80128158.
 * SHA256(span)=74373e2ad41f9dcbe5fe8dd7129eac3e589d4493ddeec019d6179b5e56637e36.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E6C4->D_80184FB4; D_8017E6CC->D_80184FBC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012DB84 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern void func_8014C978(void);
extern M2C_UNK D_80184FB4;
extern M2C_UNK D_80184FBC;

s32 func_8012DB84(void)
{
    func_8014C978();
    func_8012F568(1, 0xC001, 0, 0x3E8, &D_80184FB4, &D_80184FBC);
}
