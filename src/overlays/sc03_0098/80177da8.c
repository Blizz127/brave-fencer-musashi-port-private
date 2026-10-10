/* sc03_0098: func_80177DA8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
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

void func_80177DA8(p, v, idx)
u8 *p;
u32 v;
s16 idx;
{
    extern u8 D_80188B04[];
    u8 *r;
    u16 c;
    u16 flag;
    u32 n;
    u8 m;
    s16 i;
    u8 t;
    u32 x;
    u32 uv;
    u32 w1;
    u32 w2;
    flag = 0x100;
    i = 0;
    t = D_80188B04[idx];
    c = (t << 6) | 0x4016;
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    r = p;
    do {
        n = (v << 16) >> 28;
        m = n;
        if (n != 0 || i == 2 || i == 0xFF) {
            flag = 0;
        }
        v <<= 4;
        i++;
        *(s16 *)(r + 0xA) = flag | (*(s16 *)(r + 0xA) & ~0x100);
        *(u8 *)(r + 0xC) = m * 8 + 8;
        r += 0x14;
    } while (i < 3);
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    x = ((t << 6) | 0x4016) << 16;
    uv = idx << 4;
    w1 = uv | 0x1000;
    *(u32 *)(p + 0xC) = x | w1;
    w2 = uv | 0x1008;
    *(u32 *)(p + 0x20) = x | w2;
}
