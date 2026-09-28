/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB7F0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();

void func_800CB7F0(s32 a0) {
    if (func_80128ED8((void *)*(s32 *)(a0 + 0x20), (void *)(a0 + 0x24)) != 0) {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
