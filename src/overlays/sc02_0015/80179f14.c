/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80179F14 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80179B74(u16 *p);
extern void func_80179B74(u16 *p);

void func_80179F14(s16 a0, s16 a1) {
    s16 sp[3];
    sp[0] = 0x13;
    sp[1] = a0;
    sp[2] = a1;
    func_80179B74(sp);
}
