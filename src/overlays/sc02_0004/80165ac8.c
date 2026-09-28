/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165AC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void (*D_80180B34[])(void);

void func_80165AC8(void) {
    D_80180B34[D_80078EC1 & 0x7F]();
}
