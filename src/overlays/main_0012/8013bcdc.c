/* Overlay range [8013BCDC,8013BD34) from MAIN.CD member 0012.
 * SHA256(span)=96bc895e419c22ee1b1266f8b0f4c2fdcb4ccd15e68066256bf34ded46921549.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013BCDC - byte-exact against retail at -O0 (tools/register_match.py). */
extern s32 D_8017EAD4;

void func_8013BCDC(void) {
    s32 pad[4];
    if (D_8017EAD4 != 0) {
        ((void (*)(void))D_8017EAD4)();
    }
}
