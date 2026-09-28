/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD58C - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_800CCDE8();

void func_800CD58C(void *arg0) {
    extern u8 D_800CD6E0[];
    extern void func_80016714(void *a0, s32 a1);
    extern void func_800CCBC0(void);

    if (*(s32 *)((s32)arg0 + 0x2C) != 0) {
        func_800CCDE8(arg0, 1, 0x37);
        func_800CCBC0();
        *(s32 *)((s32)arg0 + 0x2C) = 0;
    } else {
        func_80016714(D_800CD6E0, 0xC4);
        func_800CCDE8(arg0, 0, 0);
    }
}
