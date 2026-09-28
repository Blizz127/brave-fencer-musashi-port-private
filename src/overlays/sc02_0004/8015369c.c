/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015369C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_8011DB28)(s32 a0);

void func_8015369C(s32 a0) {
    if (D_8011DB28 != 0) {
        D_8011DB28(a0 + 0xA0);
    }
    *(u8 *)(a0 + 0xDE) = 0x5A;
}
