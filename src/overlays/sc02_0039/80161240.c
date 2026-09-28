/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161240 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801612B8(void *a0, s32 a1);
extern void func_8016130C(void*, s32);
extern void func_8016130C(void *a0, s32 a1);

void func_80161240(void *a0) {
    func_8016130C(a0, func_801612B8(a0, 1));
}
