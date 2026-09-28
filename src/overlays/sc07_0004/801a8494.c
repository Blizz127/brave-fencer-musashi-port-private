/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8494 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32, s32, void*);
typedef struct { s16 x, y, z, pad; } Svec_801A8494;

void func_801A8494(void *a0)
{
    Svec_801A8494 vec;   /* sp+0x10 : func_8004945C in/out */
    s32 flag;            /* sp+0x18 */
    void *t;

    t = *(void **)((u8 *)a0 + 0x34);
    func_8004914C((void *)(*(s32 *)((u8 *)t + 0x20) + 0x34));
    func_800491AC((void *)(*(s32 *)((u8 *)t + 0x20) + 0x34));

    vec.y = -0x40;
    vec.x = 0;
    vec.z = 0x20;

    func_8004945C((s32)&vec, (s32)&vec, &flag);

    *(u16 *)((u8 *)a0 + 0x06) = vec.x;
    *(u16 *)((u8 *)a0 + 0x0A) = vec.y;
    *(u16 *)((u8 *)a0 + 0x0E) = vec.z;
}
