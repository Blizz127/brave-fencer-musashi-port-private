/* sc03_0098: func_80139D04 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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

s32 func_80139D04(s32 a0, s32 a1) {
    u8 *p;
    u32 div;
    u32 acc;
    u32 cnt;
    register u32 flag __asm__("$7");
    register u32 param_2 __asm__("$5");
    u32 q;
    register u32 rem __asm__("$4");
    u32 hi;
    register u32 pm __asm__("$3");
    u32 dm;
    p = (u8 *)a0;
    param_2 = (u32)a1;
    div = 10000;
    acc = 0;
    flag = 0;
    cnt = 5;
    do {
        q = (param_2 & 0xffff) / (div & 0xffff);
        hi = acc << 4;
        acc = q | hi;
        if ((flag & 0xffff) == 0) {
            if ((acc & 0xffff) != 0) {
                flag = cnt;
            }
            if ((flag & 0xffff) != 0) goto store;
        } else {
        store:
            *p = (u8)q;
            p = p + 1;
        }
        pm = param_2 & 0xffff;
        __asm__ __volatile__("" : : "r"(pm));
        dm = div & 0xffff;
        rem = pm % dm;
        div = dm / 10;
        cnt = cnt - 1;
        param_2 = rem;
        if ((s32)cnt < 1) {
            if ((flag & 0xffff) == 0) {
                *p = 0;
                flag = flag + 1;
            }
            return flag & 0xffff;
        }
    } while (1);
}
