/* sc02_0037: func_8012BD3C from Druthulu/BFM-decomp
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
extern s32 func_80013478(s32 a0, s32 a1);
extern s16 D_80126CB4;
extern s16 D_80126CB4;
extern s32 func_80013478(s32 a0, s32 a1);
extern s16 D_80126CBA;
extern s32 func_80013478(s32 a0, s32 a1);
extern s32 func_8012BDBC(s32 a0, s32 a1);
extern s16 D_80126CBA;
extern s16 D_80126CB4;
s32 func_8012BDBC(s32 a0, s32 a1);

s32 func_8012BD3C(s32 a0, s32 a1, s32 a2) {
    s32 v;
    s32 hp;
    hp = a1;
    if (D_80126CBA != 0) {
        v = 0x7FFFFFFF;
    } else {
        v = func_80013478(a0 + 4, (s32)&D_80126CB4);
    }
    if (a2 < v) {
        return 0;
    }
    return func_8012BDBC(a0, (s16)hp);
}
