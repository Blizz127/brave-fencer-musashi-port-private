/* Overlay range [80128C14,80128C98) from MAIN.CD member 0012.
 * SHA256(span)=6f02e31fe8bb0f8493d19d5a91c5a5ec7d00e8a3d0254c8ad4e63c82ec7ba66c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128C14 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern s16 currentLocationId;
extern short currentLocationId;
extern void func_80010AE0(s32 a0);

void func_80128C14(void) {
    s32 a0;
    switch (currentLocationId) {
    case 0x3023:
        a0 = 0x4E0;
        break;
    case 0x3081:
        a0 = 0x420;
        break;
    case 0x3067:
        a0 = 0x480;
        break;
    case 0x3093:
        a0 = 0xFFB;
        break;
    case 0x30A5:
        a0 = 0xFFB;
        break;
    default:
        a0 = 0x3E0;
        break;
    }
    func_80010AE0(a0);
}
