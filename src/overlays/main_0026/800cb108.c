/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB108 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014C168(s32 *arg0, s32 arg1);

void func_800CB108(s32 *arg0) {
    s32 s0;

    s0 = func_8014C168(arg0, 0x15C);
    if (s0 != 0) {
        *(s32 *)(s0 + 0xCC) = 0;
    }
}
