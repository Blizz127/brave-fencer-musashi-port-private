/* SC02 resident image [80168070,801681FC) at overlay base 0x80128158.
 * SHA256(span)=7723b8d3b07d0a4aa49bab3aac546e44adf4e57639fbd427650ed66995c3f86e.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168070 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149350(s32 arg0, s32 a1, s32 a2);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_80017E68(void *a0, void *a1);
extern void func_800D23D0(void *a0);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_8004D504(void *a0, void *a1, void *a2);
extern void func_80049A1C(void *a0, void *a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 D_801269A4;
extern s32 D_801269A8;
extern s32 D_801269AC;

void func_80168070(s32 param_1, s16 *param_2, s16 *param_3, void *param_4) {
    s16 mid[3];
    s16 dir[3];
    s32 pos[3];
    mid[0] = (param_2[0] + param_3[0]) >> 1;
    mid[1] = (param_2[1] + param_3[1]) >> 1;
    mid[2] = (param_2[2] + param_3[2]) >> 1;
    ((void (*)(s32, void *, void *))func_80149350)(param_1, mid, mid);
    func_800D20C0(mid, dir, 8);
    func_80017E68(mid, param_4);
    dir[0] = (u16)param_3[0] - (u16)param_2[0];
    dir[1] = (u16)param_3[1] - (u16)param_2[1];
    dir[2] = (u16)param_3[2] - (u16)param_2[2];
    func_80048FBC((void *)(*(s32 *)(param_1 + 0x20) + 0x34), dir, dir);
    func_800D23D0(dir);
    func_80049A1C(dir, param_4);
    pos[0] = D_801269A4 - mid[0];
    pos[1] = D_801269A8 - mid[1];
    pos[2] = D_801269AC - mid[2];
    func_8004D504(param_4, pos, pos);
    dir[2] = -func_8004CFEC(pos[0], pos[1]);
    func_80049A1C(dir, param_4);
}
