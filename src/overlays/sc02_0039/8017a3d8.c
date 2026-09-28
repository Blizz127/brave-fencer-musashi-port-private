/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017A3D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern short D_801A0C1C;
extern short D_801A0C18;
extern int func_800D0CA0(int);
extern int func_8001AAA0(void);
extern int func_800D0CE0(void);

int func_8017A3D8(void)
{
    switch (D_801A0C1C) {
    case 0:
        func_800D0CA0(1);
        D_801A0C1C = D_801A0C1C + 1;
        return 0;
    case 100:
    {
        register int a __asm__("$4");
        a = D_801A0C18;
        if (a != -1) {
            return func_8001AAA0() != 0;
        }
        return func_800D0CE0() == 1;
    }
    default:
        D_801A0C1C = D_801A0C1C + 1;
        if (D_801A0C1C < 0x1E) {
            return 0;
        }
        D_801A0C1C = 100;
        return 0;
    }
}
