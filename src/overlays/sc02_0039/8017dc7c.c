/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DC7C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126CAC;
extern u16 D_8019B568[];
extern void func_8002D59C(s32 a0, u16 a1, s32 a2);

void func_8017DC7C(s32 a0)
{
    s16 t;
    s16 temp;
    s16 vol;

    t = *(u16 *)(a0 + 6) - D_80126CAC;
    if (t < 0) {
        t = -t;
    }

    if (t >= 0x801) {
        *(s32 *)(*(s32 *)(a0 + 0x20) + 4) |= 0x80000000;
    } else {
        *(s32 *)(*(s32 *)(a0 + 0x20) + 4) &= 0x7FFFFFFF;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x14) += D_8019B568[*(s16 *)(a0 + 0x70)];
    }

    temp = t - 0x140;
    if (temp < 0) {
        vol = 0x7F;
    } else if (temp >= 0x200) {
        vol = 0;
    } else {
        vol = 0x7F - (temp >> 2);
    }

    if (vol == 0) {
        if (*(s16 *)(a0 + 0x84) != 0) {
            func_8002D59C(4, 0x6DD, *(u16 *)(a0 + 0x70));
            *(s16 *)(a0 + 0x84) = 0;
        }
    } else {
        func_8002D59C(0x6DD, (vol | 0x1000) & 0xFFFF, *(u16 *)(a0 + 0x70));
        *(s16 *)(a0 + 0x84) = 1;
    }
}
