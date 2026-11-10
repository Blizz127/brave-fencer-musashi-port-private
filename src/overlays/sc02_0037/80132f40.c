/* sc02_0037: func_80132F40 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
typedef struct { u16 vx, vy, vz, pad; } Svec_80132F40;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F038(int param_1, short *param_2, short *param_3);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888();
extern void *memcpy(void *, const void *, u32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131CF4(s32 a0);
extern void func_80131CA8(s32 a0, s32 a1);
extern s32 func_80131CF4(s32 a0);
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern void *memcpy(void *, const void *, u32);
extern void func_8012F038(int param_1, short *param_2, short *param_3);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32, s32, s32, s32);
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern u8 D_80126BE0[];
s32 func_80135888(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_80132F40(s32 arg0)
{
    Svec_80132F40 v[4];
    register Svec_80132F40 *q __asm__("$17");
    register s16 *p __asm__("$2");
    register s32 h __asm__("$2");
    register s32 c __asm__("$2");
    register s32 hh __asm__("$4");
    s32 w;
    s32 m;
    q = &v[1];
    v[0].vx = D_80126B5E;
    v[0].vy = D_80126B62;
    v[0].vz = D_80126B66;
    v[1] = v[0];
    if (func_80135888(*(s32 *)(arg0 + 0x20), *(s32 *)(arg0 + 0x58),
                      (s32)D_80126BE0, (s32)q) != 0) {
        do { } while (0);
        p = (s16 *)((*(s32 *)(arg0 + 0x58) & 0x0FFFFFFF) | 0x80000000);
        w = p[4];
        h = p[5];
        hh = h;
        c = (h < w);
        if (c) { m = hh; } else { m = w; }
        func_8012F038(*(s32 *)(arg0 + 0x20) + 0x34, &v[0], q);
        v[1].vy = m;
        func_8012F14C(*(s32 *)(arg0 + 0x20) + 0x34, q, &v[0]);
        D_80126B5E = v[0].vx;
        D_80126B62 = v[0].vy;
        D_80126B66 = v[0].vz;
    }
}
