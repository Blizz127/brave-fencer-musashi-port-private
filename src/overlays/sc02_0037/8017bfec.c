/* sc02_0037: func_8017BFEC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
typedef struct { u16 f0; s16 f2; u16 f4; u16 f6; u16 f8; u16 fA; } Rec027_8017C688;
typedef struct { Rec027_8017C688 r[9]; } Blk027_8017C688;
extern void func_8001D074(s32 a, s32 b);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012A828(s32 a0, void * a1);
extern void func_8012CAE4(void *a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8001C810(s32 a0, s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 func_800291B4(s32 arg);
extern void func_800233CC(void *, unsigned short);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001D074(s32, s32);
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
extern void func_8001CD50(s32 a0, s32 a1);
extern s32 func_800291B4(s32 arg);
extern void func_8012CAE4(void *a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);

void func_8017BFEC(s32 a0) {
    extern u8 D_80187620[];
    extern u8 D_8018765C[];
    extern s32 D_801C38D0;
    extern u16 D_801152BA;
    extern s16 D_80115214;
    extern s32 D_801C96E8;
    extern u8 D_801C96F4;
    extern u8 D_801C96F5;
    extern u8 D_801C96F6;
    extern u8 D_801C9704;
    extern u8 D_801C9705;
    extern u8 D_801C9706;
    extern u8 D_801C9715;
    extern u8 D_801C9716;
    extern u8 D_801C9718;
    extern u8 D_801C9719;
    extern u8 D_801C971A;
    extern u8 D_801C971C;
    extern u8 D_801C971D;
    extern u8 D_801C971E;
    extern u8 D_801C9724;
    extern Blk027_8017C688 D_801C38F8;
    extern Blk027_8017C688 D_801C9798[];
    u8 *v1;
    s32 s1;
    u8 *p;
    s32 t;
    s16 i;
    Blk027_8017C688 *dst;
    Blk027_8017C688 *tbl2;
    s32 idx;
    Blk027_8017C688 *tbl;
    s32 u;
    s32 w;
    v1 = *(u8 **)(a0 + 0xDC);
    if ((func_800291B4(v1[0] + 0x3A) & 0xFF) != 0) {
        func_8012CAE4((void *)a0);
        return;
    }
    if (*(s32 *)(a0 + 0x20) == 0) {
        if (func_8012C354(a0, (s32)D_80187620) == 0) {
            return;
        }
        func_8001C810(*(s32 *)(a0 + 0x20), (s32)&D_801C38D0);
        func_8012A828(a0, (void *)&D_8018765C[(s16)D_801152BA * 16]);
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x2C) |= 0x20;
        *(s32 *)(*(s32 *)(a0 + 0x20) + 0x80) = (s32)&D_801C96E8;
        *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4) |= 0x40000000;
        *(s16 *)(a0 + 0xAE) = -3;
    }
    s1 = ((s32 (*)(s32, s32))func_8001D074)(0x7E, 0x100);
    if (s1 == 0) {
        return;
    }
    p = &D_801C9718;
    *(s32 *)(a0 + 0xCC) = s1;
    func_8001CD50(s1, (s32)p);
    D_801C971A = 0x80;
    *p = 0x80;
    D_801C9719 = 0xE0;
    D_801C971D = 0;
    D_801C971C = 0;
    D_801C971E = 0;
    func_800233CC(p, 0x38);
    tbl = D_801C9798;
    idx = (s16)D_801152BA;
    dst = &tbl[idx];
    *(s16 *)(s1 + 0x10) = 0x400;
    *(s16 *)(s1 + 0x8) = *(u16 *)(a0 + 0x6);
    t = *(u16 *)(a0 + 0xA) - 4;
    *(u16 *)(a0 + 0xA) = t;
    *(s16 *)(s1 + 0xA) = t;
    *(s16 *)(s1 + 0xC) = *(u16 *)(a0 + 0xE);
    *(s32 *)(s1 + 0x4) |= 0x50000000;
    D_801C9716 = 0xFF;
    D_801C9724 = 0xFF;
    D_801C9706 = 0xFF;
    D_801C9704 = 0xFF;
    D_801C96F6 = 0xFF;
    D_801C96F4 = 0xFF;
    D_801C9715 = 0x80;
    D_801C9705 = 0x80;
    D_801C96F5 = 0x80;
    *dst = D_801C38F8;
    i = 5;
    tbl2 = D_801C9798;
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
