/* Exact retail overlay 0010 export [800D0488,800D0588), offset 0x21690. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0488 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s32 func_8001ABBC(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);
extern void func_8001B384(void);
extern CdFileLoc D_800AE830[];

s32 func_800D0488(s32 arg0) {
    extern s32 D_800C7C60;
    extern s32 *D_800C7C64;
    extern s32 D_800A2E20;
    extern s32 D_800D3850[];
    extern s32 D_800D384C[];
    extern s32 D_80072C7C;
    extern CdFileLoc D_800AE830[];
    extern s32 func_8001ABBC(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);
    extern void func_8001B384(void);

    s32 val;
    s32 res;
    s32 z = 0;
    s32 n = arg0;
    s32 *p;

    switch (n) {
    case 1: n = 0; break;
    case 2: n = 1; break;
    case 3: n = 2; break;
    case 4: n = 3; break;
    case 5: n = 4; break;
    case 6: n = 5; break;
    default: n = -1; break;
    }

    val = D_800D3850[n * 2];
    __asm__("");
    D_800C7C64 = &D_800A2E20;
    p = &D_800C7C60;
    *p = val;

    if (n >= 0) {
        res = func_8001ABBC(z, 0, (u8 *)&D_800AE830[D_800D384C[n * 2]], D_80072C7C, (s32)p);
    } else {
        res = 1;
    }

    if (res != 0) {
        func_8001B384();
    }
    return res;
}
