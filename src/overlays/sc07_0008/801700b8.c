/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801700B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *D_8011F738;
extern void func_801719A4(int a0, int a1);
extern s32 func_8013767C(s32 a0);
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_801700B8(u8 *a0) {
    func_801719A4((int)a0, 1);
    *(s32 *)(a0 + 0x198) = func_8013767C((s32)D_8011F738);
    func_80171928((void *)a0);
}
