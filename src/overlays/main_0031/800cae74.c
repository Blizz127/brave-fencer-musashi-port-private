/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE74 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg0);

void func_800CAE74(s32 arg0, s32 arg1, s32 *arg2) {
    s32 base;
    s32 p;
    s32 z;
    s32 *iter;
    s32 s;

    extern void func_800183E0(s32 a0);

    base = *(s32 *)(arg1 + 0xC);
    *(u16 *)(arg1 + 0x2) = *(u16 *)(arg0 + 0x2);
    *(u16 *)(arg1 + 0x4) = *(u16 *)(arg0 + 0x4);
    *(u16 *)(arg1 + 0x6) = *(u16 *)(arg0 + 0x6);
    *(u16 *)(arg1 + 0x8) = *(u16 *)(arg0 + 0x8);
    *(u16 *)(arg1 + 0xA) = *(u16 *)(arg0 + 0xA);
    p = base;
    s = *(s32 *)(arg0 + 0xC);
    do {
        *(u8 *)p = *(u8 *)s;
        p += 1;
        s += 1;
    } while (p < base + 0x1F);
    s = *arg2;
    if (s != 0) {
        iter = arg2;
        z = base;
        do {
            if ((func_80029178(s) & 0xFF) == 0) {
                *(u8 *)z = 0;
                *(u8 *)(z + 1) = 0;
            }
            iter += 1;
            s = *iter;
            z += 2;
        } while (s != 0);
    }
    func_800183E0(arg1);
}
