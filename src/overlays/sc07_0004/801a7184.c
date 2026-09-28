/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7184 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A5C44(void);
extern void func_801A5B5C(void *a0);
extern void func_801A63A8(void *a0);
extern void func_801A6428(void *a0);

void func_801A7184(void *arg0)
{
    if (*(s16 *)((u8 *)arg0 + 0x104) != *(s16 *)(*(void **)((u8 *)arg0 + 0x64) + 0x36)) {
        func_801A63A8(arg0);
    } else {
        ((void (*)(void *))func_801A5C44)(arg0);
        func_801A5B5C(arg0);
        if (*(s16 *)(*(void **)((u8 *)arg0 + 0x64) + 0x100) != 0) {
            func_801A6428(arg0);
        }
    }
}
