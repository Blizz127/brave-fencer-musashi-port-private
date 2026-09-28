/* Complete SC02 retail span [8017F3C0,8017F400).
 * Live STOP 7ECB0 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017F3C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8014706C(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_80171990(u8 *a0);

void func_8017F3C0(s32 a0) {

    extern u8 D_80188808;
    func_8014706C((void *)a0);
    func_80154274((s32 *)a0, (s32)&D_80188808);
    func_80171990((u8 *)a0);
}
