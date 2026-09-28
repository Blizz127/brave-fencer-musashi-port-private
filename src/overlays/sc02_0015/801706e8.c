/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801706E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80171990(u8 *a0);
extern void func_80170718(void *a0);

void func_801706E8(u8 *a0) {
    func_80171990(a0);
    func_80170718(a0);
}
