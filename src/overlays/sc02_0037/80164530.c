/* sc02_0037: func_80164530 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
extern void func_80016714(void *a0, s32 a1);
extern u8 D_800AF630[];
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80047D3C(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern u8 D_801202A0[];
extern s32 func_8004CFEC(s32 x, s32 y);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u8 D_800AF630[];
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80147324(s32 arg0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern s32 func_80012A60(s32 a0, s32 a1);
extern s32 func_800CF8B4();
extern void func_801599A4(void *a0);
extern void func_80162CCC();
extern void func_8014C010(s32 a0, s32 a1);
extern s32 func_8014C59C(void *a0, void *a1);
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern void func_80147324(s32 a0);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
void func_80161CD0(s32 a0, s32 a1);
extern s32 func_800CF8B4(void);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
void func_8015BDD0(s32 *a0);
void func_8015BF48(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 arg0);
extern s32 func_80012A60(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_800CF8B4(void);
extern s32 func_80161208();
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 arg0);
extern s32 func_800CF8B4();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
extern void func_8016130C(void*, s32);
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8016130C(void *a0, s32 a1);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
void func_801599A4(void *a0);
void func_8015BDD0(s32 *a0);
void func_8015BF48(s32 *a0);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_8016191C(void *a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BF48(s32 *a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(int a0, int a1);
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
void func_801599A4(void *a0);
extern void func_80147324();
extern void func_80147324(s32 arg0);
extern int func_800CF8B4();
extern void func_80147324(int arg0);
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
extern void func_80147324(s32 arg0);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80047D3C(s32 a0);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern u8 D_801202A0[];
extern void *memcpy(void *, const void *, u32);
extern void *memcpy(void *, const void *, u32);
extern u8 D_801202A0[];
extern void func_80147324(s32 a0);
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern void func_80162CCC();
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8014C59C(void *a0, void *a1);
extern s32 func_80012A60(s32 a0, s32 a1);
extern s32 func_80012DBC(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80047D3C(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern u8 D_801202A0[];
extern u8 D_800AF630[];

void func_80164530(s32 arg0) {
    u8 *p;
    s32 s0;
    u8 *unaff_s5;
    s32 unaff_s6;
    u8 *base;
    s32 iVar9;
    s16 sVar4;
    s32 ix, iy, dist;
    sVar4 = 0x1000;
    base = D_800AF630;
    p = D_801202A0;
    iVar9 = *(s32 *)(arg0 + 0x20);
    for (; p < D_801202A0 + 0x6480; p += 0x10C) {
        if ((*(u16 *)(p + 0x5C) & 0x2000) != 0) {
            s32 r2;
            s0 = func_8014C59C((void *)arg0, (void *)p);
            r2 = func_80012A60((s32)(s16)s0, (s32)*(s16 *)(iVar9 + 0x12));
            if (((s16)r2 < 0x200) && ((s16)r2 < sVar4)) {
                unaff_s6 = s0;
                sVar4 = r2;
                unaff_s5 = p;
            }
        }
    }
    if (sVar4 != 0x1000) {
        *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12) =
            (s16)func_80012DBC((s32)*(s16 *)(iVar9 + 0x12), (s32)(s16)unaff_s6, 10, 1);
        if (*(s16 *)(base + 0xA3D8) == 0x30A0) {
            u32 uVar7 = *(u32 *)(unaff_s5 + 0x58) & 0xFFFFFFF;
            if (uVar7 != 0) {
                iy = (s32)((((u32)*(u16 *)(unaff_s5 + 0xE) +
                             ((s32)*(s16 *)(uVar7 + 0xC) + (s32)*(s16 *)(uVar7 + 0xE)) / 2) -
                            (u32)*(u16 *)(arg0 + 0xE)) << 16) >> 16;
                ix = (s32)((((u32)*(u16 *)(unaff_s5 + 0x6) +
                             ((s32)*(s16 *)(uVar7 + 0x4) + (s32)*(s16 *)(uVar7 + 0x6)) / 2) -
                            (u32)*(u16 *)(arg0 + 0x6)) << 16) >> 16;
                dist = func_80047D3C(iy * iy + ix * ix);
                s0 = func_8004CFEC(((s32)*(s16 *)(unaff_s5 + 0xA) +
                             ((s32)*(s16 *)(uVar7 + 0x8) + (s32)*(s16 *)(uVar7 + 0xA)) / 2) -
                            (s32)*(s16 *)(arg0 + 0xA),
                            (s32)(s16)dist) & 0xFFF;
                *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x10) = (u16)s0;
            }
        }
    }
}
