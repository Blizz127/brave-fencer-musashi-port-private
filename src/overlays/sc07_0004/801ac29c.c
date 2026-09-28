/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC29C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8001D074(s32 a0, s32 a1);
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C2C4(s32 a0);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80143994(s32 a0, s32 a1);
extern void func_801A94A0();
extern u8 D_801B0610[];

void func_801AC29C(void *a0) {
    void *s1;
    s32 s0;
    s32 v0;
    s32 v1;

    s1 = a0;
    s0 = func_8001D074(0x7E, 0x100);
    *(s32 *)((s32)s1 + 0xCC) = s0;
    v0 = func_8012C1B8();
    *(s32 *)((s32)s1 + 0x20) = v0;
    if (v0 == 0 || s0 == 0) {
        func_8012CAE4(s1);
        return;
    }
    func_8001C2C4(v0);

    func_8001CC3C(s0, (s32)D_801B0610, 0x300, 0x100);
    *(s8 *)(s0 + 0x27) = 0x64;
    *(s16 *)(s0 + 0x8) = *(u16 *)((s32)s1 + 0x6);
    *(s16 *)(s0 + 0xA) = *(u16 *)((s32)s1 + 0xA);
    *(s16 *)(s0 + 0xC) = *(u16 *)((s32)s1 + 0xE);
    *(u16 *)(s0 + 0x2C) = 0xC040;
    *(s32 *)(s0 + 0x4) |= 0x50000000;

    if (!(*(u16 *)((s32)s1 + 0x70) & 0x100)) {
        v1 = 1;
        *(s16 *)((s32)s1 + 0xFE) = v1;
    } else {
        *(s16 *)(s0 + 0x18) = 0x1800;
        *(s16 *)(s0 + 0x1A) = 0x5000;
        v1 = 0x3000;
        *(s16 *)((s32)s1 + 0xFE) = 0;
    }

    {
        register void *ra0 __asm__("$4") = s1;
        __asm__ __volatile__("" : "=r"(ra0) : "0"(ra0));
        *(u16 *)((s32)s1 + 0x70) = *(u8 *)((s32)s1 + 0x70);
        v0 = ((s32 (*)(s32, s32))func_80143994)((s32)ra0, v1);
    }
    *(s32 *)((s32)s1 + 0xD0) = v0;
    if (v0 != 0) {
        s0 = *(s32 *)(v0 + 0xCC);
        if (s0 != 0) {
            *(u16 *)(s0 + 0x2C) = 0xC030;
        }
    }
    func_801A94A0(s1);
}
