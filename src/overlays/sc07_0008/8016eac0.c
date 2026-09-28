/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016EAC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    char _pad0;       /* 0x0 */
    unsigned char f1; /* 0x1 */
    unsigned char f2; /* 0x2 */
    char _pad3;       /* 0x3 */
    short f4;         /* 0x4 */
} Wave;
extern u16 D_801806C0[];
extern void func_8016EC0C(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));

void func_8016EAC0(Wave *param_1)
{
    unsigned char bVar1;

    param_1->f4 = param_1->f4 + D_801806C0[param_1->f2];
    ((void (*)(void *, int))func_8016EC0C)(param_1, 0x80);
    bVar1 = param_1->f2 + 1;
    param_1->f2 = bVar1;
    if (5 < bVar1) {
        param_1->f2 = 0x20;
        param_1->f1 = param_1->f1 + 1;
    }
}
