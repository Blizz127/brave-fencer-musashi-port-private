/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD2CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u16 a, b, c, d; } Rec8_801A57E8;
extern void func_800599B8(void *, void *);
extern u8 D_801B07F0[];

void func_801AD2CC(void) {
    extern u8 D_801B07F2[];
    extern u8 D_801F8A78[];
    Rec8_801A57E8 rect;

    rect.c = 0x10;
    rect.d = 1;
    rect.a = *(u16 *)D_801B07F0;
    rect.b = (*(u16 *)D_801B07F2);
    func_800599B8(&rect, D_801F8A78);
}
