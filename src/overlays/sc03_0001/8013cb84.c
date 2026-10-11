/* sc03_0001: func_8013CB84 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
typedef struct { s32 a, b, c; } Rec12;
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
extern s16 D_800B9A08;
extern short D_800B9A08;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 D_801ED44C;
extern s32 D_801ED440;
extern s32 D_801ED444;
extern s32 D_801ED450;
extern s32 D_801ED440;
extern s32 D_801ED444;
extern s32 D_801ED448;
extern s32 D_801ED44C;
extern s32 D_801ED450;
extern s32 D_801ED44C;
extern s32 D_801ED450;
extern s32 D_801ED450;
extern s32 D_801ED44C;
extern s16 D_800B9A08;
extern s32 D_801ED450;
extern s32 D_801ED448;
extern s32 D_801ED44C;
extern s32 D_801ED440;
extern s32 D_801ED444;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);
void func_8013CF68();
void func_8013D178(void);
void func_8013D330(void);
void func_8013D9B0(int param_1);
void func_8013DBE4(int param_1);

void func_8013CB84(void) {
    extern u8 D_80078EAF;
    extern s32 D_801ED454;
    extern s32 D_801ED460;
    extern s32 D_801ED468;
    extern s32 D_801EF3C0;
    extern s32 D_801EF340;
    extern s32 D_801EF334[];
    extern u8 D_801EF2F1;
    extern u8 D_801EF466;
    extern u8 D_801EF3BC;
    extern Rec12 D_8018DE74[];
    extern Rec9 D_8018DE3C[];
    extern u8 D_801EF398;
    s32 loc = D_800B9A08;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;
    D_801EF3C0 = 0;
    if (D_801ED450 == 0 && s0 != D_801ED448) {
        ta = D_8018DE74[s0].a;
        tb = D_8018DE74[s0].b;
        tc = D_8018DE74[s0].c;
        D_801ED448 = s0;
        D_801EF2F1 = tc;
        D_801EF466 = ta;
        D_801EF3BC = tb;
        *(Rec9 *)&D_801EF398 = D_8018DE3C[s0];
        D_801ED44C = 1;
        D_801ED440 = 1;
        if (D_801ED460 & 2) {
            if (s0 == 4) { D_801EF334[0] = 0x100; D_801EF340 = 0x80; }
            if (s0 == 0) { D_801EF334[0] = 0x100; D_801EF340 = 0; }
        }
    }
    if (D_801ED44C != 0) {
        t = D_801ED440 - 1;
        D_801ED440 = t;
        if (t == 0) {
            if (D_801ED450 == 0) {
                if ((D_801ED460 & 2) && s0 == 4) {
                    if (D_801ED468 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_801ED468 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_801ED440 = 2;
                if (D_801ED44C != 0) {
                    if (D_801ED460 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_801EF340;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_801EF340;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_801ED460 & 2) {
                    if (s0 == 4) D_801EF340 = 0;
                    if (s0 == 0) D_801EF340 = 0x80;
                }
            } else {
                if (D_801ED468 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_801ED440 = 1;
            }
        }
    }
    D_801ED454 = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_801ED44C != 0) D_801ED454 = D_801ED444;
            else D_801ED454 = 0x1F;
        } else if (s0 == 4) {
            if (D_801ED44C != 0) D_801ED454 = 0x1F - D_801ED444;
            else D_801ED454 = 0;
        }
    }
}
