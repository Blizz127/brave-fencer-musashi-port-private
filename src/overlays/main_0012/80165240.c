/* Overlay range [80165240,8016533C) from MAIN.CD member 0012.
 * SHA256(span)=08a0b072ab4dc8636ef76aa57b90290f8a2be04e6b67ca396560f1801bd47ead.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165240 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
typedef struct { s16 vx, vy, vz, pad; } Svec_801372B0;
struct W4 { u32 w; } __attribute__((packed, aligned(1)));
extern void ApplyMatrixSV(void *m, Svec_801372B0 *in, Svec_801372B0 *out);
extern void ApplyMatrixSV(void*, Svec_801372B0*, Svec_801372B0*);
extern s32  func_80017DC4(void *a0, void *a1);
extern void func_80016ED4(void *a0);

void func_80165240(void *param_1, void *param_2, void *param_3)
{

    extern u8  D_80180FB4[];
    extern u32 D_80180FD4, D_80180FD8, D_80180FDC, D_80180FE0;
    u8 prim[0x40];    
    u8 mat[0x20];     
    u8 *p = prim;

    func_80017DC4(param_2, mat);
    ((void (*)(void *, void *, void *))ApplyMatrixSV)(mat, &D_80180FB4[0x00], p);
    ((void (*)(void *, void *, void *))ApplyMatrixSV)(mat, &D_80180FB4[0x08], prim + 0x08);
    ((void (*)(void *, void *, void *))ApplyMatrixSV)(mat, &D_80180FB4[0x10], prim + 0x10);
    ((void (*)(void *, void *, void *))ApplyMatrixSV)(mat, &D_80180FB4[0x18], prim + 0x18);

    *(s16 *)(prim + 0x04) = 3;
    prim[0x38] = 0x2c;
    *(u32 *)(prim + 0x20) = D_80180FDC;
    *(u32 *)(prim + 0x24) = D_80180FD4;
    *(u32 *)(prim + 0x28) = D_80180FE0;
    *(u32 *)(prim + 0x2c) = D_80180FD8;
    *(struct W4 *)(prim + 0x30) = *(struct W4 *)param_3;
    *(u32 *)(prim + 0x34) = 0x50000000;

    func_80016ED4(p);
}
