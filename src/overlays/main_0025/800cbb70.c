/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBB70 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801466B4(u16 a0, s32 a1, s32 a2, s32 a3, s32 arg5);

void func_800CBB70(void *a0) {
    func_801466B4(0x27, a0, 0, 0, 0);
}
