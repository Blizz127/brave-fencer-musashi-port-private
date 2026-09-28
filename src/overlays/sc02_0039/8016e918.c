/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E918 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80115218;

void func_8016E918(short param_1, short param_2) {
    char *p;
    if (param_2 < 10) {
        p = (char *)&D_80115218 + ((s32)param_1 << 5);
        p[0] = param_1 + 1;
        p[3] = param_2;
        p[1] = 0;
    }
}
