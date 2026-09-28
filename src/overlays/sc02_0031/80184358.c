/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80184358 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
s32 aF80184358() __asm__("func_80184358");

s32 aF80184358(param_1)
    void *param_1;
{
    if (((s32 (*)(s32))func_8012BD14)(*(s32 *)((s32)param_1 + 0x64)) > 0x1000) {
        return 0;
    }
    *(s16 *)(*(s32 *)((s32)param_1 + 0x64) + 0x2) = 2;
    func_80178BF8();
    return (s32)func_80172710;
}
