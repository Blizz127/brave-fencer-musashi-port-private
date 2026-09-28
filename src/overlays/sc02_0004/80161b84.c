/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161B84 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80149884(void);
extern void func_801498C0(void);
extern void func_801599A4(void *a0);
extern void func_801599A4(void*);

s32 func_80161B84(void *a0) {
    if ((((s32 *)a0)[0x11] & 0x100) != 0) {
        if (func_80149884() != 0) {
            func_801599A4(a0);
            (*(void (*)(void *))func_801498C0)(a0);
            return 1;
        }
    }
    return 0;
}
