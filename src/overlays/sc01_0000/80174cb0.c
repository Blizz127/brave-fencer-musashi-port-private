/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174CB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
typedef struct { short vx, vy, vz, pad; } SVECTOR;
typedef struct { short m[3][3]; long t[3]; } MATRIX;
extern void func_8012A568(void (*a0)(void));
extern s16 func_80012ABC(s32, s32, s32);
extern s32 func_80012C6C(s32 a0, s32 a1, s32 a2);
extern void func_80013F3C(s32 a0);
extern void func_800123F0(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);

s32 func_80174CB0(s32 param_1, s32 param_2)
{

    extern s16 D_80126940;
    extern s16 D_80126942;
    extern s16 D_80126944;
    s16 *pv = &D_80126940;
    MATRIX mtx;
    SVECTOR vec;
    SVECTOR out;
    *(s32 *)(param_1 + 8) = (s16)((s16 (*)(s32, s32, s32))func_80012C6C)((s32)*(s16 *)(param_1 + 8), (s32)*(s16 *)(param_1 + 0xc), 4);
    *(s32 *)(param_1 + 0x10) = (s16)((s16 (*)(s32, s32, s32))func_80012C6C)((s32)*(s16 *)(param_1 + 0x10), (s32)*(s16 *)(param_1 + 0x14), 4);
    *(s16 *)(param_1 + 0x18) = ((s16 (*)(s32, s32, s32))func_80012ABC)((s32)*(s16 *)(param_1 + 0x18), (s32)*(s16 *)(param_1 + 0x20), 4);
    *(s16 *)(param_1 + 0x1a) = ((s16 (*)(s32, s32, s32))func_80012ABC)((s32)*(s16 *)(param_1 + 0x1a), (s32)*(s16 *)(param_1 + 0x22), 4);
    *(s16 *)(param_1 + 0x1c) = ((s16 (*)(s32, s32, s32))func_80012ABC)((s32)*(s16 *)(param_1 + 0x1c), (s32)*(s16 *)(param_1 + 0x24), 4);
    *(s16 *)(param_1 + 0x28) = ((s16 (*)(s32, s32, s32))func_80012C6C)((s32)*(s16 *)(param_1 + 0x28), (s32)*(s16 *)(param_1 + 0x2e), 0x10);
    *(s16 *)(param_1 + 0x2a) = ((s16 (*)(s32, s32, s32))func_80012C6C)((s32)*(s16 *)(param_1 + 0x2a), (s32)*(s16 *)(param_1 + 0x30), 0x10);
    *(s16 *)(param_1 + 0x2c) = ((s16 (*)(s32, s32, s32))func_80012C6C)((s32)*(s16 *)(param_1 + 0x2c), (s32)*(s16 *)(param_1 + 0x32), 0x10);
    *(s32 *)(param_1 + 0x48) = (s32)*(s16 *)(param_1 + 0x28) + (s32)*pv;
    *(s32 *)(param_1 + 0x4c) = (s32)*(s16 *)(param_1 + 0x2a) + (s32)D_80126942;
    *(s32 *)(param_1 + 0x50) = (s32)*(s16 *)(param_1 + 0x2c) + (s32)D_80126944;
    func_80013F3C((s32)&mtx);
    func_800123F0((s32)&mtx, (s32)*(s16 *)(param_1 + 0x1c));
    func_80012558((s32)&mtx, ((s32)*(s16 *)(param_1 + 0x1a) + (s32)(s16)param_2) & 0xFFF);
    func_800126C4((s32)&mtx, (s32)*(s16 *)(param_1 + 0x18));
    mtx.t[0] = (s32)*(s16 *)(param_1 + 0x28) + (s32)*pv;
    mtx.t[1] = (s32)*(s16 *)(param_1 + 0x2a) + (s32)D_80126942;
    mtx.t[2] = (s32)*(s16 *)(param_1 + 0x2c) + (s32)D_80126944;
    vec.vx = 0;
    vec.vy = 0;
    vec.vz = (s16)*(s32 *)(param_1 + 0x10);
    ((void (*)(s32, s32, s32))func_8012F14C)((s32)&mtx, (s32)&vec, (s32)&out);
    *(s32 *)(param_1 + 0x3c) = (s32)out.vx;
    *(s32 *)(param_1 + 0x40) = (s32)out.vy;
    *(s32 *)(param_1 + 0x44) = (s32)out.vz;
}
