/* Exact retail overlay 0010 export [800D3104,800D3120), offset 0x2430C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D3104 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u8 pad15[0x15];
    u8 field_0x15;
    u8 pad16[0x3];
    u8 field_0x19;
} Struct800D3104;

s32 func_800D3104(Struct800D3104 *a0) {
    u8 v = a0->field_0x15;
    a0->field_0x19 = 0xA;
    a0->field_0x15 = v + 1;
    return 0;
}
