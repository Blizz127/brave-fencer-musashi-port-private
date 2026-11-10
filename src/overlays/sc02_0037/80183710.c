/* sc02_0037: func_80183710 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct B16;
struct B16 { s32 w[4]; };
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
typedef struct { s32 w[4]; } Blk16_8018A8B8;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012AD44(s32 *a0, s16 a1);
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
void func_8012AD44(s32 *a0, s16 a1);
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
extern void func_8002850C(s32, s32, s32);
extern void func_80028620(s32, void *);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern struct B16 D_800A5E88;
extern struct B16 D_800A5E98;
extern struct B16 D_800A5EA8;
extern short D_800B9A02;
typedef struct { s32 w[4]; } LBlk16;

void func_80183710(void *a0)
{
    extern void func_8002850C(s32 a0, s32 a1, s32 a2);
    extern void func_8012AD44(s32 *a0, s16 a1);
    extern void func_80028620(s32 a0, void *a1);
    extern s16 D_801C6BCC, D_801C6BCE, D_801C6BD0;
    extern LBlk16 D_801C6BD4;
    extern s16 D_801C6C04, D_801C6C06, D_801C6C08;
    extern LBlk16 D_801C6C0C;
    extern s16 D_801C6C3C, D_801C6C3E, D_801C6C40;
    extern Blk16_8018A8B8 D_801C6C44;
    extern s16 D_801C6C74, D_801C6C76, D_801C6C78;
    extern Blk16_8018A8B8 D_801C6C7C;
    s32 v1 = *(s16 *)((s32)a0 + 0xFC);
    LBlk16 *s0;
    *(s16 *)((s32)a0 + 0xFE) = 0;
    switch (v1) {
    case 0:
        func_8002850C(D_801C6BCC, D_801C6BCE, D_801C6BD0);
        s0 = &D_801C6BD4;
        func_8012AD44((s32 *)a0, 1);
        break;
    case 1:
        func_8002850C(D_801C6C04, D_801C6C06, D_801C6C08);
        s0 = &D_801C6C0C;
        func_8012AD44((s32 *)a0, 2);
        break;
    case 2:
        func_8002850C(D_801C6C3C, D_801C6C3E, D_801C6C40);
        s0 = &(*(LBlk16 *)&D_801C6C44);
        func_8012AD44((s32 *)a0, 3);
        break;
    case 3:
        func_8002850C(D_801C6BCC, D_801C6BCE, D_801C6BD0);
        s0 = &D_801C6BD4;
        func_8012AD44((s32 *)a0, 4);
        break;
    case 4:
        func_8002850C(D_801C6C74, D_801C6C76, D_801C6C78);
        s0 = &(*(LBlk16 *)&D_801C6C7C);
        func_8012AD44((s32 *)a0, 5);
        break;
    }
    {
        LBlk16 *dst = &(*(LBlk16 *)&D_800A5E88);
        LBlk16 *src = s0;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        func_80028620(0, &dst[0]);
        func_80028620(1, &dst[1]);
        func_80028620(2, &dst[2]);
    }
}
