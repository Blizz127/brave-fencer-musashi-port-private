/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80129258 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_8011DB30;

void func_80129258(void) {
    s16 *p = &D_8011DB30;
    s32 i = 0x7F;
    do {
        *p = 0;
        p = (s16 *)((s32)p + 0x38);
        i--;
    } while (i >= 0);
}
