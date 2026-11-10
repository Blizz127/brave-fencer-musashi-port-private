/* sc02_0037: func_801594E8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801594E8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
extern s32 func_80029178(s32);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
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
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);
extern void func_800D185C(u8 *a0);
extern void func_80029124(s32, s32);
extern void func_80029514(s32);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern u8 D_80078E78[];
extern s32 func_80029178(s32 a0);
extern void func_80029124(s32 a0, s32 a1);
extern void func_8014BEC0(void);
extern void func_80175454(void);
extern void func_800CF804(void);

void func_801594E8(s32 param_1, s32 param_2)
{
    extern void func_80029274(void);
    extern void func_80029044(void);
    extern void func_8002906C(void);
    extern void func_80029094(void);
    extern void func_8002941C(void);
    extern void func_8002AB64(void);
    extern void func_800D1F90(void);
    extern s32 D_80128150;
    extern u8 D_800D3A44[];
    extern u8 D_800D39FC[];
    extern u8 D_800D3A20[];
    u8 *p = D_80078E78;
    func_80175454();
    switch (param_2) {
    case -1: {
        struct { u8 a, b, c; u8 pad[5]; u8 d, e; } t;
        s32 saved;
        t.a = ((s32(*)(s32))func_80029178)(0xB);
        t.b = ((s32(*)(s32))func_80029178)(0xC);
        t.c = ((s32(*)(s32))func_80029178)(0xD);
        t.d = ((s32(*)(s32))func_800291B4)(0x2C);
        t.e = ((s32(*)(s32))func_800291B4)(0x2D);
        saved = *(s32 *)(p + 0x4);
        func_80029274();
        func_80029044();
        func_8002906C();
        func_80029094();
        func_8002941C();
        ((void(*)(s32, s32))func_80029124)(0xB, t.a);
        ((void(*)(s32, s32))func_80029124)(0xC, t.b);
        ((void(*)(s32, s32))func_80029124)(0xD, t.c);
        func_800291A0(0x2C, t.d);
        func_800291A0(0x2D, t.e);
        *(s32 *)(p + 0x4) = saved;
        ((void (*)(s32))func_8014BEC0)(param_1);
        func_8002AB64();
        func_80029514(2);
        ((void(*)(u8 *))func_800D185C)(D_800D3A44);
        func_800CF804();
        break;
    }
    case 1:
        *(s16 *)(p + 0x3C) = 0x96;
        *(s16 *)(p + 0x40) = 0x96;
        *(s32 *)(p + 0x14) = D_80128150;
        break;
    case 2:
    case 3:
    case 4:
        func_800D1F90();
        break;
    case 5:
        func_800D1F90();
        ((void(*)(u8 *))func_800D185C)(D_800D39FC);
        func_80029514(0x636);
        break;
    case 6:
        func_800D1F90();
        ((void(*)(u8 *))func_800D185C)(D_800D3A20);
        func_80029514(0x636);
        break;
    }
}
