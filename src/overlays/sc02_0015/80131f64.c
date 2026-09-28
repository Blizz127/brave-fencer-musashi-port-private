/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80131F64 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_8017E7BC[])(void);

void func_80131F64(void *a0) {
    D_8017E7BC[*(u16 *)((s32)a0 + 0x2)]();
}
