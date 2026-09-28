/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8CE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801269A4;
extern s32 D_801269A8;
extern s32 D_801269AC;
extern s32 func_80132EF4(s32 a0, s32 a1);
extern s32 func_8012B744(void *a0, void *a1);
extern void func_80049A1C(void *a0, void *a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
typedef struct { s16 x, y, z, pad; } Svec_A8CE0;
typedef struct { s16 m[3][3]; s16 t[3]; s16 pad[4]; } Mtx_A8CE0 __attribute__((aligned(8)));

void func_801A8CE0(s32 a0, s16 a1, s32 a2, s32 a3)
{
    Svec_A8CE0 sp10;
    s32 flag[3];
    Mtx_A8CE0 mtx;
    s32 var_s1;
    s32 ret;

    var_s1 = func_80132EF4((s32)a0, 0x70);
    if (var_s1 != 0) {
        *(u16 *)(var_s1 + 0xA) += *(u16 *)((s32)a0 + 0x52);
        *(s32 *)(var_s1 + 0x1C) = (s16)a3;
        sp10.x = D_801269A4;
        sp10.y = D_801269A8;
        sp10.z = D_801269AC;
        ret = func_8012B744((void *)((s32)a0 + 4), &sp10);
        sp10.x = 0x200;
        sp10.y = ret;
        sp10.z = a1;
        func_80049A1C(&sp10, &mtx);
        flag[0] = a2;
        flag[1] = flag[2] = 0;
        func_800484EC((s32)&mtx, (s32)flag, var_s1 + 0x10);
        *(u16 *)(var_s1 + 0x2C) = 0;
    }
}
