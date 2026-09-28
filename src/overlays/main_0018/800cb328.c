/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB328 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixY func_8004A0DC
extern void func_80146C3C(void);

void func_800CB328(void *a0) {
    typedef struct { s16 m[3][3]; s32 t[3]; } Mtx32b;
    typedef struct { s16 vx, vy, vz; } Svec3;

    extern u8 D_80078EC1;
    extern s32 func_80146A6C(s32, void *, s32, s32, s32, s32, s32);
    extern void RotMatrixY(s32, void *);
    extern void func_8012F14C(s32, s32, s32);
    extern void func_80016714(s8 *, s32);
    extern void func_80146C3C();
    extern s16 D_80126B5E;
    extern s16 D_80126B62;
    extern s16 D_80126B66;
    extern u16 D_80126BC8;
    extern u16 D_80126BCA;
    extern u16 D_80126BCC;
    extern Mtx32b D_800AE620;

    void *obj = a0;
    register void *pf20 __asm__("$20");
    void *pf34;
    Svec3 rot;
    Mtx32b m;
    u32 mask;
    s32 cnt;
    u16 t18;

    pf20 = *(void **)((s32)obj + 0x20);
    pf34 = *(void **)((s32)obj + 0x34);

    if (D_80078EC1 == 3) {
        cnt = *(s32 *)((s32)obj + 0x2C) - 4;
        *(s32 *)((s32)obj + 0x2C) = cnt;
        if ((u32)cnt < 0x1C) {
            func_80146A6C(3, obj,
                          *(s16 *)((s32)obj + 0x6),
                          *(s16 *)((s32)obj + 0xA),
                          *(s16 *)((s32)obj + 0xE),
                          (s32)0xCCCFFFC,
                          (s32)0xE0009C00);
            D_80126BC8 = D_80126BCC = D_80126BCC + 0x400;
            D_80126BCA = D_80126BCA - 0x100;
        } else {
            mask = 0x7FFFFFFF;
            t18 = *(u16 *)((s32)pf20 + 0x1A);
            *(u32 *)((s32)pf20 + 0x4) &= mask;
            t18 = t18 - 0x2C;
            *(u16 *)((s32)pf20 + 0x1A) = t18;
            *(u16 *)((s32)pf20 + 0x18) = t18;

            *(s32 *)((s32)obj + 0x30) +=
                0xA00000u / (*(s32 *)((s32)obj + 0x2C) * 804);

            m = D_800AE620;
            RotMatrixY(*(s32 *)((s32)obj + 0x30), &m);
            rot.vx = 0;
            rot.vy = -(*(u32 *)((s32)obj + 0x2C) >> 1);
            rot.vz = *(s32 *)((s32)obj + 0x2C);
            m.t[0] = D_80126B5E;
            m.t[1] = D_80126B62 - 0x1C;
            m.t[2] = D_80126B66;
            func_8012F14C((s32)&m, (s32)&rot, (s32)&rot);

            *(u16 *)((s32)obj + 0x6) = *(u16 *)&rot.vx;
            *(u16 *)((s32)obj + 0xA) = *(u16 *)&rot.vy;
            *(u16 *)((s32)obj + 0xE) = *(u16 *)&rot.vz;

            *(u32 *)((s32)pf34 + 0x4) &= mask;
            *(u16 *)((s32)pf34 + 0x18) = *(u16 *)((s32)pf20 + 0x18);
            *(u16 *)((s32)pf34 + 0x1A) = *(u16 *)((s32)pf20 + 0x1A);
            *(u16 *)((s32)pf34 + 0x8) = *(u16 *)((s32)obj + 0x6);
            *(u16 *)((s32)pf34 + 0xA) = *(u16 *)((s32)obj + 0xA);
            *(u16 *)((s32)pf34 + 0xC) = *(u16 *)((s32)obj + 0xE);
            return;
        }
    }
    if (pf34 != 0) {
        func_80016714((s8 *)pf34, 0x38);
    }
    ((void (*)(s32))func_80146C3C)((s32)obj);
}
