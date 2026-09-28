/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4268 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801F4318;
extern s32 D_801F4358;
extern u16 D_801F43C0;
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
extern s32  func_8004787C(s32 a0);
extern s32  func_8012E544(s32 a0);
extern void func_8012EC04(s32 a0, s32 a1, s32 *a2);

void func_801A4268(s32 self)
{

    extern u8  D_801A6E38[];
    extern u16 D_800B99DA;
    s32 m[8];    /* sp+0x10 */
    s32 flag;    /* sp+0x30 */
    s32 handle;
    s32 r;
    s32 c;
    s32 v;
    s32 x;
    s32 sx;
    s32 sy;
    s32 t0;
    s32 t1;
    s32 p;

    if (D_801F4358 != 0) {
        if (D_801F43C0 == 3) {
            func_8012EC04(self, 3, m);
        } else {
            handle = func_8012E544(0x3D0);
            if (handle == 0) {
                return;
            }
            func_8012EC04(handle, 0, m);
        }
        gte_SetRotMatrix(m);
        gte_SetTransMatrix(m);
        func_8004945C((s32)D_801A6E38, (s32)(D_801F4358 + 8), &flag);
        r = func_8004787C(((s32)D_800B99DA << 6) & 0x7C0);
        c = *(s32 *)(self + 0xE0) & 0x100;
        flag = r;
        if (c == 0) {
            v = *(s32 *)(self + 0xE8);
        } else {
            v = *(s32 *)(self + 0xEC);
        }
        x = ((v << 1) + v) << 5;
        sx = (-x >> 16) + 0x60;
        t0 = (s16)sx * flag;
        sy = x >> 16;
        t1 = sy * flag;
        p = D_801F4358;
        *(u16 *)(p + 0x1A) = ((flag << 10) >> 12) + 0x800;
        *(u16 *)(p + 0x18) = ((flag << 10) >> 12) + 0x800;
        *((s8 *)&D_801F4318 + 1) = 0;
        *((s8 *)&D_801F4318 + 2) = (t0 >> 12) + sx;
        *((s8 *)&D_801F4318 + 0) = (t1 >> 12) + sy;
    }
}
