/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80160888 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161104(void);
extern void func_801608C0(s32 *a0);

void func_80160888(s32 *a0) {
    if (func_80161104()) {
        func_801608C0(a0);
    }
}
