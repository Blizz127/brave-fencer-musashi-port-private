/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80153C74 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_8011DB1A;
extern s16 D_8011DB0C;

void func_80153C74(s16 a0, s16 a1) {
    D_8011DB0C = a0;
    D_8011DB1A = a1;
}
