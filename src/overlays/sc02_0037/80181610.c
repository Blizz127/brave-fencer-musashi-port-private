/* sc02_0037: func_80181610 from Druthulu/BFM-decomp
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
extern void func_8012A828(s32 a0, void * a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s16 D_800B9A02;
extern s16 D_80126B98;
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern u16 D_80126B96;
extern void func_8012A828(s32 a0, void *a1);
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
extern void func_8012A828(s32 a0, void *a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern short D_800B9A02;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32, void *);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80181610(s32 a0) {
    extern u8 D_801A3CC8[];
    extern u8 D_801A3CA0[];
    extern u8 D_801A3CA8[];
    extern u8 D_801AFCC0[];
    extern u16 D_80126B96;
    extern s16 D_80126B98;
    s32 result;
    u16 val70;
    u16 *q;
    if ((*(u16 *)(a0 + 0x72) & 0x4000) != 0) {
        *(s16 *)(a0 + 0x2) = 0xC;
        func_8012B1B4(a0, (s32)D_801A3CC8);
        *(s16 *)(a0 + 0x16) = -0x8;
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801AFCC0);
        *(s16 *)(a0 + 0x98) = 0x1;
    }
    if (*(s32 *)(a0 + 0x94) == 0xF) {
        result = func_8012D5E4(a0, (s32)D_801A3CA0, (s32)D_801A3CA8, 0x14);
        if (result == 1) {
            func_8002D4C8(0xCB2, 0);
            val70 = *(u16 *)(a0 + 0x70);
            if (((u32)val70 - 2) < 2) {
                q = &D_80126B96;
                D_80126B98 = 0x18;
                *q = *q | 0x2000;
            }
        }
    }
}
