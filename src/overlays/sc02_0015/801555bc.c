/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801555BC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801555F4(void *a0);
extern s32 func_80161104(void);
extern void func_801555F4(void *);

void func_801555BC(void *a0) {
    if (func_80161104()) {
        func_801555F4(a0);
    }
}
