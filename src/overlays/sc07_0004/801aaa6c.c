/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AAA6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 x;      /* +0x0 */
    u16 y;      /* +0x2 */
    u16 num;    /* +0x4 */
    u16 count;  /* +0x6 */
} SV4R_801AAA6C;
extern void func_801AAB28();

void func_801AAA6C(s32 a0)
{
    SV4R_801AAA6C r1;   /* sp+0x10 : base point + running offset */
    SV4R_801AAA6C r2;   /* sp+0x18 : {yOff, seg<<10, 0x24, 5} */
    s32 j = 0;
    s16 yOff = -0x200;
    s32 i;

    r1.x = *(u16 *)(a0 + 0x06) + *(u16 *)(a0 + 0x50);
    r1.y = *(u16 *)(a0 + 0x0A) + *(u16 *)(a0 + 0x52);
    r1.num = *(u16 *)(a0 + 0x0E) + *(u16 *)(a0 + 0x54);
    r2.num = 0x24;
    r2.count = 5;
    for (; j < 2; j++) {
        for (i = 0; i < 4; i++) {
            r2.x = yOff;
            r2.y = i * 0x400;
            func_801AAB28(&r1, &r2, 0x101820);
        }
        yOff += 0x400;
    }
}
