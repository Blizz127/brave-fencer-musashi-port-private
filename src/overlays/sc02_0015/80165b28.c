/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165B28 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80181118[])(void);

void func_80165B28(void *a0) {
    *(u32 *)((s32)a0 + 0x44) |= 8;
    D_80181118[*(u8 *)((s32)a0 + 0x197)]();
}
