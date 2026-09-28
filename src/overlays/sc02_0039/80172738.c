/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172738 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80172760(s32 a0);
extern void func_80174684(void *);

void func_80172738(void) {
    func_80174684((void *)func_80172760);
}
