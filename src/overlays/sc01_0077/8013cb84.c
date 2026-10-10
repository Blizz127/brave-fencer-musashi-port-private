/* sc01_0077: func_8013CB84 from Druthulu/BFM-decomp
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
extern s32 D_801D9584;
extern s32 D_801D9590;
extern s32 D_801D9580;
extern s32 D_801D9584;
extern s32 D_801D9588;
extern s32 D_801D958C;
extern s32 D_801D9590;
extern s32 D_801D958C;
extern s32 D_801D9590;
extern s32 D_801D9590;
extern s32 D_801D958C;
extern s16 D_800B9A08;
extern u8 D_80078EAF;
extern s32 D_801D9590;
extern s32 D_801D9588;
extern s32 D_801D958C;
extern s32 D_801D9580;
extern s32 D_801D9584;
extern s32 D_801D9594;
extern s32 D_801D95A0;
extern s32 D_801D95A8;
extern s32 D_801DAAA0;
extern s32 D_801DAA20;
extern s32 D_801DAA14[];
extern u8 D_801DA9C1;
extern u8 D_801DAB2E;
extern u8 D_801DAA9C;
extern Rec12 D_80187484[];
extern Rec9 D_8018744C[];
extern u8 D_801DAA78;
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
    s32 loc = D_800B9A08;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;
    D_801DAAA0 = 0;
    if (D_801D9590 == 0 && s0 != D_801D9588) {
        ta = D_80187484[s0].a;
        tb = D_80187484[s0].b;
        tc = D_80187484[s0].c;
        D_801D9588 = s0;
        D_801DA9C1 = tc;
        D_801DAB2E = ta;
        D_801DAA9C = tb;
        *(Rec9 *)&D_801DAA78 = D_8018744C[s0];
        D_801D958C = 1;
        D_801D9580 = 1;
        if (D_801D95A0 & 2) {
            if (s0 == 4) { D_801DAA14[0] = 0x100; D_801DAA20 = 0x80; }
            if (s0 == 0) { D_801DAA14[0] = 0x100; D_801DAA20 = 0; }
        }
    }
    if (D_801D958C != 0) {
        t = D_801D9580 - 1;
        D_801D9580 = t;
        if (t == 0) {
            if (D_801D9590 == 0) {
                if ((D_801D95A0 & 2) && s0 == 4) {
                    if (D_801D95A8 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_801D95A8 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_801D9580 = 2;
                if (D_801D958C != 0) {
                    if (D_801D95A0 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_801DAA20;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_801DAA20;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_801D95A0 & 2) {
                    if (s0 == 4) D_801DAA20 = 0;
                    if (s0 == 0) D_801DAA20 = 0x80;
                }
            } else {
                if (D_801D95A8 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_801D9580 = 1;
            }
        }
    }
    D_801D9594 = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_801D958C != 0) D_801D9594 = D_801D9584;
            else D_801D9594 = 0x1F;
        } else if (s0 == 4) {
            if (D_801D958C != 0) D_801D9594 = 0x1F - D_801D9584;
            else D_801D9594 = 0;
        }
    }
}
