/* sc03_0001: func_8016C374 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
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

s32 func_8016C374(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 v;
    *(u16 *)(a1 + 0x0) = *(u16 *)(a1 + 0x0) - 0xA;
    if ((s16)*(u16 *)(a1 + 0x0) < 0) {
        *(u16 *)(a1 + 0x0) = 0;
    }
    *(u16 *)(a1 + 0x2) = *(u16 *)(a1 + 0x2) - 0xA;
    if ((s16)*(u16 *)(a1 + 0x2) < 0) {
        *(u16 *)(a1 + 0x2) = 0;
    }
    *(u16 *)(a1 + 0x4) = *(u16 *)(a1 + 0x4) - 0xA;
    if ((s16)*(u16 *)(a1 + 0x4) < 0) {
        *(u16 *)(a1 + 0x4) = 0;
    }
    *(u16 *)(a2 + 0x0) = *(u16 *)(a2 + 0x0) - 0xA;
    if ((s16)*(u16 *)(a2 + 0x0) < 0) {
        *(u16 *)(a2 + 0x0) = 0;
    }
    *(u16 *)(a2 + 0x2) = *(u16 *)(a2 + 0x2) - 0xA;
    if ((s16)*(u16 *)(a2 + 0x2) < 0) {
        *(u16 *)(a2 + 0x2) = 0;
    }
    *(u16 *)(a2 + 0x4) = *(u16 *)(a2 + 0x4) - 0xA;
    if ((s16)*(u16 *)(a2 + 0x4) < 0) {
        *(u16 *)(a2 + 0x4) = 0;
    }
    *(u8 *)(a3 + 0x0) = *(u16 *)(a1 + 0x0);
    *(u8 *)(a3 + 0x1) = *(u16 *)(a1 + 0x2);
    *(u8 *)(a3 + 0x2) = *(u16 *)(a1 + 0x4);
    *(u8 *)(a3 + 0x4) = *(u16 *)(a2 + 0x0);
    *(u8 *)(a3 + 0x5) = *(u16 *)(a2 + 0x2);
    *(u8 *)(a3 + 0x6) = *(u16 *)(a2 + 0x4);
    v = *(u16 *)(a2 + 0x4) | (*(u16 *)(a2 + 0x0) | *(u16 *)(a2 + 0x2));
    return (s16)v;
}
