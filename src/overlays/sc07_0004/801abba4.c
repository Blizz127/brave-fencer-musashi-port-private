/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ABBA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012BEE8(s32 a0);
extern void func_8017E5D4(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012AD80(s32 a0);

void func_801ABBA4(void *arg0) {
    if (func_8012BEE8((s32)arg0) != 0) {
        if (*(void **)((u8 *)arg0 + 0xCC) != NULL) {
            func_8017E5D4(*(void **)((u8 *)arg0 + 0xCC));
        }
        func_8012C218(arg0);
    } else {
        func_8012AD80(arg0);
    }
}
