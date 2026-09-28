/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A227C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C218(void *a0);
extern void func_80016450(s32 a0, s32 a1);

void func_801A227C(void *arg0) {
    void *v0;
    if (*(void **)((u8 *)arg0 + 0xCC) != NULL) {
        func_8012C218(*(void **)((u8 *)arg0 + 0xCC));
    }
    if (*(void **)((u8 *)arg0 + 0xD0) != NULL) {
        func_8012C218(*(void **)((u8 *)arg0 + 0xD0));
    }
    if (*(void **)((u8 *)arg0 + 0xD4) != NULL) {
        func_8012C218(*(void **)((u8 *)arg0 + 0xD4));
    }
    v0 = *(void **)((u8 *)arg0 + 0xD8);
    if (v0 != NULL) {
        func_80016450(*(u8 *)((u8 *)v0 + 0xFC), 0);
        func_8012C218(*(void **)((u8 *)arg0 + 0xD8));
    }
    func_8012C218(arg0);
}
