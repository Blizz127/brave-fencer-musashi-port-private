/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181170 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8001BFD0(void);
extern void func_800D0C48(s32);
extern void func_800D1E28(void);

s32 func_80181170(int param_1)
{
    s32 v0 = *(s32 *)(param_1 + 0x28);
    v0--;
    *(s32 *)(param_1 + 0x28) = v0;
    if (v0 == -1) {
        func_8002D4C8(0x1C, 0);
        func_8001BFD0();
        func_8002D4C8(0x1D, 0);
        ((s32 (*)(s32))func_800D0C48)(0x1);
        func_8002D4C8(0x4, 0x537);
        func_8002D4C8(0x4, 0x538);
        func_800D1E28();
        *(unsigned char *)(param_1 + 0x15) += 1;
    }
    return 0;
}
