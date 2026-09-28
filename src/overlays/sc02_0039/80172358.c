/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172358 - byte-exact against retail at -O2 (tools/register_match.py). */
struct U8;
struct U8 {
    char b[8];
} __attribute__((aligned(1)));

void func_80172358(u8 *a0, u8 *a1) {
    *(u16 *)(a0 + 6) = *(u16 *)(a1 + 0);
    *(u16 *)(a0 + 0xA) = *(u16 *)(a1 + 2);
    *(u16 *)(a0 + 0xE) = *(u16 *)(a1 + 4);
    *(struct U8 *)(a0 + 0x90) = *(struct U8 *)(a1 + 0);
    *(struct U8 *)(a0 + 0x88) = *(struct U8 *)(a0 + 0x90);
}
