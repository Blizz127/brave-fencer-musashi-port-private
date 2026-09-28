/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4DFC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 m[3][3]; s32 t[3]; } Mtx32_801A4DFC;
extern Mtx32_801A4DFC D_800AE620;
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8012B8A4(s16 *a0);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern s32 D_80126B58;
extern s32 D_801A7318[];
extern u8 D_801152A8[];

s32 func_801A4DFC(void *a0)
{
    Mtx32_801A4DFC mtx;
    s32 buf1[2];
    s32 buf2[2];
    u8 *p;
    u8 *q;
    u8 *b58;
    u8 *base;
    s32 i;
    s32 v0;

    mtx = D_800AE620;

    func_8004A0DC(*(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x14), &mtx);

    b58 = (u8 *)&D_80126B58;
    i = 0;

    mtx.t[0] = *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x48);
    mtx.t[1] = *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x4C);

    base = (u8 *)D_801A7318;
    q = base + 8;

    mtx.t[2] = *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x50);

    p = base;

    for (; i < 10; q += 0x10, i += 2, p += 0x10) {
        func_8012F14C((s32)&mtx, (s32)p, (s32)buf1);
        func_8012F14C((s32)&mtx, (s32)q, (s32)buf2);
        v0 = func_80135888(*(s32 *)(b58 + 0x20),
                            *(s32 *)(b58 + 0x38),
                            (s32)buf1, (s32)buf2);
        if (v0 != 0) {
            v0 = func_8012B8A4((s16 *)a0);
            func_8012F568(1, 0x4201, v0, 0x32, (s32)buf2, (s32)D_801152A8);
            return 1;
        }
    }

    return 0;
}
