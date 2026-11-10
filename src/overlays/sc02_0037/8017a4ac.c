/* sc02_0037: func_8017A4AC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
struct S126B58_inner { u16 pad[9]; u16 unk12; };
struct S126B58 { u8 pad[0x20]; struct S126B58_inner *unk20; };
struct S734 { s32 unk0; s32 unk4; s32 unk8; s32 unkC; u8 unk10[8]; s32 unk18;
              void (*unk1C)(s32, void *, s32); };
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef void (*code)(unsigned short *);
struct Fr {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_80167AE0 {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_8016A290 {
    SVEC_8016A290 center;
    SVEC_8016A290 diff;
    s32 pos[3];
    s32 _pad1c;
    s16 mtx[32];
    SVEC_8016A290 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
typedef struct { s16 x, y, z, pad; } SVec_801670E4;
typedef struct {
               u16 cx, cy, cz;
               u16 _p06;
               u16 a8[4];
               s32 pos[3];
               s32 _p1C;
               SVec_801670E4 v[4];
               struct { u8 r, g, b, cd; } col[4];
               u32 code;
               s32 _p54;
               u8 m1[0x20];
               u8 m2[0x20];
} Fr_801670E4;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80126B58;
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_80172310(u8 *a0);
extern void func_80172738(void);
extern void func_80172780(void *a0);
extern void func_80172894(void *a0);
extern void func_801729B0(s32 a0);
extern void func_80172B14(s16 a0);
extern void func_80172C50(void *a0);
extern void func_80172D68(s32 a0);
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
void func_801734BC(s32 a0, s32 a1);
extern void func_801733FC(s32 a0, s32 a1);
extern void func_801734BC(s32 a0, s32 a1);
extern void func_80173460(s32 a0, s32 a1);
extern void func_801736B0(s32 a0, s32 a1);
extern void func_801737B8(s16 a0);
extern void func_801738DC(s16 a0);
extern void func_80173A28(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern void func_8017427C(void);
extern void func_80174438(s32 a0);
extern void func_8017452C(void);
extern void func_80174584(void);
extern void func_801745DC(void);
extern s32 func_80174754(void);
extern u16 D_801C9238[0x200];
extern s16 D_801C963C;
extern s16 D_801C9638;
extern s32 D_801C9680;
extern void func_80172310(u8*);
extern void func_80172738(void);
extern void func_80172780(void*);
extern void func_80172894(void*);
extern void func_801729B0(s32);
extern void func_80172B14(s16);
extern void func_80172C50(void*);
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
extern void func_801733FC(s32, s32);
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
    extern s16 D_801C9640;
    extern s32 D_801C965C;
    extern s32 D_801C9684;
    u16 sp18[4];
    u16 sp20[4];
    u16 sp28[4];
    u16 sp30[4];
    struct S126B58 *w = &(*(struct S126B58 *)&D_80126B58);
    s16 cmd;
    if (D_801C9638 == D_801C963C) {
        if (func_80174754() != 0) {
            D_801C9640 = 0;
        } else {
            D_801C9640 = 1;
        }
        return;
    }
    D_801C9640 = 1;
    if (func_80174754() == 0) {
        return;
    }
    cmd = D_801C9238[D_801C9638];
    D_801C9638 = (D_801C9638 + 1) & 0x1FF;
    switch (cmd) {
    case 0:
        func_80172738();
        return;
    case 1:
        sp18[0] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp18[1] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp18[2] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        ((void (*)(u16 *))func_80172780)(sp18);
        return;
    case 28:
        sp18[0] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp18[1] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp18[2] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp18[3] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        ((void (*)(u16 *))func_80172894)(sp18);
        return;
    case 2:
        { s16 arg = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        ((void (*)(s16))func_801729B0)(arg);
        return; }
    case 3:
        { s16 arg = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        func_80172B14(arg);
        return; }
    case 4:
        { s16 arg = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        { s32 t = w->unk20->unk12 + arg;
        func_80172B14(t & 0xFFF); }
        return; }
    case 5:
        sp18[0] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp18[1] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp18[2] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        ((void (*)(u16 *))func_80172C50)(sp18);
        return;
    case 6:
        { s16 arg = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        ((void (*)(s16))func_80172D68)(arg);
        return; }
    case 7: func_80172E94(); return;
    case 8: func_80172ED4(); return;
    case 27: ((void (*)())D_801C9684)(); return;
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
        { s16 arg = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        func_801738DC(arg);
        return; }
    case 19: {
        s16 a, b;
        s32 ea, eb;
        a = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF; ea = a;
        b = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF; eb = b;
        func_801736B0(ea, eb);
        return;
    }
    case 20:
        { s16 arg = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        ((void (*)(s16))func_801734BC)(arg);
        return; }
    case 23:
        sp20[0] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp20[1] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp20[2] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        { s16 arg = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        ((void (*)(s16, u16 *))func_80173460)(arg, sp20);
        return; }
    case 29:
        sp28[0] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp28[1] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp28[2] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        { s16 arg = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        ((void (*)(s16, u16 *))func_801733FC)(arg, sp28);
        return; }
    case 32:
        sp30[0] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp30[1] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp30[2] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        sp30[3] = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        ((void (*)(u16 *))func_80172310)(sp30);
        return;
    case 25: func_8017452C(); return;
    case 30: func_80174584(); return;
    case 26: func_8017427C(); return;
    case 24: func_80174438(D_801C9680); return;
    case 21:
        ((void (*)(s32, s32, s32, s32, void *, s32))func_80173A28)((*(struct S734 * *)&D_801C965C)->unk0, (*(struct S734 * *)&D_801C965C)->unk4, (*(struct S734 * *)&D_801C965C)->unk8,
                      (*(struct S734 * *)&D_801C965C)->unkC, (*(struct S734 * *)&D_801C965C)->unk10, (*(struct S734 * *)&D_801C965C)->unk18);
        return;
    case 22:
        (*(struct S734 * *)&D_801C965C)->unk1C((*(struct S734 * *)&D_801C965C)->unk4, (*(struct S734 * *)&D_801C965C)->unk10, (*(struct S734 * *)&D_801C965C)->unk18);
        return;
    case 31:
        { s16 arg = D_801C9238[D_801C9638]; D_801C9638 = (D_801C9638 + 1) & 0x1FF;
        func_801737B8(arg);
        return; }
    }
}
