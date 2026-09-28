/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CE134 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146C3C(void *a0);
extern s32 func_80169A4C(s32 a0, s32 a1);

void func_800CE134(void) {
    register s32 a0v __asm__("$4");
    s32 param_1 = a0v;

    *(s32 *)(param_1 + 0x30) = *(s32 *)(param_1 + 0x1C) * 8;
    func_80169A4C(a0v, param_1 + 0x38);
    if (--*(s32 *)(param_1 + 0x1C) == 0)
        func_80146C3C((void *)param_1);
}
