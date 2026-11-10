/* sc02_0037: func_80158434 from Druthulu/BFM-decomp
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
extern void func_80146CA0(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern s32 func_80146E98(s32 a0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_801473EC(s32 *a0);
extern void func_80147460(s32 a0);
extern void func_801474EC(s32 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80148038(s32 a0, s32 a1);
extern void func_8014CBF8(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern s32 func_80146E98(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801473EC(s32 *a0);
extern int func_80155FF8(int arg, int a1);
extern int func_80155FF8(int arg, int a1);
extern int func_80155FF8(int arg, int a1);
int func_80155FF8(int arg, int a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146CA0(void *a0);
extern void func_801473EC(s32 *a0);
extern void func_80148038(int, int);
extern void func_80147460(int);
extern void func_80146CA0(void *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801473EC(s32 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_801473EC(s32 *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146CA0(void *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_801473EC(s32 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_801473EC(s32 *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_8014CBF8(void *a0);
extern void func_801474EC(s32 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801473EC(s32 *a0);
extern s32 func_801615C4(void *a0, s32 a1);
extern s32 func_80146E98(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern int func_80155FF8(int arg, int a1);

void func_80158434(s32 param_1)
{
    extern u8 D_80185F3C;
    extern u8 D_800D533C;
    u32 uVar1;
    u32 uVar2;
    s32 frame_pad[4];
    (void)&frame_pad;
    *(u32 *)(param_1 + 0x44) = *(u32 *)(param_1 + 0x44) | 2;
    if ((*(u16 *)(param_1 + 0xB8) & 0x4000) != 0) {
        *(s32 *)(param_1 + 0x234) = *(s32 *)(param_1 + 0x234) + 1;
        ((s32 (*)(void))func_8014CBF8)();
        ((void (*)(s32))func_801474EC)(param_1);
        ((void (*)(s32, s32))func_801477E8)(param_1, 0xFFFA0000);
        ((void (*)(s32, s32))func_80146DB8)(param_1, (s32)&D_80185F3C);
    }
    if (*(s32 *)(param_1 + 0x234) != 0) {
        func_80148038(param_1, 0x10000);
        func_80147460(param_1);
        func_80147AD4(param_1, 0, 0, 0);
        ((void (*)(s32))func_801473EC)(param_1);
    }
    uVar1 = ((s32 (*)(s32, s32))func_801615C4)(param_1, 0);
    if (uVar1 != 0) {
        if (uVar1 == 1) goto LAB_80158508;
        uVar2 = uVar1 & 0x2000;
    } else {
        uVar2 = func_80146E98(param_1);
    }
    if (uVar2 == 0) goto LAB_80158528;
LAB_80158508:
    ((void (*)(s32, s32))func_80154274)(param_1, (s32)&D_800D533C);
    ((void (*)(s32))func_80146CA0)(param_1);
    return;
LAB_80158528:
    ((void (*)(s32, s32))func_80155FF8)(param_1, *(u8 *)(param_1 + 0x1AA));
}
