/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80163A58 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80181CAC[])(void);

void func_80163A58(void *a0) {
    D_80181CAC[*(u16 *)((s32)a0 + 0x2)]();
}
