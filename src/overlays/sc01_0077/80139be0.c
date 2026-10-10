/* sc01_0077: func_80139BE0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
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
extern short D_800B9A02;
extern unsigned char D_801870E8[];

s32 func_80139BE0(int param_1)
{
    int v;
    if ((*(unsigned int *)(param_1 + 8) & 0x2000) == 0) {
        int t = *(unsigned char *)(param_1 + 0x22) & 0x60;
        int h = *(unsigned short *)(param_1 + 0x18);
        unsigned int idx;
        __asm__("" : "=r"(t) : "0"(t));
        idx = (unsigned char)t;
        if (h < 7) {
            if (h >= 2) {
                v = D_801870E8[idx >> 5];
            } else {
                v = D_801870E8[0];
            }
        } else {
            v = D_801870E8[0];
        }
        *(short *)(param_1 + 0x2e) = 3;
        *(short *)(param_1 + 0x2c) = v;
    }
    *(short *)(param_1 + 0x34) = *(short *)(param_1 + 0x2c) * 6;
    {
        int x = *(short *)(param_1 + 0x2e);
        *(short *)(param_1 + 0x36) = x * 12 + (x - 1) * 2;
    }
}
