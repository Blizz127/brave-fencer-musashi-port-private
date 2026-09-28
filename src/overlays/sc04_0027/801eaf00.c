/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EAF00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801F24AC[];
extern s32 D_801F24A8[];
extern s32 D_801F2624;
extern s32 func_801EADC4();

s32 func_801EAF00(void *a0) {
    s32 n;
    s32 i;
    s32 end;

    func_801EADC4();
    n = D_801F2624;
    if (n > 0) {
        i = 0;
        end = n * 16;
        do {
            if (*(s32 *)((char *)D_801F24AC + i) == (s32)a0) {
                return *(s32 *)((char *)D_801F24A8 + i);
            }
            i += 16;
        } while (i < end);
    }
    return 0;
}
