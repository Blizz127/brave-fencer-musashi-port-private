/* Complete SC02 retail span [80147364,801473DC).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80147364 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800B9A08;
extern s32 D_80126B58;
extern void func_80015978(s32, s32*);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_8002D4C8(s32 a0, s32 a1);
void aF80147364(u16 param_1, u16 param_2) __asm__("func_80147364");

void aF80147364(u16 param_1, u16 param_2) {
    s32 sp10[2];
    s32 *p = &D_80126B58;
    if (D_800B9A08 == 0x308d) {
        ((void (*)(void *, void *))func_80015978)(p + 1, sp10);
        ((void (*)(void *, s32, s32))aF8012E5CC)(sp10, param_1, param_2);
    } else {
        func_8002D4C8(param_1, param_2);
    }
}
