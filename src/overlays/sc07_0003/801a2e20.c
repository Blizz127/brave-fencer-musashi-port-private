/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2E20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801A6914[];
extern u16 D_801A6934[];
typedef struct {
    u16 r;
    u16 g;
    u16 b;
} Col6_801A2E20;
extern Col6_801A2E20 D_801F43C4[];
extern Col6_801A2E20 D_801F43C6[];
extern Col6_801A2E20 D_801F43C8[];

void func_801A2E20(void)
{
    u16 *a = D_801A6934;
    u16 *b = D_801A6914;
    s32 i;

    for (i = 0; i < 16; i++) {
        D_801F43C4[i].r = (*a & 0x1F) - (*b & 0x1F);
        D_801F43C6[i].r = ((*a >> 5) & 0x1F) - ((*b >> 5) & 0x1F);
        D_801F43C8[i].r = ((*a >> 10) & 0x1F) - ((*b >> 10) & 0x1F);
        a++;
        b++;
    }
}
