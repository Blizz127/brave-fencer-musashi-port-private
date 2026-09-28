/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A293C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif
/* GTE instruction macros (vendor/bfm-decomp/include/gte_macros.inc) for GNU as. */
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro rtps\n"
    "    cop2op 0x01, 0x01\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

extern s32 func_8005C49C(void);
extern s32 func_8012E544(s32 a0);
extern void func_8012EC04(s32 a0, s32 a1, s32 *a2);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C51C(void *a0, s32 a1);
extern s32 func_8005A600(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern u16 D_801F43C0;
extern s32 D_801F4360[];
extern u8 D_801A6C50[];
extern u8 D_801A6C98[];
extern u8 D_800AF630[];
extern u8 D_800A6610[];
extern s16 D_800B9A02;
extern s32 D_800A5E60;
#define gte_SetRotMatrix(r0) __asm__ volatile (         \
    "lw $12, 0( %0 );"                                   \
    "lw $13, 4( %0 );"                                   \
    "ctc2 $12, $0;"                                      \
    "ctc2 $13, $1;"                                      \
    "lw $12, 8( %0 );"                                   \
    "lw $13, 12( %0 );"                                  \
    "lw $14, 16( %0 );"                                  \
    "ctc2 $12, $2;"                                      \
    "ctc2 $13, $3;"                                      \
    "ctc2 $14, $4"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )
#define gte_SetTransMatrix(r0) __asm__ volatile (        \
    "lw $12, 20( %0 );"                                  \
    "lw $13, 24( %0 );"                                  \
    "ctc2 $12, $5;"                                      \
    "lw $14, 28( %0 );"                                  \
    "ctc2 $13, $6;"                                      \
    "ctc2 $14, $7"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )
#define gte_ldv0(r0) __asm__ volatile (          \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 )"                           \
    :                                            \
    : "r"( r0 ) )
#define gte_rtps() __asm__ volatile ("nop;nop;rtps")
#define gte_stsxy(r0) __asm__ volatile (         \
    "swc2 $14, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stszotz(r0) __asm__ volatile (       \
    "mfc2 $12, $19;"                             \
    "nop;"                                       \
    "sra $12, $12, 2;"                           \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )
#define gte_stflg(r0) __asm__ volatile (         \
    "cfc2 $12, $31;"                             \
    "nop;"                                       \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )
typedef struct {
    u32 addr : 24;
    u32 len : 8;
} PTag293C;
typedef struct {
    s16 f00;
    s16 f02;
    s16 f04;
    s16 f06;
    s16 f08;
    s16 f0A;
    s16 f0C;
    s16 f0E;
    s32 f10;
} Prim293C;

void func_801A293C(void *arg0)
{
    s32 sp18[8];      /* 0x18 */
    s32 sp38[8];      /* 0x38 */
    u16 sp58[4];      /* 0x58 */
    Prim293C prim;    /* 0x60 */
    s32 flag;         /* 0x78 */
    s32 otz1;         /* 0x7C */
    s32 otz2;         /* 0x80 */
    s32 dX[1];        /* 0x84 dead 4-byte slot (frame oracle: target 0xB8) */
    s32 base;         /* 0x88 spill */
    s32 f5;
    s32 w, m, s1, s3, s6, s7, s0, fp, i, p;
    register s32 s5v __asm__("$21");

    PTag293C *e;

    w = (s32)arg0;
    if (D_801F43C0 == 3) {
        func_8012EC04(w, 3, sp18);
        func_8012EC04(w, 0, sp38);
        s1 = w;
        s6 = D_801F43C0;
        f5 = 0;
    } else {
        s1 = func_8012E544(0x3D0);
        if (s1 == 0) {
            return;
        }
        func_8012EC04(s1, 0, sp18);
        func_8012EC04(s1, 1, sp38);
        s6 = 0;
        f5 = 1;
    }

    if (*(s32 *)(w + 0xE0) & 4) {
        i = 0;
        s3 = 0x38E38E39;
        for (; i < 3; i++) {
            if (D_801F4360[i] % *(s32 *)(w + 0xE4) == 0) {
                if ((func_8005C49C() & 1) == 0) {
                    s0 = (s32)(D_801A6C50 + (func_8005C49C() % 9) * 8);
                    func_8012F14C((s32)sp18, s0, (s32)sp58);
                    prim.f0E = s6;
                } else {
                    s0 = (s32)(D_801A6C98 + (func_8005C49C() % 9) * 8);
                    func_8012F14C((s32)sp38, s0, (s32)sp58);
                    prim.f0E = f5;
                }
                prim.f00 = sp58[0];
                prim.f02 = sp58[1];
                prim.f04 = sp58[2];
                prim.f06 = 0x399;
                prim.f0A = 0;
                prim.f08 = 0;
                prim.f10 = s0;
                prim.f0C = 0x7FFF;
                func_8012C51C(&prim, s1);
            }
        }
    }

    i = 0;
    s5v = (s32)sp58;
    __asm__("addiu %0,%1,0x18" : "=r"(m) : "r"(D_800AF630));
    s7 = (s32)&flag;
    fp = -0x1001;
    base = (s32)D_800A6610 + (*(u16 *)&D_800B9A02 << 14);

    for (i = 0; i < 9; i++) {
        p = D_800A5E60;
        D_800A5E60 = p + 0x14;
        *(s8 *)(p + 3) = 4;
        *(s32 *)(p + 4) = 0x808080;
        *(s32 *)(p + 0xC) = 0x404040;
        *(s8 *)(p + 7) = 0x52;
        func_8012F14C((s32)sp18, (s32)(D_801A6C50 + i * 8), s5v);
        gte_SetRotMatrix((void *)m);
        gte_SetTransMatrix((void *)m);
        gte_ldv0((void *)s5v);
        gte_rtps();
        gte_stsxy((void *)(p + 8));
        gte_stflg((void *)s7);
        gte_stszotz(&otz1);
        if ((flag & fp) == 0) {
            func_8012F14C((s32)sp38, (s32)(D_801A6C98 + i * 8), s5v);
            gte_SetRotMatrix((void *)m);
            gte_SetTransMatrix((void *)m);
            gte_ldv0((void *)s5v);
            gte_rtps();
            gte_stsxy((void *)(p + 0x10));
            gte_stflg((void *)s7);
            gte_stszotz(&otz2);
            if ((flag & fp) == 0) {
                otz1 = (otz1 + otz2) >> 1;
                otz1 = otz1 + 1;
                if (otz1 >= 0x1000) {
                    otz1 = 0x1000;
                }
                s0 = D_800A5E60;
                D_800A5E60 = s0 + 0xC;
                func_8005A600(s0, 0, 0, 0x12A, 0);
                e = (PTag293C *)(otz1 * 4 + base);
                /* addPrim(e, p) */
                ((PTag293C *)p)->addr = e->addr;
                e->addr = (u32)p;
                /* addPrim(e, s0) */
                ((PTag293C *)s0)->addr = e->addr;
                s0 = (s32)s0 & 0xFFFFFF;
                *(s32 *)e = (*(s32 *)e & 0xFF000000) | s0;
            }
        }
    }
}
