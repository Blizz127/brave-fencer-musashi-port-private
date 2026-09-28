/* SC02 resident retail span [80171EC8,80171FFC). Offset 0x49D70 at base 80128158.
 * SHA256(span)=9935df8a2c2b12b15423234d90a1f1a4e1b228461149cfa0cb592f73d21cdba1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_80171EC8 shape (h_exact 0dfc2a4f) with ratan2 bound to func_8004CFEC and D_801151D4 already matching this member; oracle MATCH 77/77.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171EC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 D_801151D4;

void func_80171EC8(s32 a0) {
    s32 base = D_801151D4;
    s32 s0;
    s32 s1;
    s32 v1;
    s32 ang;
    *(s8 *)(a0 + 0xA9) = 0x73;
    ang = func_8004CFEC(*(s32 *)(base + 0x68) - *(s32 *)(base + 0x5C),
                 *(s32 *)(base + 0x70) - *(s32 *)(base + 0x64));
    s0 = (ang + 0x800) & 0xFFF;
    s0 = (*(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) - s0) & 0xFF8;
    if (s0 == 0x400 || s0 == 0xC00) {
        s1 = 0x80;
    } else {
        s32 t = -(func_80047948(s0) << 7);
        if (t < 0) {
            t += 0xFFF;
        }
        s1 = (t >> 12) + 0x80;
    }
    if (s1 < 0) {
        s1 = 0;
    }
    if (!(s1 < 0x100)) {
        s1 = 0xFF;
    }
    if (s0 == 0 || s0 == 0x800) {
        v1 = 0x80;
    } else {
        s32 t = func_8004787C(s0);
        if (t < 0) {
            t += 0x1F;
        }
        v1 = (t >> 5) + 0x80;
    }
    if (v1 < 0) {
        v1 = 0;
    }
    if (!(v1 < 0x100)) {
        v1 = 0xFF;
    }
    *(s16 *)(a0 + 0xAE) = (v1 & 0xFF) | (s1 << 8);
}
