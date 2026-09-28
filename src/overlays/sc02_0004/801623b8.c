/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801623B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800167B8(s32 a0);
extern void func_800D0C48(s32 a0);

s32 func_801623B8(s32 *a0) {
    if (--a0[0xA] == -1) {
        func_800D0C48(1);
        func_800167B8(4);
        *((u8 *)a0 + 0x15) += 1;
    }
    return 0;
}
