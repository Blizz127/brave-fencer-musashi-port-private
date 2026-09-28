/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149B14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8015DAC4(s32 *a0);
extern void func_8015554C(s32 *a0);

void func_80149B14(s32 *a0) {
    s32 pad[6];
    (void)pad;
    if (*(s32 *)((s32)a0 + 0x178) != 0) {
        func_8015DAC4(a0);
    } else {
        func_8015554C(a0);
    }
}
