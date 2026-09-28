/* Exact retail overlay 0010 export [800D2FEC,800D302C), offset 0x241F4. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2FEC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D33E0(void);
typedef struct {
    u8 pad00[0x15];
    u8 field_0x15;   /* 0x15 */
    u8 pad16[0x12];
    s32 field_0x28;  /* 0x28 */
} Struct800D2FEC;

s32 func_800D2FEC(Struct800D2FEC *a0) {
    func_800D33E0();
    a0->field_0x28 = 0xA;
    a0->field_0x15 = a0->field_0x15 + 1;
    return 0;
}
