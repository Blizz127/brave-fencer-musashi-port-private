/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012C1DC - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_800B3DF0[];

s32 func_8012C1DC(s32 a0) {
    u8 *p;
    u8 *end;
    p = (u8 *)(*(s32 *)(a0 + 0x20) + 0x84);
    end = D_800B3DF0;
    if (p != end) {
        do {
            if (*(u16 *)p == 0) {
                return (s32)p;
            }
            p += 0x84;
        } while (p != end);
    }
    return 0;
}
