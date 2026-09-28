/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD384 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_800CDD08[])(void);

void func_800CD384(void) {
    register s32 idx __asm__("$2");
    __asm__ __volatile__("" : : "r"(idx));
    D_800CDD08[idx]();
}
