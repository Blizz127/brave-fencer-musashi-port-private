/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80179F6C - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80179B74(u16 *p);
extern void func_80179B74(u16 *p);

void func_80179F6C(short a0) {
    short sp[2];
    sp[1] = a0;
    sp[0] = 0x14;
    func_80179B74(sp);
}
