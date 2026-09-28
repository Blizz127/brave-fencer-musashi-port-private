/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015BEE4 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_8015B950(s32 arg0);
extern s32 func_8015B950(s32 arg0);

s32 func_8015BEE4(void) {
    return ((s32 (*)(void))func_8015B950)();
}
