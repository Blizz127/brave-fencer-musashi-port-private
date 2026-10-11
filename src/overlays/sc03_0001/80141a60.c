/* sc03_0001: func_80141A60 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_801376E8(int a0, int a1);
extern void func_80137B80(void);
extern void func_80139954(void);
extern s32 func_800D0EC4(void);
extern unsigned short D_80115112;
extern u16 D_8011511A;
extern void func_8013FAF8(s16 a0, s16 a1);
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern s32 D_80115130;
extern s16 D_8011514C;
extern s32 func_8013F350(void);
extern s32 func_8014032C(s32 a0, s32 a1);
extern unsigned char D_8018E888;
extern u16 D_80115112;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern s16 D_8011514C;
extern u8 D_8011514D;
extern u8 D_8011515C;
extern unsigned short D_80115112;
extern u16 D_80115112;
extern short D_800B9A02;
extern u16 D_80115112;
extern unsigned short D_80115112;
extern u16 D_80115112;
extern volatile u16 D_8011511A;
extern s32 D_80115130;
extern s16 D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern s16 D_8011514C;
extern s32 D_80115130;
extern u8 D_8018E888;
extern u16 D_80115112;
extern s32 func_8013F350(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern s32 func_8014032C(s32 a0, s32 a1);
extern void func_80139954(void);
extern void func_801376E8(int a0, int a1);
extern void func_80137B80(void);
extern s32 func_800D0EC4(void);

void func_80141A60(void)
{
    extern u8 D_8011514D;
    extern u8 D_8011515C;
    extern u16 D_80115116;
    s32 iVar1;
    s32 pad[2];
    (void)&pad;
    D_801151D0 = ((s32 *)D_801151C8)[(*(u16 *)&D_800B9A02)];
    func_8013F350();
    if ((*(u16 *)&D_8011511A) >= 4) {
        func_8013FAF8((*(u16 *)&D_8011511A), (*(u16 *)&D_8011511A) + 1);
    }
    func_8013FAF8(2, 3);
    iVar1 = func_8014032C(2, (s16)((*(u8 *)&D_8011514C) + D_8011514D * D_8011515C));
    if (iVar1 != 0 && iVar1 != D_80115130) {
        D_80115130 = iVar1;
        func_80139954();
        func_801376E8(iVar1, (int)&D_8018E888);
    }
    func_80137B80();
    iVar1 = func_800D0EC4();
    if (iVar1 != 0) {
        D_80115116 = 0xfff8;
        D_80115112 = D_80115112 + 1;
    }
}
