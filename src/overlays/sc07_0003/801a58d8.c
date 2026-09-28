/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A58D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct { s16 vx, vy, vz, pad; } SVECTOR;
extern void (*D_801A7434[])(void);
extern u16 D_801A7422;
extern u16 D_801A7424;
extern u16 D_801A7426;
extern u16 D_801A742E;
extern u16 D_801A7430;
extern u16 D_801A7432;
extern u8 D_800D3918[];
extern void func_8012EC04(s32 a0, s32 a1, s32 *a2);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8012B2CC(s32 a0);

void func_801A58D8(void *a0) {
    s32 p;
    s32 v0;
    s32 v1;
    MATRIX m1;
    SVECTOR svec_out;

    D_801A7434[*(u16 *)((s32)a0 + 0x2)]();

    if (*(u16 *)((s32)a0 + 0x0) != 0) {
        p = *(s32 *)((s32)a0 + 0x64);
        v0 = *(s32 *)(p + 0x20);
        v1 = *(s32 *)(v0 + 0x20);

        D_801A7422 = *(u16 *)(v1 + 0xD2);
        D_801A7424 = *(u16 *)(v1 + 0xD4);
        D_801A7426 = *(u16 *)(v1 + 0xD6);
        D_801A742E = *(u16 *)(v1 + 0xDE);
        D_801A7430 = *(u16 *)(v1 + 0xE0);
        D_801A7432 = *(u16 *)(v1 + 0xE2);

        func_8012EC04(p, 0x11, (s32 *)&m1);
        func_8012F14C((s32)&m1, (s32)D_800D3918, (s32)&svec_out);

        *(s16 *)((s32)a0 + 0x6) = svec_out.vx;
        *(s16 *)((s32)a0 + 0xA) = svec_out.vy;
        *(s16 *)((s32)a0 + 0xE) = svec_out.vz;
        func_8012B2CC((s32)a0);
    }
}
