/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FB10 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);
extern s32 func_80171CC4(void *a0, void *a1);

void func_8016FB10(void *a0) {
    if (func_80171CC4(a0, &D_8011F738)) {
        func_80171990((u8 *)a0);
    }
}
