/* SC02.CD member31 [8014CF04,8014D04C); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014CF04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s32 func_8014C918(s32 a0, s32 a1);

s32 func_8014CF04(s32 a0, s32 a1, void *a2) {
    extern u8 D_801202A0[];
    extern u8 D_80126720[];
    u8 *p;
    u8 *q;
    s32 t;
    p = D_801202A0;
    if (p < p + 0x6480) {
        q = p + 0x75;
    loop:
        if (*(u16 *)p != 0) {
            if ((*(u16 *)(q - 0x19) & 0x400) != 0) {
                t = *(s32 *)(q - 0x1D);
                if (t != 0) {
                    if (p != *(u8 **)(a0 + 0x178)) {
                        if (p != *(u8 **)(a0 + 0x174)) {
                            if (*(s16 *)(q - 0x6B) >= *(s16 *)(a0 + 0xA)) {
                                if (func_80135A4C(*(s32 *)(q - 0x55), t, (s32 *)a1, (s32)a2) != 0) {
                                    *(u8 **)(a0 + 0x174) = p;
                                    q[-1] = 1;
                                    *(u16 *)(a0 + 6) = *(u16 *)a2;
                                    *(u16 *)(a0 + 0xA) = *(u16 *)((u8 *)a2 + 2);
                                    *(u16 *)(a0 + 0xE) = *(u16 *)((u8 *)a2 + 4);
                                    *(u16 *)(a0 + 0x16E) = func_8014C918(a0, q[0]) & 0xFF;
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        p += 0x10C;
        q += 0x10C;
        if ((u32)p < (u32)D_80126720) {
            goto loop;
        }
    }
    return 0;
}
