/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A38E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s16 vx;
    s16 vy;
    s16 vz;
    s16 pad;
} SVec801A38E4;
extern void func_8012EA90(s32 a0, s32 a1, s32 *a2);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern u8 D_801A6CE8[];
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

void func_801A38E4(void *a0, void *a1, s32 a2, s32 a3, s32 a4)
{
    s32 m[8];
    SVec801A38E4 sv0;
    SVec801A38E4 sv1;
    SVec801A38E4 o0;
    SVec801A38E4 o1;
    s32 flag;
    u16 *p;
    u16 *q;

    p = (u16 *)(D_801A6CE8 + (a3 << 4));

    func_8012EA90((s32)a0, a2, m);
    gte_SetRotMatrix(m);
    gte_SetTransMatrix(m);

    if (a4 == 0) {
        sv0.vx = p[0];
        sv0.vz = 0;
        sv0.vy = 0;
        sv1.vx = p[4];
        sv1.vz = 0;
        sv1.vy = 0;
        func_8004945C((s32)&sv0, (s32)&o0, &flag);
        func_8004945C((s32)&sv1, (s32)&o1, &flag);
        if (o0.vx > o1.vx) {
            ((s16 *)a1)[3] = o0.vx;
            ((s16 *)a1)[2] = o1.vx;
        } else {
            ((s16 *)a1)[3] = o1.vx;
            ((s16 *)a1)[2] = o0.vx;
        }

        sv0.vy = p[1];
        sv0.vz = 0;
        sv0.vx = 0;
        sv1.vy = p[5];
        sv1.vz = 0;
        sv1.vx = 0;
        func_8004945C((s32)&sv0, (s32)&o0, &flag);
        func_8004945C((s32)&sv1, (s32)&o1, &flag);
        if (o0.vy > o1.vy) {
            ((s16 *)a1)[5] = o0.vy;
            ((s16 *)a1)[4] = o1.vy;
        } else {
            ((s16 *)a1)[5] = o1.vy;
            ((s16 *)a1)[4] = o0.vy;
        }

        sv0.vz = p[2];
        sv0.vy = 0;
        sv0.vx = 0;
        sv1.vz = p[6];
        sv1.vy = 0;
        sv1.vx = 0;
        func_8004945C((s32)&sv0, (s32)&o0, &flag);
        func_8004945C((s32)&sv1, (s32)&o1, &flag);
        if (o0.vz > o1.vz) {
            ((s16 *)a1)[7] = o0.vz;
            ((s16 *)a1)[6] = o1.vz;
        } else {
            ((s16 *)a1)[7] = o1.vz;
            ((s16 *)a1)[6] = o0.vz;
        }
    } else {
        q = p;
        p += 4;
        func_8004945C((s32)q, (s32)&o0, &flag);
        func_8004945C((s32)p, (s32)&o1, &flag);
        if (o0.vx > o1.vx) {
            ((s16 *)a1)[3] = o0.vx;
            ((s16 *)a1)[2] = o1.vx;
        } else {
            ((s16 *)a1)[3] = o1.vx;
            ((s16 *)a1)[2] = o0.vx;
        }
        if (o0.vy > o1.vy) {
            ((s16 *)a1)[5] = o0.vy;
            ((s16 *)a1)[4] = o1.vy;
        } else {
            ((s16 *)a1)[5] = o1.vy;
            ((s16 *)a1)[4] = o0.vy;
        }
        if (o0.vz > o1.vz) {
            ((s16 *)a1)[7] = o0.vz;
            ((s16 *)a1)[6] = o1.vz;
        } else {
            ((s16 *)a1)[7] = o1.vz;
            ((s16 *)a1)[6] = o0.vz;
        }
    }
}
