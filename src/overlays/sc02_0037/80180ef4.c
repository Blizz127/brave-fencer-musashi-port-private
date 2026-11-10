/* sc02_0037: func_80180EF4 from Druthulu/BFM-decomp
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012C098(void *param_1);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8002A04C(s32 a0);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
void func_8012C098(void *param_1);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
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
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern short D_800B9A02;
extern void func_8012B2CC(s32 a0);
extern void func_8012B2CC(s32);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012B2CC(s32 a0);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
void func_8012B2CC(s32 a0);
s32 func_80153BD8(s32 a0);
s32 func_80153BF0(s32 a0);
void func_8002A04C(s32 a0);
void func_8012C098(void *param_1);

void func_80180EF4(s32 param_1)
{
    s32 result;
    if (*(unsigned short *)param_1 == 0) {
        return;
    }
    if (*(short *)(param_1 + 0x70) == 4) {
        result = func_8012C658(0x12C, 4, param_1);
        if (result != 0) {
            *(unsigned short *)(result + 0x6) = *(unsigned short *)(param_1 + 0x88);
            *(unsigned short *)(result + 0x88) = *(unsigned short *)(param_1 + 0x88);
            *(unsigned short *)(result + 0xE) = *(unsigned short *)(param_1 + 0x8C);
            *(unsigned short *)(result + 0x8C) = *(unsigned short *)(param_1 + 0x8C);
            *(unsigned short *)(result + 0xA) = *(unsigned short *)(param_1 + 0x8A) - 0x400;
            *(unsigned short *)(result + 0x8A) = *(unsigned short *)(param_1 + 0x8A);
            func_8012B2CC(result);
        }
    }
    if (func_80153BD8(param_1) != 0) {
        func_80153BF0(param_1);
    }
    if (*(s32 *)(param_1 + 0x78) != 0) {
        func_8002A04C(param_1);
    }
    func_8012C098((void *)param_1);
}
