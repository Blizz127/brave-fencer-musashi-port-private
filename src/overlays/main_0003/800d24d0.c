/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D24D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800EC9DC;
extern s32 D_800A5F1C;
extern void func_80046D1C(void);
extern s32 D_800EC9B0[];
extern s32 D_800EC9A4[];
extern s32 D_800EC9B8;
extern s16 D_800EC9BC[];
extern s16 D_800EC9BE[];
extern s16 D_800EC9C0[];
extern s32 D_800EC9CC;
extern s16 D_800EC9D0;
extern s16 D_800EC9D2;
extern s16 D_800EC9D4;
extern s16 D_800EC9D6;
extern s32 D_800EC9D8;
extern s32 D_800EC9F0;
extern u16 aD_800EC9BC[] __asm__("D_800EC9BC");
extern void func_800D2C88();
extern void func_800599B8(u16 *, u16 *);
typedef struct { u16 x, y, w, h; } D24D0_Rect;

void func_800D24D0(void) {
    D24D0_Rect sp10[2];
    s32 s0;
    s32 idx;
    s32 r;
    s16 *p;
    s32 n;

    if (D_800EC9DC != 0) {
        if (D_800A5F1C != 0) {
            func_80046D1C();
            D_800A5F1C = 0;
        }
    }
    sp10[0] = *(D24D0_Rect *)&D_800EC9D0;
    {
        s32 *pb = &D_800EC9B8;
        s0 = *pb;
        __asm__ __volatile__("" ::: "memory");
        *pb = (*pb == 0);
    }
    if (D_800EC9F0 != 0) {
        r = D_800EC9C0[D_800EC9CC * 4] % D_800EC9D4;
        if (r != 0) {
            D_800EC9F0 = 0;
            D_800EC9D0 = D_800EC9D0 + r;
            goto join;
        }
    }
    {
        s16 *px = &D_800EC9D0;
        *px = *px + D_800EC9D4;
    }
join:
    p = (s16 *)((u8 *)D_800EC9A4 + 0x2C);
    idx = D_800EC9CC;
    if (*p < D_800EC9BC[idx * 4] + D_800EC9C0[idx * 4]) {
        __asm__ __volatile__("");
        ((void (*)()) func_800D2C88)((&D_800EC9A4[3])[D_800EC9B8],
                                    ((D_800EC9D4 << 4) * ((D_800EC9D6 - 1) / 16 + 1)) >> 1);
    } else {
        D_800EC9D8 = 1;
        n = (idx == 0);
        D_800EC9CC = n;
        *p = *(u16 *)((u8 *)aD_800EC9BC + n * 8);
        D_800EC9F0 = 1;
        D_800EC9D2 = D_800EC9BE[n * 4];
    }
    func_800599B8((u16 *)sp10, (u16 *)D_800EC9B0[s0]);
}
