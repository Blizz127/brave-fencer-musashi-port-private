/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801598BC - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_800167F0(int arg);

int func_801598BC(void) {
    return (func_800167F0(4) & 0xFFFF) != 0;
}
