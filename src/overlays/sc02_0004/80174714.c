/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174714 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147060(u8 * a0);
extern s32 func_8016F0AC();
extern void func_80147060(u8 *a0);
extern s32 D_80126B58;
extern s32 func_800CF8CC(void);

void func_80174714(void) {
    if (func_800CF8CC() == 0) {
        func_80147060((u8 *)&D_80126B58);
        func_8016F0AC();
    }
}
