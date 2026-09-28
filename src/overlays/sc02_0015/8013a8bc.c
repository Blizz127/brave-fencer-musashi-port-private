/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013A8BC - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_8011DA80[];

s32 func_8013A8BC(void) {
    s32 p;
    s32 i;
    p = (s32)D_8011DA80;
    for (i = 0; i < 0x20; i += 0x10) {
        if (*(s16*)((s32)D_8011DA80 + i) == 0) {
            return p;
        }
        p += 0x10;
    }
    return 0;
}
