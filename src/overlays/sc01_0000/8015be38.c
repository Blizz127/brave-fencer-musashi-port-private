/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BE38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char pad[0x12]; s16 field_0x12; } Obj;

void func_8015BE38(struct Obj *a0) {

    extern void (*D_80181418[])(void);
    D_80181418[*(u16 *)((s32)a0 + 0x2)]();
}
