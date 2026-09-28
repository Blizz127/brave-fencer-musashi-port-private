/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80132EF4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 *func_8012913C(s32 a0);
extern u8 * func_8012913C(s32 arg0);
extern void func_80129350(s32 a0, s32 a1);

s32 func_80132EF4(s32 a0, s32 a1) {
    s32 s0 = func_8012913C(a1 & 0xFFFF);
    if (s0 != 0) {
        func_80129350(s0, a0);
    }
    return s0;
}
