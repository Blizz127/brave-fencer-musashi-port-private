/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB358 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB358(void *param_1) {
    extern void (*D_800CB834[])(void);
    extern void func_80146C3C();

    if (*(u16 *)(*(s32 *)((s32)param_1 + 0x34)) == 0x26) {
        D_800CB834[*(u16 *)((s32)param_1 + 2)]();
    } else {
        func_80146C3C(param_1);
    }
}
