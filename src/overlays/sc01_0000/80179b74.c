/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179B74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801A5268[0x200];
extern s16 D_801A566C;

void func_80179B74(u16 *p) {
    s32 pad[10];
    s16 c;

    (void)&pad;
    c = *p++;
    D_801A5268[D_801A566C] = c;
    D_801A566C = (D_801A566C + 1) & 0x1FF;
    switch (c) {
    case 0:
        break;
    case 1:
    case 5:
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        break;
    case 0x13:
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        break;
    case 2:
    case 3:
    case 4:
    case 6:
    case 0x12:
    case 0x14:
    case 0x1F:
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        break;
    case 0x17:
    case 0x1C:
    case 0x1D:
    case 0x20:
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        { s16 t = *p++; D_801A5268[D_801A566C] = t; D_801A566C = (D_801A566C + 1) & 0x1FF; }
        break;
    case 0x22:
        break;
    }
}
