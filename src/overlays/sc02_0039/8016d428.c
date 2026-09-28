/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016D428 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80182390[])(void);

void func_8016D428(void *a0) {
    D_80182390[*(u16 *)((s32)a0 + 0x2)]();
}
