/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD1F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800233CC(void *arg0, u16 arg1);

void func_800CD1F4(void *a0, void *a1) {
    void *s0;

    s0 = a1;
    if (*(s32 *)((s32)a0 + 0x50) == 0) {
        func_800233CC(s0, 0x40);
    } else {
        func_800233CC(s0, 0x30);
    }
    *(u8 *)((s32)s0 + 0) = 0;
    *(u8 *)((s32)s0 + 1) = 0;
    *(u8 *)((s32)s0 + 2) = 0;
    *(u8 *)((s32)s0 + 4) = 0;
    *(u8 *)((s32)s0 + 5) = 0;
    *(u8 *)((s32)s0 + 6) = 0;
}
