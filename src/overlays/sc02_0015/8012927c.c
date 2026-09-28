/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012927C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_8011DB30;
extern void func_801292C8(u8 *a0);

void func_8012927C(void) {
    s32 i;
    u8 *p = (u8 *)&D_8011DB30;
    for (i = 0; i < 0x80; i++) {
        func_801292C8(p);
        p += 0x38;
    }
}
