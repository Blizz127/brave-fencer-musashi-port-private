/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C088 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8011F9D0;

s32 func_8014C088(s32 a0, s32 a1) {
    u8 *p;
    u8 *end;
    p = (u8 *)&D_8011F9D0;
    end = p + 0xC30;
    if (p >= end) {
        return 0;
    }
    do {
        if (*(u16 *)p == a1) {
            return (s32)p;
        }
        p += 0x68;
    } while (p < end);
    return 0;
}
