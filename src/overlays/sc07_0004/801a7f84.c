/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7F84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;
extern void func_800233CC(void *a0, unsigned short a1);
extern void func_8001CD9C(s32, s32);
extern Blk4_801A7358 D_801A01E8;
extern Blk4_801A7358 D_801F88F8;

void func_801A7F84(s32 a0) {
    register s32 v1 __asm__("$3");
    s32 t;
    s32 buf;

    buf = *(s32 *)(a0 + 0x24);
    func_800233CC((void *)buf, 0x80);
    *(Blk4_801A7358 *)(buf + 0x0) = D_801A01E8;
    *(Blk4_801A7358 *)(buf + 0x4) = D_801A01E8;
    func_8001CD9C(*(s32 *)(a0 + 0x20), (s32)&D_801F88F8);

    v1 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v1 + 0x1A) = 0x3800;
    *(s16 *)(v1 + 0x18) = 0x3800;

    *(s32 *)(a0 + 0x1C) = 0x10;

    v1 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v1 + 0x1E) = 0xD00;

    t = *(s32 *)(a0 + 0x20);
    *(s32 *)(t + 0x4) |= 0x60000000;

    v1 = *(s32 *)(a0 + 0x20);
    *(u16 *)(v1 + 0x2C) = 0xC040;

    *(s16 *)(a0 + 0x2) = 8;
}
