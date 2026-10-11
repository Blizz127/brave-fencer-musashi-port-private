/* sc03_0001: func_80145934 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_after.c (preprocessed; only the declarations it uses),
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
extern void func_800D185C(u8 *a0);
extern s32 func_80029504(void);
extern void func_800D185C(u8 *a0);
extern void func_80145B24(void);
extern u8 D_8018FA44;
extern u8 D_8018F9B4;
extern u8 D_8018F990;
extern u8 D_8018F96C;
extern u8 D_8018FA20;
extern u8 D_8018F9FC;
extern u8 D_8018F9D8;
extern u8 D_8018F948;
void func_80145B24(void);

void func_80145934(void) {
    s32 v;
    void *p;
    v = func_80029504();
    if (v >= 0x6A4) {
        p = &D_8018FA44;
        __asm__ __volatile__("" ::: "memory");
    } else if (v >= 0x5DC) {
        p = &D_8018F9B4;
    } else if (v >= 0x578) {
        p = &D_8018F990;
    } else if (v >= 0x514) {
        p = &D_8018F96C;
    } else if (v >= 0x384) {
        p = &D_8018FA44;
    } else if (v >= 0x258) {
        p = &D_8018FA20;
    } else if (v >= 0xC8) {
        p = &D_8018F9FC;
    } else if (v >= 0xA) {
        p = &D_8018F9D8;
    } else {
        p = &D_8018F948;
    }
    ((void (*)(void *))func_800D185C)(p);
    func_80145B24();
}
