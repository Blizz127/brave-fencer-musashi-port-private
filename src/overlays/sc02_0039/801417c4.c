/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801417C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned short D_80115112;
extern u16 D_80115112;
extern void func_8001903C(void);

void func_801417C4(void) {
    u16 *p = &D_80115112;
    func_8001903C();
    *p = *p + 1;
}
