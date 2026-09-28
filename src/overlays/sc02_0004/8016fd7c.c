/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FD7C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void func_80171928(void *);
extern s32 func_80172658(s32 *a0);

void func_8016FD7C(s32 *a0) {
    if (func_80172658(a0)) {
        func_80171928(a0);
    }
}
