/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801426D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012AD50(void * arg0);
extern s32 func_8012AD50(void *a0);

void func_801426D4(s32 a0) {
    s32 s0 = *(s32 *)(a0 + 0x20);
    s16 fc = *(s16 *)(a0 + 0xFC);
    if (fc != 0) {
        *(s16 *)(a0 + 0xFC) = fc - 0x10;
        *(u16 *)(s0 + 0x18) += 0x800;
        *(u16 *)(s0 + 0x1A) += 0x800;
    } else {
        *(s32 *)(a0 + 0x1C) = 0xC;
        func_8012AD50((void *)a0);
        *(u16 *)(s0 + 0x1A) = 0x1800;
        *(u16 *)(s0 + 0x18) = 0x1800;
    }
}
