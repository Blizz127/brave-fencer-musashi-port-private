/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153CCC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 pad0;
    u16 idx;  /* offset 2 */
} S80153CCC;
extern void func_80019064(void *a0);
extern s32 D_8017FDCC;
extern void (*D_8017FDF4[])(void *a0);
extern s16 D_8011DB0C;
extern u16 D_8011F748;

void func_80153CCC(S80153CCC *a0) {
    ((s32 (*)(s32))func_80019064)((s32)&D_8017FDCC);
    D_8017FDF4[a0->idx](a0);
    D_8011DB0C = 0;
    D_8011F748 = 0;
}
