/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80135168 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 *D_80183DF0;
extern int D_801EC6D8;
extern u16 D_801EC6E8;
extern int func_80134A74(int, s16, s16, int);

int func_80135168(u16 arg0, u16 *p1, u16 *p2)
{
    /* [T51] scoped in from file scope: a file-scope decl of these symbols constrains every
       LATER function in this TU, which blocks a byte-true decl of a different type.
       Declaration-only move (cookbook §100); the whole-binary byte-gate is the arbiter. */
    extern u8 D_80183DE8;
    extern u8 D_80183DEC;
    extern u8 D_80183DF4;
    register s16 *pb0 __asm__("$8");
    register s16 *pac __asm__("$6");
    register s16 *pb8 __asm__("$7");
    u16 *pb4;
    u16 a, b;
    int a1v, a2v, d94;

    pb0 = (*(s16 * *)&D_80183DEC);
    __asm__ __volatile__("" : : "r"(pb0));

    a = p2[0]; pac = (*(s16 * *)&D_80183DE8); pb0[0] = a; b = p1[0]; pb8 = (*(s16 * *)&D_80183DF4); pac[0] = b; pb8[0] = a - b;
    a = p2[1]; pb0[1] = a; b = p1[1]; pac[1] = b; pb8[1] = a - b;
    a = p2[2]; pb0[2] = a; b = p1[2]; pac[2] = b; pb8[2] = a - b;

    a1v = pac[0]; a2v = pac[2]; d94 = D_801EC6D8;
    __asm__ __volatile__("" ::: "memory");
    D_801EC6E8 = 0;
    if (func_80134A74(arg0, a1v, a2v, d94)) {
        pb4 = (*(u16 * *)&D_80183DF0);
        p2[0] = pb4[0];
        p2[1] = pb4[1];
        p2[2] = pb4[2];
        p2[3] = D_801EC6E8;
        return 1;
    }
    return 0;
}
