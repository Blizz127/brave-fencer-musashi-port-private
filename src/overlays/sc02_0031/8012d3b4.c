/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012D3B4,8012D4B4).
 * Offset 0x525C at overlay base 80128158. SHA256(span)=60f4dc39f94daa013874d4e6664147f8e4795577b15a8eec4d1ce28d44cf3ccd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012d3b4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012D3B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80058C6C(s32, void *);
extern s32 func_8004955C(s32, s32, s32 *, s32 *);
extern void func_80058E9C(void *);
extern void *func_80010A08(s32);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern s32 D_800A651C;
extern u8 D_800AF648;
extern s16 D_800B9A02;

void func_8012D3B4(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp10;
    s32 sp14;
    s32 temp_v0_2;
    void *temp_v0;
    temp_v0 = func_80010A08(0x10);
    (*(s32 *)((s8*)(temp_v0)+(4))) = arg2;
    func_80058E9C(temp_v0);
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    temp_v0_2 = func_8004955C(arg0, temp_v0 + 8, &sp10, &sp14);
    if ((temp_v0_2 > 0) && (sp14 >= 0) && (func_8004955C(arg1, temp_v0 + 0xC, &sp10, &sp14) > 0) && (sp14 >= 0)) {
        func_80058C6C(*(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + (temp_v0_2 * 4), temp_v0);
    }
}
