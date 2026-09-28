/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3490 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80190C84 {
    s16 f0, f2, f4, f6, f8, fA, fC, fE;
    s32 f10;
};
extern void func_8012E9C0(s32 a0);
extern void func_8002A520(s32 a0);
extern void func_8002A790(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012C51C(void *a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_801A38E4(void *a0, void *a1, s32 a2, s32 a3, s32 a4);
extern u16 D_801F43C0;
struct V8 { u16 vx, vy, vz, pad; };

void func_801A3490(s32 p)
{
    s32 linked;
    s32 pCC;

    pCC = p + 0xCC;
    linked = *(s32 *)(p + 0x64);

    if (*(u16 *)(p + 0x5C) & 1) {
        s32 tbl;
        s32 dec;

        *(u16 *)(p + 0x60) = 0x280;
        func_8012E9C0(p);

        if (*(u16 *)(p + 0x5E) != 0x1D) {
            if (*(u8 *)(p + 0xC8)) func_8002A520(p);
            if (*(u8 *)(p + 0xC9)) func_8002A790(p);
        }

        tbl = *(s32 *)(p + 0x78);
        dec = ((s32)*(s16 *)(p + 0x60) * (s32)*(s16 *)(tbl + 0x30)) >> 12;
        if (dec <= 0) {
            dec = 1;
        }

        {
            s16 t = *(u16 *)(linked + 0x76) - dec;
            *(s16 *)(linked + 0x76) = t;
            if (t < 0) {
                *(s16 *)(linked + 0x76) = 0;
            }
        }

        *(s32 *)(linked + 0xE0) |= 0x20;
        func_8002D4C8(0xB9F, 0);

        {
            struct S80190C84 sp;
            sp.f0 = *(u16 *)(p + 0x7C);
            sp.f2 = *(u16 *)(p + 0x7E);
            sp.f4 = *(u16 *)(p + 0x80);
            sp.f6 = 0x3D5;
            sp.fA = 0;
            sp.f8 = 0;
            sp.f10 = 0;
            sp.fE = 0;
            sp.fC = 0x7FFF;
            func_8012C51C(&sp, p);
        }

        func_8012C218((void *)p);
    } else {
        func_801A38E4((void *)linked, (void *)pCC, (s32)D_801F43C0, 3, 1);

        *(struct V8 *)(*(s32 *)(p + 0x20) + 0x10) =
            *(struct V8 *)(*(s32 *)(linked + 0x20) + 0x10);

        *(s32 *)(p + 4) = *(s32 *)(linked + 4);
        *(s32 *)(p + 8) = *(s32 *)(linked + 8);
        *(s32 *)(p + 0xC) = *(s32 *)(linked + 0xC);
    }
}
