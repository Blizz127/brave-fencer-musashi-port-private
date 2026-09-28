/* Complete SC02 retail span [8014C6E0,8014C6F4).
 * Gap after 4C6D0→existing 4C968; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C6E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80126D1E;

void func_8014C6E0(void) {
    D_80126D1E = 1;
}
