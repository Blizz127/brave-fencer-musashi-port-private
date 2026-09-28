/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017129C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct B16 { s32 w[4]; };
typedef struct { s32 a, b, c, d; } S16;
extern void *D_8011F738;
extern struct B16 D_800A5E88;
extern struct B16 D_800A5E98;
extern struct B16 D_800A5EA8;
extern void func_801719A4(int, int);
extern s32 func_80171990(u8*);
extern void func_80171384(void*);

void func_8017129C(int param_1) {
    S16 *p;
    func_801719A4(param_1, 1);
    p = (*(S16 * *)&D_8011F738);
    p[0] = (*(S16 *)&D_800A5E88);
    p[1] = (*(S16 *)&D_800A5E98);
    p[2] = (*(S16 *)&D_800A5EA8);
    *(unsigned short *)(*(int *)(param_1 + 0x20) + 0x2C) |= 0x20;
    *(int *)(*(int *)(param_1 + 0x20) + 0x80) = (int)p;
    ((void (*)(int))func_80171990)(param_1);
    ((void (*)(int))func_80171384)(param_1);
}
