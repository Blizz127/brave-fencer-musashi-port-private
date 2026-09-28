/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801489E8 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801489E8(s32 a0) {
    u8 v1;
    v1 = *(u8*)(a0 + 0xA9);
    switch (v1) {
    case 0x41:
        return *(u16*)(a0 + 0xAA) & 0x8000;
    case 0x53:
    case 0x73:
        return *(u8*)(a0 + 0xAE) < 0x40;
    }
    return 0;
}
