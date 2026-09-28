/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A4AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S126B58_inner { u16 pad[9]; u16 unk12; };
struct S126B58 { u8 pad[0x20]; struct S126B58_inner *unk20; };
struct S734 { s32 unk0; s32 unk4; s32 unk8; s32 unkC; u8 unk10[8]; s32 unk18;
              void (*unk1C)(s32, void *, s32); };
extern u16 D_801A5268[0x200];
extern s16 D_801A5668;
extern s16 D_801A566C;
extern s32 D_801A56B0;
extern s32 D_80126B58;
extern s16 D_801A5670;
extern s32 D_801A568C;
extern s32 D_801A56B4;
extern void func_80172310(u8*);
extern void func_80172738(void);
extern void func_80172780(void*);
extern void func_80172894(void*);
extern void func_801729B0(s32);
extern void func_80172B14(s16);
extern void func_80172C50(u16 *);
extern void func_80172D68(s32);
extern void func_80172E94(void);
extern void func_80172ED4(void);
extern void func_80172EFC(void);
extern void func_80172F24(void);
extern void func_80172F4C(void);
extern void func_80172F9C(void);
extern void func_80172FEC(void);
extern void func_80173174(void);
extern void func_8017329C(void);
extern void func_8017334C(void);
extern void func_801733A4(void);
extern void func_801733FC(s16, u16 *);
extern void func_80173460(s32, s32);
extern void func_801734BC(s32, s32);
extern void func_801736B0(s32, s32);
extern void func_801737B8(s16);
extern void func_801738DC(s16);
extern void func_80173A28(s32, s32, s32, s32, s32, s32);
extern void func_8017427C(void);
extern void func_80174438(s32);
extern void func_8017452C(void);
extern void func_80174584(void);
extern void func_801745DC(void);
extern s32 func_80174754(void);

void func_8017A4AC(void) {
    u16 sp18[4];
    u16 sp20[4];
    u16 sp28[4];
    u16 sp30[4];
    struct S126B58 *w = &(*(struct S126B58 *)&D_80126B58);
    s16 cmd;

    if (D_801A5668 == D_801A566C) {
        if (func_80174754() != 0) {
            D_801A5670 = 0;
        } else {
            D_801A5670 = 1;
        }
        return;
    }
    D_801A5670 = 1;
    if (func_80174754() == 0) {
        return;
    }
    cmd = D_801A5268[D_801A5668];
    D_801A5668 = (D_801A5668 + 1) & 0x1FF;
    switch (cmd) {
    case 0:
        func_80172738();
        return;
    case 1:
        sp18[0] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp18[1] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp18[2] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        ((void (*)(u16 *))func_80172780)(sp18);
        return;
    case 28:
        sp18[0] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp18[1] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp18[2] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp18[3] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        ((void (*)(u16 *))func_80172894)(sp18);
        return;
    case 2:
        { s16 arg = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        ((void (*)(s16))func_801729B0)(arg);
        return; }
    case 3:
        { s16 arg = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        func_80172B14(arg);
        return; }
    case 4:
        { s16 arg = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        { s32 t = w->unk20->unk12 + arg;
        func_80172B14(t & 0xFFF); }
        return; }
    case 5:
        sp18[0] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp18[1] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp18[2] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        func_80172C50(sp18);
        return;
    case 6:
        { s16 arg = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        ((void (*)(s16))func_80172D68)(arg);
        return; }
    case 7: func_80172E94(); return;
    case 8: func_80172ED4(); return;
    case 27: ((void (*)())D_801A56B4)(); return;
    case 9: func_80172EFC(); return;
    case 10: func_80172F24(); return;
    case 11: func_80173174(); return;
    case 12: func_80172F4C(); return;
    case 33: func_80172F9C(); return;
    case 34: func_80172FEC(); return;
    case 13: func_801745DC(); return;
    case 14:
    case 15: func_8017329C(); return;
    case 16: func_8017334C(); return;
    case 17: func_801733A4(); return;
    case 18:
        { s16 arg = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        func_801738DC(arg);
        return; }
    case 19: {
        s16 a, b;
        s32 ea, eb;
        a = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF; ea = a;
        b = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF; eb = b;
        func_801736B0(ea, eb);
        return;
    }
    case 20:
        { s16 arg = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        ((void (*)(s16))func_801734BC)(arg);
        return; }
    case 23:
        sp20[0] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp20[1] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp20[2] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        { s16 arg = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        ((void (*)(s16, u16 *))func_80173460)(arg, sp20);
        return; }
    case 29:
        sp28[0] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp28[1] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp28[2] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        { s16 arg = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        func_801733FC(arg, sp28);
        return; }
    case 32:
        sp30[0] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp30[1] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp30[2] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        sp30[3] = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        ((void (*)(u16 *))func_80172310)(sp30);
        return;
    case 25: func_8017452C(); return;
    case 30: func_80174584(); return;
    case 26: func_8017427C(); return;
    case 24: func_80174438(D_801A56B0); return;
    case 21:
        ((void (*)(s32, s32, s32, s32, void *, s32))func_80173A28)((*(struct S734 * *)&D_801A568C)->unk0, (*(struct S734 * *)&D_801A568C)->unk4, (*(struct S734 * *)&D_801A568C)->unk8,
                      (*(struct S734 * *)&D_801A568C)->unkC, (*(struct S734 * *)&D_801A568C)->unk10, (*(struct S734 * *)&D_801A568C)->unk18);
        return;
    case 22:
        (*(struct S734 * *)&D_801A568C)->unk1C((*(struct S734 * *)&D_801A568C)->unk4, (*(struct S734 * *)&D_801A568C)->unk10, (*(struct S734 * *)&D_801A568C)->unk18);
        return;
    case 31:
        { s16 arg = D_801A5268[D_801A5668]; D_801A5668 = (D_801A5668 + 1) & 0x1FF;
        func_801737B8(arg);
        return; }
    }
}
