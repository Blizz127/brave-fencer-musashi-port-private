/* sc03_0001: func_8012C354 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
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
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8001CFDC(s32 a, s32 b);
extern void func_8001CFDC(s32 a, s32 b);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern u8 D_80078EAE;
void func_8012CAE4(void *a0);

s32 func_8012C354(s32 a0, s32 a1) {
    s32 v;
    *(s32*)(a0 + 0x78) = a1;
    if (D_80078EAE == 0) {
        v = (*(s16*)(a1 + 0x0) * 24) / 16;
    } else {
        v = *(u16*)(a1 + 0x0);
    }
    *(s16*)(a0 + 0x76) = v;
    *(s16*)(a0 + 0x5C) = *(u16*)(a1 + 0x2);
    if (*(s32*)(a1 + 0x4) != 0) {
        *(s32*)(a0 + 0x20) = ((s32 (*)(s32, s32))func_8001CFDC)(0x26, 0x85);
        if (*(s32*)(a0 + 0x20) == 0) {
            func_8012CAE4((void *)a0);
            return 0;
        }
        func_8001C214(*(s32*)(a0 + 0x20), *(s32*)(a1 + 0x4));
    }
    if (*(s32*)(a1 + 0x8) != 0) {
        *(s32*)(a0 + 0x58) = *(s32*)(a1 + 0x8) | 0x60000000;
    }
    return 1;
}
