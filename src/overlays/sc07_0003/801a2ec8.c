/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2EC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 r;
    u16 g;
    u16 b;
} Col6_801A2E20;
extern void func_800599B8(u16 *a0, u16 *a1);
extern u16 D_801A6914[];
extern u16 D_801A6CE0[];
extern u16 D_801F4424[];
extern Col6_801A2E20 D_801F43C4[];
extern Col6_801A2E20 D_801F43C6[];
extern Col6_801A2E20 D_801F43C8[];

void func_801A2EC8(void *a0)
{
    u16 *dst = D_801F4424;
    u16 *src = D_801A6914;
    s32 i;
    s32 j;
    s32 fade;

    if (!(*(s32 *)((s32)a0 + 0xE0) & 0x100)) {
        fade = *(s32 *)((s32)a0 + 0xE8);
    } else {
        if (*(s32 *)((s32)a0 + 0xEC) <= 0) {
            fade = 0;
            *(s32 *)((s32)a0 + 0xEC) = 0x10000;
            *(s32 *)((s32)a0 + 0xE0) &= ~0x100;
        } else {
            fade = (*(s32 *)((s32)a0 + 0xEC) -= 0x800);
        }
    }

    i = 0;
    j = 0;
    do {
        u16 w;
        s32 t;
        s32 r;
        s32 g;
        s32 b;
        s32 c4 = *(s16 *)((u8 *)D_801F43C4 + j);
        s32 c6 = *(s16 *)((u8 *)D_801F43C6 + j);
        s32 c8;

        i++;
        c8 = *(s16 *)((u8 *)D_801F43C8 + j);
        j += 6;
        w = *src++;

        r = (w & 0x1F) + ((c4 * fade) >> 16);
        r &= 0x1F;
        t = w << 16;
        g = ((t >> 21) & 0x1F) + ((c6 * fade) >> 16);
        g &= 0x1F;
        b = ((t >> 26) & 0x1F) + ((c8 * fade) >> 16);
        b &= 0x1F;

        *dst++ = (u16)(r | ((b << 10) | (g << 5)));
    } while (i < 16);

    func_800599B8(D_801A6CE0, D_801F4424);
}
