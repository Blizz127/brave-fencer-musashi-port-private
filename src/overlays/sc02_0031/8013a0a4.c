/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013A0A4,8013A164).
 * Offset 0x11F4C at overlay base 80128158. SHA256(span)=c3064f7562d2197a6bf2ea4b2fd03f748347a5116a56440094686c4e9036d6d1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013a0a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A0A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S8013A0A4 {
    u8 pad0[4];
    s16 field_4;
    u8 pad6[2];
    s32 field_8;
    u8 pad12[10];
    u16 field_16;
    u8 pad18[6];
    u8 field_1E;
    u8 pad1F[15];
    s16 field_2E;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);

void func_8013A0A4(struct S8013A0A4 *a0) {
    if (a0->field_1E != 0) {
        a0->field_1E = a0->field_1E + 5;
    } else {
        a0->field_1E = 4;
    }
    if (a0->field_1E >= 0xC) {
        a0->field_16 = (a0->field_16 + 1) % (a0->field_2E + 1);
        a0->field_1E = 0;
        if (a0->field_8 & 0x100) {
            a0->field_4 = 6;
        } else {
            a0->field_4 = 2;
        }
    }
    func_80139A8C((s32)a0);
    func_80139B18((s32)a0);
}
