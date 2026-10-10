/* sc03_0098: func_8017BFEC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { u16 f0; s16 f2; u16 f4; u16 f6; u16 f8; u16 fA; } Rec027_8017BFEC;
typedef struct { Rec027_8017BFEC r[9]; } Blk027_8017BFEC;
extern s32 func_800291B4(s32 arg);
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001D074(s32, s32);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_8012A568(void (*a0)(void));
extern s32 func_800291B4(s32 arg);
extern void func_8012CAE4(void *a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);

void func_8017BFEC(s32 a0) {
    extern u8 D_80188D34[];
    extern u8 D_80188D70[];
    extern s32 D_801BF084;
    extern u16 D_801152BA;
    extern s16 D_80115214;
    extern s32 D_801C54C8;
    extern u8 D_801C54D4;
    extern u8 D_801C54D5;
    extern u8 D_801C54D6;
    extern u8 D_801C54E4;
    extern u8 D_801C54E5;
    extern u8 D_801C54E6;
    extern u8 D_801C54F5;
    extern u8 D_801C54F6;
    extern u8 D_801C54F8;
    extern u8 D_801C54F9;
    extern u8 D_801C54FA;
    extern u8 D_801C54FC;
    extern u8 D_801C54FD;
    extern u8 D_801C54FE;
    extern u8 D_801C5504;
    extern Blk027_8017BFEC D_801BF0AC;
    extern Blk027_8017BFEC D_801C5578[];
    u8 *v1;
    s32 s1;
    u8 *p;
    s32 t;
    s16 i;
    Blk027_8017BFEC *dst;
    Blk027_8017BFEC *tbl2;
    s32 idx;
    Blk027_8017BFEC *tbl;
    s32 u;
    s32 w;
    v1 = *(u8 **)(a0 + 0xDC);
    if ((func_800291B4(v1[0] + 0x3A) & 0xFF) != 0) {
        func_8012CAE4((void *)a0);
        return;
    }
    if (*(s32 *)(a0 + 0x20) == 0) {
        if (func_8012C354(a0, (s32)D_80188D34) == 0) {
            return;
        }
        func_8001C810(*(s32 *)(a0 + 0x20), (s32)&D_801BF084);
        func_8012A828(a0, (void *)&D_80188D70[(s16)D_801152BA * 16]);
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x2C) |= 0x20;
        *(s32 *)(*(s32 *)(a0 + 0x20) + 0x80) = (s32)&D_801C54C8;
        *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4) |= 0x40000000;
        *(s16 *)(a0 + 0xAE) = -3;
    }
    s1 = ((s32 (*)(s32, s32))func_8001D074)(0x7E, 0x100);
    if (s1 == 0) {
        return;
    }
    p = &D_801C54F8;
    *(s32 *)(a0 + 0xCC) = s1;
    func_8001CD50(s1, (s32)p);
    D_801C54FA = 0x80;
    *p = 0x80;
    D_801C54F9 = 0xE0;
    D_801C54FD = 0;
    D_801C54FC = 0;
    D_801C54FE = 0;
    func_800233CC(p, 0x38);
    tbl = D_801C5578;
    idx = (s16)D_801152BA;
    dst = &tbl[idx];
    *(s16 *)(s1 + 0x10) = 0x400;
    *(s16 *)(s1 + 0x8) = *(u16 *)(a0 + 0x6);
    t = *(u16 *)(a0 + 0xA) - 4;
    *(u16 *)(a0 + 0xA) = t;
    *(s16 *)(s1 + 0xA) = t;
    *(s16 *)(s1 + 0xC) = *(u16 *)(a0 + 0xE);
    *(s32 *)(s1 + 0x4) |= 0x50000000;
    D_801C54F6 = 0xFF;
    D_801C5504 = 0xFF;
    D_801C54E6 = 0xFF;
    D_801C54E4 = 0xFF;
    D_801C54D6 = 0xFF;
    D_801C54D4 = 0xFF;
    D_801C54F5 = 0x80;
    D_801C54E5 = 0x80;
    D_801C54D5 = 0x80;
    *dst = D_801BF0AC;
    i = 5;
    tbl2 = D_801C5578;
    *(s32 *)(a0 + 0xD8) = (s32)&tbl2[(s16)D_801152BA];
    while (i < 0x28) {
        if ((func_800291B4(i + 0x3B) & 0xFF) != 0) {
            break;
        }
        i++;
    }
    if (i != 0x28) {
        *(s16 *)(a0 + 0x10A) = 1;
    }
    w = D_801152BA + 1;
    u = *(u16 *)(a0 + 0x2) + 1;
    D_80115214 = 0;
    D_801152BA = w;
    *(u16 *)(a0 + 0x2) = u;
}
