/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD030 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146CA0(void *);
extern s32 func_80146CA0(void *a0);

void func_800CD030(s32 *a0) {
        *(s16 *)((s32)a0 + 0x60) = 0;
        ((void (*)(void))func_80146CA0)();
    }
