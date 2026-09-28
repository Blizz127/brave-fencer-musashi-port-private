/* Exact retail overlay 0010 export [800D00E4,800D0214), offset 0x212EC. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D00E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800D00E4(s32 arg0) {
    extern u8 D_800CA23C;
    extern u8 D_800C8448;
    extern u8 D_800CA84C;
    extern u8 D_800CA3E4;
    extern u8 D_800CA344;
    extern u8 D_800C83AC;
    extern u8 D_800C9A30;
    extern u8 D_800C9158;
    extern u8 D_800C9310;
    extern u8 D_800C83A0;
    extern u8 D_800C8058;
    extern u8 D_800CADE8;
    extern u8 D_800C8500;
    extern u8 D_800C8514;
    extern u8 D_800C9140;
    extern void func_8002F5C8(u8 *arg0);
    u8 *p;
    switch (arg0 - 1) {                                /* jtbl_80113ED8 */
    case 0:  p = &D_800CA23C; break;
    case 1:  p = &D_800C8448; break;
    case 2:  p = &D_800CA84C; break;
    case 3:  p = &D_800CA3E4; break;
    case 4:  p = &D_800CA344; break;
    case 5:  p = &D_800C83AC; break;
    case 6:  p = &D_800C9A30; break;
    case 7:  p = &D_800C9158; break;
    case 8:  p = &D_800C9310; break;
    case 9:  p = &D_800C83A0; break;
    case 10: p = &D_800C8058; break;
    case 11: p = &D_800CADE8; break;
    case 12: p = &D_800C8500; break;
    case 13: p = &D_800C8514; break;
    case 14: p = &D_800C9140; break;
    default: return;
    }
    func_8002F5C8(p);
}
