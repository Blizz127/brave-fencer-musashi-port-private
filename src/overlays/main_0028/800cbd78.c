/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBD78 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CB8A0(void *a0);
extern void func_80146C3C();

void func_800CBD78(s32 param_1) {
    extern void func_800CB8A0();
    s16 var;

    var = *(u16 *)(param_1 + 0x28) - 0x100;
    *(u16 *)(param_1 + 0x28) = var;
    if (var > 0) {
        *(s32 *)(param_1 + 0x50) -= 3;
        func_800CB8A0(param_1);
    } else {
        func_80146C3C();
    }
}
