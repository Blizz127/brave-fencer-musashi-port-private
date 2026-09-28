/* Main-exec range [8002F67C,8002F714) from the SLUS executable.
 * SHA256(span)=d1bfb59f95dd2f0c91c1401575c77d0f3fc6b54d51b80b079bc320a4e9e3a426.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002F67C - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8  D_800A4698;
extern s16 D_800A4688;
extern s16 D_800C5328[];
extern s16 D_800A46A2;
extern u8  D_800A46B0;

extern void func_800415A8(s32);

void func_8002F67C(void) {
    u8 *p = &D_800A4698;
    s32 v0;
    s32 t;

    if (*p == 0) {
        v0 = D_800A4688;
        *(s16 *)((u8 *)D_800C5328 + (v0 << 2)) = -1;
        *p = 1;
    }

    t = D_800A46A2;
    if (t >= 0) {
        func_800415A8(t);
        D_800A46A2 = -1;
    }

    if (D_800A46B0 == 0) {
        D_800A46B0 = 1;
    }
}
