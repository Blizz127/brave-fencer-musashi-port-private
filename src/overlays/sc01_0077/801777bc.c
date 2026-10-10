/* sc01_0077: func_801777BC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
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
extern void func_8012A568(void (*a0)(void));

void *func_801777BC(void *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6)
{
    u32 cl;
    u32 flag;
    u32 nn;
    register u32 n __asm__("$10");
    u32 t;
    register u32 col __asm__("$4");
    u32 mask;
    s32 cnt;
    s32 dp;
    s16 i;
    flag = 0x1000000;
    cl = ((((s16)a5 + 0x100) << 6) | 0x16) << 16;
    dp = a6;
    i = 0;
    if ((s16)a4 > 0) {
        cnt = (s16)a4;
        do {
            nn = ((u32)(a1 << 16)) >> 28;
            n = nn;
            if (((nn != 0) || (i == cnt - 1)) || (i == ((s32)(dp << 16) >> 16))) {
                flag = 0;
            }
            mask = 0xffffff;
            col = 0x74808080;
            t = ((u32)((u32 *)a0 - 5)) & mask;
            mask = 0x3000000;
            t = t | mask;
            ((u32 *)a0)[0] = t;
            t = ((a3 << 16) | (a2 & 0xffff)) | flag;
            ((u32 *)a0)[2] = t;
            ((u32 *)a0)[1] = col;
            t = n << 3;
            t = t + 8;
            t = t | 0x4000;
            ((u32 *)a0)[3] = cl | t;
            a0 = (void *)((u32 *)a0 + 5);
            a2 += 8;
            a1 <<= 4;
            col = 0;
            i++;
        } while ((s16)i < cnt);
    }
    return a0;
}
