/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170D68 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_8018120C[])(void);

void func_80170D68(void *a0) {
    D_8018120C[*(u8 *)((s32)a0 + 0x216)]();
}
