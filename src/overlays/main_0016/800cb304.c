/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB304 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
void func_800CAF84();
extern void func_800CAF84();

void func_800CB304(s32 arg0) {
    extern void func_800CAF84();
    extern s32 rand(void);
    s32 s0 = arg0;
    s32 v0;
    s32 t;
    if (*(s16 *)(s0 + 0x28) > *(s16 *)(s0 + 0x2A)) {
        v0 = *(s32 *)(s0 + 0x1C);
        if (v0 > 0) {
            v0 = (rand() & 0x180) + 0x500;
            *(s16 *)(s0 + 0x2A) = v0;
            *(s32 *)(s0 + 0x1C) = -0xA0;
        }
    } else {
        v0 = *(s32 *)(s0 + 0x1C);
        if (v0 < 0) {
            v0 = (rand() & 0x180) + 0x800;
            *(s16 *)(s0 + 0x2A) = v0;
            *(s32 *)(s0 + 0x1C) = 0xA0;
        }
    }

    *(s16 *)(s0 + 0x28) = *(u16 *)(s0 + 0x28) + *(s32 *)(s0 + 0x1C);
    *(s32 *)(s0 + 0x4C) += *(s16 *)(s0 + 0x12);
    *(s32 *)(s0 + 0x50) -= 2;
    *(s32 *)(s0 + 0x54) += *(s16 *)(s0 + 0x1A);

    func_800CAF84(s0);

    t = *(s32 *)(s0 + 0x30);
    *(s32 *)(s0 + 0x30) = t - 1;
    if (t == 0) {
        *(u16 *)(s0 + 0x2) += 1;
    }
}
