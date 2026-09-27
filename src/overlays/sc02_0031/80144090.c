/* Complete SC02 retail span [80144090,801442F8).
 * Particle/ring prim fan.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

typedef struct {
    s32 a;
} OtBlk;

extern void *func_80010A08(s32);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 RotTransPers(s32, s32, s32 *, s32 *);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 AddPrim(s32, void *);
extern OtBlk D_800A651C[];
extern u8 D_800AF648;
extern s16 D_800B9A02;

void func_80144090(s32 obj) {
    void *prim;
    s32 depth;
    s32 i3;
    s32 i4;
    s32 i5;
    s32 ang;
    struct {
        s16 v10[4];
        u16 sxy[2];
        s32 p;
        s32 flag;
    } L;

    prim = func_80010A08(0x140);
    if (prim == 0) {
        return;
    }
    *(s32 *)(obj + 4) = *(s32 *)(obj + 4) + *(s32 *)(obj + 0x10);
    *(s32 *)(obj + 8) = *(s32 *)(obj + 8) + *(s32 *)(obj + 0x14);
    *(s32 *)(obj + 0xc) = *(s32 *)(obj + 0xc) + *(s32 *)(obj + 0x18);
    L.v10[0] = *(u16 *)(obj + 6);
    L.v10[1] = *(u16 *)(obj + 0xa);
    L.v10[2] = *(u16 *)(obj + 0xe);
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    depth = RotTransPers((s32)L.v10, (s32)L.sxy, &L.p, &L.flag);
    depth = depth + 4;
    if (depth < 0) {
        depth = 0;
    }
    ang = 0;
    do {
        *(s32 *)((u8 *)prim + 4) = 0xffffff;
        *(u8 *)((u8 *)prim + 3) = 4;
        *(u8 *)((u8 *)prim + 7) = 0x20;
        if (*(s32 *)(obj + 0x1c) - 6 < 1) {
            *(s16 *)((u8 *)prim + 8) = L.sxy[0];
            *(s16 *)((u8 *)prim + 0xa) = L.sxy[1];
        } else {
            i5 = func_8004787C(ang);
            *(s16 *)((u8 *)prim + 8) =
                L.sxy[0] + ((i5 * ((*(s32 *)(obj + 0x1c) - 6) << 4)) >> 0xc);
            i5 = func_80047948(ang);
            *(s16 *)((u8 *)prim + 0xa) =
                L.sxy[1] + ((i5 * ((*(s32 *)(obj + 0x1c) - 6) << 4)) >> 0xc);
        }
        i3 = func_8004787C(ang) * (*(s32 *)(obj + 0x1c) << 4);
        i4 = func_80047948(ang) * (*(s32 *)(obj + 0x1c) << 4);
        ang = ang + 0x100;
        *(s16 *)((u8 *)prim + 0x10) = L.sxy[0] + ((i3 + (i4 >> 6)) >> 0xc);
        *(s16 *)((u8 *)prim + 0x12) = L.sxy[1] + ((i4 + (i3 >> 6)) >> 0xc);
        *(s16 *)((u8 *)prim + 0xc) = L.sxy[0] + ((i3 - (i4 >> 6)) >> 0xc);
        *(s16 *)((u8 *)prim + 0xe) = L.sxy[1] + ((i4 - (i3 >> 6)) >> 0xc);
        AddPrim(D_800A651C[(u16)D_800B9A02].a + (depth * 4), prim);
        prim = (u8 *)prim + 0x14;
    } while (ang < 0x1000);
}
