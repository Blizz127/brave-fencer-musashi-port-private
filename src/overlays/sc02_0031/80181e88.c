/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181E88 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80016A3C(void *a0);
typedef struct { u8 c[4]; } W4_80181E88;
typedef struct {
    W4_80181E88 f00;   /* 0x00 */
    u16 f04;           /* 0x04 */
    u16 f06;           /* 0x06 */
    W4_80181E88 f08;   /* 0x08 */
    u32 f0c;           /* 0x0c */
    u32 f10;           /* 0x10 */
    u32 f14;           /* 0x14 */
    u32 f18;           /* 0x18 */
} Prim_80181E88;

void func_80181E88(void *a0) {
    Prim_80181E88 p;

    p.f00 = *(W4_80181E88 *)a0;
    p.f08 = *(W4_80181E88 *)((u8 *)a0 + 4);
    p.f04 = 1;
    p.f10 = 0x808080;
    p.f14 = 0;
    p.f18 = 0x50000000;
    func_80016A3C(&p);
}
