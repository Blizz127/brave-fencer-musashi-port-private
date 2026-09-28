/* Exact retail overlay 0010 export [800D02D0,800D0488), offset 0x214D8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D02D0 - byte-exact against retail at -O2 (tools/register_match.py). */
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

s32 func_800D02D0(s32 arg0) {
    extern CdFileLoc D_800AE830[];
    extern CdFileLoc D_800D3768[];
    extern CdFileLoc D_800D3764[];
    extern s32 D_800C7C60;
    extern s32 *D_800C7C64;
    extern s32 D_80072C78;
    extern s32 D_800A2E20;
    extern s32 func_8001ABBC(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);
    extern void func_8001B384(void);

    register s32 *p __asm__("$2");
    s32 ret;

    arg0 = arg0 - 1;
    switch (arg0) {
    case 4: arg0 = 1; break;
    case 0: arg0 = 3; break;
    case 7: arg0 = 2; break;
    case 6: arg0 = 0; break;
    case 12: arg0 = 4; break;
    case 16: arg0 = 5; break;
    case 11: arg0 = 6; break;
    case 2: arg0 = 7; break;
    case 1: arg0 = 9; break;
    case 3: arg0 = 10; break;
    case 5: arg0 = 11; break;
    case 17: arg0 = 12; break;
    case 14: arg0 = 8; break;
    case 21: arg0 = 13; break;
    case 23: arg0 = 14; break;
    case 20: arg0 = 15; break;
    case 19: arg0 = 16; break;
    case 18: arg0 = 17; break;
    case 25: arg0 = 18; break;
    case 8: arg0 = 19; break;
    case 10: arg0 = 20; break;
    case 15: arg0 = 21; break;
    case 9: arg0 = 22; break;
    case 22: arg0 = 23; break;
    case 24: arg0 = 24; break;
    case 26: arg0 = 25; break;
    case 27: arg0 = 26; break;
    case 28: arg0 = 27; break;
    case 29: arg0 = 28; break;
    default: arg0 = -1; break;
    }

    p = &D_800A2E20;
    D_800C7C64 = p;
    p = &D_800C7C60;
    *p = D_800D3768[arg0].word0;
    if (arg0 >= 0) {
        ret = func_8001ABBC(0, 0, (u8 *)&D_800AE830[D_800D3764[arg0].word0], D_80072C78, (s32)p);
    } else {
        ret = 1;
    }
    if (ret != 0) {
        func_8001B384();
    }
    return ret;
}
