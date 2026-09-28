/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165240 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
struct W4 { u32 w; } __attribute__((packed, aligned(1)));
extern void ApplyMatrixSV(void *a0, void *a1, void *a2);
extern void func_80016ED4(void *a0);
extern s32 func_80017DC4(void *a0, void *a1);

void func_80165240(void *param_1, void *param_2, void *param_3)
{

    extern u8 D_80180910[];
    extern u32 D_80180930, D_80180934, D_80180938, D_8018093C;
    extern u32 D_80180930, D_80180934, D_80180938, D_8018093C;
    extern u32 D_80180930, D_80180934, D_80180938, D_8018093C;
    extern u32 D_80180930, D_80180934, D_80180938, D_8018093C;
    u8 prim[0x40];    
    u8 mat[0x20];     
    u8 *p = prim;

    func_80017DC4(param_2, mat);
    ApplyMatrixSV(mat, &D_80180910[0x00], p);
    ApplyMatrixSV(mat, &D_80180910[0x08], prim + 0x08);
    ApplyMatrixSV(mat, &D_80180910[0x10], prim + 0x10);
    ApplyMatrixSV(mat, &D_80180910[0x18], prim + 0x18);

    *(s16 *)(prim + 0x04) = 3;
    prim[0x38] = 0x2c;
    *(u32 *)(prim + 0x20) = D_80180938;
    *(u32 *)(prim + 0x24) = D_80180930;
    *(u32 *)(prim + 0x28) = D_8018093C;
    *(u32 *)(prim + 0x2c) = D_80180934;
    *(struct W4 *)(prim + 0x30) = *(struct W4 *)param_3;
    *(u32 *)(prim + 0x34) = 0x50000000;

    func_80016ED4(p);
}
