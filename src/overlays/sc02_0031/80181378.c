/* Complete SC02 camera handler [80181378,801814E4). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181378 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_80126940;
extern s16 D_80126942;
extern s16 D_80126944;
extern void func_801814E4(s32 param_1, s16 *param_2);

void func_80181378(s32 param_1)
{
    s16 buf[3];

    if (D_80126944 < 0x800) {
        u16 t = D_80126940;
        if ((u16)(t + 0x2FF) < 0xFF) {
            s32 val = -0x200 - (s32)((s16)t * 4);
            *(s16 *)(param_1 + 0x22) = val;
            *(s16 *)(param_1 + 0x1A) = val;
        }
    }

    if (D_80126944 < 0x11A0) {
        s16 a1 = D_80126940;
        if (a1 < -0x4C0) buf[0] = -0x4C0;
        else if (a1 > 0x2C0) buf[0] = 0x2C0;
        else buf[0] = a1;
        buf[1] = (u16)D_80126942;
        buf[2] = (u16)D_80126944;
    } else {
        s16 a1 = D_80126940;
        if (a1 < -0x2C0) buf[0] = -0x2C0;
        else if (a1 > 0x2C0) buf[0] = 0x2C0;
        else buf[0] = a1;

        if (D_80126940 < -0x200) {
            s16 d44 = D_80126944;
            if (d44 < 0x13D1) buf[2] = d44;
            else buf[2] = 0x13D0;
        } else {
            buf[2] = (u16)D_80126944;
        }
        buf[1] = (u16)D_80126942;
    }

    func_801814E4(param_1, buf);
}
