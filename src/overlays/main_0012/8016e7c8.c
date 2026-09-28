/* Overlay range [8016E7C8,8016E8F0) from MAIN.CD member 0012.
 * SHA256(span)=4714b0d45805f283cd893c829eefbec0143569028ad8b8837b3d0b3d55b5e4a1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E7C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransSV func_8004945C
typedef struct { short vx, vy, vz, pad; } SVECTOR;
typedef struct { short m[3][3]; short pad; s32 t[3]; } MATRIX_c2;
typedef struct {
    SVECTOR v[4];                
    s32 f0, f1, f2, f3, f4, f5;  
    u8  f6;                      
    u8  pad[7];                  
} Prim_8016E7C8_8016E7C8;
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void RotTransSV(s32 a0, s32 a1, void *a2);
extern void func_8004914C();
extern void func_800491AC();
extern s32  func_80017DC4(void *a0, void *a1);
extern void func_80016ED4(void *a0);
extern s32 func_80017DC4(void *a0, void *a1);

void func_8016E7C8(int param_1, short *param_2, unsigned int *param_3)
{
    extern void func_8004914C(void *a0);
    extern void func_800491AC(void *a0);
    extern void RotTransSV(s32, s32, void*);
    extern void func_80016ED4(void *a0);
    extern SVECTOR D_801816CC[4];
    extern s32 D_801816EC;
    extern s32 D_801816F4;
    extern s32 D_801816FC;
    extern s32 D_80181704;

    Prim_8016E7C8_8016E7C8 prim;
    MATRIX_c2 m;
    SVECTOR tmp;
    register Prim_8016E7C8_8016E7C8 *pp __asm__("$18");    

    ((void (*)(void *, void *))func_80017DC4)(param_2, &m);
    m.t[0] = *(short *)(param_1 + 6);
    m.t[1] = *(short *)(param_1 + 10);
    m.t[2] = *(short *)(param_1 + 14);
    func_8004914C(&m);
    func_800491AC(&m);
    pp = &prim;
    ((void (*)(void *, void *, void *))RotTransSV)(&D_801816CC[0], pp, &tmp);
    ((void (*)(void *, void *, void *))RotTransSV)(&D_801816CC[1], &prim.v[1], &tmp);
    ((void (*)(void *, void *, void *))RotTransSV)(&D_801816CC[2], &prim.v[2], &tmp);
    ((void (*)(void *, void *, void *))RotTransSV)(&D_801816CC[3], &prim.v[3], &tmp);
    prim.v[0].vz = 3;
    prim.f5 = 0x50000000;
    prim.f0 = D_801816EC;
    prim.f1 = D_801816F4;
    prim.f2 = D_801816FC;
    prim.f3 = D_80181704;
    prim.f4 = *param_3;
    prim.f6 = 0x27;
    func_80016ED4(pp);
}
