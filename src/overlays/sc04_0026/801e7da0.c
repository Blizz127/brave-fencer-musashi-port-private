/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E7DA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u8 c[8]; } Blk8;
extern const Blk8 D_801E7B2C ;  /* data at its retail address */
extern s32 func_80171D78(u32, void *);
extern void func_80171A1C(void*);

void func_801E7DA0(u32 arg0) {
    Blk8 buffer;

    buffer = D_801E7B2C;

    if (func_80171D78(arg0, &buffer)) {
        ((void (*)(u32))func_80171A1C)(arg0);
    }
}
