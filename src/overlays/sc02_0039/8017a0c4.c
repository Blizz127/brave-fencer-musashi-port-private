/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017A0C4 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80179B74(u16 *p);
extern void func_80179B74(u16 *p);
extern s32 D_801A0BFC;

void func_8017A0C4(s32 arg0) {
    s16 sp10;

    D_801A0BFC = arg0;
    sp10 = 0x16;
    func_80179B74(&sp10);
}
