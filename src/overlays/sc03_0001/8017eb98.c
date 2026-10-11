/* sc03_0001: func_8017EB98 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { short vx, vy, vz, pad; } SVECTOR;
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
typedef struct { short m[3][3]; long t[3]; } MATRIX;
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
extern s32 func_80012C6C(s32 a0, s32 a1, s32 a2);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8012A568(void (*a0)(void));
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_80049CAC(s32 a0, s32 a1);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern s32 func_80012ABC(s32 a0, s32 a1, s32 a2);
extern s32 func_80012C6C(s32 a0, s32 a1, s32 a2);
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);

void func_8017EB98(s32 param_1)
{
    extern s16 D_80126940;
    extern s16 D_80126942;
    extern s16 D_80126944;
    MATRIX m1;
    SVECTOR svec_in;
    SVECTOR svec_out;
    s32 lim;
    lim = *(u16 *)(param_1 + 0x9C);
    {
        s32 delta = func_80012B04(*(s16 *)(param_1 + 0x1A), *(s16 *)(param_1 + 0x22), 0x14);
        if ((s16)delta > (s16)lim) {
            delta = lim;
        } else if ((s16)delta < -(s16)lim) {
            delta = -lim;
        }
        *(s16 *)(param_1 + 0x1A) = (*(u16 *)(param_1 + 0x1A) + delta) & 0xFFF;
        *(s16 *)(param_1 + 0x18) = func_80012ABC(*(s16 *)(param_1 + 0x18), *(s16 *)(param_1 + 0x20), 4);
    }
    *(s16 *)(param_1 + 0x1C) = func_80012ABC(*(s16 *)(param_1 + 0x1C), *(s16 *)(param_1 + 0x24), 4);
    *(s32 *)(param_1 + 0x8) = (s16)func_80012C6C(*(s16 *)(param_1 + 0x8), *(s16 *)(param_1 + 0xC), 4);
    *(s32 *)(param_1 + 0x10) = (s16)func_80012C6C(*(s16 *)(param_1 + 0x10), *(s16 *)(param_1 + 0x14), 4);
    *(s16 *)(param_1 + 0x28) = func_80012C6C(*(s16 *)(param_1 + 0x28), *(s16 *)(param_1 + 0x2E), 0x10);
    *(s16 *)(param_1 + 0x2A) = func_80012C6C(*(s16 *)(param_1 + 0x2A), *(s16 *)(param_1 + 0x30), 0x10);
    *(s16 *)(param_1 + 0x2C) = func_80012C6C(*(s16 *)(param_1 + 0x2C), *(s16 *)(param_1 + 0x32), 0x10);
    {
        s16 *p940 = &D_80126940;
        *(s32 *)(param_1 + 0x48) = (s32)*(s16 *)(param_1 + 0x28) + *p940;
        *(s32 *)(param_1 + 0x4C) = (s32)*(s16 *)(param_1 + 0x2A) + D_80126942;
        *(s32 *)(param_1 + 0x50) = (s32)*(s16 *)(param_1 + 0x2C) + D_80126944;
        func_80049CAC(param_1 + 0x18, (s32)&m1);
        m1.t[0] = *(s16 *)(param_1 + 0x28) + *p940;
        m1.t[1] = *(s16 *)(param_1 + 0x2A) + D_80126942;
        m1.t[2] = *(s16 *)(param_1 + 0x2C) + D_80126944;
    }
    svec_in.vx = 0;
    svec_in.vy = 0;
    svec_in.vz = *(s32 *)(param_1 + 0x10);
    ((void (*)(s32, s32, s32))func_8012F14C)((s32)&m1, (s32)&svec_in, (s32)&svec_out);
    *(s32 *)(param_1 + 0x3C) = (s32)svec_out.vx;
    *(s32 *)(param_1 + 0x40) = (s32)svec_out.vy;
    *(s32 *)(param_1 + 0x44) = (s32)svec_out.vz;
}
