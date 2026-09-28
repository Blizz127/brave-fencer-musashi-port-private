/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80141C50 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_8011511E;
extern s32 func_80015144(void);
extern u16 D_8011511C;

s32 func_80141C50(void) {
    if (D_8011511C != 0x90F) {
        return 0;
    }
    if ((D_8011511E & 0x800) == 0) {
        return 0;
    }
    return func_80015144() != 0;
}
