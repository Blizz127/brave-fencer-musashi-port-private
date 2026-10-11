/* sc03_0001: func_80137FD8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
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
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern void memcpy();
extern s16 D_800B9A02;
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
void func_80137030(s16 a0, s16 a1);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_80137614(s32 a0, s32 a1, s32 a2);
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_801376E8(int a0, int a1);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_80139BE0(s32 a0);
void *aF801376E8(int a0, int a1) __asm__("func_801376E8");
void * aF801376E8(int a0, int a1) __asm__("func_801376E8");
void *aF801376E8(int a0, int a1) __asm__("func_801376E8");
void func_801377B4(s32 a0, s32 a1, s32 a2);
extern s32 D_801269F0;
extern int D_801269F0;
extern short D_800B9A02;
extern int D_801269F0;

void func_80137FD8(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 v;
    u16 h30;
    *(u8 *)(a2 + 0x3) = 8;
    *(u8 *)(a2 + 0x7) = 0x3A;
    *(u8 *)(a2 + 0x4) = *(u8 *)(a1 + 0x0);
    *(u8 *)(a2 + 0x5) = *(u8 *)(a1 + 0x1);
    *(u8 *)(a2 + 0x6) = *(u8 *)(a1 + 0x2);
    *(u8 *)(a2 + 0xC) = *(u8 *)(a1 + 0x0);
    *(u8 *)(a2 + 0xD) = *(u8 *)(a1 + 0x1);
    *(u8 *)(a2 + 0xE) = *(u8 *)(a1 + 0x2);
    *(u8 *)(a2 + 0x14) = 0xFF;
    *(u8 *)(a2 + 0x15) = 0xFF;
    *(u8 *)(a2 + 0x16) = 0xFF;
    *(u8 *)(a2 + 0x1C) = 0xFF;
    *(u8 *)(a2 + 0x1D) = 0xFF;
    *(u8 *)(a2 + 0x1E) = 0xFF;
    h30 = *(u16 *)(a0 + 0x30);
    *(u16 *)(a2 + 0x18) = h30;
    *(u16 *)(a2 + 0x8) = h30;
    if (*(u32 *)(a0 + 0x8) & 0x2000) {
        v = (*(u16 *)(a0 + 0x30) + *(u16 *)(a0 + 0x34)) - 0xC;
        *(u16 *)(a2 + 0x20) = v;
        *(u16 *)(a2 + 0x10) = v;
    } else {
        s32 w = *(u16 *)(a0 + 0x30) + *(u16 *)(a0 + 0x34);
        *(u16 *)(a2 + 0x20) = w;
        *(u16 *)(a2 + 0x10) = w;
    }
    if (*(u8 *)(a1 + 0x3) == 0) {
        s32 hi = a3 + 0x5;
        *(u16 *)(a2 + 0x12) = a3;
        *(u16 *)(a2 + 0xA) = a3;
        *(u16 *)(a2 + 0x22) = hi;
        *(u16 *)(a2 + 0x1A) = hi;
        return;
    }
    {
        s32 lo = a3 + 0xC;
        register s32 hi __asm__("$3") = a3 + 0x5;
        *(u16 *)(a2 + 0x12) = lo;
        *(u16 *)(a2 + 0xA) = lo;
        *(u16 *)(a2 + 0x22) = hi;
        *(u16 *)(a2 + 0x1A) = hi;
    }
}
