/* Complete SC02 retail span [8014C88C,8014C8C8).
 * Gap after 4C6D0→existing 4C968; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C88C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C8C8(s32 a0, s32 *a1);

void func_8014C88C(s32 a0) {
    s32 sp10;
    func_80015978(a0 + 4, &sp10);
    func_8014C8C8(a0, &sp10);
}
