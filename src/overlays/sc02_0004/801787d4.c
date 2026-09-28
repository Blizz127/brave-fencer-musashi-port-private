/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801787D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];
extern void func_80178840();

void func_801787D4(void) {
    u8 *p = D_801202A0;
    s32 i;
    for (i = 0; i < 0x60; i++) {
        if (*(u16 *)(p + 0) != 0 && p[0xC0] != 0) {
            func_80178840(p);
        }
        p += 0x10C;
    }
}
