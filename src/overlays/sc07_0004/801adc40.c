/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ADC40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz, pad; } SV_801ADC40;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_801ADC40;
typedef struct { s32 vx, vy, vz; } VEC32_801ADC40;
extern int func_8005C49C(void);
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern u8 *func_801290DC(s32 a0, u8 *a1);
extern void func_80048B6C(void *in, void *out);
extern s32 D_801B0894[];

void func_801ADC40(u8 *a0)
{
    SV_801ADC40 sv;    /* sp+0x10 */
    VEC32_801ADC40 vec; /* sp+0x18 */
    MTX_801ADC40 mtx;  /* sp+0x28 */
    s32 flag;          /* sp+0x48 */
    s32 v1;

    sv.vx = (func_8005C49C() & 0x7FF) - 0x400;
    sv.vy = func_8005C49C() & 0xFFF;
    sv.vz = 0;
    func_80049CAC((s32)&sv, (s32)&mtx);

    func_8004914C(&mtx);
    mtx.t[0] = *(s16 *)(a0 + 0x6) + *(s16 *)(a0 + 0x50);
    mtx.t[1] = *(s16 *)(a0 + 0xA) + *(s16 *)(a0 + 0x52) - 0x40;
    mtx.t[2] = *(s16 *)(a0 + 0xE) + *(s16 *)(a0 + 0x54);
    func_800491AC(&mtx);

    sv.vy = 0;
    sv.vx = 0;
    sv.vz = -0x310;
    func_8004945C((s32)&sv, (s32)&sv, &flag);

    a0 = func_801290DC(0x2E, (u8 *)&sv);
    if (a0 != 0) {
        v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = 0xC020;
        vec.vx = 0;
        vec.vy = 0;
        vec.vz = 0x300000;
        func_80048B6C(&vec, a0 + 0x10);
        *(s16 *)(a0 + 0x30) = 8;
        *(s16 *)(a0 + 0x32) = 0x10;
        *(s32 *)(a0 + 0x34) = D_801B0894[func_8005C49C() % 6];
    }
}
