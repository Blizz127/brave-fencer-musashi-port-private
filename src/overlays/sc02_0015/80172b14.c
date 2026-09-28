/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172B14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80174684(void *);
extern s16 D_80126B32;
extern s32 func_80172B44();

void func_80172B14(s16 a0) {
    D_80126B32 = a0;
    func_80174684((void *)func_80172B44);
}
