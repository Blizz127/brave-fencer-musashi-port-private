/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFD0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAFD0(void *a0) {
    extern u8 D_8011F9D0[];
    extern void func_80162CCC();
    s32 i;
    u8 *ptr;

    for (i = 0; i < 0x14; i++) {
        ptr = D_8011F9D0 + (i * 0x68);
        if (*(u16 *)ptr == 0x18) {
            func_80162CCC(ptr);
        }
    }

    *(u32 *)((s32)a0 + 0x44) &= ~2;
}
