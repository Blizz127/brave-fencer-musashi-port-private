/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801511E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_80151204(int arg, int a1);

int func_801511E0(int arg) {
    return func_80151204(arg, *(short *)((int)arg + 0xF2));
}
