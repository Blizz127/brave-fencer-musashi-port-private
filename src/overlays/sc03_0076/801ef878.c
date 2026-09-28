/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF878 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80115116;
extern unsigned short D_80115112;
extern void (*D_801F3468[])(void);
extern void func_80141C04(void);

void func_801EF878(void) {

    extern u16 D_80115112;
    extern u16 D_80115116;
    extern void (*D_801F3468[])(void);
    u16 i;
    i = D_80115112;
    D_801F3468[i]();
    func_80141C04();
    D_80115116++;
}
