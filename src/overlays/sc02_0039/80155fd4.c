/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80155FD4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_80155FF8(int arg, int a1);

int func_80155FD4(int arg, int a1) {
    return func_80155FF8(arg, a1 | 0x20000);
}
