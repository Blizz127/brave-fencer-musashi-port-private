/* sc02_0037: func_8015B6F4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015A3C8.c (preprocessed; only the declarations it uses),
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
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80147300(u16 arg0);
extern void func_80147324(s32 arg0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 func_80149AA8(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80156648(s32 *a0);
extern void func_80154A74(int, int);
extern s32 func_80149AA8(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80154150(s32 a0, s32 a1);
extern s32 D_800D4A9C;
extern s32 func_80149AA8(s32 *a0);
extern void func_80156648(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80147324(s32 arg0);
extern void func_80147300(u16 arg0);
extern s32 D_800D4A9C;

int func_8015B6F4(int param_1)
{
    int b4;
    register unsigned int f44 __asm__("$2");
    register unsigned int bc __asm__("$4");
    if (((int (*)(void))func_80149AA8)() == 0) return 0;
    ((void (*)(int))func_80156648)(param_1);
    b4 = *(int *)(param_1 + 0xb4);
    *(unsigned char *)(param_1 + 0x1aa) = 6;
    __asm__ __volatile__("" ::: "memory");
    f44 = *(unsigned int *)(param_1 + 0x44);
    bc = *(unsigned char *)(param_1 + 0xbc);
    *(int *)(param_1 + 0x23c) = b4;
    *(unsigned int *)(param_1 + 0x44) = f44 | 2;
    *(unsigned char *)(param_1 + 0x244) = bc;
    if (*(int *)(param_1 + 0xb4) == (int)&D_800D4A9C) {
        func_80154150(param_1, 0xb);
    } else {
        func_80154150(param_1, 0xc);
    }
    func_80154A74(param_1, 0x22);
    *(unsigned char *)(param_1 + 0xda) = 0;
    ((void (*)(int, int, int, int))func_80146994)(4, param_1, 5, 0);
    func_80147324(0x400);
    ((void (*)(int))func_80147300)(0x5f3);
    return 1;
}
