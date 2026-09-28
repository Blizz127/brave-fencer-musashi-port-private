/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149884 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern s16 currentLocationId;
extern s32 func_8016F1AC(void);

s32 func_80149884(void) {
    s32 ret;
    if (currentLocationId == 0x308F) {
        ret = 0;
    } else {
        ret = func_8016F1AC() == 0;
    }
    return ret;
}
