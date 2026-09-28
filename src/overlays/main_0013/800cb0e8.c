/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB0E8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB0E8(void *a0) {
    extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
    s32 v1;

    v1 = func_80146994(0x15, (s32)a0, 0, 0);
    if (v1 != 0) {
        *(s32 *)(v1 + 0x30) = *(s16 *)((u8 *)a0 + 0x36);
    }
}
