/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AAF8C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz, pad; } SV_801AAF8C;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_801AAF8C;
extern s32  func_8004CFEC(s32 a0, s32 a1);
extern s32  func_80047948(s32 a0);
extern s32  func_8004787C(s32 a0);
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern s32  func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern s16  D_80126B5E;
extern s16  D_80126B62;
extern s16  D_80126B66;
extern s32 *D_80126B78;
extern s32 *D_80126B90;
extern u8   D_801152A8[];

s32 func_801AAF8C(SV_801AAF8C *src, SV_801AAF8C *ofs, s32 arg2)
{
    MTX_801AAF8C mtx;   /* sp+0x18 */
    SV_801AAF8C  rot;   /* sp+0x38 */
    SV_801AAF8C  pos;   /* sp+0x40 */
    SV_801AAF8C  sv;    /* sp+0x48 */
    s32          flag;  /* sp+0x50 */
    s32 dx, dy, dz;
    s32 ang;
    s32 s;
    s32 t;

    pos = *src;
    if (ofs != 0) {
        pos.vx += ofs->vx;
        pos.vy += ofs->vy;
        pos.vz += ofs->vz;
    }

    dz = D_80126B66 - pos.vz;
    dx = D_80126B5E - pos.vx;
    t  = pos.vy + 0x20;
    dy = D_80126B62 - t;

    ang = (func_8004CFEC(-dz, dx) - 0x400) & 0xFFF;
    rot.vy = ang;
    s = func_80047948(ang);
    dz = (dz * s + dx * func_8004787C(rot.vy)) >> 12;
    rot.vx = func_8004CFEC(dy, -dz);
    rot.vz = 0;
    func_80049CAC((s32)&rot, (s32)&mtx);

    func_8004914C(&mtx);
    mtx.t[0] = pos.vx;
    mtx.t[1] = pos.vy;
    mtx.t[2] = pos.vz;
    func_800491AC(&mtx);

    sv.vy = 0;
    sv.vx = 0;
    sv.vz = -arg2;
    func_8004945C((s32)&sv, (s32)&sv, &flag);

    if (func_80135888((s32)D_80126B78, (s32)D_80126B90, (s32)&pos, (s32)&sv) != 0) {
        func_8012F568(1, 1, 0, 0xA, (s32)&sv, (s32)D_801152A8);
        return 1;
    }
    return 0;
}
