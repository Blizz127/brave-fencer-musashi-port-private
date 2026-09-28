/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6184 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 m[3][3]; s32 t[3]; } Mtx_801A6184;
typedef struct { s16 x, y, z, pad; } Svec_801A6184;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern void func_800D23D0(void *a0);
extern void func_80049A1C(void *a0, void *a1);
extern void func_8004D504(void *a0, void *a1, void *a2);
extern s32  func_8004CFEC(s32 a0, s32 a1);
extern void func_8004838C(void *a0, void *a1, void *a2);
extern s32 D_801269A4;
extern s32 D_801269A8;
extern s32 D_801269AC;
extern u8  D_800AF648;

void func_801A6184(u8 *s2, s32 p1, s32 p2)
{
    s32 pos[3];           /* sp+0x10 */
    Svec_801A6184 out1;   /* sp+0x20 : func_8004945C(p1) result   */
    Svec_801A6184 out2;   /* sp+0x28 : func_8004945C(p2) result   */
    Svec_801A6184 mid;    /* sp+0x30 : (out1+out2)>>1          */
    Svec_801A6184 diff;   /* sp+0x38 : out2-out1, then rot vec */
    Mtx_801A6184  mtx;    /* sp+0x40 */
    s32 flag;             /* sp+0x60 */

    func_8004914C((void *)(*(s32 *)(s2 + 0x20) + 0x34));
    func_800491AC((void *)(*(s32 *)(s2 + 0x20) + 0x34));

    func_8004945C(p1, (s32)&out1, &flag);
    func_8004945C(p2, (s32)&out2, &flag);

    mid.x = (out1.x + out2.x) >> 1;
    mid.y = (out1.y + out2.y) >> 1;
    mid.z = (out1.z + out2.z) >> 1;
    diff.x = out2.x - out1.x;
    diff.y = out2.y - out1.y;
    diff.z = out2.z - out1.z;

    func_800D23D0(&diff);
    func_80049A1C(&diff, &mtx);

    pos[0] = D_801269A4 - mid.x;
    pos[1] = D_801269A8 - mid.y;
    pos[2] = D_801269AC - mid.z;
    func_8004D504(&mtx, pos, pos);

    diff.z = -func_8004CFEC(pos[0], pos[1]);
    func_80049A1C(&diff, &mtx);

    mtx.t[0] = *(s32 *)(*(s32 *)(s2 + 0x20) + 0x48);
    mtx.t[1] = *(s32 *)(*(s32 *)(s2 + 0x20) + 0x4C);
    mtx.t[2] = *(s32 *)(*(s32 *)(s2 + 0x20) + 0x50);
    func_8004838C(&D_800AF648, &mtx, &mtx);

    func_8004914C(&mtx);
    func_800491AC(&mtx);
}
