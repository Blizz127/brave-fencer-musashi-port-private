/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80179E74 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80179B74(u16 *p);
extern void func_80179B74(u16 *p);

void func_80179E74(s16 a0) {
    s16 sp[2];
    sp[0] = 0x4;
    sp[1] = a0;
    func_80179B74(sp);
}
