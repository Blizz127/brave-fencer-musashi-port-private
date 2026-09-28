/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FC24 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);
extern s32 func_80171B4C(s32 a0, s32 a1);

void func_8016FC24(s32 a0) {
    if (func_80171B4C(a0, *(u8 *)&D_8011F738)) {
        func_80171990((u8 *)a0);
    }
}
