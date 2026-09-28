/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A63A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);

void func_801A63A8(void *arg0) {
    void *temp_a0;

    temp_a0 = *(void **)((char *)arg0 + 0xCC);
    if (temp_a0 != NULL) {
        func_80016714(temp_a0, 0x38);
    }
    func_8012C218(arg0);
}
