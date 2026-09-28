/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012EECC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8002A4FC(s32 a0);

s32 func_8012EECC(s32 a0) {
    s32 n = a0 * func_8002A4FC(a0);
    return a0 - (n * 100) / 7680;
}
