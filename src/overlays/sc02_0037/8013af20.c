/* sc02_0037: func_8013AF20 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct { u32 addr : 24; u32 len : 8; u8 r0, g0, b0, code; } P_TAG;
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
extern void *func_80010A08(s32);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *, const void *, u32);
extern void *memcpy(void *, const void *, u32);
extern short D_800B9A02;
extern void *func_80010A08(s32);

void func_8013AF20(u32 *param_1, u16 *param_2, u16 *param_3, u8 *param_4)
{
    u32 *puVar3;
    u32 *puVar4;
    u32 *puVar5;
    s32 iVar8;
    s32 j;
    puVar3 = (u32 *)func_80010A08(0x168);
    puVar4 = (u32 *)func_80010A08(0x1e0);
    puVar5 = (u32 *)func_80010A08(0x1e0);
    iVar8 = 0;
    j = 0;
    do {
        *(u8 *)((s32)puVar4 + 3) = 3;
        *(u8 *)((s32)puVar4 + 7) = 0x40;
        *(u8 *)((s32)puVar4 + 4) = 0x3d;
        *(u8 *)((s32)puVar4 + 5) = 0x3d;
        *(u8 *)((s32)puVar4 + 6) = 0x3d;
        *(u16 *)((s32)puVar4 + 8) = param_3[j];
        *(u16 *)((s32)puVar4 + 0xa) = param_3[j + 1];
        iVar8 = iVar8 + 1;
        *(u16 *)((s32)puVar4 + 0xc) = param_3[j + 2];
        *(u16 *)((s32)puVar4 + 0xe) = param_3[j + 3];
        j += 2;
        ((P_TAG *)puVar4)->addr = ((P_TAG *)param_1)->addr;
        ((P_TAG *)param_1)->addr = (u32)puVar4;
        puVar4 = puVar4 + 4;
    } while (iVar8 < 0x1e);
    iVar8 = 0;
    j = 0;
    do {
        iVar8 = iVar8 + 1;
        *(u8 *)((s32)puVar5 + 3) = 3;
        *(u8 *)((s32)puVar5 + 7) = 0x40;
        *(u8 *)((s32)puVar5 + 4) = 0x92;
        *(u8 *)((s32)puVar5 + 5) = 0x92;
        *(u8 *)((s32)puVar5 + 6) = 0x92;
        *(u16 *)((s32)puVar5 + 8) = param_3[j] + (s8)param_4[j];
        *(u16 *)((s32)puVar5 + 0xa) = param_3[j + 1] + (s8)param_4[j + 1];
        *(u16 *)((s32)puVar5 + 0xc) = param_3[j + 2] + (s8)param_4[j + 2];
        *(u16 *)((s32)puVar5 + 0xe) = param_3[j + 3] + (s8)param_4[j + 3];
        j += 2;
        ((P_TAG *)puVar5)->addr = ((P_TAG *)param_1)->addr;
        ((P_TAG *)param_1)->addr = (u32)puVar5;
        puVar5 = puVar5 + 4;
    } while (iVar8 < 0x1e);
    iVar8 = 0;
    j = 0;
    do {
        *(u8 *)((s32)puVar3 + 3) = 5;
        *(u8 *)((s32)puVar3 + 7) = 0x28;
        *(u8 *)((s32)puVar3 + 4) = 0xff;
        *(u8 *)((s32)puVar3 + 5) = 0xff;
        *(u8 *)((s32)puVar3 + 6) = 0xff;
        *(u16 *)((s32)puVar3 + 8) = param_3[j];
        *(u16 *)((s32)puVar3 + 0xa) = param_3[j + 1];
        *(u16 *)((s32)puVar3 + 0xc) = param_2[0];
        *(u16 *)((s32)puVar3 + 0xe) = param_2[1];
        *(u16 *)((s32)puVar3 + 0x10) = param_3[j + 2];
        *(u16 *)((s32)puVar3 + 0x12) = param_3[j + 3];
        iVar8 = iVar8 + 2;
        *(u16 *)((s32)puVar3 + 0x14) = param_3[j + 4];
        *(u16 *)((s32)puVar3 + 0x16) = param_3[j + 5];
        j += 4;
        ((P_TAG *)puVar3)->addr = ((P_TAG *)param_1)->addr;
        ((P_TAG *)param_1)->addr = (u32)puVar3;
        puVar3 = puVar3 + 6;
    } while (iVar8 < 0x1e);
}
