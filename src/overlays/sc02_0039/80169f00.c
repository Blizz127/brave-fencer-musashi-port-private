/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80169F00 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_801821DC[])(void);

void func_80169F00(void *a0) {
    D_801821DC[*(u16 *)((s32)a0 + 0x2)]();
}
