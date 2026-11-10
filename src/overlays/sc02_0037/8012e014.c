/* sc02_0037: func_8012E014 from Druthulu/BFM-decomp
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
extern u8 D_80126B5C;
extern void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2);
extern void func_8012F1A4(s32 *a0, s32 a1, s32 *a2);
extern void func_80049CAC(s32 a0, s32 a1);
void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2);
void func_8012F1A4(s32 *a0, s32 a1, s32 *a2);

void func_8012E014(s32 a0) {
    extern s32 gVecX __asm__("D_80126B5C");
    extern s32 gVecY __asm__("D_80126B60");
    extern s32 gVecZ __asm__("D_80126B64");
    s32 in[4];
    s32 out[4];
    s32 tmp[4];
    s32 v;
    s32 w;
    s16 t;
    in[0] = gVecX;
    in[1] = gVecY;
    in[2] = gVecZ;
    func_8012F0BC((s32 *)(*(s32 *)(a0 + 0x20) + 0x34), in, tmp);
    v = *(s32 *)(a0 + 0x20);
    if (v != 0) {
        func_80049CAC(v + 0x10, v + 0x34);
        w = *(s32 *)(a0 + 0x20);
        t = *(u16 *)(a0 + 0x6) + *(u16 *)(a0 + 0x50);
        *(s16 *)(w + 0x8) = t;
        *(s32 *)(w + 0x48) = t;
        t = *(u16 *)(a0 + 0xA) + *(u16 *)(a0 + 0x52);
        *(s16 *)(w + 0xA) = t;
        *(s32 *)(w + 0x4C) = t;
        t = *(u16 *)(a0 + 0xE) + *(u16 *)(a0 + 0x54);
        *(s16 *)(w + 0xC) = t;
        *(u16 *)(w + 0x2C) |= 1;
        *(s32 *)(w + 0x50) = t;
    }
    func_8012F1A4((s32 *)(*(s32 *)(a0 + 0x20) + 0x34), (s32)tmp, out);
    gVecX = out[0];
    gVecY = out[1];
    gVecZ = out[2];
}
