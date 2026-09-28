/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170E34 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_8018177C[])(void);

void func_80170E34(void *a0) {
    D_8018177C[*(u8 *)((s32)a0 + 0x216)]();
}
