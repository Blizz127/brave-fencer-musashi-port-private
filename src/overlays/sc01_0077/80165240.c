/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165240 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct W4 { u32 w; } __attribute__((packed, aligned(1)));
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_80016ED4(void *a0);
extern s32 func_80017DC4(void *a0, void *a1);

void func_80165240(void *param_1, void *param_2, void *param_3)
{

    extern u8 D_80189750[];
    extern u32 D_80189770, D_80189774, D_80189778, D_8018977C;
    extern u32 D_80189770, D_80189774, D_80189778, D_8018977C;
    extern u32 D_80189770, D_80189774, D_80189778, D_8018977C;
    extern u32 D_80189770, D_80189774, D_80189778, D_8018977C;
    u8 prim[0x40];   /* $sp+0x10 .. 0x50 */
    u8 mat[0x20];    /* $sp+0x50 .. 0x70 */
    u8 *p = prim;

    func_80017DC4(param_2, mat);
    func_80048FBC(mat, &D_80189750[0x00], p);
    func_80048FBC(mat, &D_80189750[0x08], prim + 0x08);
    func_80048FBC(mat, &D_80189750[0x10], prim + 0x10);
    func_80048FBC(mat, &D_80189750[0x18], prim + 0x18);

    *(s16 *)(prim + 0x04) = 3;
    prim[0x38] = 0x2c;
    *(u32 *)(prim + 0x20) = D_80189778;
    *(u32 *)(prim + 0x24) = D_80189770;
    *(u32 *)(prim + 0x28) = D_8018977C;
    *(u32 *)(prim + 0x2c) = D_80189774;
    *(struct W4 *)(prim + 0x30) = *(struct W4 *)param_3;
    *(u32 *)(prim + 0x34) = 0x50000000;

    func_80016ED4(p);
}
