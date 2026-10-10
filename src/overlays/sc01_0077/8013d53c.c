/* sc01_0077: func_8013D53C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
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
extern s32 D_801D958C;
extern s32 D_801D9580;
extern s32 D_801D9590;
extern s32 D_801D9580;
extern s32 D_801D9588;
extern s32 D_801D958C;
extern s32 D_801D9590;
extern s32 D_801D958C;
extern s32 D_801D9590;
extern s32 D_801D9590;
extern s32 D_801D958C;
extern u8 D_80078EAF;
extern s32 D_801D9590;
extern s32 D_801D9588;
extern s32 D_801D958C;
extern s32 D_801D9580;
extern s32 D_801D9594;
extern s32 D_801D95A0;
extern s32 D_801D95A8;
extern s32 D_801DAAA0;
extern u8 D_801DA9C1;
extern u8 D_801DAB2E;
extern u8 D_801DAA9C;
extern Rec12 D_80187484[];
extern Rec9 D_8018744C[];
extern u8 D_801DAA78;
extern s32 D_801D9598;
extern s32 D_801D9580;
extern s32 D_801D959C;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern s32 D_801D9598;
extern unsigned char D_801DA9B8, D_801DA9B9, D_801DA9BA, D_801DA9BB, D_801DA9BC,
                     D_801DA9BD, D_801DA9BE, D_801DA9BF, D_801DA9C0;
extern unsigned char D_801DAA78, D_801DAA79, D_801DAA7A, D_801DAA7B, D_801DAA7C,
                     D_801DAA7D, D_801DAA7E, D_801DAA7F, D_801DAA80;
extern u8 D_801DAABA;
extern u8 D_801DAB2E;
extern u8 D_801DA9C2;
extern u8 D_801DAA9C;
extern u8 D_801DA998;
extern u8 D_801DA9C1;
extern s32 D_801DAAA0;
extern void *D_801D9570;
extern void *D_801D9578;
extern s32 D_801D95A0;
extern s32 D_801D95A8;
extern s32 D_801D95A0;
extern u8 D_80078EAF;
extern s32 D_801D9588;
extern u8 D_801DAABA;
extern u8 D_801DAB2E;
extern u8 D_801DA9C2;
extern u8 D_801DAA9C;
extern u8 D_801DA998;
extern u8 D_801DA9C1;
extern u8 D_801DAA78;
extern s32 D_801DAAA0;
extern s32 D_801D959C;
extern s32 D_801D9598;
extern s32 D_801D9594;
extern s32 D_801D9580;
extern s32 D_801D958C;
extern s32 D_801D9590;
extern void *D_801D9570;
extern s32 D_801D95A8;
extern void *D_801D9578;

void func_8013D53C(void *arg0v) {
    Cmd_8013D53C *arg0 = arg0v;
    extern u8 D_80187488[];
    extern u8 D_8018748C[];
    extern unsigned char D_801DA9B8;
    extern s16 *D_801D957C;
    extern s32 D_801D95AC;
    extern s32 D_801D95B0;
    extern s32 D_801D95B4;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];
    if (!(D_801D95A0 & 1)) {
        D_801D9588 = 1;
    } else {
        D_801D9588 = D_80078EAF;
    }
    b0 = ((u8 *)D_80187484)[D_801D9588 * 12];
    D_801DAABA = b0;
    D_801DAB2E = b0;
    b1 = D_80187488[D_801D9588 * 12];
    D_801DA9C2 = b1;
    D_801DAA9C = b1;
    b2 = D_8018748C[D_801D9588 * 12];
    D_801DA998 = b2;
    D_801DA9C1 = b2;
    (*(S9 *)&D_801DA9B8) = ((S9 *)D_8018744C)[D_801D9588];
    (*(S9 *)&D_801DAA78) = *(S9 *)(&D_801DA998 + 0x20);
    D_801DAAA0 = 1;
    D_801D959C = -1;
    D_801D9598 = 0;
    D_801D9594 = -1;
    D_801D9580 = 0;
    D_801D958C = 0;
    D_801D9590 = 0;
    if ((D_801D95A0 & 2) && (D_801D9588 == 4)) {
        s0v = (*(s32 * *)&D_801D9570)[18];
        t9v = (*(s32 * *)&D_801D9570)[19];
        t8v = (*(s32 * *)&D_801D9570)[20];
    } else {
        s32 *p = (s32 *)(D_801D9588 * 12 + (s32) (*(s32 * *)&D_801D9570));
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }
    (*(Cmd_8013D53C * *)&D_801D957C) = arg0;
    if (arg0 != 0) {
        if (D_801D95A8 != 0) {
            s32 *p = (s32 *)(D_801D9588 * 12 + (s32) (*(s32 * *)&D_801D9578));
            D_801D95AC = p[0];
            D_801D95B0 = p[1];
            D_801D95B4 = p[2];
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
