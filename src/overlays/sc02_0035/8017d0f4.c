/* SC02.CD member35 [8017D0F4,8017D130): the same code as sc01_0000 8017D1B4
 * (src/overlays/sc01_0000/8017d1b4.c) with this scene's handler table
 * D_80187F34; byte-identical to the sc02_0035 retail words. */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80187F34[])(void *);

void func_8017D0F4(void *a0) {
    D_80187F34[*(u8 *)((s32)a0 + 0x4)](a0);
}
