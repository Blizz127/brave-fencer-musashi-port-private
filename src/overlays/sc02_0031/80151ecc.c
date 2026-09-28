/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151ECC,80151F38).
 * Offset 0x29D74 at overlay base 80128158. SHA256(span)=ffb418d29847c259101e381e5c5157d5132c5338d6c1133121cabe20d76de51f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151ecc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151ECC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80151ECC {
    u8 pad0[0x64];
    s16 f64;        /* 0x64 */
    u8 padr[0x78];
    u8 fDE;         /* 0xDE */
};
extern void func_80149020(s32 *a0);
extern void func_80146CA0(void *a0);
extern s32 func_80172630(u8 *a0);

void func_80151ECC(struct S80151ECC *a0) {
    func_80149020((s32 *)a0);
    a0->f64 = a0->f64 + (a0->fDE << 6);
    a0->fDE = a0->fDE + 5;
    if (a0->f64 >= 0x1556) {
        a0->fDE = 0x10;
        func_80146CA0(a0);
    }
    func_80172630((u8 *)a0);
}
