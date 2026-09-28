/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80153150 {
    u8 pad0[0x60];
    s16 f60;   /* 0x60 */
    s16 f62;   /* 0x62 */
    u16 f64;   /* 0x64 */
    u8 padr[0x78];
    u8 fDE;    /* 0xDE */
};
extern void func_80149020(s32 *a0);
extern void func_801470B4(s32 a0);
extern void func_8015369C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80153150(struct S80153150 *a0) {
    s16 nv;
    func_80149020((s32 *)a0);
    nv = (s16)(a0->f64 - 0x100);
    a0->f64 = nv;
    a0->f62 = nv;
    a0->f60 = nv;
    if (nv <= 0) {
        a0->fDE = 0x10;
        func_801470B4((s32)a0);
        func_8015369C((s32)a0);
        func_80146CA0(a0);
    }
}
