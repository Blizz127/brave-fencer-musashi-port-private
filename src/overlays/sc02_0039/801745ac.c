/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801745AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147060(u8 * a0);
extern void func_80147060(u8 *a0);
extern s32 func_80174650(s32);

void func_801745AC(s32 *a0) {
    ((void (*)(s32 *))func_80147060)(a0);
    func_80174650((s32)a0);
}
