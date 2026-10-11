/* sc03_0001: func_8013D178 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");

void func_8013D178(void) {
    extern u8 D_801EF2E8;
    extern u8 D_801EF2E9;
    extern u8 D_801EF2EA;
    extern u8 D_801EF2EB;
    extern u8 D_801EF2EC;
    extern u8 D_801EF2ED;
    extern u8 D_801EF2EE;
    extern u8 D_801EF2EF;
    extern u8 D_801EF2F0;
    extern unsigned char D_801EF398, D_801EF399, D_801EF39A, D_801EF39B, D_801EF39C, D_801EF39D, D_801EF39E, D_801EF39F, D_801EF3A0;
    extern unsigned char D_801EF398, D_801EF399, D_801EF39A, D_801EF39B, D_801EF39C, D_801EF39D, D_801EF39E, D_801EF39F, D_801EF3A0;
    extern unsigned char D_801EF398, D_801EF399, D_801EF39A, D_801EF39B, D_801EF39C, D_801EF39D, D_801EF39E, D_801EF39F, D_801EF3A0;
    extern unsigned char D_801EF398, D_801EF399, D_801EF39A, D_801EF39B, D_801EF39C, D_801EF39D, D_801EF39E, D_801EF39F, D_801EF3A0;
    extern unsigned char D_801EF398, D_801EF399, D_801EF39A, D_801EF39B, D_801EF39C, D_801EF39D, D_801EF39E, D_801EF39F, D_801EF3A0;
    extern unsigned char D_801EF398, D_801EF399, D_801EF39A, D_801EF39B, D_801EF39C, D_801EF39D, D_801EF39E, D_801EF39F, D_801EF3A0;
    extern unsigned char D_801EF398, D_801EF399, D_801EF39A, D_801EF39B, D_801EF39C, D_801EF39D, D_801EF39E, D_801EF39F, D_801EF3A0;
    extern unsigned char D_801EF398, D_801EF399, D_801EF39A, D_801EF39B, D_801EF39C, D_801EF39D, D_801EF39E, D_801EF39F, D_801EF3A0;
    extern unsigned char D_801EF398, D_801EF399, D_801EF39A, D_801EF39B, D_801EF39C, D_801EF39D, D_801EF39E, D_801EF39F, D_801EF3A0;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");
    p = &D_801EF2E8; v = *p; t = D_801EF398;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801EF2E9; v = *p; t = D_801EF399;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801EF2EA; v = *p; t = D_801EF39A;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801EF2EB; v = *p; t = D_801EF39B;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801EF2EC; v = *p; t = D_801EF39C;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801EF2ED; v = *p; t = D_801EF39D;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801EF2EE; v = *p; t = D_801EF39E;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801EF2EF; v = *p; t = D_801EF39F;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801EF2F0; v = *p; t = D_801EF3A0;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
