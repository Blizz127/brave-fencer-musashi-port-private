/* sc02_0037: func_8016E7C8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8016AE5C.c (preprocessed; only the declarations it uses),
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
typedef struct { short vx, vy, vz, pad; } SVECTOR;
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
typedef struct { short m[3][3]; short pad; s32 t[3]; } MATRIX_c2;
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
typedef struct {
    SVECTOR v[4];
    s32 f0, f1, f2, f3, f4, f5;
    u8 f6;
    u8 pad[7];
} Prim_8016E7C8_8016E7C8;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern s16 D_800B9A02;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern void func_8004914C();
extern void func_800491AC();
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
extern s32 func_80017DC4(void *a0, void *a1);
extern void func_80016ED4(void *a0);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_80016ED4(void *a0);
extern s32 func_80017DC4(void *a0, void *a1);
extern s32 func_80017DC4(void *a0, void *a1);

void func_8016E7C8(int param_1, short *param_2, unsigned int *param_3)
{
    extern void func_8004914C(void *a0);
    extern void func_800491AC(void *a0);
    extern void func_8004945C(s32, s32, void*);
    extern void func_80016ED4(void *a0);
    extern SVECTOR D_80186F58[4];
    extern s32 D_80186F78;
    extern s32 D_80186F80;
    extern s32 D_80186F88;
    extern s32 D_80186F90;
    Prim_8016E7C8_8016E7C8 prim;
    MATRIX_c2 m;
    SVECTOR tmp;
    Prim_8016E7C8_8016E7C8 *pp;
    ((void (*)(void *, void *))func_80017DC4)(param_2, &m);
    m.t[0] = *(short *)(param_1 + 6);
    m.t[1] = *(short *)(param_1 + 10);
    m.t[2] = *(short *)(param_1 + 14);
    func_8004914C(&m);
    func_800491AC(&m);
    pp = &prim;
    ((void (*)(void *, void *, void *))func_8004945C)(&D_80186F58[0], pp, &tmp);
    ((void (*)(void *, void *, void *))func_8004945C)(&D_80186F58[1], &prim.v[1], &tmp);
    ((void (*)(void *, void *, void *))func_8004945C)(&D_80186F58[2], &prim.v[2], &tmp);
    ((void (*)(void *, void *, void *))func_8004945C)(&D_80186F58[3], &prim.v[3], &tmp);
    prim.v[0].vz = 3;
    prim.f5 = 0x50000000;
    prim.f0 = D_80186F78;
    prim.f1 = D_80186F80;
    prim.f2 = D_80186F88;
    prim.f3 = D_80186F90;
    prim.f4 = *param_3;
    prim.f6 = 0x27;
    func_80016ED4(pp);
}
