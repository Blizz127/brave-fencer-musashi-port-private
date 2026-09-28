/* Complete SC02 retail span [8014B310,8014B33C).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014B310 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014B33C(void);
extern s32 D_80078ECC;

void func_8014B310(void) {
    func_8014B33C();
    D_80078ECC = 0x80000000;
}
