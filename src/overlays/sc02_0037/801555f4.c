/* sc02_0037: func_801555F4 from Druthulu/BFM-decomp
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
extern s32 func_80029178(s32);
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
extern s32 func_80029178(s32 arg);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147300(u16 arg0);
extern void func_80147324(s32 arg0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 func_80029178(s32 a0);
extern void func_80147324(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern s32 D_8011F730;
extern s32 func_80029178(s32 arg);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147300(u16 arg0);
extern void func_80147324(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
void func_80156648(s32 *a0);

void func_801555F4(void *param_1)
{
    extern void func_80156648(int *a0);
    extern int D_800D4C94;
    extern int D_800D4CE4;
    extern int D_800D4D38;
    extern int D_800D4D88;
    extern int D_800D4E10;
    extern int D_800D4E6C;
    int uVar1;
    unsigned char bVar3;
    int s1;
    unsigned short uVar4;
    ((void(*)(int, int))func_80154A74)(((int)param_1), 0x15);
    if ((*(unsigned int *)(((int)param_1) + 0x44) & 0x200) == 0) {
        if (*(int *)(((int)param_1) + 0x2c) == -0xb0000) {
            uVar1 = ((int(*)(int))func_80029178)(0x82);
            if ((uVar1 & 0xff) != 0) {
                uVar1 = 7;
                goto L_648;
            }
        }
    } else {
        uVar1 = 5;
L_648:
        *(unsigned char *)(((int)param_1) + 0x1aa) = uVar1;
    }
    switch (*(unsigned char *)(((int)param_1) + 0x1aa)) {
    case 0:
    case 1:
        bVar3 = *(unsigned char *)(((int)param_1) + 0x1ab) ^ 1;
        *(unsigned char *)(((int)param_1) + 0x1ab) = bVar3;
        if (bVar3 != 0)
            *(unsigned char *)(((int)param_1) + 0x1aa) = 0;
        else
            *(unsigned char *)(((int)param_1) + 0x1aa) = 1;
        ((void(*)(int *, int))func_80154274)((int *)((int)param_1), (int)&D_800D4C94);
        ((void(*)(int))func_80147324)(0x400);
        ((void(*)(unsigned short))func_80147300)(0x5f3);
        s1 = 0;
        D_8011F730 |= 3;
        func_80146CA0((void *)((int)param_1));
        goto L_7b8;
    case 2:
        ((void(*)(int *, int))func_80154274)((int *)((int)param_1), (int)&D_800D4CE4);
        ((void(*)(int))func_80147324)(0x446);
        ((void(*)(unsigned short))func_80147300)(0x5f3);
        s1 = 1;
        goto L_575c;
    case 3:
        ((void(*)(int *, int))func_80154274)((int *)((int)param_1), (int)&D_800D4D38);
        ((void(*)(int))func_80147324)(0x400);
        ((void(*)(unsigned short))func_80147300)(0x5f3);
        s1 = 2;
        goto L_575c;
    case 4:
        ((void(*)(int *, int))func_80154274)((int *)((int)param_1), (int)&D_800D4D88);
        ((void(*)(unsigned short))func_80147300)(0x5f6);
        s1 = 3;
        func_80146CA0((void *)((int)param_1));
L_575c:
        func_80146CA0((void *)((int)param_1));
        goto L_7b8;
    case 5:
        ((void(*)(int *, int))func_80154274)((int *)((int)param_1), (int)&D_800D4E10);
        s1 = 4;
        uVar4 = 7;
        goto L_7b0;
    case 7:
        ((void(*)(int))func_80147324)(0x7f);
        ((void(*)(unsigned short))func_80147300)(0x5f4);
        ((void(*)(int *, int))func_80154274)((int *)((int)param_1), (int)&D_800D4E6C);
        s1 = 6;
        uVar4 = 8;
L_7b0:
        *(unsigned short *)(((int)param_1) + 2) = uVar4;
        goto L_7b8;
    default:
        ;
    }
L_7b8:
    ((void(*)(int *, int))func_80146E90)((int *)((int)param_1), 0);
    func_80156648((int *)((int)param_1));
    if (s1 >= 0) {
        ((int(*)(int, int, int, int))func_80146994)(4, ((int)param_1), s1, 0);
    }
    ((void(*)(int *))func_801553A8)((int *)((int)param_1));
}
