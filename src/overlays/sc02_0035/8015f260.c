/* SC02.CD member35: func_8015F260 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
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
extern void func_80149048(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);
extern void func_80154A74(s32, s32);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80149048(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80149048(s32 *a0);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80149048(s32 *a0);

void func_8015F260(s32 *a0) {
    s32 v;
    func_801553A8(a0);
    func_80154A74((s32)a0, 0x11);
    v = a0[0x11];
    v &= -0x3;
    v &= -0x2;
    a0[0x11] = v;
    func_80149048(a0);
    *(s16 *)((u8 *)a0 + 0xF6) = 0x1000;
}
