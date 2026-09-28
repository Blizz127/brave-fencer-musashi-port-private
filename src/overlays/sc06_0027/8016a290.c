/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016A290 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef void (*code)(unsigned short *);
struct Fr_8016A290 {
    SVEC_8016A290 center;                          /* 0x00 -> sp+0x10 */
    SVEC_8016A290 diff;                            /* 0x08 -> sp+0x18 */
    s32  pos[3];                          /* 0x10 -> sp+0x20 */
    s32  _pad1c;                          /* 0x1C -> sp+0x2C */
    s16  mtx[32];                         /* 0x20 -> sp+0x30 */
    SVEC_8016A290 v[4];                            /* 0x60 -> sp+0x70 */
    struct { u8 r, g, b, pad; } col[4];   /* 0x80 -> sp+0x90 */
    u32  code;                            /* 0x90 -> sp+0xA0 */
};
extern u16  D_800B99DA;
extern void func_80149350(s32 arg0);
extern void func_80017E68(void *a0, void *a1);
extern s32 D_801269A4;
extern s32 D_801269A8;
extern s32 D_801269AC;
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern s32  func_80017758(void *a0, void *a1);
extern void func_80049A1C(void *a0, void *a1);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_8004D504(void *a0, void *a1, void *a2);
extern s32 func_8004CFEC(s32 a0, s32 a1);

void func_8016A290(s32 param_1, void *param_2, void *param_3) {
    extern u8 D_801810BC;
    extern u8 D_801810D0[];

    struct Fr_8016A290 fr;
    u8 *p;
    s32 i;
    register s32 t __asm__("$2");
    register s32 zr __asm__("$0");
    s32 flags;
    s32 iVar3;

    iVar3 = *(s32 *)(param_1 + 0x34);

    fr.center.x = (*((s16 *)param_2) + *((s16 *)param_3)) >> 1;
    fr.center.y = (((s16 *)param_2)[1] + ((s16 *)param_3)[1]) >> 1;
    fr.center.z = (((s16 *)param_2)[2] + ((s16 *)param_3)[2]) >> 1;
    ((void(*)(s32, void *, void *))func_80149350)(iVar3, &fr.center, &fr.center);

    *(u16 *)(param_1 + 0x6) = *(u16 *)&fr.center.x;
    *(u16 *)(param_1 + 0xA) = *(u16 *)&fr.center.y;
    *(u16 *)(param_1 + 0xE) = *(u16 *)&fr.center.z;
    func_800D20C0(&fr.center, &fr.diff, 8);
    func_80017E68(&fr.center, fr.mtx);

    fr.diff.x = *(u16 *)((s16 *)param_3) - *(u16 *)((s16 *)param_2);
    fr.diff.y = *(u16 *)(((s16 *)param_3) + 1) - *(u16 *)(((s16 *)param_2) + 1);
    fr.diff.z = *(u16 *)(((s16 *)param_3) + 2) - *(u16 *)(((s16 *)param_2) + 2);
    ((void(*)(s32, void *, void *))func_80048FBC)(*(s32 *)(iVar3 + 0x20) + 0x34, &fr.diff, &fr.diff);
    func_800D23D0(&fr.diff);
    func_80049A1C(&fr.diff, fr.mtx);

    fr.pos[0] = D_801269A4 - fr.center.x;
    fr.pos[1] = D_801269A8 - fr.center.y;
    fr.pos[2] = D_801269AC - fr.center.z;
    func_8004D504(fr.mtx, fr.pos, fr.pos);
    fr.diff.z = -func_8004CFEC(fr.pos[0], fr.pos[1]);
    func_80049A1C(&fr.diff, fr.mtx);

    fr.v[3].z = 0;
    fr.v[2].z = 0;
    fr.v[0].z = 0;
    fr.v[1].z = 0;
    fr.v[1].y = 0;
    fr.v[1].x = 0;
    flags = D_800B99DA;
    if (flags & 1) {
        fr.col[1].r = *(s32 *)(param_1 + 0x30) + 0x20;
    } else if (flags & 2) {
        fr.col[1].r = *(s32 *)(param_1 + 0x30) + 0x40;
    } else {
        fr.col[1].r = *(s32 *)(param_1 + 0x30);
    }

    p = ((u8 *)&D_801810BC);
    fr.col[0].b = 0;
    fr.col[0].g = 0;
    fr.col[0].r = 0;
    fr.col[2].b = 0;
    fr.col[2].g = 0;
    fr.col[2].r = 0;
    fr.col[3].b = 0;
    fr.col[3].g = 0;
    fr.col[3].r = 0;
    fr.code = 0x50000000;
    fr.col[1].b = fr.col[1].r >> 3;
    fr.col[1].g = fr.col[1].r >> 3;
    i = 0;
L1:
        fr.v[0].x = (s8)*p++;
        fr.v[0].y = (s8)*p++;
        fr.v[2].x = (s8)*p++;
        fr.v[2].y = (s8)*p++;
        fr.v[3].x = (s8)*p++;
        fr.v[3].y = (s8)*p--;
        func_80017758(fr.v, fr.mtx);
        t = i + 1;
        i = t + zr;
        if ((s16)t < 4) goto L1;

    fr.v[3].y = 0;
    fr.v[2].y = 0;
    fr.v[0].y = 0;
    fr.v[1].y = 0;
    fr.v[1].x = 0;
    fr.v[1].z = -0x20;
    p = D_801810D0;
    i = 0;
L2:
        fr.v[0].x = (s8)*p++;
        fr.v[0].z = (s8)*p++;
        fr.v[2].x = (s8)*p++;
        fr.v[2].z = (s8)*p++;
        fr.v[3].x = (s8)*p++;
        fr.v[3].z = (s8)*p--;
        func_80017758(fr.v, fr.mtx);
        if ((s16)i == 1) {
            fr.v[1].z = 0x20;
            p += 2;
        }
        t = i + 1;
        i = t + zr;
        if ((s16)t < 4) goto L2;

    p += 2;
    fr.v[0].x = 0;
    fr.v[0].z = -0x20;
    fr.col[0].r = fr.col[1].r;
    fr.col[0].b = fr.col[1].g;
    fr.col[0].g = fr.col[1].g;
    i = 0;
L3:
        fr.v[2].x = (s8)*p++;
        fr.v[2].z = (s8)*p++;
        fr.v[3].x = (s8)*p++;
        fr.v[3].z = (s8)*p++;
        func_80017758(fr.v, fr.mtx);
        t = i + 1;
        i = t + zr;
        if ((s16)t < 2) goto L3;
}
