/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017162C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void *D_8011F738;
extern s32 func_801716AC(s32 a0, void *a1, s32 *a2);
extern void func_80171928(void *a0);

void func_8017162C(void *a0) {
    void *s1 = a0;
    void *s0 = D_8011F738;
    s32 local;
    local = 0;
    func_801716AC(0, s0, &local);
    func_801716AC(1, s0, &local);
    func_801716AC(2, s0, &local);
    if (local == 0) {
        func_80171928(s1);
    }
}
