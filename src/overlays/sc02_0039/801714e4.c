/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801714E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_8018266C[])(void);

void func_801714E4(void *a0) {
    D_8018266C[*(u8 *)((s32)a0 + 0x216)]();
}
