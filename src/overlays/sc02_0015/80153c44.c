/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80153C44 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80153C74(s16 a0, s16 a1);
extern s16 D_8011DB18;

void func_80153C44(int a0, int a1, s16 a2)
{
    ((void (*)(int, int))func_80153C74)(a0, a1);
    D_8011DB18 = a2;
}
