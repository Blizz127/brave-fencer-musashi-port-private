/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149374 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_80015954(s32 a0, s32 a1);

void func_80149374(s32 arg0, s32 arg1)
{
    u64 sp10;
    u64 sp18;
    ((void (*)(s32, void*))func_80015978)(arg1, &sp10);
    {
        void *q = &sp18;
        ((void (*)(s32, void*, void*))func_8012F14C)(*(s32*)(arg0 + 0x20) + 0x34, &sp10, q);
        __asm__ __volatile__("" : "=r"(q));  /* LOAD-BEARING: kills the (plus sp 0x18) CSE class reg; emits 0 bytes */
    }
    ((void (*)(void*, s32))func_80015954)(&sp18, arg1);
}
