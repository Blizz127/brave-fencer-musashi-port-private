/* Complete SC02 retail span [801777BC,801778A8); independently matched ordinary C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801777BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void *func_801777BC(void *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6)
{
    u32 cl;
    u32 flag;
    u32 nn;
    register u32 n __asm__("$10");
    u32 t;
    register u32 col __asm__("$4");
    u32 mask;
    s32 cnt;
    s32 dp;
    s16 i;
    flag = 0x1000000;
    cl = ((((s16)a5 + 0x100) << 6) | 0x16) << 16;
    dp = a6;
    i = 0;
    if ((s16)a4 > 0) {
        cnt = (s16)a4;
        do {
            nn = ((u32)(a1 << 16)) >> 28;
            n = nn;
            if (((nn != 0) || (i == cnt - 1)) || (i == ((s32)(dp << 16) >> 16))) {
                flag = 0;
            }
            mask = 0xffffff;
            col = 0x74808080;
            t = ((u32)((u32 *)a0 - 5)) & mask;
            mask = 0x3000000;
            t = t | mask;
            ((u32 *)a0)[0] = t;
            t = ((a3 << 16) | (a2 & 0xffff)) | flag;
            ((u32 *)a0)[2] = t;
            ((u32 *)a0)[1] = col;
            t = n << 3;
            t = t + 8;
            t = t | 0x4000;
            ((u32 *)a0)[3] = cl | t;
            a0 = (void *)((u32 *)a0 + 5);
            a2 += 8;
            a1 <<= 4;
            col = 0;
            i++;
        } while ((s16)i < cnt);
    }
    return a0;
}
