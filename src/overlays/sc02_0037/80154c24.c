/* sc02_0037: func_80154C24 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801549F8.c (preprocessed; only the declarations it uses),
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
extern void func_80154ED8(s32 a0, s32 a1);
void func_80154ED8(s32 a0, s32 a1);

void func_80154C24(s32 param_1, s32 *param_2, s32 *param_3) {
    u16 uVar2;
    s32 iVar3;
    s32 uVar5;
    s32 uVar6;
    if (*(u8 *)(param_1 + 0xd4) == 0) {
        return;
    }
    if (*param_2 == 0) {
        *(u16 *)(param_1 + 0xd4) = (u16)*(u8 *)(param_1 + 0xd4);
        *param_2 = *param_2 + 1;
    }
    uVar2 = *(u16 *)(param_1 + 0xd4) - 1;
    *(u16 *)(param_1 + 0xd4) = uVar2;
    if ((uVar2 & 0xff) != 0) {
        goto LAB_80154e6c;
    }
    switch (*(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0))) {
    case 0:
        *(u16 *)(param_1 + 0xd4) = 0;
        *param_3 = *param_3 | 0x8000;
        *(u16 *)(param_1 + 0xd6) = 0;
        *(u8 *)(param_1 + 0xd8) = 0;
        *(u8 *)(param_1 + 0xd9) = 0;
        break;
    case 1:
        *(u16 *)(param_1 + 0xd4) = 1;
        *param_3 = *param_3 | 0x8000;
        *(u8 *)(param_1 + 0xd8) = 0;
        *(u8 *)(param_1 + 0xd9) = 0;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 2:
        *(u16 *)(param_1 + 0xd4) = 0;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        goto LAB_80154e9c;
    case 3:
        uVar5 = *(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0) + 4);
        *(u16 *)(param_1 + 0xd4) = 1;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 2;
        *(s16 *)(param_1 + 0xd6) = (s16)uVar5;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 5:
        iVar3 = (u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0);
        uVar5 = *(s32 *)(iVar3 + 4);
        uVar6 = *(s32 *)(iVar3 + 8);
        *(u16 *)(param_1 + 0xd4) = 1;
        *(s8 *)(param_1 + 0xd8) = (s8)uVar6;
        *(s32 *)(param_1 + 0xd0) = uVar5;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 6:
        uVar6 = *(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0) + 4);
        *(u16 *)(param_1 + 0xd4) = 1;
        *(s8 *)(param_1 + 0xd8) = (s8)uVar6;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 7:
        *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd6);
        *param_3 = *param_3 | 0x4000;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        *(s8 *)(param_1 + 0xd9) = *(s8 *)(param_1 + 0xd9) + 1;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 8:
        *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd6);
        *param_3 = *param_3 | 0x2000;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        *(s8 *)(param_1 + 0xd9) = *(s8 *)(param_1 + 0xd9) + 1;
        func_80154C24(param_1, param_2, param_3);
        break;
    default:
        func_80154ED8(param_1, *(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0)));
        *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd6);
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        break;
    }
    goto LAB_80154eac;
LAB_80154e6c:
    if (uVar2 != 1) {
        goto LAB_80154eac;
    }
    if (*(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0)) != 0) {
        goto LAB_80154eac;
    }
LAB_80154e9c:
    *param_3 = *param_3 | 0x8000;
LAB_80154eac:
    *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd4) | *param_3;
    return;
}
