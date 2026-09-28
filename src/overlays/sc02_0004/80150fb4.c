/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150FB4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80151184(s32 a0, s32 a1, s32 a2);
extern int func_80151184(int arg, int a1, int a2);

int func_80150FB4(int arg) {
    return func_80151184(arg, 0x8, 0);
}
