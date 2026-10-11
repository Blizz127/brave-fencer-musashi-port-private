/* sc03_0001: func_8013F1BC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
typedef struct { s32 f0; } E4;
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
extern unsigned short D_80115112;
extern s32 D_80115188;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern u16 D_80115112;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern s16 D_800B9A02;
extern E4 aD80115188[] __asm__("D_80115188");
extern u16 D_80115112;
extern void func_800D2624(void);
extern unsigned short D_80115118;
extern unsigned short D_80115112;
extern void func_800D2624(void);
extern short D_800B9A02;
extern unsigned short D_80115114;
extern unsigned short D_80115112;
extern unsigned short D_80115118;

void func_8013F1BC(void) {
    unsigned short *p = &D_80115118;
    if (*p != 0) {
        *p -= 0x10;
        __asm__ __volatile__("" ::: "memory");
        if (*p != 0) {
            return;
        }
    }
    if (D_80115114 == ((unsigned short)D_800B9A02 ^ 1)) {
        func_800D2624();
    } else {
        D_80115112 += 1;
    }
}
