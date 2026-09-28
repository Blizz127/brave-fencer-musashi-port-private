/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF9DC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012E544(s32 a0);

void func_801EF9DC(void) {
    s32 v0 = func_8012E544(0x157);
    if (v0 != 0) {
        *(s16*)(v0 + 0xFC) = 2;
    }
}
