/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801702FC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_8018171C[])(void);

void func_801702FC(void *a0) {
    D_8018171C[*(u8 *)((s32)a0 + 0x216)]();
}
