/* Overlay range [8013C360,8013C400) from MAIN.CD member 0012.
 * SHA256(span)=d316a8fa8c3995a3cc79f34cc0b1b667bcd56fbdbb5d92b9d8ab33e3a18a7921.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013C360 - byte-exact against retail at -O0 (tools/register_match.py). */


void func_8013C360(s32 a0) {
    s32 *p;
    u32 i;
    p = (s32 *)(a0 + 0x10);
    for (i = 0; i < *(u32 *)(a0 + 8); i++) {
        *(s32 *)(*(s32 *)p) = *(s32 *)((s32)p + 4);
        p = (s32 *)((s32)p + 0xC);
    }
}
