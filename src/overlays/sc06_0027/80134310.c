/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80134310 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 x, y, z; } Vec3s;
extern void func_8012A5F8(void (*a0)(void), s32 a1);

s32 func_80134310(Vec3s *a0, Vec3s *a1, s32 a2) {
    return a0->x * a1->x + a0->y * a1->y + a0->z * a1->z + a2;
}
