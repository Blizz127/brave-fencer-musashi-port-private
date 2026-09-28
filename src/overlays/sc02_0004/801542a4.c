/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801542A4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154418(void *a0);

void func_801542A4(s32 *a0, s32 a1) {
        *(s32 *)((u8 *)a0 + 0xB4) = a1;
        *(s16 *)((u8 *)a0 + 0xBA) = 1;
        *(s16 *)((u8 *)a0 + 0xB8) = 1;
        *(s8 *)((u8 *)a0 + 0xBC) = 0;
        *(s8 *)((u8 *)a0 + 0xBD) = 0;
        *(s8 *)((u8 *)a0 + 0xDC) = 0;
        ((void (*)(void))func_80154418)();
    }
