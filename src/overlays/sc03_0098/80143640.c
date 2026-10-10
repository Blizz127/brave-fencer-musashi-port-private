/* sc03_0098: func_80143640 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
extern u8 *func_8012913C(s32 a0);
extern u8 * func_8012913C(s32 arg0);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern s32 func_8005C49C(void);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern short D_800B9A02;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u16 D_80115116;
extern void *memcpy(void *, const void *, u32);
extern u8 *func_8012913C(s32 a0);
extern s32 func_8005C49C(void);

void func_80143640(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *s0;
    s32 r;
    s32 d0, d1, d2;
    s32 t;
    s32 pad[6];
    (void)pad;
    if ((*(u16 *)(a0 + 0) & (s16)((1 << a3) - 1)) == 0) {
        s0 = func_8012913C(0x22);
        if (s0 != 0) {
            r = func_8005C49C();
            d0 = *(s16 *)(a2 + 0);
            *(s16 *)(s0 + 6) = (*(u16 *)(a1 + 0) + (r % (d0 << 1))) - d0;
            r = func_8005C49C();
            d1 = *(s16 *)(a2 + 2);
            *(s16 *)(s0 + 0xA) = (*(u16 *)(a1 + 2) + (r % (d1 << 1))) - d1;
            r = func_8005C49C();
            d2 = *(s16 *)(a2 + 4);
            t = *(u16 *)(a1 + 4);
            *(s32 *)(s0 + 0x18) = 0;
            *(s32 *)(s0 + 0x14) = 0;
            *(s32 *)(s0 + 0x10) = 0;
            *(s16 *)(s0 + 0xE) = (t + (r % (d2 << 1))) - d2;
            *(s16 *)(s0 + 0x34) = *(u16 *)(a1 + 6);
            *(u16 *)(*(s32 *)(s0 + 0x20) + 0x2C) = 0xC008;
        }
    }
    *(u16 *)(a0 + 0) += 1;
}
