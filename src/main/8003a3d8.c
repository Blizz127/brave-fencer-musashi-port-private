/* Main-exec range [8003A3D8,8003A404) from the SLUS executable.
 * SHA256(span)=d0c82ad7db2cc766e8ffc926f6c0975e143708bcf7d9a032f55b5d01f57feb80.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8003A3D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

u32 func_8003A3D8(u32 a) {
    return ((a & 0xFF) << 24) + (((a >> 8) & 0xFF) << 16) + (((a >> 16) & 0xFF) << 8) | (a >> 24);
}
