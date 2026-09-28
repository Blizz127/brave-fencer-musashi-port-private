/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80142FFC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80142DB8(s32 *a0);
extern void func_80142BB4(s32 *a0, s32 a1, s32 a2);
extern s32 func_80142D38(s32 *a0);
void func_80142BB4(s32 * param_1, s32 param_2, s32 param_3);
s32 func_80142D38(s32 *a0);
s32 func_80142DB8(s32 *a0);

void func_80142FFC(s32 *a0) {
    if (func_80142DB8(a0) == 1) {
        func_80142BB4(a0, 1, 3);
    } else if (func_80142D38(a0) == 1) {
        func_80142BB4(a0, 0, 3);
    }
}
