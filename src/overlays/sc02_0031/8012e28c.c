/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E28C,8012E32C).
 * Offset 0x6134 at overlay base 80128158. SHA256(span)=188ac574d0b148b6b66ad16e4ca6bae4c0b1db1e906f5262083330221f36a64b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e28c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012E28C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80058C6C(s32, void *);
extern void *func_80010A08(s32);
extern s32 func_80058B40(s32, s32, s32, s32);
extern s32 func_8005A600(s32, s32, s32, s32, s32);
extern s32 D_800A651C;
extern s16 D_800B9A02;

void func_8012E28C(s32 arg0, s32 arg1) {
    void *temp_v0;
    s32 temp_v1;
    s32 base;
    if (arg0 > 0) {
        base = *(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + (arg0 * 4);
        temp_v0 = func_80010A08(0xC);
        temp_v1 = func_80058B40(0, arg1, 0, 0);
        func_8005A600((s32)temp_v0, 0, 0, (u16)temp_v1, 0);
        func_80058C6C(base, temp_v0);
    }
}
