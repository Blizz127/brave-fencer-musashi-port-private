/* sc03_0098: func_80137030 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);

void func_80137030(s16 a0, s16 a1) {
    struct {
        u32 tag;
        s16 x0;
        s16 y0;
        s16 x1;
        s16 y1;
        u8 r;
        u8 g;
        u8 b;
    } line;
    s16 cx;
    s16 cy;
    s16 tx;
    s16 ty;
    tx = a0 - 3;
    ty = a1 - 3;
    cx = a0;
    cy = a1;
    line.tag = 0;
    line.r = 0;
    line.g = 0xFF;
    line.b = 0;
    line.x0 = tx;
    line.y0 = ty;
    line.x1 = cx;
    line.y1 = cy;
    func_80051DC8(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
    tx = a0 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0xFF;
    line.b = 0;
    line.x0 = tx;
    line.y0 = ty;
    line.x1 = cx;
    line.y1 = cy;
    func_80051DC8(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
    ty = a1 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0xFF;
    line.b = 0;
    line.x0 = cx;
    line.y0 = ty;
    line.x1 = cx;
    line.y1 = cy;
    func_80051DC8(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
}
