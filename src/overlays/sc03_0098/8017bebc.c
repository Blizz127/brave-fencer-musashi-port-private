/* sc03_0098: func_8017BEBC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct vec;
struct obj;
struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
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
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MTX_L_8017BEBC;
typedef struct { s16 a, b, c, d; } SV4_L_8017BEBC;
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_80049A1C(void *a0, void *a1);
extern void func_8012A568(void (*a0)(void));
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_80049A1C(void *a0, void *a1);

void func_8017BEBC(s32 param_1, s32 param_2)
{
    extern s32 D_801C54C8;
    extern s32 D_801C54CC;
    extern s32 D_801C54D0;
    extern s32 D_801C54D8;
    extern s32 D_801C54DC;
    extern s32 D_801C54E0;
    extern s32 D_801C54E8;
    extern s32 D_801C54EC;
    extern s32 D_801C54F0;
    SV4_L_8017BEBC vec;
    MTX_L_8017BEBC mtx;
    s32 obj = *(s32 *)(param_1 + 0xCC);
    s32 prim = *(s32 *)(param_1 + 0x20);
    s32 mode;
    s32 val;
    s32 hi;
    s32 code;
    s32 t;
    if ((s16)param_2 != 0) {
        mode = 0x40000000;
        val = 0x1000;
    } else {
        mode = 0x50000000;
        val = 0x1333;
    }
    code = *(s32 *)(prim + 4) & 0xCFFFFFFF;
    hi = 0x40000000;
    *(s32 *)(prim + 4) = code | (mode | hi);
    if (*(u16 *)(*(s32 *)(param_1 + 0xCC)) != 0) {
        *(s16 *)(obj + 0x1A) = val;
        *(s16 *)(obj + 0x18) = val;
    }
    t = *(u16 *)(param_1 + 0xFC) + 0x80;
    *(u16 *)(param_1 + 0xFC) = t;
    vec.a = t;
    t = *(u16 *)(param_1 + 0xFE) + 0x100;
    *(u16 *)(param_1 + 0xFE) = t;
    vec.b = t;
    vec.c = 0;
    func_80049A1C(&vec, &mtx);
    vec.b = 0;
    vec.a = 0;
    vec.c = 0x100;
    func_80048FBC(&mtx, &vec, &vec);
    D_801C54E8 = vec.a;
    D_801C54D8 = vec.a;
    D_801C54C8 = vec.a;
    D_801C54EC = vec.b;
    D_801C54DC = vec.b;
    D_801C54CC = vec.b;
    D_801C54F0 = vec.c;
    D_801C54E0 = vec.c;
    D_801C54D0 = vec.c;
}
