/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FA44 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);
extern s32 func_80171C64(s32 a0, s32 a1);

void func_8016FA44(s32 a0) {
    if (func_80171C64(a0, *(u8 *)&D_8011F738)) {
        func_80171928((void *)a0);
    }
}
