/* sc03_0001: func_8013D53C from Druthulu/BFM-decomp
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
typedef struct { u8 b[9]; } S9;
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
typedef struct {
    u16 cmd;
    u16 pad2;
    u16 pad4;
    u16 pad6;
    s16 w;
    s16 h;
    u16 *data;
} Cmd_8013D53C;
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
extern s32 D_801ED450;
extern s32 D_801ED440;
extern s32 D_801ED448;
extern s32 D_801ED44C;
extern s32 D_801ED450;
extern s32 D_801ED44C;
extern s32 D_801ED450;
extern s32 D_801ED450;
extern s32 D_801ED44C;
extern s32 D_801ED450;
extern s32 D_801ED448;
extern s32 D_801ED44C;
extern s32 D_801ED440;
extern s32 D_801ED458;
extern s32 D_801ED440;
extern s32 D_801ED45C;
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern s32 D_801ED458;
extern u8 D_801EF3F2;
extern u8 D_801EF466;
extern u8 D_801EF2F2;
extern u8 D_801EF3BC;
extern u8 D_801EF2C8;
extern u8 D_801EF2F1;
extern s32 D_801EF3C0;
extern void *D_801ED430;
extern void *D_801ED438;
extern s32 D_801ED460;
extern s32 D_801ED468;
extern s32 D_801ED460;
extern s32 D_801ED448;
extern u8 D_801EF3F2;
extern u8 D_801EF466;
extern u8 D_801EF2F2;
extern u8 D_801EF3BC;
extern u8 D_801EF2C8;
extern u8 D_801EF2F1;
extern s32 D_801EF3C0;
extern s32 D_801ED45C;
extern s32 D_801ED458;
extern s32 D_801ED440;
extern s32 D_801ED44C;
extern s32 D_801ED450;
extern void *D_801ED430;
extern s32 D_801ED468;
extern void *D_801ED438;

void func_8013D53C(void *arg0v) {
    extern Rec9 D_8018DE3C[];
    extern Rec12 D_8018DE74[];
    extern u8 D_80078EAF;
    extern u8 D_801EF398;
    extern s32 D_801ED454;
    Cmd_8013D53C *arg0 = arg0v;
    extern u8 D_8018DE78[];
    extern u8 D_8018DE7C[];
    extern unsigned char D_801EF2E8;
    extern s16 *D_801ED43C;
    extern s32 D_801ED46C;
    extern s32 D_801ED470;
    extern s32 D_801ED474;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];
    if (!(D_801ED460 & 1)) {
        D_801ED448 = 1;
    } else {
        D_801ED448 = D_80078EAF;
    }
    b0 = ((u8 *)D_8018DE74)[D_801ED448 * 12];
    D_801EF3F2 = b0;
    D_801EF466 = b0;
    b1 = D_8018DE78[D_801ED448 * 12];
    D_801EF2F2 = b1;
    D_801EF3BC = b1;
    b2 = D_8018DE7C[D_801ED448 * 12];
    D_801EF2C8 = b2;
    D_801EF2F1 = b2;
    (*(S9 *)&D_801EF2E8) = ((S9 *)D_8018DE3C)[D_801ED448];
    (*(S9 *)&D_801EF398) = *(S9 *)(&D_801EF2C8 + 0x20);
    D_801EF3C0 = 1;
    D_801ED45C = -1;
    D_801ED458 = 0;
    D_801ED454 = -1;
    D_801ED440 = 0;
    D_801ED44C = 0;
    D_801ED450 = 0;
    if ((D_801ED460 & 2) && (D_801ED448 == 4)) {
        s0v = (*(s32 * *)&D_801ED430)[18];
        t9v = (*(s32 * *)&D_801ED430)[19];
        t8v = (*(s32 * *)&D_801ED430)[20];
    } else {
        s32 *p = (s32 *)(D_801ED448 * 12 + (s32) (*(s32 * *)&D_801ED430));
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }
    (*(Cmd_8013D53C * *)&D_801ED43C) = arg0;
    if (arg0 != 0) {
        if (D_801ED468 != 0) {
            s32 *p = (s32 *)(D_801ED448 * 12 + (s32) (*(s32 * *)&D_801ED438));
            D_801ED46C = p[0];
            D_801ED470 = p[1];
            D_801ED474 = p[2];
        } else {
            while ((arg0->cmd & 0xFFFF) != 0xFF) {
                if ((arg0->cmd & 0xFFFF) == 9) {
                    s32 n;
                    s32 i;
                    u16 *src;
                    u16 *dst;
                    n = arg0->w * arg0->h;
                    i = 0;
                    src = arg0->data;
                    __asm__("" :: "r"(src));
                    dst = src + n;
                    if (n > 0) {
                        do {
                            u16 px;
                            s32 r, g, b, out;
                            __asm__("" :: "r"(i));
                            px = *src;
                            r = ((px & 0x1F) * s0v) / 2560;
                            g = (((px & 0x3E0) * t9v) / 2560) & 0x3E0;
                            b = (((px & 0x7C00) * t8v) / 2560) & 0x7C00;
                            out = r | g | b | (px & 0x8000);
                            if (out == 0 && px != 0) {
                                out = 0x8000;
                            }
                            *dst = out;
                            dst++;
                            i++;
                            src++;
                        } while (i < n);
                    }
                }
                arg0++;
            }
        }
    }
}
