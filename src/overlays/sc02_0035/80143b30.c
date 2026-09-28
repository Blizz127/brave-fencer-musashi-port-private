/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80143B30 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80185DF4[])(void);

void func_80143B30(void *a0) {
    D_80185DF4[*(u16 *)((s32)a0 + 0x2)]();
}
