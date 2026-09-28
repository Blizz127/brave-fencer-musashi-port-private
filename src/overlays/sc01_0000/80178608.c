/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178608 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80016714(void *a0, s32 a1);
extern void func_8013E4B4(void);
extern u8 D_801202A0[];
extern u16 D_801270C0;
extern s16 D_801270C4;
extern s32 D_801274D8;
extern s16 D_801270C2;
extern u8 D_801270C6;
extern u8 D_801270C7;
extern s32 D_801274DC;
extern s32 D_801274E0;

void func_80178608(void) {
    u16 *p = &D_801270C0;
    func_80016714(D_801202A0, 0x6480);
    *p = 1;
    D_801270C4 = 1;
    D_801274D8 = 0x240000;
    D_801270C2 = 0;
    D_801270C6 = 0;
    D_801270C7 = 0;
    D_801274DC = 0x271000;
    D_801274E0 = 0x400000;
    func_80016714((u8 *)p + 8, 0x400);
    func_8013E4B4();
}
