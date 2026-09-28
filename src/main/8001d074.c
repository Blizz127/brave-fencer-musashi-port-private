/* Exact retail [8001D074,8001D0E8).
 * Words from pinned SLUS_007.26.
 */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference. */
/* func_8001D074 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800AF630[];

u8 *func_8001D074(s32 start, s32 end) {
    u8 *base = D_800AF630;
    s32 off;
    u8 *ptr;

    if ((u32)start >= 0x100U) {
        goto none;
    }
    if ((u32)end >= 0x101U) {
        return 0;
    }
    if (start >= end) {
        goto none;
    }
    ptr = base + start * 56;
    off = start * 56;
    do {
        if (*(u16 *)(ptr + 0x65A8) == 0) {
            return base + (off + 0x65A8);
        }
        ptr += 0x38;
        start += 1;
        off += 0x38;
    } while (start < end);
none:
    return 0;
}
