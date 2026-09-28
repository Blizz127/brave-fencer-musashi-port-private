/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801707D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void func_80171928(void *);
extern s32 func_80174ED4(void);

void func_801707D4(void *a0) {
    if ((s16)func_80174ED4() != 0) {
        func_80171928(a0);
    }
}
