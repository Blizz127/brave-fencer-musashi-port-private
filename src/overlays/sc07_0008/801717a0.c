/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801717A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801719A4(int a0, int a1);
extern int func_800D0F8C(int a0);
extern int func_800D0FE0(int a0);
extern void func_80171928(void *a0);
extern void *D_8011F738;

void func_801717A0(void *a0) {
    int v0;
    func_801719A4((int)a0, 1);
    v0 = func_800D0F8C(*(u8 *)&D_8011F738);
    if (v0 != 0) {
        func_800D0FE0(v0);
    }
    func_80171928(a0);
}
