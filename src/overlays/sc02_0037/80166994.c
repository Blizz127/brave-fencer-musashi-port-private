/* sc02_0037: func_80166994 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef struct { s16 f0, f1, f2, f3, f4, f5; } TrailEntry;
typedef struct { u8 flag, idx, count, timer; TrailEntry e[16]; } Trail;
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
extern void func_80016714(void *a0, s32 a1);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern s32 func_80047E98(void *a0, void *a1);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80147324(s32 arg0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern void func_801484B0(s32 a0, s32 a1);
extern void func_80148534(s32 a0, s32 a1);
extern s32 func_800CF8B4();
extern void func_80149350(s32 arg0);
extern void func_801599A4(void *a0);
extern void func_80162CCC();
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
void func_80161CD0(s32 a0, s32 a1);
extern s32 func_800CF8B4(void);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
void func_8015BDD0(s32 *a0);
void func_8015BF48(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80148534(s32 a0, s32 a1);
extern void func_80149350(s32 arg0);
extern s32 func_80161208();
extern s32 func_800CF8B4(void);
extern s32 func_80161208();
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern void func_80148534(s32 a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_801484B0(s32, s32);
extern void func_80148534(s32, s32);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 arg0);
extern s32 func_800CF8B4();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
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
extern void func_8016191C(void *a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(int a0, int a1);
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
void func_801599A4(void *a0);
extern void func_80147324();
extern void func_80147324(s32 arg0);
extern int func_800CF8B4();
extern void func_80147324(int arg0);
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
extern void func_80147324(s32 arg0);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void *memcpy(void *, const void *, u32);
extern void *memcpy(void *, const void *, u32);
extern void func_80147324(s32 a0);
extern void func_80149350(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern void func_80162CCC();
extern void func_80162CCC();
extern void func_80148534(s32 a0, s32 a1);
extern void func_80162CCC();
extern void func_80148534(s32 a0, s32 a1);
extern void func_80162CCC();
extern s32 func_80161208();
extern void func_801599A4(void *a0);
extern void func_80016714(void *a0, s32 a1);
extern void func_801484B0(s32 a0, s32 a1);
extern s32 func_80165FA4(s32 a0, s32 a1, s32 a2);
extern void func_80148534(s32 a0, s32 a1);
s32 func_80165FA4(s32 arg0, s32 arg1, s32 arg2);
extern void func_801484B0(s32 a0, s32 a1);
extern void func_80148534(s32 a0, s32 a1);
extern void func_80149350(s32 arg0);
extern s32 func_80165FA4(s32 a0, s32 a1, s32 a2);

s32 func_80166994(param_1, param_2, param_3, param_4)
    s32 param_1;
    s16 param_2;
    s16 param_3;
    s16 param_4;
{
    extern u8 D_801C8710[];
    extern void func_8004945C(s32, s32, void*);
    extern s32 func_80047E98(void *a0, void *a1);
    Trail *p = &((Trail *)D_801C8710)[param_3];
    s32 uVar6 = *(s32 *)(param_1 + 0x34);
    s16 v10[4];
    s16 v18[4];
    s16 v20[4];
    s16 v28[4];
    s16 out[4];
    s32 c;
    switch (param_2) {
    case 0:
        p->flag = 1;
        p->count = 0;
        p->idx = 0;
        p->timer = 0xf4;
        break;
    case 1:
        v20[0] = p->e[p->idx].f0;
        v20[1] = p->e[p->idx].f1;
        v20[2] = p->e[p->idx].f2;
        v28[0] = p->e[p->idx].f3;
        v28[1] = p->e[p->idx].f4;
        v28[2] = p->e[p->idx].f5;
        c = p->idx;
        p->idx = c + 1;
        if ((u8)(c + 1) > 0xf) {
            p->idx = 0;
        }
        if (p->count < 0xf) {
            p->count = p->count + 1;
        }
        break;
    case 2: {
        u8 bVar3 = p->timer - 0x10;
        p->timer = bVar3;
        if (bVar3 < 0x10) {
            p->flag = 0;
            return 1;
        }
        {
            u8 bVar1 = p->count;
            if (bVar1 >= 2 && (bVar3 >> 4) < bVar1) {
                p->count = bVar1 - 1;
            }
        }
        return 0;
    }
    }
    if (param_3 < 2) {
        func_801484B0((s32)v10, (s32)v18);
    } else {
        func_80148534((s32)v10, (s32)v18);
    }
    func_80165FA4(uVar6, (s32)v10, (s32)v18);
    ((void (*)(s32, s32, s32))func_80149350)(uVar6, (s32)v10, (s32)v10);
    ((void (*)(void *, void *, void *))func_8004945C)(v18, v18, out);
    if (param_2 != 0) {
        v20[0] = (v10[0] + v20[0]) >> 1;
        v20[1] = (v10[1] + v20[1]) >> 1;
        v20[2] = (v10[2] + v20[2]) >> 1;
        v28[0] = (v18[0] + v28[0]) >> 1;
        v28[1] = (v18[1] + v28[1]) >> 1;
        v28[2] = (v18[2] + v28[2]) >> 1;
        v20[0] = v20[0] - v28[0];
        v20[1] = v20[1] - v28[1];
        v20[2] = v20[2] - v28[2];
        func_80047E98(v20, v20);
        v20[0] = v28[0] + v20[0] / param_4;
        v20[1] = v28[1] + v20[1] / param_4;
        v20[2] = v28[2] + v20[2] / param_4;
        p->e[p->idx].f0 = v20[0];
        p->e[p->idx].f1 = v20[1];
        p->e[p->idx].f2 = v20[2];
        p->e[p->idx].f3 = v28[0];
        p->e[p->idx].f4 = v28[1];
        p->e[p->idx].f5 = v28[2];
        c = p->idx;
        p->idx = c + 1;
        if ((u8)(c + 1) > 0xf) {
            p->idx = 0;
        }
        if (p->count < 0xf) {
            p->count = p->count + 1;
        }
    }
    p->e[p->idx].f0 = v10[0];
    p->e[p->idx].f1 = v10[1];
    p->e[p->idx].f2 = v10[2];
    p->e[p->idx].f3 = v18[0];
    p->e[p->idx].f4 = v18[1];
    p->e[p->idx].f5 = v18[2];
    return 0;
}
