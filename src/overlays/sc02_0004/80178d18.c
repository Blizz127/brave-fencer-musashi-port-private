/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178D18 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80174714(void);
extern short D_801963C4;

void func_80178D18(void) {
    D_801963C4 = 0;
    func_80174714();
}
