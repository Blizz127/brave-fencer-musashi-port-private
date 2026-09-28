/* SC02.CD FILE_031 / ov_SC02_031 retail span [80136D08,80136DFC).
 * Offset 0xEBB0 at overlay base 80128158. SHA256(span)=ce8170763c0523add0ae9c75ac28bc5dd458c5245f45fb319586983f90a390a9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80136d08.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80136D08 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80058EB0(void *);
extern void *func_80010A08(s32);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern s32 D_800A651C;
extern u8 D_800AF648;
extern s16 D_800B9A02;

void func_80136D08(s32 arg0, s32 arg1) {
    s32 sp10;
    s32 sp14;
    s32 temp_v0;
    s32 temp_v0_2;
    void *buf;
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    buf = func_80010A08(0x14);
    func_80058EB0(buf);
    *((u8 *)buf + 0xE) = 0xFF;
    *((u8 *)buf + 0x4) = 0xFF;
    *((u8 *)buf + 0xD) = 0x80;
    *((u8 *)buf + 0x5) = 0x80;
    *((u8 *)buf + 0xC) = 0x80;
    *((u8 *)buf + 0x6) = 0x80;
    temp_v0 = func_8004955C(arg0, (s32)buf + 8, &sp10, &sp14);
    temp_v0_2 = func_8004955C(arg1, (s32)buf + 0x10, &sp10, &sp14);
    temp_v0 = ((temp_v0 + temp_v0_2) >> 3) * 4;
    func_80058C6C(*(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + temp_v0, buf);
}
