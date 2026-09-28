/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3A4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80049CAC(s32 arg0, s32 arg1);

void func_800CB3A4(void *arg0) {
    s32 temp_v0 = *(s32 *)((s32)arg0 + 0x20);

    if (temp_v0 != 0) {
        func_80049CAC(temp_v0 + 0x10, *(s32 *)(temp_v0 + 0x34));
    }
}
