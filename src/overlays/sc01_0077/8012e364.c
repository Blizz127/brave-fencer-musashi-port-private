/* sc01_0077: func_8012E364 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern s16 D_80126CE0;
extern s32 D_801D9498;
extern s32 D_801D949C;

void func_8012E364(s32 arg0_)
{
    s32 arg0;
    register s32 prev __asm__("$5");
    register u16 flags __asm__("$2");
    s32 a;
    s32 diff;
    s32 v;
    register s32 d __asm__("$2");
    s32 spd;
    s32 e1;
    s32 e2;
    arg0 = arg0_;
    *(s16 *)(arg0 + 0x5C) = 0;
    a = D_80126CE0;
    if (a == 0) {
        D_801D9498 = 0x1000;
        D_801D949C = 0x1000;
    }
    a = ((0x90 - a) << 12) / 0x90;
    *(s32 *)(arg0 + 0x1C) += 1;
    spd = 0x1000;
    diff = D_801D9498 - a;
    if (diff > 0) {
        D_801D9498 -= diff >> 2;
    } else if (diff < 0) {
        D_801D9498 += (-diff) / 4;
    }
    prev = D_801D949C;
    e1 = *(s32 *)(arg0 + 0x20);
    v = D_801D9498 - prev + spd;
    D_801D949C = spd;
    flags = *(u16 *)(e1 + 0x2C);
    D_801D9498 = v;
    *(u16 *)(e1 + 0x2C) = flags | 0x10;
    e2 = *(s32 *)(arg0 + 0x20);
    d = __builtin_abs(v);
    *(s16 *)(e2 + 0x1C) = d;
    *(s16 *)(e2 + 0x18) = d;
    *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x1A) = 0x1000;
}
