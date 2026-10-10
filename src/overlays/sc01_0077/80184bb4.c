/* sc01_0077: func_80184BB4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
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
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern int func_8012BEE8(int a0);
void func_801846F8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012B8E4(s32 arg0, s32 arg1);
extern s32 func_8012BEE8(s32 a0);
extern void func_801846F8(s32 a0);

void func_80184BB4(int param_1)
{
    int v;
    unsigned short *p;
    v = func_8012B8E4(param_1, 4);
    p = (unsigned short *)(*(int *)(param_1 + 0x20) + 0x12);
    *p = (unsigned short)(*p + v);
    if (func_8012BEE8(param_1) != 0) {
        func_801846F8(param_1);
    }
}
