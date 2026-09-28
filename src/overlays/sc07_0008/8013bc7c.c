/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013BC7C - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char pad_8013BC7C[0x68]; s32 f68; } S_8013BC7C_8013BC7C;

void func_8013BC7C(void *arg0) {

    extern void (*D_8017D2B8[])(void *);
    D_8017D2B8[((S_8013BC7C_8013BC7C *)arg0)->f68](arg0);
}
