/* Exact retail overlay 0010 export [800D2E20,800D2E6C), offset 0x24028. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2E20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D3348(u8 *arg0);
extern void func_8016EDEC(void *arg0, s32 arg1);
typedef struct {
    u8 pad15[0x15];
    u8 field_0x15;  /* 0x15 */
    u8 pad16[0x3];
    u8 field_0x19;  /* 0x19 */
} Struct800D2E20;

s32 func_800D2E20(Struct800D2E20 *a0) {
    func_8016EDEC(func_800D3348, 0x1000000);
    a0->field_0x19 = 0xA;
    a0->field_0x15 = a0->field_0x15 + 1;
    return 0;
}
