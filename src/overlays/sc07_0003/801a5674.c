/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5674 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 x; s16 y; s16 z; s16 pad; } SVec801A5674;
typedef struct { SVec801A5674 v[2]; s32 col[2]; s32 tag; s32 pad; } Prim801A5674;
extern void func_8012C218(void *a0);
extern void func_8012EC04(s32 param_1, s32 param_2, s32 *param_3);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8012CC40(s32 a0, s32 a1);
extern s32 func_80016A5C();

void func_801A5674(void *arg0) {
    u16 out[4];        /* sp+0x10 */
    s32 buf[8];        /* sp+0x18 */
    Prim801A5674 prim; /* sp+0x38 */
    s32 e;
    u16 st;
    s32 p;

    e = (s32)arg0;
    if (*(s16 *)(e + 0xA) >= 0x10) {
        func_8012C218(arg0);
        return;
    }

    switch (*(u16 *)(e + 0x34)) {
    case 0:
        p = *(s32 *)(e + 0x64);
        if (*(s16 *)(e + 0x10A) == *(s16 *)(p + 0x36)) {
            func_8012EC04(p, *(s16 *)(e + 0xFC), buf);
            ((void (*)(s32 *, s32, u16 *))func_8012F14C)(buf, *(s32 *)(e + 0xDC), out);
            *(u16 *)(e + 0x6) = out[0];
            *(u16 *)(e + 0xA) = out[1];
            *(u16 *)(e + 0xE) = out[2];
        }
        *(s32 *)(e + 0xE4) += *(s32 *)(e + 0xE8);
        if (*(s32 *)(e + 0xE4) >= *(s32 *)(e + 0xE0)) {
            *(s32 *)(e + 0xE4) = *(s32 *)(e + 0xE0);
            *(u16 *)(e + 0x34) += 1;
        }
        break;
    case 1:
        out[2] = 0;
        out[0] = 0;
        out[1] = *(s32 *)(e + 0xE4);
        if (((s32 (*)(s32, u16 *))func_8012CC40)(e, out) & 0x2000) {
            *(u16 *)(e + 0x34) += 1;
        }
        break;
    case 2:
        *(s32 *)(e + 0xEC) += 0x10;
        if (*(s32 *)(e + 0xEC) >= *(s32 *)(e + 0xE4)) {
            func_8012C218((void *)e);
            return;
        }
        break;
    }

    prim.v[1].z = 0;
    prim.v[1].x = 0;
    prim.v[0].z = 0;
    prim.v[0].x = 0;
    prim.tag = 0x50000000;
    st = *(u16 *)(e + 0x34);
    prim.col[0] = 0x808080;
    prim.col[1] = 0x101010;
    if (st < 2) {
        prim.v[0].y = *(s32 *)(e + 0xE4);
        prim.v[1].y = 0;
    } else {
        prim.v[0].y = *(s32 *)(e + 0xE4);
        prim.v[1].y = *(s32 *)(e + 0xEC);
    }
    func_80016A5C(&prim, *(s32 *)(e + 0x20) + 0x34);
}
