/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014A4B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);

s32 func_8014A4B4(void *a0) {
    if ((func_80029178(0x1E) & 0xFF) != 0) {
        u32 v = *(u16 *)((s32)a0 + 0xAC) & 0x40;
        return v != 0;
    }
    return 0;
}
