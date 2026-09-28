/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2014 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

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
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80029514(s32 a0);
extern s32  func_8004787C(s32 a0);
extern s32  func_80047948(s32 a0);
extern void func_8012CBA4(s32 a0);
extern void func_8012ADE4(u8 *a0);
extern s32  func_8012C51C(void *a0, s32 a1);
extern s32  func_8012C588(s32 a0, s32 a1);
extern void func_8012EC04(s32 a0, s32 a1, s32 *a2);
extern s32  func_80132EF4(s32 a0, s32 a1);
extern s32  func_80178970();
extern void func_80178D18();
extern s32  func_80181A00();
extern void func_801A227C();
extern void func_801A24E8(s32 a0);
extern u8  D_801A6BB8[];
extern u16 D_801A6BBE[];
typedef struct Prim801A2014 {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
    /* 0x06 */ s16 f06;
    /* 0x08 */ s16 f08;
    /* 0x0A */ s16 f0A;
    /* 0x0C */ s16 f0C;
    /* 0x0E */ s16 f0E;
    /* 0x10 */ s32 f10;
} Prim801A2014;

void func_801A2014(s32 p)
{
    Prim801A2014 prim;   /* sp+0x10 */
    u16 sv[4];           /* sp+0x28 */
    s32 m[8];            /* sp+0x30 */
    s32 flag;            /* sp+0x50 */
    s32 i;
    s32 off;

    switch (*(u16 *)(p + 0x34)) {
    case 0:
        if ((u32)*(s32 *)(p + 0x94) < 0x33) {
            if (((((s32 (*)(s32))func_8012CBA4)(p)) & 0x2000) == 0) {
                func_8012ADE4((u8 *)p);
            }
            func_801A24E8(p);
        }
        if ((u32)(*(s32 *)(p + 0x94) - 0x32) < 0x3D) {
            *(u16 *)(p + 0x50) += func_8004787C(*(s32 *)(p + 0x1C)) >> 9;
            *(u16 *)(p + 0x54) += func_80047948(*(s32 *)(p + 0x1C)) >> 9;
            *(s32 *)(p + 0x1C) += 0x400;
        }
        if (*(s32 *)(p + 0x94) == 0x6B) {
            func_8002D4C8(0xC8C, 0);
        }
        break;

    case 1:
        func_8012EC04(p, 4, m);
        gte_SetRotMatrix(m);
        gte_SetTransMatrix(m);
        for (i = 0; i < 16; i++) {
            off = i * 8;
            func_8004945C((s32)(D_801A6BB8 + off), (s32)sv, &flag);
            prim.x = sv[0];
            prim.y = sv[1];
            prim.z = sv[2];
            prim.f06 = 0x38A;
            prim.f08 = i;
            prim.f0A = 0;
            /* §190-B / sched1 LUID tie-break: the 0x0E / 0x10 / 0x0C stores must be
             * written in THIS order -- it is the only ordering of the nine field stores
             * that reproduces the target's sched1+sched2 interleave (see notes). */
            prim.f0E = *(u16 *)(*(s32 *)(p + 0x20) + 0x12) +
                       *(u16 *)((u8 *)D_801A6BBE + off);
            prim.f10 = 0;
            prim.f0C = 0x7FFF;
            func_8012C51C(&prim, p);
        }
        func_8002D4C8(0xB9E, 0);
        *(s16 *)(p + 0x34) = 3;
        break;

    case 2:
        *(s32 *)(p + 0xD8) = func_8012C588(0x380, p);
        func_80132EF4(p, 0x6E);
        *(s16 *)(p + 0x34) = 3;
        break;
    }

    if (func_80178970(p) == 1) {
        func_80178D18(p);
        func_801A227C(p);
        func_80029514(0x640);
        func_80181A00();
    }
}
