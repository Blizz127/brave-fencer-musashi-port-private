/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164ACC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801202A0[];
extern u8 D_80126720[];
extern s32 func_8014C308(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_8014C3A4(void *a0, s32 a1, s32 a2, s32 a3);

void func_80164ACC(s32 a0) {
    u8 *p;
    s16 buf[4];
    p = D_801202A0;
    if (p < p + 0x6480) {
        do {
            if (func_8014C308(a0, (s32)p, 0xB, 2) != 0) {
                if (func_8014C278(a0, (s32)p, 0x50) != 0) {
                    func_80015978((s32)(p + 4), (s32 *)buf);
                    buf[3] = 0;
                    func_8014C3A4((void *)a0, (s32)p, 0xB, (s32)buf);
                    *(s16 *)(p + 0x60) = (s16)(*(s16 *)(p + 0x60)) / 2;
                }
            }
            p += 0x10C;
        } while (p < D_80126720);
    }
}
