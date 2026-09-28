/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015ABD4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg);
extern s32 func_8016F1AC(void);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern s32 D_8011F9C4;

s32 func_8015ABD4(s32 a0, s32 a1, s32 a2) {
    if (func_8016F1AC() != 0) {
        return 0;
    }
    if (a2 < a1) {
        if (D_8011F9C4 == 0) {
            return 0;
        }
        if ((func_80029178(0x21) & 0xFF) != 0) {
            return 0;
        }
    }
    return 1;
}
