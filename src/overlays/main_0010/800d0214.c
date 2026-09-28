/* Exact retail overlay 0010 export [800D0214,800D02C0), offset 0x2141C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0214 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s16 D_800B9A08;
extern int func_80019A24(void *dst, void *src, int arg2, int arg3);
extern CdFileLoc D_800AE830[];
extern s32 D_800D34AC[];

s32 func_800D0214(s32 arg0) {
    extern s16 D_800B9A08;
    extern s32 D_800C7C60;
    extern s32 *D_800C7C64;
    extern s32 D_800A2E20;
    extern s32 D_800D34AC[];
    extern s16 D_800D34AE[];
    extern CdFileLoc D_800AE830[];
    extern s32 func_80019A24(void *, void *, s32, s32);

    register s32 mask __asm__("$3") = ~0xF000;
    s32 idx = D_800B9A08 & mask;
    s32 raw = D_800D34AC[idx];
    s32 val = D_800D34AE[idx * 2];
    s32 *p = &D_800C7C60;
    s32 id;

    __asm__("" ::: "memory");
    D_800C7C64 = &D_800A2E20;
    *p = val;

    id = raw & 0xFFF;
    if (id >= 0 && D_800AE830[id].word0 != 0) {
        return func_80019A24(&D_800AE830[id], arg0, 0, p);
    }
    return 1;
}
