/* sc02_0037: func_80173CB4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
struct S8;
struct UnalignedPair;
struct S80126B38;
struct packed_word;
union word_bytes;
struct S8 { u32 a; u32 b; } __attribute__((packed, aligned(1)));
struct UnalignedPair {
    int a;
    int b;
} __attribute__((packed, aligned(1)));
struct S80126B38 { s32 a; s32 b; } __attribute__((packed));
struct packed_word { int w; } __attribute__((packed, aligned(1)));
union word_bytes {
    struct packed_word pw;
    u8 b[4];
};
typedef struct { s16 a; s16 b; s16 c; s16 d; } S8;
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
extern s32 D_801151D4;
extern void *memcpy(void *, const void *, unsigned int);
extern s32 D_801151D4;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 func_8013767C(s32 a0);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_8014706C(void *arg0);
extern void func_80147324(s32 arg0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern void func_80147324(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80147324();
extern void func_80147324(int arg0);
extern void func_8014706C(void *a0);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_8016BADC(void *a0, s32 a1, s32 a2);
extern s16 func_80171AB0(s32 a0, void *a1);
extern u8 D_800D5DA8;
extern void func_80171A1C(u8 *a0);
extern s16 func_80171AB0(s32 param_1, void* _arg1);
extern s32 D_801151D4;
extern s32 D_801151D4;
extern s32 D_801151D4;
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171A1C(u8 *a0);
extern void func_8014706C(void *arg0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_8014706C(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern void func_80147324(s32 a0);
extern void func_80171A1C(u8 *a0);
extern struct S80126B38 D_80126B38;
typedef struct { u32 a; u32 b; } __attribute__((packed, aligned(1))) Unaligned8;
extern struct S80126B38 D_80126B38;
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 D_8012750C;
extern void func_80171A1C(u8 *a0);
extern struct S80126B38 D_80126B38;
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_8014706C(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_8016BADC(void *a0, s32 a1, s32 a2);
extern void func_80147324(s32 a0);
extern s32 func_8013767C(s32 a0);
extern void func_80171A1C(u8 *a0);
extern s32 D_801151D4;
extern struct S80126B38 D_80126B38;
extern u8 D_800D5DA8;
extern u8 D_800D5DB8;
extern s32 D_8012750C;

void func_80173CB4(s32 a0) {
    s32 s0 = a0;
    s32 v1 = D_801151D4;
    s16 tmp[4];
    s32 a;
    s32 d;
    tmp[0] = *(s32 *)(v1 + 0x3C);
    tmp[1] = *(s32 *)(v1 + 0x40);
    tmp[2] = *(s32 *)(v1 + 0x44);
    if (func_80171AB0(a0, tmp) != 0) {
        return;
    }
    func_8014706C((void *)s0);
    switch ((u8)(*(u8 *)&D_80126B38)) {
    case 0:
        func_80154274((s32 *)s0, (s32)&D_800D5DA8);
        *(s32 *)(s0 + 0x200) = 0x20;
        a = 0x843;
        goto ld0;
    case 1:
        func_80154274((s32 *)s0, (s32)&D_800D5DA8);
        goto lb8;
    case 2:
        func_80154274((s32 *)s0, (s32)&D_800D5DA8);
        __asm__ __volatile__("");
        goto lb8;
    case 3:
        func_80154274((s32 *)s0, (s32)&D_800D5DB8);
        func_801553A8((s32 *)s0);
        goto lb8;
    default:
        goto ld8;
    }
lb8:
    func_8016BADC((void *)s0, -0x40, 0x40);
    *(s32 *)(s0 + 0x200) = 0x80;
    a = 0x6A6;
ld0:
    func_80147324(a);
ld8:
    d = D_8012750C;
    if (d != 0) {
        *(s32 *)(s0 + 0x198) = func_8013767C(d);
    } else {
        *(s32 *)(s0 + 0x198) = 0;
    }
    func_80171A1C((u8 *)s0);
}
