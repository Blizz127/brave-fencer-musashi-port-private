/* Exact retail overlay 0010 export [800D302C,800D30A8), offset 0x24234. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D302C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8002D4C8(s32, s32);
extern void func_8001BFD0(void);
extern void func_800D0C48(u16 arg0);
extern void func_800D1E28(void);
typedef struct {
    u8  pad00[0x15];
    u8  field_0x15;   /* 0x15 */
    u8  pad16[0x12];
    s32 field_0x28;   /* 0x28 */
} Obj800D302C;

s32 func_800D302C(Obj800D302C *arg0) {
    s32 v;

    v = arg0->field_0x28 - 1;
    arg0->field_0x28 = v;
    if (v == -1) {
        func_8002D4C8(0x1C, 0);
        func_8001BFD0();
        func_8002D4C8(0x1D, 0);
        func_800D0C48(1);
        func_800D1E28();
        arg0->field_0x15 = arg0->field_0x15 + 1;
    }
    return 0;
}
