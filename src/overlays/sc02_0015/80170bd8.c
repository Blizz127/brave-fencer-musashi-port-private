/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170BD8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80181764[])(void);

void func_80170BD8(void *a0) {
    D_80181764[*(u8 *)((s32)a0 + 0x216)]();
}
