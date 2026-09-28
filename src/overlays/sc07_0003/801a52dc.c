/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A52DC - byte-exact against retail at -O2 (tools/register_match.py). */
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

typedef struct { s16 m[3][3]; s32 t[3]; } Mtx32_801A4DFC;
typedef struct { s16 m[3][3]; s32 t[3]; } Mtx32_801A52DC;
typedef struct { short vx, vy, vz, pad; } SVECTOR_801A52DC;
typedef struct {
    SVECTOR_801A52DC v[4];
    s32 f0;
    s32 f1;
    s32 f2;
    s32 f3;
    s32 f4;
} Prim_801A52DC;
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
extern void func_80016714(s8 *a0, s32 a1);
extern void func_8012C218(void *a0);
extern Mtx32_801A4DFC D_800AE620;
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern u8 D_800AF648;
extern void func_800176F0(void *a0);

void func_801A52DC(s32 param_1)
{
    Prim_801A52DC prim;
    Mtx32_801A52DC m;
    s32 otz[4];
    s32 flag;
    SVECTOR_801A52DC *p;
    s32 i;
    s32 a, b, t;
    s16 h;

    if (*(s16 *)(*(s32 *)(param_1 + 0x64) + 0x36) != *(s16 *)(param_1 + 0x10A)) {
        if (*(s32 *)(param_1 + 0xCC) != 0) {
            func_80016714((s8 *)(*(s32 *)(param_1 + 0xCC)), 0x38);
        }
        func_8012C218((void *)param_1);
        return;
    }

    t = *(s32 *)(param_1 + 0xE0) - 0x80;
    *(s32 *)(param_1 + 0xE0) = t;
    if (t < -0x400) {
        *(s32 *)(param_1 + 0xE0) = -0x400;
    }

    prim.v[0].vx = -0x10;
    prim.v[1].vx = 0x10;
    h = *(u16 *)(param_1 + 0xE0);
    prim.v[3].vy = 0;
    prim.v[2].vy = 0;
    prim.v[3].vx = 0;
    prim.v[2].vx = 0;
    prim.v[1].vy = 0;
    prim.v[0].vy = 0;
    prim.v[1].vz = 0;
    prim.v[0].vz = 0;
    prim.v[3].vz = h;
    prim.v[2].vz = h;

    m = (*(Mtx32_801A52DC *)&D_800AE620);
    func_8004A0DC(*(s16 *)(param_1 + 0xFE), &m);
    func_8012F14C((s32)&m, (s32)&prim.v[2], (s32)&prim.v[2]);

    m = (*(Mtx32_801A52DC *)&D_800AE620);
    func_8004A0DC(-*(s16 *)(param_1 + 0xFE), &m);
    func_8012F14C((s32)&m, (s32)&prim.v[3], (s32)&prim.v[3]);

    gte_SetRotMatrix((void *)(*(s32 *)(param_1 + 0x20) + 0x34));
    gte_SetTransMatrix((void *)(*(s32 *)(param_1 + 0x20) + 0x34));

    func_8004945C((s32)&prim.v[0], (s32)&prim.v[0], &flag);
    func_8004945C((s32)&prim.v[1], (s32)&prim.v[1], &flag);
    func_8004945C((s32)&prim.v[2], (s32)&prim.v[2], &flag);
    func_8004945C((s32)&prim.v[3], (s32)&prim.v[3], &flag);

    gte_SetRotMatrix(&D_800AF648);
    gte_SetTransMatrix(&D_800AF648);

    for (i = 0, p = &prim.v[0]; i < 4; i++, p++) {
        gte_ldv0(p);
        gte_rtps();
        gte_stsxy(p);
        gte_stflg(&flag);
        gte_stszotz(&otz[i]);
        if (flag & ~0x1000) {
            return;
        }
    }

    a = otz[2];
    if (otz[3] < a) {
        a = otz[3];
    }
    b = otz[0];
    if (otz[1] < b) {
        b = otz[1];
    }
    if (b > a) {
        b = a;
    }
    prim.f0 = 0x808080;
    prim.f1 = 0x808080;
    prim.v[0].vz = b;
    prim.f2 = 0;
    prim.f3 = 0;
    prim.f4 = 0x50000000;
    func_800176F0(&prim);
}
