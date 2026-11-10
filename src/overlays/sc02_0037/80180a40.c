/* sc02_0037: func_80180A40 from Druthulu/BFM-decomp
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
extern s32 D_801151D4;
extern void *memcpy(void *, const void *, unsigned int);
extern s32 D_801151D4;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012B77C(s32 out, s32 a1, s32 a2);
extern void func_8012C218(void *a0);
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
void func_8012C218(void *a0);
extern s32 func_8005C49C(void);
extern void func_80143C74(s32 a0, s32 a1);
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
extern int func_8005C49C(void);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012C218(void*);
extern int func_8005C49C(void);
extern short D_800B9A02;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012C218(void *a0);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012B77C(s32 out, s32 from, s32 to);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_80143C74(s32, s32);
extern s32 func_8005C49C(void);

void func_80180A40(s32 param_1)
{
    extern s32 D_801151D4;
    s32 sp10[4];
    s32 sp20;
    s32 v0;
    s32 v1;
    v0 = *(s32 *)(param_1 + 0x1C);
    v1 = D_801151D4;
    *(s32 *)(param_1 + 0x1C) = v0 - 1;
    *(s16 *)((s32)sp10 + 0x2) = *(s32 *)(v1 + 0x5C);
    *(s16 *)((s32)sp10 + 0x6) = *(s32 *)(v1 + 0x60);
    *(s16 *)((s32)sp10 + 0xA) = *(s32 *)(v1 + 0x64);
    func_8012B77C((s32)&sp20, param_1 + 4, (s32)sp10);
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x10) = (sp20 + 0x400) & 0xFFF;
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x18) += 0x55;
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x1A) += 0x55;
    v1 = *(s32 *)(param_1 + 0x1C);
    if (v1 == 0xF) {
        func_8002D4C8(0xCBA, 0);
        v1 = *(s32 *)(param_1 + 0x1C);
    }
    if (v1 < 0x10) {
        if (v1 == 0) {
            func_8012C218((void *)param_1);
        } else {
            param_1 = ((s32 (*)(s32, s32))func_80143C74)(param_1, 0);
            if (param_1 != 0) {
                *(s16 *)(param_1 + 0x16) = -4;
                v0 = func_8005C49C();
                *(s16 *)(param_1 + 0x12) = (v0 & 7) - 4;
                v0 = func_8005C49C();
                *(s16 *)(param_1 + 0x1A) = (v0 & 7) - 4;
                v0 = func_8005C49C();
                { s32 t = *(u16 *)(param_1 + 0x6) - 0x10; *(s16 *)(param_1 + 0x6) = t + (v0 & 0x1F); }
                v0 = func_8005C49C();
                { s32 t = *(u16 *)(param_1 + 0xE) - 0x10; *(s16 *)(param_1 + 0xE) = t + (v0 & 0x1F); }
            }
        }
    }
}
