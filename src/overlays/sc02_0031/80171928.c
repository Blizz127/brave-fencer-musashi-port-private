/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171928,8017196C).
 * Offset 0x497D0 at overlay base 80128158. SHA256(span)=5a853247f7d161379160f826f14cd29b985cb6003260335164255e2ef1dcb1dc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171928.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
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
