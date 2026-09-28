/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA2F8 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern Blk4_801A7358 D_801A01E8;
extern Blk4_801A7358 D_801F88B8;
extern u8 D_801F88B9[];
extern u8 D_801F88BA;

void func_801AA2F8(void) {
    register u8 *pbase __asm__("$2");
    register s32 idx __asm__("$16");
    register s32 c1 __asm__("$17");
    register s32 p __asm__("$18");
    register s32 c0 __asm__("$19");
    register u8 *q __asm__("$20");
    register s32 i __asm__("$21");

    i = 0;
    pbase = ((u8 *)&D_801F88B8);
    q = pbase + 4;
    c1 = -1;
    c0 = -0x40;
    p = (s32)pbase;
    idx = 0;

    do {
        func_800233CC((void *)p, 0x20);
        ((u8 *)&D_801F88B8)[idx] = c0;
        D_801F88B9[idx] = c1;
        ((u8 *)&D_801F88BA)[idx] = c1;
        *(Blk4_801A7358 *)q = D_801A01E8;
        q += 0x40;
        c1 -= 0x40;
        c0 -= 0x30;
        p += 0x40;
        idx += 0x40;
        i++;
    } while (i < 4);
}
