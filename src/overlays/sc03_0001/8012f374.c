/* sc03_0001: func_8012F374 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_80126CB8;
extern s16 D_80126CB4;
extern s16 D_80126CB8;
extern s16 D_80126CB4;
extern s16 D_80126CB4;
extern s16 D_80126CB8;
extern s16 D_80126CB4;
extern void func_8004D504(void *a0, void *a1, void *a2);
extern void func_8004D504(void *a0, void *a1, void *a2);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern void func_80015954(s32 a0, s32 a1);
static inline void tail_8012F274(s32 *in, s32 e) {
    s32 out[2];
    s32 flag[2];
    ((void (*)(s32 *, s32 *, s32 *))func_8004945C)(in, out, flag);
    ((void (*)(s32 *, s32))func_80015954)(out, e);
}
extern void func_8004D504(void *a0, void *a1, void *a2);
extern void func_8004D504(void *a0, void *a1, void *a2);
extern s16 D_80126CB4;
extern s16 D_80126CB6;
extern s16 D_80126CB8;

void func_8012F374(s32 a0, s32 a1) {
    s32 s0 = a1;
    s32 in[3];
    s32 out[3];
    s32 mtx;
    mtx = *(s32 *)(a0 + 0x20);
    in[0] = D_80126CB4 - *(s32 *)(mtx + 0x48);
    in[1] = D_80126CB6 - *(s32 *)(mtx + 0x4C);
    in[2] = D_80126CB8 - *(s32 *)(mtx + 0x50);
    func_8004D504((void *)(mtx + 0x34), in, out);
    *(s16 *)(s0 + 0x0) = out[0];
    *(s16 *)(s0 + 0x2) = out[1];
    *(s16 *)(s0 + 0x4) = out[2];
}
