/* SC02 resident retail span [80174BF4,80174C60). Offset 0x4CA9C at base 80128158.
 * SHA256(span)=e25adac374471d8a77a5279883bb13ad0a13258fc9d66b3527c2ec059590c71a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819F8->D_801882E8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174BF4 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void (*D_801882E8[])(void *);

void func_80174BF4(void * arg0)
{
    M2C_FIELD(arg0, s32 *, 0xC) = 0x12C;
    M2C_FIELD(arg0, s32 *, 0x14) = 0x12C;
    M2C_FIELD(arg0, s16 *, 0x20) = 0x155;
    M2C_FIELD(arg0, s16 *, 0x22) = 0x800;
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s16 *, 0x2E) = 0;
    M2C_FIELD(arg0, s16 *, 0x30) = -0x28;
    M2C_FIELD(arg0, s16 *, 0x32) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    D_801882E8[M2C_FIELD(arg0, u8 *, 4)](arg0);
}
