/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD884 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern void func_800CD96C(s32 a0);
extern s32 rand(void);

void func_800CD884(void *arg0) {
    s32 s0;
    u16 w;
    u16 t2;

    s0 = *(s32 *)((s32)arg0 + 0x20);
    if (*(s16 *)((s32)arg0 + 0x60) != 0) {
        w = *(u16 *)(s0 + 0x18) + 0x100;
        *(u16 *)(s0 + 0x18) = w;
        if ((s16)w > 0x1000) {
            if ((rand() & 1) != 0) {
                *(u16 *)(s0 + 0x18) = 0x1000;
            } else {
                *(u16 *)(s0 + 0x18) = 0x1333;
            }
        }
    } else {
        w = *(u16 *)(s0 + 0x18) - 0x100;
        *(u16 *)(s0 + 0x18) = w;
        if ((s16)w < 0) {
            *(u16 *)(s0 + 0x18) = 0;
        }
    }
    t2 = *(u16 *)(s0 + 0x18);
    *(u16 *)(s0 + 0x1C) = t2;
    *(u16 *)(s0 + 0x1A) = t2;
    *(u16 *)(s0 + 0x12) += 0x1C7;
    func_800CD96C((s32)arg0);
}
