/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A860 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_8012ACE0(void *a0);
extern void func_8012AAAC();

void func_8012A860(void *a0, int a1) {
    int v0;
    register char *p asm("$4");
    *(int *)((char *)a0 + 0x90) = a1;
    v0 = func_8012ACE0(a0);
    p = (char *)a0;
    *(unsigned short *)(p + 0x72) = *(unsigned short *)(p + 0x72) | 0x200;
    *(int *)(p + 0x94) = v0 - 1;
    *(int *)(p + 0x9C) = 0;
    *(short *)(p + 0x9A) = 0;
    func_8012AAAC();
}
