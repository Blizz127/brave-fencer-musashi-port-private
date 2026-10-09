/* SC02.CD member35 [80155458,801554B8): twin of main_0012 80155458 (src/overlays/main_0012/80155458.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80155458,801554B8) from MAIN.CD member 0012.
 * SHA256(span)=9e1c51789b156a0cfab4e692cacc499f23d15153ec067c8564d39609062c5f7a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80155458 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80155458(s32 param_1)
{

    extern int (*D_8018633C[])(void);
    int idx;

    idx = *(unsigned char *)(param_1 + 0x4e);
    if (idx != 0) {
        idx = idx - 1;
        if ((*D_8018633C[idx])() == 0) {
            *(unsigned char *)(param_1 + 0x4e) = 0;
        }
    }
    return *(unsigned char *)(param_1 + 0x4e);
}
