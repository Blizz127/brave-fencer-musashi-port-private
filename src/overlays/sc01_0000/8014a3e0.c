/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A3E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S_8014A3E0 {
    char pad0[0x12];
    s16 h12;      /* 0x12 */
    char pad14[0x6];
    s16 h1A;      /* 0x1A */
    char pad1C[0x6C];
    u16 h88;      /* 0x88 */
    u16 h8A;      /* 0x8A */
    u16 h8C;      /* 0x8C */
};
extern s16 D_801152B0;
extern s16 D_801152B4;

s32 func_8014A3E0(struct S_8014A3E0 *a0) {
    s32 sp[4];
    sp[0] = a0->h12 * D_801152B0;
    sp[2] = a0->h1A * D_801152B4;
    if (sp[0] >= 0 && sp[2] >= 0) {
        return 1;
    }
    *(s16 *)((char *)a0 + 0x6) = a0->h88;
    *(s16 *)((char *)a0 + 0xA) = a0->h8A;
    *(s16 *)((char *)a0 + 0xE) = a0->h8C;
    return 0;
}
