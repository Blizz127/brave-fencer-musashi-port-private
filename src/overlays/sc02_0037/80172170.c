/* sc02_0037: func_80172170 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
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
extern s32 D_801151D4;
extern void *memcpy(void *, const void *, unsigned int);
extern s32 D_801151D4;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern int func_80047948(int a0);
extern int func_8004787C(int a0);
extern s32 func_8004CFEC(s32 x, s32 y);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
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
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern s32 func_8004CFEC(s32, s32);
extern s32 D_801151D4;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 D_801151D4;
extern s32 func_8004CFEC(s32, s32);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 D_801151D4;

void func_80172170(s32 a0, s32 a1) {
    s32 base = D_801151D4;
    s32 s0;
    s32 s1;
    s32 v1;
    s32 s3 = a1;
    s32 ang;
    *(s8 *)(a0 + 0xA9) = 0x73;
    ang = func_8004CFEC(*(s32 *)(base + 0x68) - *(s32 *)(base + 0x5C),
                 *(s32 *)(base + 0x70) - *(s32 *)(base + 0x64));
    s0 = (ang + 0x800) & 0xFFF;
    s0 = (*(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) - s0) & 0xFF8;
    if (s0 == 0x400 || s0 == 0xC00) {
        s1 = 0x80;
    } else {
        s32 t = -((s3 & 0xFF) >> 1) * func_80047948(s0);
        if (t < 0) {
            t += 0xFFF;
        }
        s1 = (t >> 12) + 0x80;
    }
    if (s1 < 0) {
        s1 = 0;
    }
    if (!(s1 < 0x100)) {
        s1 = 0xFF;
    }
    if (s0 == 0 || s0 == 0x800) {
        v1 = 0x80;
    } else {
        s32 t = ((s3 & 0xFF) >> 1) * func_8004787C(s0);
        if (t < 0) {
            t += 0xFFF;
        }
        v1 = (t >> 12) + 0x80;
    }
    if (v1 < 0) {
        v1 = 0;
    }
    if (!(v1 < 0x100)) {
        v1 = 0xFF;
    }
    *(s16 *)(a0 + 0xAE) = (v1 & 0xFF) | (s1 << 8);
}
