/* SC02 resident retail span [80165E2C,80165E90). Offset 0x3DCD4 at base 80128158.
 * SHA256(span)=5da1e18dad2c554a6444b3790f478349a8f36ea92dcb3f3a892abb02d3ca3bb1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018394C->D_801B5D58.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165E2C - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern M2C_UNK D_801B5D58;

void func_80165E2C(u16 *arg0) {
    func_8001534C(0, &D_801B5D58, 0x80, 0x80, 0, 0);
    func_800153CC(1, *arg0, 0xA8, 0x80, 0x40, 0);
}
