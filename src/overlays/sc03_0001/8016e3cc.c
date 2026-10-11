/* sc03_0001: func_8016E3CC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern void func_80049A1C(void *a0, void *a1);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80049A1C(void *a, void *b);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D20C0();
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80049A1C(void *a0, void *a1);

void func_8016E3CC(s32 a0) {
    s16 src[4];
    u8 mtx[8];
    s32 p;
    p = *(s32 *)(a0 + 0x34);
    src[0] = *(u16 *)(p + 0x6);
    src[1] = *(u16 *)(p + 0xA) - 0x28;
    src[2] = *(u16 *)(p + 0xE);
    func_800D20C0((void *)src, (void *)mtx, 6);
    *(s16 *)(a0 + 0x6) = src[0];
    *(s16 *)(a0 + 0xA) = src[1];
    *(s16 *)(a0 + 0xE) = src[2];
    func_800D23D0((void *)mtx);
    func_80049A1C((void *)mtx, (void *)(a0 + 0x38));
}
