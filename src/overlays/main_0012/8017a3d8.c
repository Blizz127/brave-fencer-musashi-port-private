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

    extern short D_80185384;
    extern short D_80185380;
    switch (D_80185384) {
    case 0:
        func_800D0CA0(1);
        D_80185384 = D_80185384 + 1;
        return 0;
    case 100:
    {
        register int a __asm__("$4");
        a = D_80185380;
        if (a != -1) {
            return func_8001AAA0() != 0;
        }
        return func_800D0CE0() == 1;
    }
    default:
        D_80185384 = D_80185384 + 1;
        if (D_80185384 < 0x1E) {
            return 0;
        }
        D_80185384 = 100;
        return 0;
    }
}
