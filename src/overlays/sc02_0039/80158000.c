/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80158000 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161104(void);
extern void func_80158038(void *);

void func_80158000(void *a0) {
    if (func_80161104()) {
        func_80158038(a0);
    }
}
