/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012D4B4,8012D5DC).
 * Offset 0x535C at overlay base 80128158. SHA256(span)=86bb12d16fb4a0869224207b0566817e8ec3dde2293f7741a5e83989f668d154.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012d4b4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012D4B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_80058C6C(s32, void *);
extern s32 func_8004955C(s32, s32, s32 *, s32 *);
extern void func_80058E9C(void *);
extern void *func_80010A08(s32);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern s32 D_800A651C;
extern u8 D_800AF648;
extern s16 D_800B9A02;

void func_8012D4B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp10[2];
    s32 sp18[2];
    s32 sp20;
    s32 sp24;
    s32 temp_v0_2;
    void *temp_v0;
    func_8012F214(arg0, arg1, (s32)sp10);
    func_8012F214(arg0, arg2, (s32)sp18);
    temp_v0 = func_80010A08(0x10);
    (*(s32 *)((s8 *)(temp_v0) + (4))) = arg3;
    func_80058E9C(temp_v0);
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    temp_v0_2 = func_8004955C((s32)sp10, temp_v0 + 8, &sp20, &sp24);
    if ((temp_v0_2 > 0) && (sp24 >= 0) &&
        (func_8004955C((s32)sp18, temp_v0 + 0xC, &sp20, &sp24) > 0) && (sp24 >= 0)) {
        func_80058C6C(*(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + (temp_v0_2 * 4), temp_v0);
    }
}
