/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015E924 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161104(void);
extern void func_8015E95C(s32);

void func_8015E924(s32 a0) {
    if (func_80161104() != 0) {
        func_8015E95C(a0);
    }
}
