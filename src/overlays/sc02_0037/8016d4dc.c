/* sc02_0037: func_8016D4DC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8016AE5C.c (preprocessed; only the declarations it uses),
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern s32 func_80047E98(void *a0, void *a1);
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
void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern s32 D_80126B58;
extern s32 func_80047E98(void *a0, void *a1);
void func_8016C74C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern s32 func_80047E98(void *a0, void *a1);
extern void func_800D22E4(s32 a0);
extern short func_8016CF04();
void func_8016C83C(s32 a0);
short func_8016CF04(s32 param_1, s32 param_2);
extern void func_800D22E4(s32 a0);
extern short func_8016CF04();
extern s32 D_80126B58;
extern void func_8016C83C(s32 a0);
extern s32 func_80047E98(void *a0, void *a1);
extern short func_8016CF04();
extern void func_8016C74C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_800D22E4(s32 a0);

void func_8016D4DC(s32 a0) {
    s16 d[20];
    s32 a1 = *(s32 *)(a0 + 0x34);
    s32 dist;
    s32 idx;
    if (*(u16 *)a1 != 1) {
        *(s16 *)(a0 + 2) = 3;
        *(s32 *)(a0 + 0x34) = (s32)&D_80126B58;
        *(s32 *)(a0 + 0x1C) = 0x40;
        func_8016C83C(a0);
        return;
    }
    d[0] = *(u16 *)(a1 + 6) - *(u16 *)(a0 + 6);
    d[1] = *(u16 *)(a1 + 0xA) - *(u16 *)(a0 + 0xA);
    d[2] = *(u16 *)(a1 + 0xE) - *(u16 *)(a0 + 0xE);
    dist = func_80047E98(d, d);
    if (dist < 0x510) {
        func_8016CF04(a0, 2);
        *(s16 *)(a0 + 2) = 4;
        return;
    }
    if (dist < 0x1900) {
        idx = 6;
    } else if (dist < 0x6400) {
        idx = 5;
    } else {
        idx = 4;
    }
    func_8016C74C(a0, (s32)d, idx, 9, 0x400);
    func_800D22E4(a0);
    func_8016CF04(a0, 1);
}
