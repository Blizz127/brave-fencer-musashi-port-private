/* sc02_0037: func_8012B2CC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
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
extern void func_80049CAC(s32 a0, s32 a1);

void func_8012B2CC(s32 a0)
{
    s32 a1;
    s32 p;
    s16 v;
    a1 = *(s32 *)(a0 + 0x20);
    if (a1 != 0) {
        func_80049CAC(a1 + 0x10, a1 + 0x34);
        p = *(s32 *)(a0 + 0x20);
        v = *(u16 *)(a0 + 0x6) + *(u16 *)(a0 + 0x50);
        *(s16 *)(p + 0x8) = v;
        *(s32 *)(p + 0x48) = v;
        v = *(u16 *)(a0 + 0xA) + *(u16 *)(a0 + 0x52);
        *(s16 *)(p + 0xA) = v;
        *(s32 *)(p + 0x4C) = v;
        v = *(u16 *)(a0 + 0xE) + *(u16 *)(a0 + 0x54);
        *(s16 *)(p + 0xC) = v;
        *(u16 *)(p + 0x2C) = *(u16 *)(p + 0x2C) | 1;
        *(s32 *)(p + 0x50) = v;
    }
}
