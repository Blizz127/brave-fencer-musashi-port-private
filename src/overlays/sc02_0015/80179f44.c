/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80179F44 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80179B74(u16 *p);
extern void func_80179B74(u16 *p);

void func_80179F44(void) {
    short sp10;
    sp10 = 0x18;
    func_80179B74(&sp10);
}
