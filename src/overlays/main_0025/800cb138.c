/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB138 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(u8 *a0);
extern void func_80159B3C(void *a0);

void func_800CB138(u8 *a0) {
    if (*(u16 *)(a0 + 0xB8) & 0x8000) {
        func_801599A4(a0);
        func_80159B3C(a0);
    }
}
