/* sc03_0001: func_8016F95C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
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
extern void func_80147060(u8 * a0);
extern void func_80148634(void *a0);
extern void func_801511A8(u8 *a0);
extern u8 D_800B9A17;
extern u8 D_800B9A17;
extern void func_8017196C(s32 *a0, s8 a1);
extern void func_80147060(u8 *a0);
extern void func_801511A8(u8 *a0);
extern void func_80148634(void *a0);
void aF8016F0E4(u8 *p) __asm__("func_8016F0E4");
extern void func_80148634(void *a0);
extern u8 D_800B9A17;
extern u8 D_800B9A17;
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80147060(u8 *a0);
extern void func_80171928(void *a0);
extern void func_80148634(void *a0);
extern void func_80171928(void *a0);
extern void func_80148634(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *);
extern void func_80171928(void *a0);
extern s32 func_80171CC4(void *a0, void *a1);
extern s32 func_80171D1C(void *a0, void *a1, s32 a2);
extern void func_80171928(void *a0);
extern u16 D_8011F73E;
void func_80171928(void * a0);
void func_8017196C(s32 *a0, s8 a1);

void func_8016F95C(void *a0) {
    u16 *p = &D_8011F73E;
    u16 v = *p;
    s32 r;
    if (v == 0) {
        r = func_80171CC4(a0, p - 3);
    } else {
        r = func_80171D1C(a0, p - 3, v & 0xFF);
    }
    if (r != 0) {
        func_80171928(a0);
    }
}
