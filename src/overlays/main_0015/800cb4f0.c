/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB4F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#define MulMatrix0 func_8004818C
#define RotMatrixZ func_8004A27C
#define rand func_8005C49C
typedef struct { u32 a, b, c, d; } Blk16;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C(void);

void func_800CB4F0(void *arg0) {
    typedef struct { u32 a, b, c, d; } Blk16;
    extern s32 func_801465E4(void);
    extern void func_8001C810(s32 a0, s32 a1);
    extern void func_80149350();
    extern void func_80149374(s32 a0, s32 a1);
    extern s32 func_80017DC4(void *a0, void *a1);
    extern void RotMatrixZ(s32 a0, void *a1);
    extern void MulMatrix0(s32 a0, void *a1, s32 a2);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern void func_80146C3C(void);
    extern s32 rand(void);
    extern s32 D_800CC870;
    extern s32 D_800636C8;

    short sv[3];
    int mtx[8];
    s32 s3;
    s32 s2;
    s32 t;

    s3 = *(s32 *)((char *)arg0 + 0x34);
    s2 = func_801465E4();
    *(s32 *)((char *)arg0 + 0x20) = s2;
    if (s2 == 0) goto Lcall;

    func_8001C810(s2, (s32)&D_800CC870);
    *(u32 *)(s2 + 4) |= 0x50000040;
    *(s32 *)(s2 + 0x20) = (s32)&D_800636C8;

    sv[0] = 0;
    sv[1] = -6;
    sv[2] = *(u16 *)((char *)arg0 + 0xE) - 0x24;
    func_80149350(s3, sv, sv);

    t = *(s32 *)(s3 + 0x20);
    *(Blk16 *)((char *)arg0 + 0x38) = *(Blk16 *)(t + 0x34);
    *(Blk16 *)((char *)arg0 + 0x48) = *(Blk16 *)(t + 0x44);

    *(s32 *)((char *)arg0 + 0x4C) = sv[0];
    *(s32 *)((char *)arg0 + 0x50) = sv[1];
    *(s32 *)((char *)arg0 + 0x54) = sv[2];
    func_80149374(s3, (s32)arg0 + 4);

    sv[2] = 0x1800;
    sv[1] = 0x1800;
    sv[0] = 0x1800;
    func_80017DC4(sv, mtx);

    RotMatrixZ(rand() & 0xFFF, mtx);
    MulMatrix0(*(s32 *)(s3 + 0x20) + 0x34, mtx, s2 + 0x34);

    func_80146A6C(0x13, arg0,
                  *(short *)((char *)arg0 + 6),
                  *(short *)((char *)arg0 + 0xA),
                  *(short *)((char *)arg0 + 0xE),
                  0, 0);

    *(s32 *)((char *)arg0 + 0x30) = 0x80;
    func_800CB6FC(arg0);
    *(u16 *)((char *)arg0 + 2) = *(u16 *)((char *)arg0 + 2) + 1;
    goto Lend;

Lcall:
    ((void (*)(void *))func_80146C3C)(arg0);
Lend:;
}
