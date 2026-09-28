/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801685EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
s32 func_80166690(s32 param_1, s32 param_2);
s32 func_80166994();
extern void func_80146C3C(void);
extern s32 func_80166994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80166690();

void func_801685EC(s32 a0) {
    func_80166994(a0, 2, 2, 0);
    if ((short)func_80166690(2, 1) == 0) {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
