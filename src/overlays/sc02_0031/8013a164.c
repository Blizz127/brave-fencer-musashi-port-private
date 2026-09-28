/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013A164,8013A1E8).
 * Offset 0x1200C at overlay base 80128158. SHA256(span)=3f9d98342e371b7c45d56d95a944000247d0a803e607e0996e15a1d49e7ddc36.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013a164.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A164 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S8013A164 {
    char pad0[0x4];
    s16 field_04;      /* 0x04 */
    char pad06[0x2];
    s32 field_08;      /* 0x08 */
    char pad0C[0xC];
    u16 field_18;      /* 0x18 */
    char pad1A[0x26];
    s16 *field_40;     /* 0x40 */
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_8012752C;

void func_8013A164(struct S8013A164 *a0) {
    s32 flags;
    if (a0->field_40 == 0 || a0->field_18 == 0 || *a0->field_40 == 2) {
        flags = a0->field_08 | 0x1000;
        a0->field_08 = flags;
        if (flags & 0x10000) {
            if (D_8012752C != 0) {
                if (flags & 0x40000) {
                    a0->field_04 = 2;
                } else {
                    a0->field_04 = 0x10;
                }
            } else {
                a0->field_04 = 2;
            }
        } else {
            a0->field_04 = 2;
        }
    }
}
