/* sc01_0077: func_80176218 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
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
extern u8 D_80078E78[];
extern u16 D_80078EB2;
extern s16 D_80078EB4;
extern void func_8012A568(void (*a0)(void));
extern u8 D_8011F7A8;
extern u8 D_80078E78[];
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern u8 D_8018A2B8[];
extern s32 func_8005A600(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern u16 D_80078EB2;
extern u16 D_8011F82A;
extern u16 D_8011F82C;
extern s16 D_80078EB4;
extern u16 D_8011F8C4;
extern u8 D_8011F7A8;
extern u8 D_80078E78[];
extern u8 D_8018A2B8[];
extern u8 *D_8018A23C[];
extern void func_80176FF4(s32);
extern void func_80177340(s32);
extern u32 func_801783D0(s32, s32);
extern void func_80177F84(s32, s32);
extern void func_80177DA8(u8 * p, u32 v, s32 idx);
extern void func_80177AD4(int, unsigned int);
extern s32 func_80024054(u8 *, u8 *);
extern u32 *func_80178298(u32*, u8*, short, short);
extern s32 func_8005A600(s32, s32, s32, s32, s32);
void func_80176FF4(s32 a0);
void func_80177340(s32 a0);
void func_80177AD4(int param_1, unsigned int param_2);
void func_80177DA8();
void func_80177F84(s32 param_1, s32 param_2);
u32 *func_80178298(u32 *param_1, u8 *param_2, short param_3, short param_4);
u32 func_801783D0(s32 a0, s32 a1);

void func_80176218(s32 param_1)
{
    s32 st = (s32)&D_8011F7A8;
    s32 cach = st + 0x48;
    s32 flag = st + 0xE0;
    s32 cur = (s32)&(*(u8 *)D_80078E78);
    u8 buf[24];
    s32 ne;
    s32 t;
    u16 sA;
    sA = D_80078EB2;
    t = (sA != D_8011F82A);
    if (D_8011F82C == (*(u16 *)&D_80078EB4)) {
        ne = t;
        if (ne == 0 && D_8011F8C4 == 0) goto L340;
    } else {
        s32 d = (s16)(D_8011F82C - (*(u16 *)&D_80078EB4));
        u16 nv;
        if (d < 0) {
            if (d < -10) nv = D_8011F82C + 2;
            else nv = D_8011F82C + 1;
        } else {
            if (d > 10) nv = D_8011F82C - 2;
            else nv = D_8011F82C - 1;
        }
        D_8011F82C = nv;
        *(u16 *)(flag + 0x3C) = 1;
        *(u16 *)(cach + 0x3A) = *(u16 *)(cur + 0x3A);
        goto L328;
    }
    if (ne) {
        *(u16 *)(st + 0x82) = sA;
        *(u16 *)(st + 0x11C) = 1;
    } else {
        *(u16 *)(st + 0x11C) = 0;
    }
L328:
    func_80176FF4(*(s32 *)(((param_1 << 16) >> 14) + st + 0x18));
L340:
    sA = *(u16 *)(cur + 0x3E);
    t = (sA != *(u16 *)(cach + 0x3E));
    if (*(u16 *)(cach + 0x40) == *(u16 *)(cur + 0x40)) {
        ne = t;
        if (ne == 0 && *(u16 *)(flag + 0x40) == 0) goto L444;
    } else {
        s32 d = (s16)(*(u16 *)(cach + 0x40) - *(u16 *)(cur + 0x40));
        u16 nc;
        if (d < 0) {
            if (d < -10) nc = *(u16 *)(cach + 0x40) + 2;
            else nc = *(u16 *)(cach + 0x40) + 1;
        } else {
            if (d > 10) nc = *(u16 *)(cach + 0x40) - 2;
            else nc = *(u16 *)(cach + 0x40) - 1;
        }
        *(u16 *)(cach + 0x40) = nc;
        *(u16 *)(flag + 0x40) = 1;
        *(u16 *)(cach + 0x3E) = *(u16 *)(cur + 0x3E);
        goto L3E8;
    }
    if (ne) {
        *(u16 *)(cach + 0x3E) = sA;
        *(u16 *)(flag + 0x40) = 1;
    } else {
        *(u16 *)(flag + 0x40) = 0;
    }
L3E8:
    {
        s32 s0b = ((param_1 << 16) >> 14) + st;
        u16 cc;
        s32 pp;
        func_80177340(*(s32 *)(s0b + 0x18) + 0x104);
        cc = *(u16 *)(cach + 0x40);
        pp = *(s32 *)(s0b + 0x28);
        if (cc < 100)
            *(u8 *)(pp + 0x5D) = D_8018A2B8[cc / 5];
        else
            *(u8 *)(pp + 0x5D) = 0;
    }
L444:
    if (*(s32 *)(cach + 0x14) == *(s32 *)(cur + 0x14)) {
        if (*(s32 *)(flag + 0x14) == 0) goto L4D0;
        *(s32 *)(flag + 0x14) = 0;
        goto L4A8;
    } else {
        s32 d = *(s32 *)(cur + 0x14) - *(s32 *)(cach + 0x14);
        s32 nd;
        if (d > 0) {
            if (d < 10) nd = *(s32 *)(cach + 0x14) + 1;
            else nd = *(s32 *)(cach + 0x14) + 10;
        } else {
            if (d < -9) nd = *(s32 *)(cach + 0x14) - 10;
            else nd = *(s32 *)(cach + 0x14) - 1;
        }
        *(s32 *)(cach + 0x14) = nd;
        *(s32 *)(flag + 0x14) = 1;
    }
L4A8:
    {
        u32 r = func_801783D0(*(s32 *)(cach + 0x14), 0);
        func_80177F84(*(s32 *)(((param_1 << 16) >> 14) + st + 0x18) + 0x208, r);
    }
L4D0:
    if (*(u16 *)(cur + 0x34) != *(u16 *)(cach + 0x34)) {
        *(u16 *)(cach + 0x34) = *(u16 *)(cur + 0x34);
        *(u16 *)(flag + 0x34) = 1;
        *(u8 *)(cach + 0x42) = *(u8 *)(cur + 0x42);
    } else {
        if (*(u16 *)(flag + 0x34) == 0) goto L558;
        *(u16 *)(flag + 0x34) = 0;
    }
    {
        u16 e = 999;
        s16 r;
        if (*(u16 *)(cach + 0x34) < 1000) e = *(u16 *)(cach + 0x34);
        r = (s16)func_801783D0((s16)e, 4);
        func_80177DA8(*(s32 *)(((param_1 << 16) >> 14) + st + 0x18) + 0x294,
                      (s32)r, *(u8 *)(cach + 0x42));
    }
L558:
    if (*(s16 *)(cach + 0x1A) != *(s16 *)(cur + 0x1A)) {
        *(s16 *)(cach + 0x1A) = *(s16 *)(cur + 0x1A);
        *(s16 *)(flag + 0x1A) = 1;
    } else {
        if (*(s16 *)(flag + 0x1A) == 0) goto L63C;
        *(s16 *)(flag + 0x1A) = 0;
    }
    {
        u16 f = *(u16 *)(cach + 0x1A);
        s32 e = *(s32 *)(((param_1 << 16) >> 14) + st + 0x18);
        s32 i6, i4, sum;
        if (f & 1) *(s16 *)(e + 0x32A) = 0x200;
        else *(s16 *)(e + 0x32A) = *(u16 *)(st + 0x16) + 0x65;
        {
            s32 t = (((s16)f / 15) & 3) * 15;
            i6 = func_801783D0(((s16)f / 15) * 0x10000 >> 0x12, 8);
            i4 = func_801783D0((t * 0x10000) >> 16, 0);
        }
        sum = i4;
        i4 = i6 + sum;
        ((void (*)(s32, s32))func_80177AD4)(*(s32 *)(((param_1 << 16) >> 14) + st + 0x18) + 800,
                      i4 * 0x10000 >> 0x10);
    }
L63C:
    if (*(u8 *)(cur + 0x4A) != *(u8 *)(cach + 0x4A)) {
        *(u8 *)(cach + 0x4A) = *(u8 *)(cur + 0x4A) & 0x7F;
        *(u8 *)(flag + 0x4A) = 1;
    } else {
        if (*(u8 *)(flag + 0x4A) == 0) return;
        *(u8 *)(flag + 0x4A) = 0;
    }
    {
        s32 s0b = ((param_1 << 16) >> 14) + st;
        u8 *arg = D_8018A23C[*(u8 *)(cach + 0x4A)];
        u32 *p = (u32 *)(*(s32 *)(s0b + 0x18) + 900);
        func_80024054(arg, buf);
        p = ((u32 * (*)(u32 *, u8 *, s32, s32))func_80178298)(p, buf,
                          (s16)(*(u16 *)(st + 0x14) + 0x39),
                          (s16)(*(u16 *)(st + 0x16) + 0x5B));
        func_8005A600((s32)p, 0, 0, 0x15, 0);
        *p = ((u32)((u8 *)p - 0x14) & 0xffffff) | 0x2000000;
        *(u32 **)(s0b + 0x20) = p;
    }
}
