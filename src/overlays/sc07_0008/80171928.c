/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171928 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);

void func_80171928(void * a0)
{
    unsigned char idx     = *(unsigned char *)((char *)a0 + 0x214);
    unsigned int *base    = *(unsigned int **)((char *)a0 + 0x1FC);
    unsigned int  cur     = *(unsigned int *)((char *)a0 + 0x1F8);
    *(unsigned int *)((char *)a0 + 0x1F8) = base[idx] | (cur & 0x7F000000);
    ((void (*)(void *))func_80171A1C)(a0);
}
