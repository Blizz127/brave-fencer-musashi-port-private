/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80147324 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *D_8012707C;
extern void func_80147364();

void func_80147324(s32 arg0) {
    s32 temp_a0;
    temp_a0 = arg0 & 0xFFFF;
    if (temp_a0 == D_8012707C) {
        D_8012707C = 0;
        return;
    }
    func_80147364(temp_a0, 0);
}
