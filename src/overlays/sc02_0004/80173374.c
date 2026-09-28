/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80173374 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016F2EC(void);
extern s32 func_80174650(s32);

void func_80173374(s32 *a0) {
        ((void (*)(s32 *))func_8016F2EC)(a0);
        func_80174650((s32)a0);
    }
