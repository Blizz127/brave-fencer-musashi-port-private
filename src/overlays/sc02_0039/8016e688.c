/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E688 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016E778();

void func_8016E688(void *a0) {
    u16 *p = (u16 *)a0;
    s16 v;
    p[0x10/2] += 0x200;
    v = p[0x12/2] + p[0x10/2];
    p[0x12/2] = v;
    if (v >= 0x3000) {
        *(s32 *)((u8 *)a0 + 0x1C) = 4;
        *(s16 *)((u8 *)a0 + 0x2) += 1;
    }
    func_8016E778();
}
