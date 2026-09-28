/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016C374 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8016C374(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 v;
    *(u16 *)(a1 + 0x0) = *(u16 *)(a1 + 0x0) - 0xA;
    if ((s16)*(u16 *)(a1 + 0x0) < 0) {
        *(u16 *)(a1 + 0x0) = 0;
    }
    *(u16 *)(a1 + 0x2) = *(u16 *)(a1 + 0x2) - 0xA;
    if ((s16)*(u16 *)(a1 + 0x2) < 0) {
        *(u16 *)(a1 + 0x2) = 0;
    }
    *(u16 *)(a1 + 0x4) = *(u16 *)(a1 + 0x4) - 0xA;
    if ((s16)*(u16 *)(a1 + 0x4) < 0) {
        *(u16 *)(a1 + 0x4) = 0;
    }
    *(u16 *)(a2 + 0x0) = *(u16 *)(a2 + 0x0) - 0xA;
    if ((s16)*(u16 *)(a2 + 0x0) < 0) {
        *(u16 *)(a2 + 0x0) = 0;
    }
    *(u16 *)(a2 + 0x2) = *(u16 *)(a2 + 0x2) - 0xA;
    if ((s16)*(u16 *)(a2 + 0x2) < 0) {
        *(u16 *)(a2 + 0x2) = 0;
    }
    *(u16 *)(a2 + 0x4) = *(u16 *)(a2 + 0x4) - 0xA;
    if ((s16)*(u16 *)(a2 + 0x4) < 0) {
        *(u16 *)(a2 + 0x4) = 0;
    }
    *(u8 *)(a3 + 0x0) = *(u16 *)(a1 + 0x0);
    *(u8 *)(a3 + 0x1) = *(u16 *)(a1 + 0x2);
    *(u8 *)(a3 + 0x2) = *(u16 *)(a1 + 0x4);
    *(u8 *)(a3 + 0x4) = *(u16 *)(a2 + 0x0);
    *(u8 *)(a3 + 0x5) = *(u16 *)(a2 + 0x2);
    *(u8 *)(a3 + 0x6) = *(u16 *)(a2 + 0x4);
    v = *(u16 *)(a2 + 0x4) | (*(u16 *)(a2 + 0x0) | *(u16 *)(a2 + 0x2));
    return (s16)v;
}
