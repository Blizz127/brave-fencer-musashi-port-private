/* sc03_0001: func_8013D3D4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8013C98C.c (preprocessed; only the declarations it uses),
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern u8 D_80078E78[];
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_8013CF68(void);
void func_8013CF68();
extern u8 D_80078E78[];
extern void *D_801ED430;
extern void *D_801ED434;
extern void *D_801ED438;
extern s32 D_801ED460;
extern s32 D_801ED464;
extern s32 D_801ED468;
extern s32 D_801EF334[];
extern u8 D_8018DD4C[];
extern u8 D_8018DDF4[];
extern u8 D_8018DCA4[];
extern u8 D_8018DDA0[];
extern u8 D_8018DE20[];
extern u8 D_8018DCF8[];
extern void func_8013D53C(void *arg0v);
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);
void func_8013D53C(void *arg0v);
void func_8013D8FC(void);
void func_8013DD68();

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;
    D_801ED460 = param_2;
    D_801ED464 = (param_2 >> 2) & 3;
    D_801ED468 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_801ED430 = D_8018DD4C;
        D_801ED434 = D_8018DDF4;
        D_801ED438 = D_8018DCA4;
    } else {
        D_801ED430 = D_8018DDA0;
        D_801ED434 = D_8018DE20;
        D_801ED438 = D_8018DCF8;
    }
    ((void (*)(void))func_8013D53C)();
    if ((param_2 & 1) != 0) {
        if (D_801ED468 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801ED460 & 2) != 0) {
            D_801EF334[0] = 0x140;
            D_801EF334[3] = 0x80;
            if (p[0x37] == 4) {
                D_801EF334[0] = 0x140;
                D_801EF334[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801EF334[0] = 0x140;
                D_801EF334[3] = 0x80;
            }
        }
    }
}
