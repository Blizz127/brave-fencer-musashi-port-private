/* sc02_0037: func_8016163C from Druthulu/BFM-decomp
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
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 x, s32 y);
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
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s16 D_801152B0;
extern s16 D_801152B4;
extern s32 func_8014A6C4(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern void func_80161D20(s32 a0, s32 a1);
extern void func_80159B3C(void * a0);
extern void func_8014C010(s32 a0, s32 a1);
void func_8015BDD0(s32 *a0);
void func_8015BF48(s32 *a0);
extern s16 D_801152B0;
extern s16 D_801152B4;
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 func_80161208();
void func_8015F2F0(s32 *a0);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_8016130C(void*, s32);
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8016130C(void *a0, s32 a1);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
void func_801599A4(void *a0);
void func_8015BDD0(s32 *a0);
void func_8015BF48(s32 *a0);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20();
extern void func_8015BF48(s32 *a0);
extern s32 func_8014A6C4(s32 a0);
extern void func_8015F2F0(s32 *a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s16 D_801152B0;
extern s16 D_801152B4;
void func_80161D20(s32 param_1, s32 param_2);

s32 func_8016163C(s32 a0, u32 a1)
{
    s32 result;
    if ((a1 & 1) != 0) {
        func_801599A4(a0);
        func_80159B3C(a0);
        func_8014C010((s32)a0, 1);
        func_80161D20((s32)a0, *(u16 *)((s32)a0 + 0x16E));
        return 1;
    }
    if ((a1 & 0x4000) != 0) {
        func_801599A4(a0);
        func_8015BF48((s32 *)a0);
        func_8014C010((s32)a0, 1);
        func_80161D20((s32)a0, *(u16 *)((s32)a0 + 0x16E));
        return 2;
    }
    if ((a1 & 0x2000) != 0) {
        func_801599A4(a0);
        func_80159B3C(a0);
        func_8014C010((s32)a0, 1);
        func_80161D20((s32)a0, *(u16 *)((s32)a0 + 0x16E));
        return 4;
    }
    if ((a1 & 0x8000) != 0) {
        if (*(u16 *)((s32)a0 + 0x16C) != 0x15) {
            return 0;
        }
        if (func_8014A6C4((s32)a0) == 0) {
            return 0;
        }
        func_801599A4(a0);
        func_8015F2F0(a0);
        result = func_8004CFEC(D_801152B0, D_801152B4);
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = (s16)result;
        return 8;
    }
    return 0;
}
