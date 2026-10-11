/* sc03_0001: func_8012EC04 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef struct { u32 a, b, c, d; } Blk16;
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
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_80049CAC();
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_80049CAC(s32 a0, s32 a1);
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro mvmva sf, mx, v, cv, lm\n"
    "    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

void func_8012EC04(s32 param_1, s32 param_2, s32 *param_3)
{
    struct { s16 h[8]; } buf;
    s32 iVar4;
    s32 M;
    s32 c;
    u32 v;
    iVar4 = *(s32 *)(param_1 + 0x20);
    v = *(u32 *)(iVar4 + 0x20);
    if (v == 0) {
        *(Blk16 *)(param_3) = *(Blk16 *)(iVar4 + 0x34);
        *(Blk16 *)((s32)param_3 + 0x10) = *(Blk16 *)(iVar4 + 0x44);
    } else if ((v & 0x1000000) != 0) {
        s32 p;
        s32 w;
        p = (s32)(v & 0xfeffffff);
        p = p + param_2 * 8;
        buf.h[0] = *(s16 *)(p + 6);
        w = *(s32 *)p;
        buf.h[1] = (s16)(*(u8 *)(p + 1) | ((w & 0xf) << 8));
        buf.h[2] = (s16)(((w >> 0x10) & 0xff) | ((w & 0xf0) << 4));
        func_80049CAC((s32)&buf, (s32)param_3);
        param_3[5] = *(s8 *)(p + 3);
        param_3[6] = *(s8 *)(p + 4);
        param_3[7] = *(s8 *)(p + 5);
    } else {
        s32 q;
        v = v + param_2 * 0xc;
        q = (s32)v;
        buf.h[0] = *(s16 *)(q + 6);
        buf.h[1] = *(s16 *)(q + 8);
        buf.h[2] = *(s16 *)(q + 0xa);
        func_80049CAC((s32)&buf, (s32)param_3);
        param_3[5] = *(s16 *)(q + 0);
        param_3[6] = *(s16 *)(q + 2);
        param_3[7] = *(s16 *)(q + 4);
    }
    M = *(s32 *)(param_1 + 0x20) + 0x34;
    __asm__ __volatile__(
        "lw $12, 0(%0)\n" "lw $13, 4(%0)\n"
        "ctc2 $12, $0\n" "ctc2 $13, $1\n"
        "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n"
        "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n"
        : : "r"(M) : "$12", "$13", "$14", "memory");
    __asm__ __volatile__(
        "lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
        "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
        "nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n"
        : : "r"((s32)param_3) : "$12", "$13", "$14", "memory");
    __asm__ volatile ( "mfc2 $12, $9;" "mfc2 $13, $10;" "mfc2 $14, $11;" "sh $12, 0( %0 );" "sh $13, 6( %0 );" "sh $14, 12( %0 )" : : "r"( (s32)param_3 ) : "$12", "$13", "$14", "memory" );
    c = (s32)param_3 + 2;
    __asm__ __volatile__(
        "lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
        "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
        "nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n"
        : : "r"(c) : "$12", "$13", "$14", "memory");
    __asm__ volatile ( "mfc2 $12, $9;" "mfc2 $13, $10;" "mfc2 $14, $11;" "sh $12, 0( %0 );" "sh $13, 6( %0 );" "sh $14, 12( %0 )" : : "r"( c ) : "$12", "$13", "$14", "memory" );
    c = (s32)param_3 + 4;
    __asm__ __volatile__(
        "lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
        "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
        "nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n"
        : : "r"(c) : "$12", "$13", "$14", "memory");
    __asm__ volatile ( "mfc2 $12, $9;" "mfc2 $13, $10;" "mfc2 $14, $11;" "sh $12, 0( %0 );" "sh $13, 6( %0 );" "sh $14, 12( %0 )" : : "r"( c ) : "$12", "$13", "$14", "memory" );
    M = *(s32 *)(param_1 + 0x20) + 0x34;
    __asm__ __volatile__(
        "lw $12, 20(%0)\n" "lw $13, 24(%0)\n"
        "ctc2 $12, $5\n" "lw $14, 28(%0)\n"
        "ctc2 $13, $6\n" "ctc2 $14, $7\n"
        : : "r"(M) : "$12", "$13", "$14", "memory");
    c = (s32)param_3 + 0x14;
    __asm__ __volatile__(
        "lhu $13, 4(%0)\n" "lhu $12, 0(%0)\n"
        "sll $13, $13, 16\n" "or $12, $12, $13\n"
        "mtc2 $12, $0\n" "lwc2 $1, 8(%0)\n"
        "nop\n" "nop\n" "mvmva 1, 0, 0, 0, 0\n"
        : : "r"(c) : "$12", "$13", "memory");
    __asm__ volatile ( "swc2 $25, 0( %0 );" "swc2 $26, 4( %0 );" "swc2 $27, 8( %0 )" : : "r"( c ) : "memory" );
}
