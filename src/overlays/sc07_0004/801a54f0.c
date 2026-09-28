/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A54F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx32_801A90D8;
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern s32 func_8012B8A4(s16 *a0);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
typedef struct { s16 m[3][3]; s32 t[3]; } Mtx32_801A54F0;
typedef struct { s16 vx, vy, vz, pad; } SV_801A54F0;
extern Mtx32_801A90D8 D_800AE620;
extern s16 D_80126B62;
extern s32 *D_80126B78;
extern s32 *D_80126B90;
extern u8 D_801152A8[];

s32 func_801A54F0(s32 param_1, s32 param_2)
{
    Mtx32_801A54F0 mtx;  /* sp+0x18 */
    SV_801A54F0 pos;     /* sp+0x38 */
    SV_801A54F0 vec2;    /* sp+0x40 */
    SV_801A54F0 out;     /* sp+0x48 */
    s32 v1;
    s32 t;

    mtx = *(Mtx32_801A54F0 *)&(*(Mtx32_801A54F0 *)&D_800AE620);

    func_8004A0DC((s16)func_8012B8A4((s16 *)param_1), &mtx);
    func_8004914C(&mtx);

    v1 = *(u16 *)(param_1 + 6);
    t = (u16)D_80126B62 - 0x20;
    pos.vx = v1;
    arr0:
    mtx.t[0] = (s16)v1;
    pos.vy = t;
    mtx.t[1] = (s16)t;
    pos.vz = *(u16 *)(param_1 + 0xE);
    mtx.t[2] = pos.vz;
    func_800491AC(&mtx);

    vec2.vy = 0;
    vec2.vx = 0;
    vec2.vz = -param_2;
    func_8004945C((s32)&vec2, (s32)&vec2, &out);

    if (func_80135888((s32)D_80126B78, (s32)D_80126B90, (s32)&pos, (s32)&vec2) != 0) {
        func_8012F568(1, 1, 0, 0xA, (s32)&vec2, (s32)D_801152A8);
        return 1;
    }
    return 0;
}
