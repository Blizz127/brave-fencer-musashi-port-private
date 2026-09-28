/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D7A4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80181D80[])(void);

void func_8017D7A4(void *a0) {
    D_80181D80[*(u16 *)((s32)a0 + 0x2)]();
}
