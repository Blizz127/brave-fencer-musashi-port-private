/* Overlay range [8017A3B0,8017A3D8) from MAIN.CD member 0012.
 * SHA256(span)=878e8b2edd286fa3aae75824e44ed9a2b5c02333c6adde8b377bf90f64ba6574.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017A3B0 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8017A3B0(void) {

    extern s16 D_80185348;
    switch (D_80185348) {
    case 0:
        return 1;
    case 1:
        return 0;
    default:
        return 1;
    }
}
