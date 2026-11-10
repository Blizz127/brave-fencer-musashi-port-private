/* sc02_0037: func_801588CC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801555F4.c (preprocessed; only the declarations it uses),
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
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 func_80159464();
extern s32 func_800D0CA0(s32);
extern s32 func_8001AAA0(void);
extern s32 func_8001BD80(void);
extern s32 func_80159464(void);
s32 func_80159464(void);

void func_801588CC(s32 param_1) {
    extern void (*D_80185FAC[])(void);
    extern s32 D_801C8580;
    extern s32 D_801C8584;
    extern s32 D_801C8588;
    extern s32 D_801C858C;
    extern s32 D_801C8590;
    s16 sVar1;
    D_80185FAC[*(u16 *)(param_1 + 2)]();
    switch (D_801C8580) {
    case 0:
        break;
    case 1:
        ((void (*)(s32))func_800D0CA0)(2);
        D_801C8588 = 0;
        D_801C8584 = 0x46;
        D_801C8580 += 1;
        break;
    case 2:
        if (D_801C8584 == 0) {
            if (func_8001BD80() == 0) {
                D_801C8580 += 1;
            }
        } else {
            D_801C8584 -= 1;
        }
        break;
    case 3:
        if (((s32 (*)(s32))func_8001AAA0)(0x83) != 0) {
            D_801C8580 += 1;
        }
        break;
    case 4:
        D_801C858C = 0;
        sVar1 = ((s32 (*)(s32))func_80159464)(param_1);
        if (sVar1 != 0) {
            D_801C8584 = 0xd2;
        } else {
            D_801C8584 = 1;
        }
        break;
    case 5:
        D_801C8584 -= 1;
        if (D_801C8584 == -1 || D_801C8590 != 0) {
            D_801C8584 = 0;
            D_801C8580 += 1;
        }
        break;
    case 6:
        ((void (*)(s32))func_800D0CA0)(1);
        D_801C8584 = 0x28;
        D_801C8580 += 1;
        break;
    case 7:
        if (D_801C8584 == 0) {
            if (func_8001BD80() == 0) {
                D_801C8580 += 1;
            }
        } else {
            D_801C8584 -= 1;
        }
        break;
    case 8:
        D_801C8588 = 1;
        break;
    }
}
