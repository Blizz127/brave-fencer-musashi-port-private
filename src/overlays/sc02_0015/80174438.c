/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174438 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80174684(void *);
extern s32 D_80127508;
extern s32 func_80174474(void *a0);

void func_80174438(s32 a0) {
    func_80174684((void *)func_80174474);
    D_80127508 = a0;
}
