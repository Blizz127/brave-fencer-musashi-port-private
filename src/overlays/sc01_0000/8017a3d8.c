/* Overlay range [8017A3D8,8017A460) from MAIN.CD member 0012.
 * SHA256(span)=6cbecb50f3f8d25714fb18fdeca6c16855fc15964d38c1e54961679b22250c72.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017A3D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_800D0CA0(int);
extern int func_8001AAA0(void);
extern int func_800D0CE0(void);

int func_8017A3D8(void)
{

    extern short D_801A56AC;
    extern short D_801A56A8;
    switch (D_801A56AC) {
    case 0:
        func_800D0CA0(1);
        D_801A56AC = D_801A56AC + 1;
        return 0;
    case 100:
    {
        register int a __asm__("$4");
        a = D_801A56A8;
        if (a != -1) {
            return func_8001AAA0() != 0;
        }
        return func_800D0CE0() == 1;
    }
    default:
        D_801A56AC = D_801A56AC + 1;
        if (D_801A56AC < 0x1E) {
            return 0;
        }
        D_801A56AC = 100;
        return 0;
    }
}
