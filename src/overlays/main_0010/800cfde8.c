/* MAIN10 resident retail span [800CFDE8,800CFE60), offset 0x20FF0 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFDE8 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s32 D_800D34AC[];
extern CdFileLoc D_800AE830[];
extern s32 func_8001ABBC(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);

void func_800CFDE8(s32 arg0) {
    s32 idx = D_800D34AC[arg0 & 0xFFFF0FFF] & 0xFFF;
    if (idx >= 0 && D_800AE830[idx].word0 != 0) {
        func_8001ABBC(2, 0, (u8 *)&D_800AE830[idx], 0, 0);
    }
}
