/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801751D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern s32 func_80161104(void);
extern s32 func_80175218(void *a0);

void func_801751D8(void *a0) {
    void *s = a0;
    if (func_80161104()) {
        func_80175218(s);
        func_80146CA0(s);
    }
}
