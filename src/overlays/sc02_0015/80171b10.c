/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171B10 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014C568(s16 *a0, s16 *a1);

void func_80171B10(void *a0) {
    s32 ret = ((s32 (*)())func_8014C568)(a0);
    *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = ret;
}
