/* sc03_0001: func_801418F8 from Druthulu/BFM-decomp
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
extern s32 func_80029178(s32);
extern void func_8002D4C8(s32 a0, s32 a1);
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
extern void func_800D24A0(s32 a0);
extern u16 D_80115110;
extern unsigned short D_80115112;
extern u16 D_8011511A;
extern s16 D_8018E884;
extern s16 D_8018E886;
extern void func_800D24A0(s32 arg);
extern s32 D_80115130;
extern short D_80115128;
extern u16 D_80115112;
extern unsigned short D_80115118;
extern void func_80141C0C(s32);
extern s32 func_80029178(s32 arg);
extern void func_8002D4C8(s32 a0, s32 a1);
extern short D_80115128;
extern short D_80115128;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern u8 D_80115158[];
extern u8 D_8011515C;
extern void func_80141C0C(s32);
extern unsigned short D_80115112;
extern u16 D_80115112;
extern short D_800B9A02;
extern u16 D_80115112;
extern unsigned short D_80115112;
extern u16 D_80115110;
extern u16 D_80115112;
extern unsigned short D_80115118;
extern volatile u16 D_8011511A;
extern s16 D_80115128;
extern s32 D_80115130;
extern s16 D_8018E884;
extern s16 D_8018E886;
extern void func_800D24A0(s32 a0);
extern s32 func_80029178(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80141C0C(s32 a0);
void func_80141C0C(s32 param_1);

void func_801418F8(void)
{
    extern s16 D_8011512E;
    extern u8 D_80115158[];
    extern s16 D_8011515A;
    extern u8 D_8011515C;
    extern s16 D_8011515E;
    extern s16 D_80115162;
    extern s16 D_80115166;
    extern u8 D_8018E524;
    extern u8 D_8018E53C;
    extern u8 D_8018E5B0;
    extern u8 D_8018E5B8;
    extern void *D_801ED488;
    extern void *D_801ED48C;
    u16 t;
    func_800D24A0(1);
    D_8011511A = 2;
    t = D_8011511A;
    (*(s16 *)&D_80115118) = 0;
    D_80115130 = 0;
    if (t >= 4) {
        D_8011511A = t - 3;
    }
    (*(s16 *)D_80115158) = 0x106;
    if ((func_80029178(0x1C) & 0xFF) == 0) {
        D_801ED488 = &D_8018E524;
        D_801ED48C = &D_8018E5B0;
    } else {
        D_801ED488 = &D_8018E53C;
        D_801ED48C = &D_8018E5B8;
    }
    D_8011515A = 0x104;
    (*(s16 *)&D_8011515C) = 0x104;
    D_8011515E = 0x129;
    D_80115162 = 0x103;
    D_80115166 = 0x105;
    D_80115128 = 0;
    D_8011512E = 0;
    if (D_80115110 == 3) {
        func_8002D4C8(0x46E, 0);
    } else {
        func_80141C0C(0);
    }
    D_80115128 = 1;
    D_8018E884 = 0xE;
    D_8018E886 = 3;
    D_80115112 = D_80115112 + 1;
}
