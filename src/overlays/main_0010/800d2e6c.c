/* Exact retail overlay 0010 export [800D2E6C,800D2EE8), offset 0x24074. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2E6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8002D4C8(s32 arg0, s32 arg1);
extern void func_8001BFD0(void);
extern void func_800D0C48(u16 arg0);
extern void func_800167B8(s32 arg0);
typedef struct {
    u8 pad00[0x15];    /* 0x00..0x14 */
    u8 field_0x15;     /* 0x15 */
    u8 pad16[0x3];     /* 0x16..0x18 */
    u8 field_0x19;     /* 0x19 */
} Struct800D2E6C;

s32 func_800D2E6C(Struct800D2E6C *arg0) {
    u8 v = arg0->field_0x19;
    arg0->field_0x19 = v + 0xFF;
    if (v == 0) {
        func_8002D4C8(0x1C, 0);
        func_8001BFD0();
        func_8002D4C8(0x1D, 0);
        func_800D0C48(1);
        func_800167B8(4);
        arg0->field_0x15++;
    }
    return 0;
}
