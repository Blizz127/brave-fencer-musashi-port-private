/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128CFC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s32 word0;
    s32 word4;
} CdFileLoc;
extern s32 D_8019AB88;
extern CdFileLoc D_800AE830[];
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);

s32 func_80128CFC(s32 arg0) {

    extern s16 D_8017DFD8[];
    s16 idx = D_8017DFD8[arg0];

    if (idx >= 0) {
        func_8001ABBC(0, 0, (u8 *)&D_800AE830[idx], D_8019AB88, 0);
    } else {
        return 1;
    }
}
