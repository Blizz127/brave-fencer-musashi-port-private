/* sc02_0037: func_80156848 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801555F4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
struct S8;
struct UnalignedPair;
struct packed_word;
union word_bytes;
struct S8 { u32 a; u32 b; } __attribute__((packed, aligned(1)));
struct UnalignedPair {
    int a;
    int b;
} __attribute__((packed, aligned(1)));
struct packed_word { int w; } __attribute__((packed, aligned(1)));
union word_bytes {
    struct packed_word pw;
    u8 b[4];
};
typedef struct { s16 a; s16 b; s16 c; s16 d; } S8;
typedef struct { u8 b[8]; } B8;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
struct PW8017E6D8 { int w; } __attribute__((packed, aligned(1)));
struct W4 { u32 w; } __attribute__((packed, aligned(1)));
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4;
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_80165140;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_80165140;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
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
struct PW8017C290 { int w; } __attribute__((packed, aligned(1)));
struct PW8017E72C { int w; } __attribute__((packed, aligned(1)));
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_8018EDB0;
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_8018F060;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_8018EDB0;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_8018F060;
typedef struct { u8 b[4]; } __attribute__((packed, aligned(1))) Blk4_E960;
typedef struct { u8 b[4]; } __attribute__((packed, aligned(1))) Block4;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 func_801469C8(int a0, void *a1, int a2, int a3, u16 arg5, int arg6, int arg7, int arg8);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_801151E0[];
extern S8 D_80126AF0[];
extern s32 D_801151E0[];
extern s32 D_801151E0[];
extern s32 D_801151E0[];
extern B8 D_80128120[];
extern B8 D_80128138[];
extern S8 D_80126AF0[];
extern u8 D_80126730[];
void func_80156A1C(s32 param_1, s32 param_2);

void func_80156848(s32 param_1, s32 param_2) {
    extern s32 D_801151E0[];
    extern u8 D_80126730[];
    extern S8 D_80126AF0[];
    extern B8 D_80128120[];
    extern B8 D_80128138[];
    extern void func_80013E94(void *a0, void *a1);
    extern s32 func_801469C8(int a0, void *a1, int a2, int a3, u16 arg5, int arg6, int arg7, int arg8);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern void func_80156A1C(s32 a0, s32 a1);
    u32 uVar1;
    s32 i;
    u32 uVar3;
    u32 local_20[2];
    uVar3 = 0;
    i = 0;
    do {
        uVar1 = D_801151E0[uVar3];
        if (uVar1 & 1) {
            func_80013E94(&D_80128120[i], local_20);
            ((s32 (*)(s32, s32, s32, s32, s32, s32, s32))func_80146A6C)(*(u8 *)(param_2 + 8), param_1, (s32)D_80126AF0[i].a,
                          (s32)D_80126AF0[i].b, (s32)D_80126AF0[i].c, local_20[0],
                          *(u8 *)(param_2 + 9));
        } else if (uVar1 & 6) {
            func_80156A1C(param_1, uVar3);
            func_80013E94(&D_80128138[i], local_20);
            if ((D_801151E0[uVar3] & 6) == 4) {
                local_20[0] = local_20[0] | 0x80000000;
            }
            ((s32 (*)(s32, s32, s32, s32, s32, s32, s32))func_80146A6C)(6, param_1, (s32)D_80126AF0[i].a,
                          (s32)D_80126AF0[i].b, (s32)D_80126AF0[i].c, local_20[0], 0);
            if (D_80126730[uVar3] == 0x24) {
                ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32))func_801469C8)(0x53, param_1, (s32)D_80126AF0[i].a,
                              (s32)D_80126AF0[i].b, (s32)D_80126AF0[i].c, local_20[0], 0, 0x14);
            }
        }
        uVar3 = uVar3 + 1;
        i = i + 1;
    } while (uVar3 < 3);
}
