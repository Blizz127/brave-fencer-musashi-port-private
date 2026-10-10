/* sc01_0077: func_8017EB2C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
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
extern s32 D_80126B58;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern int func_8005C49C(void);
extern s32 D_80126B58;
extern u8 *func_8012913C(s32 a0);
extern int func_8005C49C(void);

void func_8017EB2C(int param_1, int param_2)
{
    s32 base = (s32)&D_80126B58;
    u8 *p;
    s32 s1, v;
    if ((param_1 & 1) != 0) {
        p = func_8012913C(2);
    } else {
        p = func_8012913C(1);
    }
    if (p != 0) {
        int t;
        s32 d;
        register s32 r __asm__("$2");
        t = func_8005C49C();
        s1 = t - (t / 256) * 256;
        r = func_8005C49C() % 640;
        d = (s32)*(u16 *)(base + 0xe) - 0x140;
        d += r;
        *(s16 *)(p + 0xe) = d;
        if ((param_2 & 1) != 0) {
            *(s16 *)(p + 6) = s1 + 0x7a;
            v = (s32)*(u16 *)(base + 0xa) - 0xe0;
        } else {
            *(s16 *)(p + 6) = s1 - 0xf8;
            v = (s32)*(u16 *)(base + 0xa) - 0xc0;
        }
        *(s16 *)(p + 0xa) = v;
        *(s16 *)(p + 0x36) = (s32)*(u16 *)(base + 0xa) - 0x50;
    }
}
