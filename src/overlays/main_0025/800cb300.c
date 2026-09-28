/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB300 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 arg0);
extern s32 func_800CB7B0(s32 a0);
extern void func_80147364(u16 a0, s32 a1);

void func_800CB300(s32 arg0) {
    typedef struct { u8 b[8]; } W8;
    typedef struct { s32 w[4]; } M16;

    extern u8 D_800CAE0C[];
    extern s16 D_800CBEA0;
    extern u16 D_800B99DA;
    extern s16 D_800CBEA2;
    extern u8 D_800CBEB0[];
    extern u8 D_80114EB0[];
    extern s16 D_80126B18;
    extern s16 D_80126B1A;
    extern s16 D_80126B1C;
    extern u8 D_80114EC8[];
    extern s32 D_801151D8;

    extern s32 func_80146E98(s32 a0);
    extern void func_80013F3C(void *a0);
    extern void func_800126C4(s32 a0, s32 a1);
    extern void func_800123F0(s32 a0, s32 a1);
    extern void func_80012558(s32 a0, s32 a1);
    extern void func_80163194(s32 a0, s32 a1, s32 a2, s32 a3, s32 arg4);
    extern void func_80162FC0(s32 *a0);
    extern s32 func_80163950(s32 a0);
    extern void func_8016345C(s32 a0, u16 a1, s32 a2, u16 a3, s32 a4);
    extern void func_80163328(s32 a0);
    extern u32 func_801633A8(s32 a0);
    extern void func_80019064(void *a0);
    extern void func_80013E94(void *a0, void *a1);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern s32 func_801632E0(s32 a0);
    extern s32 func_800CB7B0(s32 a0);
    extern void func_800CB760(void *a0, s16 a1);
    extern s32 func_8016380C(s32 a0, s32 a1);
    extern void func_80146E90(s32 *a0, s16 a1);
    extern void func_80147364(u16 a0, s32 a1);
    extern void func_80147324(s32 arg0);
    extern void func_80146CA0(void *a0);

    s32 mat[8];
    W8 work[3];
    s32 s1;
    s32 s2;
    s32 s0;
    s32 hv;
    s32 bit;
    s32 flags;
    s32 st;

    s1 = arg0;
    s0 = *(s32 *)(s1 + 0x20);
    work[0] = *(W8 *)D_800CAE0C;
    s2 = (s32)&work;
    if (func_80146E98(s1) != 0) {
        goto L6A8;
    }
    func_80013F3C(&mat);
    func_800126C4((s32)&mat, *(s16 *)(s0 + 0x10));
    func_800123F0((s32)&mat, *(s16 *)(s0 + 0x14));
    func_80012558((s32)&mat, *(s16 *)(s0 + 0x12));
    *(M16 *)(s0 + 0x34) = *(M16 *)&mat[0];
    *(M16 *)(s0 + 0x44) = *(M16 *)&mat[4];
    *(u16 *)(s0 + 0x2C) = *(u16 *)(s0 + 0x2C) | 1;
    func_80163194(s1, -(((*(s32 *)(s1 + 0x50) - 0x28) << 14) / 40), 0, 0, (s32)&mat);
    func_80162FC0((s32 *)s1);
    func_80163950(s1);
    hv = *(u16 *)(s0 + 0x1A) + 0x200;
    *(u16 *)(s0 + 0x18) = *(u16 *)(s0 + 0x1A) = hv;
    if ((s16)hv > 0x2000) {
        *(u16 *)(s0 + 0x1A) = 0x2000;
        *(u16 *)(s0 + 0x18) = 0x2000;
    }
    bit = D_800B99DA & 1;
    D_800CBEA0 = bit - 0x10;
    D_800CBEA2 = -0x20 - bit;
    func_8016345C(s1, 0x26, 0, 0x8000, s2);
    func_80163328(s1);
    switch (func_801633A8(s1)) {
    case 1:
        func_80019064(D_800CBEB0);
        func_80013E94(D_80114EB0, &work[2]);
        *(s32 *)&work[2] |= 0x80000000;
        func_80146A6C(0x1F, (void *)s1, D_80126B18, D_80126B1A, D_80126B1C,
                      *(s32 *)&work[2], 0);
        s0 = func_801632E0(s1);
        if (s0 != 0) {
            if (func_800CB7B0(s1) == 0) {
                if (*(u16 *)s0 == 0x151) {
                    func_800CB760((void *)s1, 0x7B3);
                } else {
                    func_800CB760((void *)s1, 0x648);
                }
            }
        }
        break;
    case 4:
        func_80013E94(D_80114EC8, &work[2]);
        *(s32 *)&work[2] |= 0x80000000;
        func_80146A6C(7, (void *)s1, D_80126B18, D_80126B1A, D_80126B1C,
                      *(s32 *)&work[2], 0);
        goto L6A8;
    case 2:
        break;
    }
    flags = func_8016380C(s1, (s32)&work[1]);
    if (flags & 0x8000) {
        goto L6A8;
    }
    if (!(flags & 0x2000)) {
        return;
    }
    st = work[1].b[6];
    if (st == 0x19) {
        if (D_801151D8 != 0) {
            if (func_800CB7B0(s1) == 0) {
                func_800CB760((void *)s1, 0x6DE);
            }
        }
        goto L6A8;
    }
    if (st != 2) {
        return;
    }
    func_80146A6C(0x10, (void *)s1, *(s16 *)(s1 + 6), *(s16 *)(s1 + 0xA),
                  *(s16 *)(s1 + 0xE), 0, 0);
    func_80146E90((s32 *)s1, 0x1E);
    func_80147364(4, 0x649);
    func_80147324(0x441);
    func_80146CA0((void *)s1);
L6A8:
    func_80146CA0((void *)s1);
}
