/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801290DC - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 *func_8012913C(s32 a0);

u8 *func_801290DC(s32 a0, u8 *a1) {
    u8 *v1 = func_8012913C(a0 & 0xFFFF);
    if (v1 != 0) {
        *(u16 *)(v1 + 0x6) = *(u16 *)(a1 + 0x0);
        *(u16 *)(v1 + 0xA) = *(u16 *)(a1 + 0x2);
        *(u16 *)(v1 + 0xE) = *(u16 *)(a1 + 0x4);
    }
    return v1;
}
