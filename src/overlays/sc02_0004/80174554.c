/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174554 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014706C(void *arg0);
extern void func_8014706C(void *a0);
extern s32 func_80174650(s32);

void func_80174554(s32 arg0) {
        ((void (*)(s32 *))func_8014706C)((s32 *)arg0);
        func_80174650(arg0);
    }
