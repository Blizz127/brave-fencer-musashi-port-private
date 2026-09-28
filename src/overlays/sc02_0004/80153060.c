/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80153060 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_8017FAAC[])(void);

void func_80153060(void *a0) {
    D_8017FAAC[*(u16 *)((s32)a0 + 0x2)]();
}
