/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C588 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);

s32 func_8012C588(s32 a0, s32 a1) {
    s32 p;
    s32 end;
    s32 v0;
    s32 q;
    s16 sp[10];
    if (a1 != 0 && *(u16*)a1 != 0) {
        sp[0] = *(u16*)(a1 + 0x6);
        sp[1] = *(u16*)(a1 + 0xA);
        sp[2] = *(u16*)(a1 + 0xE);
    } else {
        sp[2] = 0;
        sp[1] = 0;
        sp[0] = 0;
    }
    sp[3] = a0;
    q = (s32)&sp[0];
    sp[5] = 0;
    sp[4] = 0;
    *(s32*)&sp[8] = 0;
    sp[7] = 0;
    sp[6] = 0x7FFF;
    end = (s32)D_801202A0 + 0x6480;
    if (a1 == 0) {
        p = (s32)D_801202A0;
    } else {
        p = a1 + 0x10C;
    }
    if (p != end) {
        for (;;) {
            if (*(u16*)p == 0) {
                goto found;
            }
            p += 0x10C;
            if (p == end) {
                break;
            }
        }
    }
    p = 0;
found:
    v0 = 0;
    if (p != 0) {
        v0 = func_8012C890(q, p, a1);
    }
    return v0;
}
