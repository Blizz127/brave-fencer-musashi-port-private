/* sc01_0077: func_8013D178 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
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
extern u8 D_801DAA78;
extern unsigned char D_801DA9B8, D_801DA9B9, D_801DA9BA, D_801DA9BB, D_801DA9BC,
                     D_801DA9BD, D_801DA9BE, D_801DA9BF, D_801DA9C0;
extern unsigned char D_801DAA78, D_801DAA79, D_801DAA7A, D_801DAA7B, D_801DAA7C,
                     D_801DAA7D, D_801DAA7E, D_801DAA7F, D_801DAA80;

void func_8013D178(void) {
    unsigned char v, t;
    register unsigned char *p __asm__("$5");
    p = &D_801DA9B8; v = *p; t = D_801DAA78;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801DA9B9; v = *p; t = D_801DAA79;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801DA9BA; v = *p; t = D_801DAA7A;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801DA9BB; v = *p; t = D_801DAA7B;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801DA9BC; v = *p; t = D_801DAA7C;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801DA9BD; v = *p; t = D_801DAA7D;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801DA9BE; v = *p; t = D_801DAA7E;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801DA9BF; v = *p; t = D_801DAA7F;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801DA9C0; v = *p; t = D_801DAA80;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
