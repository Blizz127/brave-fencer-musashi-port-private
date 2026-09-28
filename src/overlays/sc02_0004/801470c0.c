/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801470C0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801470C0(s32 a0) {
    s32 a1;
    a1 = *(s32*)(a0 + 0x20);
    if (a1 != 0) {
        if ((*(u8*)(a0 + 0x221) | *(u8*)(a0 + 0x220) | *(u8*)(a0 + 0x222)) != 0) {
            *(s32*)(a1 + 0x4) |= 0x80000000;
        } else {
            *(s32*)(a1 + 0x4) &= 0x7FFFFFFF;
        }
    }
}
