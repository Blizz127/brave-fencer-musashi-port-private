/* sc02_0037: func_8017F578 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
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
extern void func_8002D4C8(s32 a0, s32 a1);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];
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
extern void func_8002D4C8(int, int);
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
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern short D_800B9A02;
extern void func_8002D4C8(s32 a0, s32 a1);
extern u8 D_801202A0[];
extern void func_8002D4C8(s32 a0, s32 a1);

void func_8017F578(s32 a0)
{
    s32 a3;
    u8 *a2;
    s32 t0;
    s32 t1;
    s32 v1p;
    s32 va;
    if (*(s16 *)(a0 + 0xFE) != 0) {
        return;
    }
    a3 = 0;
    a2 = D_801202A0;
    t1 = 0x12C;
    t0 = 1;
    for (; a3 < 0x60; a3++, a2 += 0x10C) {
        if (*(u16 *)a2 == t1) {
            va = *(s16 *)(a2 + 0xA);
            if ((u32)(va - *(s16 *)(a0 + 0xA) + 0x30) < 0x51) {
                va = *(s16 *)(a2 + 0x6);
                if ((u32)(va - *(s16 *)(a0 + 0x6) + 0x70) < 0xE1) {
                    va = *(s16 *)(a2 + 0xE);
                    if ((u32)(va - *(s16 *)(a0 + 0xE) + 0x70) < 0xE1) {
                        goto found;
                    }
                }
            }
        }
    }
    t0 = 0;
found:
    if (t0 != 1) {
        return;
    }
    v1p = *(s32 *)(a0 + 0xCC);
    if (v1p != 0) {
        *(s16 *)(v1p + 0xFC) = 9;
    }
    v1p = *(s32 *)(a0 + 0xD0);
    if (v1p != 0) {
        *(s16 *)(v1p + 0xFC) = 9;
    }
    *(s16 *)(a0 + 0xFE) = 1;
    func_8002D4C8(0x73A, 0);
}
