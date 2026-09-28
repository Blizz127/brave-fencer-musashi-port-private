/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170B14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801719A4(int a0, int a1);
extern void func_80170B48(int a0);

void func_80170B14(int a0) {
    func_801719A4(a0, 1);
    func_80170B48(a0);
}
